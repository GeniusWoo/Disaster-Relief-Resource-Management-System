// JUANERSDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "JUANERSDLG.h"
#include "afxdialogex.h"


// JUANERSDLG 对话框

IMPLEMENT_DYNAMIC(JUANERSDLG, CDialogEx)

JUANERSDLG::JUANERSDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_JUANERS, pParent)
{

}

JUANERSDLG::~JUANERSDLG()
{
}

void JUANERSDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_Listjuaners);
}


BEGIN_MESSAGE_MAP(JUANERSDLG, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &JUANERSDLG::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &JUANERSDLG::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// JUANERSDLG 消息处理程序


BOOL JUANERSDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Listjuaners.InsertColumn(0,_T("捐赠人"),0,100);
	m_Listjuaners.InsertColumn(1, _T("捐赠时间"),0,100);
	m_Listjuaners.InsertColumn(2, _T("捐赠物品"),0,100);
	m_Listjuaners.InsertColumn(3, _T("捐赠数量"),0,100);

	for (int i = 0; i < 10; i++)
	{
		//m_Listjuaners.InsertItem(i,)
	}






	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void JUANERSDLG::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void JUANERSDLG::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码






}
