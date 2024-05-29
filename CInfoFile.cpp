#include "pch.h"
#include "CInfoFile.h"
#include <afxwin.h> 
CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}


//��ȡ������Ϣ
void CInfoFile::ReadDocline()
{
	ifstream ifs(_D_NEED); //���뷽ʽ���ļ�
	char* but;
	char buf[1024] = { 0 };
	num = 0;	//��ʼ��������ĿΪ0
	ls.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //û���ļ���β
	{
		Diqu tmp;

		ifs.getline(buf, sizeof(buf)); //��ȡһ��
		num++;	//������Ŀ��һ

		//AfxMessageBox(CString(buf));
		char* sst = strtok_s(buf, "|",&but); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.SetName(CString(sst)); //������
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.SetThingname(CString(sst));	//��������
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.SetNum(atoi(sst));	//������Ŀ
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //�ԡ�|���и�
		if (sst != NULL)
		{
			if (*sst == 'y')tmp.Satisfied();      //״̬
		}
		else
		{
			break;
		}
		ls.push_back(tmp); //��������ĺ���
	}

	ifs.close(); //�ر��ļ�
}

//��������д���ļ�
void CInfoFile::WirteDocline()
{
	ofstream ofs(_D_NEED);//�����ʽ���ļ�

	if (ls.size() > 0)	//�������������ݲ�ִ��
	{
		ofs << "��������|��������|������|״̬" << endl; //д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<Diqu>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			CString ma1 = it->GetName();
			string p = CW2A(ma1.GetString());
			ofs << p<< "|";
			CString ma2 = it->GetThingname();
			string q = CW2A(ma2.GetString());
			ofs << q<< "|";
			ofs << it->GetNum() << "|";
			if(it->GetZhaungtai()==true) ofs << 'y' << endl;
			else ofs << 'n' << endl;
		}
	}

	ofs.close();//�ر��ļ�
}

//����µ�������
//name:��Ʒ���ƣ�num����棬price���۸�
void CInfoFile::Addline(CString name, CString tname, int num)
{

	if (ls.size() >= 0)
	{
		//��Ʒ���ƣ���棬�۸���Ч
		if (!name.IsEmpty() && num > 0 && !tname.IsEmpty())
		{
			Diqu tmp(name, tname, num);
			ls.push_back(tmp);	//��������ĺ���
			
		}
	}
}