
// MFCApplication6.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMFCApplication6App:
// 有关此类的实现，请参阅 MFCApplication6.cpp
//

class CMFCApplication6App : public CWinApp
{
public:
	CMFCApplication6App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication6App theApp;
class thing {
protected:
	CString Origin;//来源
	bool Zhuangtai;//状态
	CString Quxiang;//去向
	CString Jingshou;//经手
	int Num;         //数量
	int Leaved;      //剩余
	CString Name;    //名称
	CString Time;    //捐助时间
public:
	CString GetOrigin() { return Origin; }
	bool Getzhuangtai() { return Zhuangtai; }
	CString GetQuxiang() { return Quxiang; }
	CString GetoJingshou() { return Jingshou; }
	int GetLeaved() { return Leaved; }
	int GetNum() { return Num; }
	CString GetName() { return Name; }
	void SetNum(int N) { Num = N; }
	void SetName(CString name) { Name = name; }
	void SetJingshou(CString jingshou) { Jingshou = jingshou; }
	void SetQuxiang(CString quxiang) { Quxiang = quxiang; }
	void SetOrigin(CString origin) { Origin = origin; }
	void SetLeaved(int le) { Leaved = le; }
	void SetTime(CString time) { Time = time; }
	CString GetTime() { return Time; }
	
};
class Money :public thing {
public:
	int GetNum1() { return Num; }
	void SetNum(int num1) { Num = num1; }
};
class Wuzi :public thing {
public:
	
	int GetNum2() { return Num; }
	void SetNum2(int num2) { Num = num2; }
};