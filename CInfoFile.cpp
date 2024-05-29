#include "pch.h"
#include "CInfoFile.h"
#include <afxwin.h> 
CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}


//读取地区信息
void CInfoFile::ReadDocline()
{
	ifstream ifs(_D_NEED); //输入方式打开文件
	char* but;
	char buf[1024] = { 0 };
	num = 0;	//初始化地区数目为0
	ls.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //没到文件结尾
	{
		Diqu tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行
		num++;	//地区数目加一

		//AfxMessageBox(CString(buf));
		char* sst = strtok_s(buf, "|",&but); //以“|”切割
		if (sst != NULL)
		{
			tmp.SetName(CString(sst)); //地区名
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //以“|”切割
		if (sst != NULL)
		{
			tmp.SetThingname(CString(sst));	//需求名称
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //以“|”切割
		if (sst != NULL)
		{
			tmp.SetNum(atoi(sst));	//需求数目
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, "|", &but); //以“|”切割
		if (sst != NULL)
		{
			if (*sst == 'y')tmp.Satisfied();      //状态
		}
		else
		{
			break;
		}
		ls.push_back(tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
}

//地区需求写入文件
void CInfoFile::WirteDocline()
{
	ofstream ofs(_D_NEED);//输出方式打开文件

	if (ls.size() > 0)	//地区链表有内容才执行
	{
		ofs << "地区名称|需求名称|需求数|状态" << endl; //写入表头

		//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
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

	ofs.close();//关闭文件
}

//添加新地区需求
//name:商品名称，num：库存，price：价格
void CInfoFile::Addline(CString name, CString tname, int num)
{

	if (ls.size() >= 0)
	{
		//商品名称，库存，价格有效
		if (!name.IsEmpty() && num > 0 && !tname.IsEmpty())
		{
			Diqu tmp(name, tname, num);
			ls.push_back(tmp);	//放在链表的后面
			
		}
	}
}