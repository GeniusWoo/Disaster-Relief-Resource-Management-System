// RENYUANDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "RENYUANDLG.h"
#include "afxdialogex.h"
#include"CNewREN.h"
#include"locale.h"
// RENYUANDLG 对话框

IMPLEMENT_DYNAMIC(RENYUANDLG, CDialogEx)

RENYUANDLG::RENYUANDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIG_RENYUAN, pParent)
{

}

RENYUANDLG::~RENYUANDLG()
{
}

void RENYUANDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_LIST_RENYUAN, m_ListRenyuan);
}


BEGIN_MESSAGE_MAP(RENYUANDLG, CDialogEx)
	//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &RENYUANDLG::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON2, &RENYUANDLG::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &RENYUANDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &RENYUANDLG::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_RENYUAN, &RENYUANDLG::OnLvnItemchangedListRenyuan)
END_MESSAGE_MAP()


// RENYUANDLG 消息处理程序


BOOL RENYUANDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/*CRect tabRect;

	m_tab.InsertItem(0, _T("捐款者"));
	m_tab.InsertItem(1, _T("管理者"));

	m_juaners.Create(IDD_DIALOG_JUANERS, &m_tab);
	m_guaners.Create(IDD_DIALOG_GUANERS, &m_tab);

	m_tab.GetClientRect(&tabRect);

	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;

	m_juaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	m_guaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	*/

	m_ListRenyuan.InsertColumn(0, _T("捐款人员"),0,100);
	m_ListRenyuan.InsertColumn(1, _T("捐款物品"),0,100);
	m_ListRenyuan.InsertColumn(2, _T("捐款数量"),0,100);
	m_ListRenyuan.InsertColumn(3, _T("捐款日期"),0,100);
	m_ListRenyuan.InsertColumn(4, _T("剩余物品"), 0, 100);







	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
				 
}


void RENYUANDLG::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;

	switch (m_tab.GetCurSel())
	{
	case 0:
		m_juaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		m_guaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		break;
	case 1:
		m_juaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_guaners.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		break;
	default:
		break;
	}

	*/

	*pResult = 0;



}


void RENYUANDLG::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CNewREN dlg;
	dlg.DoModal();
}


void RENYUANDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(TRUE, _T("txt"), _T("人员捐款信息"), OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt"), NULL);
	CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
	CString cs;
	int index = 0;
	setlocale(LC_CTYPE, ("chs"));

	m_ListRenyuan.DeleteAllItems();
	while (file.ReadString(cs))
	{
		int x = cs.Find(_T("|"));
		int x2 = cs.Find(_T("|"), x + 1);
		int x3 = cs.Find(_T("|"), x2 + 1);
		int x4 = cs.Find(_T("|"), x3 + 1);


		int n = x2 - x - 1;
		int l = x3 - x2 - 1;
		int m = x4 - x3 - 1;
		

		m_ListRenyuan.InsertItem(index, cs.Left(x));
		m_ListRenyuan.SetItemText(index, 1, cs.Mid(x + 1, n));
		m_ListRenyuan.SetItemText(index, 2, cs.Mid(x2 + 1, l));
		m_ListRenyuan.SetItemText(index, 3, cs.Mid(x3 + 1, m));
		m_ListRenyuan.SetItemText(index, 4, cs.Right(cs.GetLength() - x4-1));
		index++;



	}


}


void RENYUANDLG::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void RENYUANDLG::OnLvnItemchangedListRenyuan(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
