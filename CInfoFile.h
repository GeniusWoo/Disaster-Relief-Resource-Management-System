#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include"Diqu.h"

#define _D_NEED "./DIQU.txt"

using namespace std;

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();


	// ��ȡ��������
	void ReadDocline();

	//����д���ļ�
	void WirteDocline();

	//����µ���
	void Addline(CString name,CString tname, int num);

	list<Diqu> ls;	//�洢��������
	int num;			//������¼��Ʒ����
};

