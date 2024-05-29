// GUANERSDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "GUANERSDLG.h"
#include "afxdialogex.h"


// GUANERSDLG 对话框

IMPLEMENT_DYNAMIC(GUANERSDLG, CDialogEx)

GUANERSDLG::GUANERSDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GUANERS, pParent)
{

}

GUANERSDLG::~GUANERSDLG()
{
}

void GUANERSDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_Listguaners);
}


BEGIN_MESSAGE_MAP(GUANERSDLG, CDialogEx)
END_MESSAGE_MAP()


// GUANERSDLG 消息处理程序


BOOL GUANERSDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Listguaners.InsertColumn(0, _T("管理人"), 0, 100);
	m_Listguaners.InsertColumn(1, _T("管理时间"), 0, 100);
	m_Listguaners.InsertColumn(2, _T("管理物品"), 0, 100);
	m_Listguaners.InsertColumn(3, _T("管理数量"), 0, 100);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
