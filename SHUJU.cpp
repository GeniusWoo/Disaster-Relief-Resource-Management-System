// SHUJU.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "SHUJU.h"
#include "afxdialogex.h"
#include "MFCApplication6Dlg.h"
#include "DRAWIDlg.h"
#include "Reader.h"
// SHUJU 对话框

IMPLEMENT_DYNAMIC(SHUJU, CDialogEx)

SHUJU::SHUJU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

SHUJU::~SHUJU()
{
}

void SHUJU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, M_LIST2);
	DDX_Control(pDX, IDC_LIST1, M_LIST1);
	DDX_Control(pDX, IDC_LIST3, M_LIST3);
	DDX_Control(pDX, IDC_LIST4, M_LIST4);
}


BEGIN_MESSAGE_MAP(SHUJU, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONa, &SHUJU::OnBnClickedButtona)
	ON_BN_CLICKED(IDC_BUTTONb, &SHUJU::OnBnClickedButtonb)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTONc, &SHUJU::OnBnClickedButtonc)
	ON_BN_CLICKED(IDC_BUTTONd, &SHUJU::OnBnClickedButtond)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &SHUJU::OnLvnItemchangedList2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &SHUJU::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// SHUJU 消息处理程序

Money a, b, c;
Wuzi m1,m2,m3,n1,n2,n3,z1,z2,z3;
Reader x;
void SHUJU::OnBnClickedButtona()
{
	a.SetNum(x.ComputeWuZongMoney());
	b.SetNum(x.ComputeWuMoney());
	c.SetNum((x.ComputeWuZongMoney()- x.ComputeWuMoney()));
	ShowWindow(SW_HIDE);
	DRAWIDlg  dlg1;
	dlg1.Setia(a.GetNum1());
	dlg1.Setib(b.GetNum1());
	dlg1.Setic(c.GetNum1());
	dlg1.Seto(1);
	dlg1.m_statictitle = "总金额";
	dlg1.m_statictitle2 = "剩余金额";
	dlg1.m_statictitle3 = "已用金额";
	dlg1.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SHUJU::OnBnClickedButtonb()
{
	m1.SetNum2(x.ComputeWuZongKouzhao());
	m2.SetNum2(x.ComputeWuKouzhao());
	m3.SetNum2((x.ComputeWuZongKouzhao()-x.ComputeWuKouzhao()));
	ShowWindow(SW_HIDE);
	DRAWIDlg  dlg2;
	dlg2.Setia(m1.GetNum2());
	dlg2.Setib(m2.GetNum2());
	dlg2.Setic(m3.GetNum2());
	dlg2.Seto(2);
	dlg2.m_statictitle = "总口罩";
	dlg2.m_statictitle2 = "剩余口罩";
	dlg2.m_statictitle3 = "已用口罩";
	dlg2.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

void SHUJU::OnBnClickedButtonc()
{
	// TODO: 在此添加控件通知处理程序代码
	n1.SetNum2(x.ComputeWuZongFanghu());
	n2.SetNum2(x.ComputeWuFanghu());
	n3.SetNum2((x.ComputeWuZongFanghu()- x.ComputeWuFanghu()));
	ShowWindow(SW_HIDE);
	DRAWIDlg  dlg3;
	dlg3.Setia(n1.GetNum2());
	dlg3.Setib(n2.GetNum2());
	dlg3.Setic(n3.GetNum2());
	dlg3.Seto(2);
	dlg3.m_statictitle = "总防护服";
	dlg3.m_statictitle2 = "剩余防护服";
	dlg3.m_statictitle3 = "已用防护服";
	dlg3.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
void SHUJU::OnBnClickedButtond()
{
	z1.SetNum2(x.ComputeWuZongFood());
	z2.SetNum2(x.ComputeWuFood());
	z3.SetNum2((x.ComputeWuZongFood()- x.ComputeWuFood()));
	ShowWindow(SW_HIDE);
	DRAWIDlg  dlg4;
	dlg4.Setia(z1.GetNum2());
	dlg4.Setib(z2.GetNum2());
	dlg4.Setic(z3.GetNum2());
	dlg4.Seto(2);
	dlg4.m_statictitle = "总食物";
	dlg4.m_statictitle2 = "剩余食物";
	dlg4.m_statictitle3 = "已用食物";
	dlg4.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

CString money1, money2, money3, kz1, kz2,kz3, fhf1,fhf2,fhf3, sw1,sw2,sw3;
BOOL SHUJU::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CDialogEx::OnInitDialog();
	a.SetNum(x.ComputeWuZongMoney());
	b.SetNum(x.ComputeWuMoney());
	c.SetNum((x.ComputeWuZongMoney() - x.ComputeWuMoney()));
	m1.SetNum2(x.ComputeWuZongKouzhao());
	m2.SetNum2(x.ComputeWuKouzhao());
	m3.SetNum2((x.ComputeWuZongKouzhao() - x.ComputeWuKouzhao()));
	n1.SetNum2(x.ComputeWuZongFanghu());
	n2.SetNum2(x.ComputeWuFanghu());
	n3.SetNum2((x.ComputeWuZongFanghu() - x.ComputeWuFanghu()));
	z1.SetNum2(x.ComputeWuZongFood());
	z2.SetNum2(x.ComputeWuFood());
	z3.SetNum2((x.ComputeWuZongFood() - x.ComputeWuFood()));
	// TODO:  在此添加额外的初始化
	M_LIST1.InsertColumn(0, _T("捐款金钱总额"), 0, 200);
	M_LIST1.InsertColumn(1, _T("剩余金钱"), 0, 200);
	M_LIST1.InsertColumn(2, _T("已用金钱"), 0, 200);
	M_LIST2.InsertColumn(0, _T("总口罩"), 0, 200);
	M_LIST2.InsertColumn(1, _T("剩余口罩"), 0, 200);
	M_LIST2.InsertColumn(2, _T("已用口罩"), 0, 200);

	M_LIST3.InsertColumn(0, _T("总防护服"), 0, 200);
	M_LIST3.InsertColumn(1, _T("剩余防护服"), 0, 200);
	M_LIST3.InsertColumn(2, _T("已用防护服"), 0, 200);

	M_LIST4.InsertColumn(0, _T("总食物"), 0, 200);
	M_LIST4.InsertColumn(1, _T("剩余食物"), 0, 200);
	M_LIST4.InsertColumn(2, _T("已用食物"), 0, 200);
	int i1 = a.GetNum1();
	int i2 = b.GetNum1();
	int i3 = c.GetNum1();
	int i4 = m1.GetNum2();
	int i5 = m2.GetNum2();
	int i6 = m3.GetNum2();
	int i7 = n1.GetNum2();
	int i8 = n2.GetNum2();
	int i9 = n3.GetNum2();
	int i10 = z1.GetNum2();
	int i11 = z2.GetNum2();
	int i12 = z3.GetNum2();
	money1.Format(_T("总金额=%d"), i1);
	money2.Format(_T("剩余金额=%d"), i2);
	money3.Format(_T("已用金额=%d"), i3);
	kz1.Format(_T("总口罩=%d"), i4);
	kz2.Format(_T("剩余口罩=%d"), i5);
	kz3.Format(_T("已用口罩=%d"), i6);
	fhf1.Format(_T("总防护服=%d"), i7);
	fhf2.Format(_T("剩余防护服=%d"), i8);
	fhf3.Format(_T("已用防护服=%d"), i9);
	sw1.Format(_T("总食物=%d"), i10);
	sw2.Format(_T("剩余食物=%d"), i11);
	sw3.Format(_T("已用食物=%d"), i12);
	M_LIST1.InsertItem(0, money1);
	M_LIST1.SetItemText(0, 1, money2);
	M_LIST1.SetItemText(0, 2, money3);
	M_LIST2.InsertItem(0, kz1);
	M_LIST2.SetItemText(0, 1, kz2);
	M_LIST2.SetItemText(0, 2, kz3);

	M_LIST3.InsertItem(0, fhf1);
	M_LIST3.SetItemText(0, 1, fhf2);
	M_LIST3.SetItemText(0, 2, fhf3);
	M_LIST4.InsertItem(0,sw1);
	M_LIST4.SetItemText(0, 1, sw2);
	M_LIST4.SetItemText(0, 2, sw3);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}





void SHUJU::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void SHUJU::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
