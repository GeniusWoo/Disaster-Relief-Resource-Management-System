// CZHUCE.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "CZHUCE.h"
#include "afxdialogex.h"


// CZHUCE 对话框

IMPLEMENT_DYNAMIC(CZHUCE, CDialogEx)

CZHUCE::CZHUCE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_zcyonghu(_T(""))
	, m_zcmima(_T(""))
	, m_zcmimaqr(_T(""))
{

}

CZHUCE::~CZHUCE()
{
}

void CZHUCE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ZCYONGHU, m_zcyonghu);
	DDX_Text(pDX, IDC_EDIT_ZCMIMA, m_zcmima);
	DDX_Text(pDX, IDC_EDIT_ZCMIMAQR, m_zcmimaqr);
	DDX_Control(pDX, IDC_RADIO_JUA, zcjuan);
}


BEGIN_MESSAGE_MAP(CZHUCE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ZC, &CZHUCE::OnBnClickedButtonZc)
END_MESSAGE_MAP()


// CZHUCE 消息处理程序


void CZHUCE::OnBnClickedButtonZc()
{
	// TODO: 在此添加控件通知处理程序代码

	CString pwd, pwdsure;
	GetDlgItemText(IDC_EDIT_ZCMIMA, pwd);
	GetDlgItemText(IDC_EDIT_ZCMIMAQR, pwdsure);
	if (pwd == pwdsure) {

		if (((CButton*)GetDlgItem(IDC_RADIO_JUA))->GetCheck())
		{
			CFileDialog fDlg(FALSE, _T(".txt"), _T("捐赠者账户"), OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt"), NULL);
			CString sPath = fDlg.GetPathName();
			//创建文件对象
			CStdioFile file(sPath, CFile::modeWrite);
			CString name, pwd;
			GetDlgItemText(IDC_EDIT_ZCYONGHU, name);
			GetDlgItemText(IDC_EDIT_ZCMIMA, pwd);

			//写入操作
			file.WriteString(name);
			file.WriteString(_T("|"));
			file.WriteString(pwd);

			file.Close();

		}
		
	}
	else {
		MessageBox(_T("应输入相同密码"));
	}
}

void CZHUCE::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}