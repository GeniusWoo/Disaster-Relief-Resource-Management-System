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


	// 读取地区数据
	void ReadDocline();

	//地区写入文件
	void WirteDocline();

	//添加新地区
	void Addline(CString name,CString tname, int num);

	list<Diqu> ls;	//存储地区容器
	int num;			//用来记录商品个数
};

