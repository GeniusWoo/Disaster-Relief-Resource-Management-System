// MFCAPPLICATION1_DIG_DNEW.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "MFCAPPLICATION1_DIG_DNEW.h"
#include "afxdialogex.h"
#include<list>
#include"CInfoFile.h"
#include "CMFCApplication1Dlg.h"


// MFCAPPLICATION1_DIG_DNEW 对话框

IMPLEMENT_DYNAMIC(MFCAPPLICATION1_DIG_DNEW, CDialogEx)

MFCAPPLICATION1_DIG_DNEW::MFCAPPLICATION1_DIG_DNEW(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, DIQUNEW_NUM(0)
{

}

MFCAPPLICATION1_DIG_DNEW::~MFCAPPLICATION1_DIG_DNEW()
{
}

void MFCAPPLICATION1_DIG_DNEW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, DIQUNEW_COM);
	DDX_Control(pDX, IDC_COMBO2, DIQUNEW_WUP);
	DDX_Text(pDX, IDC_EDIT1, DIQUNEW_NUM);
}


BEGIN_MESSAGE_MAP(MFCAPPLICATION1_DIG_DNEW, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &MFCAPPLICATION1_DIG_DNEW::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &MFCAPPLICATION1_DIG_DNEW::OnCbnSelchangeCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &MFCAPPLICATION1_DIG_DNEW::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &MFCAPPLICATION1_DIG_DNEW::OnCbnDropdownCombo2)
	ON_EN_CHANGE(IDC_EDIT1, &MFCAPPLICATION1_DIG_DNEW::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &MFCAPPLICATION1_DIG_DNEW::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// MFCAPPLICATION1_DIG_DNEW 消息处理程序


void MFCAPPLICATION1_DIG_DNEW::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (DIQUNEW_NUM <= 0) {
		MessageBox(TEXT("需求数需大于0")); return;
	}

	CInfoFile file;
	CString type1, type2;
	//获取当前选中项
	int index1 = DIQUNEW_COM.GetCurSel();
	int index2 = DIQUNEW_WUP.GetCurSel();
	//获取组合框当前内容
	DIQUNEW_COM.GetLBText(index1, type1);
	DIQUNEW_WUP.GetLBText(index2, type2);
	file.ReadDocline();
/*	list<Diqu>::iterator i, j = file.ls.end();
	for (i = file.ls.begin(); i != file.ls.end(); i++) {
		if (type1 == i->GetName() && type2 == i->GetThingname()) j = i;
	}
	if (j != file.ls.end()) {
		int a = j->GetNum();
		j->SetNum(a + DIQUNEW_NUM);
	}
	else*/ 
	file.Addline(type1, type2, DIQUNEW_NUM);
	file.WirteDocline(); //更新文件内容
	MessageBox(TEXT("添加成功"));
	DIQUNEW_NUM = 0;
	UpdateData(FALSE);
	//调整地区需求显示
	CMFCApplication1Dlg* p = (CMFCApplication1Dlg*)GetParent();
	CString head[] = { TEXT("地区"), TEXT("需求内容"), TEXT("数目/（万）"), TEXT("是否满足") };
	//删去原列
	p->WUZI_LIST.DeleteAllItems();
	//插入列
	/*p->WUZI_LIST.InsertColumn(0, head[0], LVCFMT_LEFT, 150);
	p->WUZI_LIST.InsertColumn(1, head[1], LVCFMT_LEFT, 150);
	p->WUZI_LIST.InsertColumn(2, head[2], LVCFMT_LEFT, 150);
	p->WUZI_LIST.InsertColumn(3, head[3], LVCFMT_LEFT, 150);*/
	//插入正文内容，先确定行，再确定列
	int ia = 0;
	file.ReadDocline(); //读取地区信息
	for (list<Diqu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		CString str;
		str.Format(it->GetName(), ia);
		p->WUZI_LIST.InsertItem(ia, str);
		int j = 0;
		p->WUZI_LIST.SetItemText(ia, ++j, it->GetThingname());
		CString te;
		te.Format(_T("%d"), it->GetNum());
		p->WUZI_LIST.SetItemText(ia, ++j, te);
		if (it->GetZhaungtai() == true) p->WUZI_LIST.SetItemText(ia, ++j, TEXT("是"));
		else p->WUZI_LIST.SetItemText(ia, ++j, TEXT("否"));
		ia++;
	}

	file.ls.clear(); //清空list的内容
	p->UpdateData(FALSE);
}


void MFCAPPLICATION1_DIG_DNEW::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MFCAPPLICATION1_DIG_DNEW::OnCbnDropdownCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	DIQUNEW_COM.ResetContent();
	DIQUNEW_COM.AddString(TEXT("北京"));
	DIQUNEW_COM.AddString(TEXT("天津"));
	DIQUNEW_COM.AddString(TEXT("河北"));
	DIQUNEW_COM.AddString(TEXT("辽宁"));
	DIQUNEW_COM.AddString(TEXT("吉林"));
	DIQUNEW_COM.AddString(TEXT("黑龙江"));
	DIQUNEW_COM.AddString(TEXT("山东"));
	DIQUNEW_COM.AddString(TEXT("江苏"));
	DIQUNEW_COM.AddString(TEXT("上海"));
	DIQUNEW_COM.AddString(TEXT("浙江"));
	DIQUNEW_COM.AddString(TEXT("安徽"));
	DIQUNEW_COM.AddString(TEXT("福建"));
	DIQUNEW_COM.AddString(TEXT("江西"));
	DIQUNEW_COM.AddString(TEXT("广东"));
	DIQUNEW_COM.AddString(TEXT("广西"));
	DIQUNEW_COM.AddString(TEXT("海南"));
	DIQUNEW_COM.AddString(TEXT("河南"));
	DIQUNEW_COM.AddString(TEXT("湖南"));
	DIQUNEW_COM.AddString(TEXT("湖北"));
	DIQUNEW_COM.AddString(TEXT("山西"));
	DIQUNEW_COM.AddString(TEXT("内蒙古"));
	DIQUNEW_COM.AddString(TEXT("宁夏"));
	DIQUNEW_COM.AddString(TEXT("青海"));
	DIQUNEW_COM.AddString(TEXT("陕西"));
	DIQUNEW_COM.AddString(TEXT("甘肃"));
	DIQUNEW_COM.AddString(TEXT("新疆"));
	DIQUNEW_COM.AddString(TEXT("四川"));
	DIQUNEW_COM.AddString(TEXT("贵州"));
	DIQUNEW_COM.AddString(TEXT("云南"));
	DIQUNEW_COM.AddString(TEXT("重庆"));
	DIQUNEW_COM.AddString(TEXT("西藏"));
	DIQUNEW_COM.SetCurSel(0);
	
}


void MFCAPPLICATION1_DIG_DNEW::OnCbnDropdownCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	DIQUNEW_WUP.ResetContent();
	DIQUNEW_WUP.AddString(TEXT("金钱"));
	DIQUNEW_WUP.AddString(TEXT("口罩"));
	DIQUNEW_WUP.AddString(TEXT("防护服"));
	DIQUNEW_WUP.AddString(TEXT("食物"));
	DIQUNEW_WUP.SetCurSel(0);
}


void MFCAPPLICATION1_DIG_DNEW::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void MFCAPPLICATION1_DIG_DNEW::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}

void MFCAPPLICATION1_DIG_DNEW::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}
