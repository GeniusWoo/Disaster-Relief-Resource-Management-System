// CNewREN.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "CNewREN.h"
#include "afxdialogex.h"
#include"locale.h"

// CNewREN 对话框

IMPLEMENT_DYNAMIC(CNewREN, CDialogEx)

CNewREN::CNewREN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_RENYUANZENG, pParent)
	, m_renyuan(_T(""))
	, m_shuliang(_T(""))
	, m_time(_T(""))
{

}

CNewREN::~CNewREN()
{
}

void CNewREN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_xinwu, newwupin);
	DDX_Text(pDX, IDC_EDIT_xinname, m_renyuan);
	DDX_Text(pDX, IDC_EDIT_xinshu, m_shuliang);
	DDX_Text(pDX, IDC_EDIT_xinshi, m_time);
}


BEGIN_MESSAGE_MAP(CNewREN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewREN::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_xinwu, &CNewREN::OnCbnSelchangeComboxinwu)
END_MESSAGE_MAP()


// CNewREN 消息处理程序


void CNewREN::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(FALSE, _T("txt"), _T("人员捐款信息"), OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt"), NULL);

	int nw = newwupin.GetCurSel();
	UpdateData(TRUE);

	CString cs, nw1, cs1, cs2;
	GetDlgItemText(IDC_EDIT_xinname, cs);
	//MessageBox(cs);
	GetDlgItemText(IDC_EDIT_xinshu, cs1);
	GetDlgItemText(IDC_EDIT_xinshi, cs2);

	newwupin.GetLBText(nw, nw1);
	cs += _T("|");
	//MessageBox(cs);
	cs += nw1;
	cs += _T("|");
	//MessageBox(cs);
	cs += cs1;
	cs += _T("|");
	//MessageBox(cs);
	cs += cs2;
	MessageBox(cs);
	cs += _T("|");
	cs += cs1;//初始为未用
	cs += "\n";
	//MessageBox(cs);
	CString sPath = _T("人员捐款信息");
	setlocale(LC_CTYPE, ("chs"));
	CStdioFile* file = new CStdioFile(sPath, CFile::modeWrite);
	file->SeekToEnd();
	file->WriteString(cs.GetBuffer());
	file->Close();
	delete file;
	
	/*CString sPath = _T("人员捐款信息");
	CFile file(sPath, CFile::modeWrite);
	file.SeekToEnd();
	file.Write("\xff\xfe", 2);

	int len = cs.GetLength();
	file.Write(cs,len*sizeof(wchar_t));
	file.Flush();
	file.Close();
	*/

}


void CNewREN::OnCbnSelchangeComboxinwu()
{
	// TODO: 在此添加控件通知处理程序代码
}
