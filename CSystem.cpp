// CSystem.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "CSystem.h"
#include "afxdialogex.h"
#include"RENYUANDLG.h"
#include"SHUJU.h"
#include "CMFCApplication1Dlg.h"
#include"Reader.h"
// CSystem 对话框

IMPLEMENT_DYNAMIC(CSystem, CDialogEx)

CSystem::CSystem(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAINMENU, pParent)
{

}

CSystem::~CSystem()
{
}

void CSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Adding);
}


BEGIN_MESSAGE_MAP(CSystem, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON_RENYUAN, &CSystem::OnBnClickedButtonRenyuan)
	ON_BN_CLICKED(IDC_BUTTON_WUZI, &CSystem::OnBnClickedButtonWuzi)
	ON_BN_CLICKED(IDC_BUTTON_DIQU, &CSystem::OnBnClickedButtonDiqu)
	ON_BN_CLICKED(IDC_BUTTON_DIQU, &CSystem::OnBnClickedButtonDiqu2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSystem::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSystem 消息处理程序





void CSystem::OnBnClickedButtonRenyuan()
{
	// TODO: 在此添加控件通知处理程序代码
	RENYUANDLG dlg;
	dlg.DoModal();



}


void CSystem::OnBnClickedButtonWuzi()
{
	// TODO: 在此添加控件通知处理程序代码
	SHUJU dlg;
	dlg.DoModal();
}


void CSystem::OnBnClickedButtonDiqu()
{
	// TODO: 在此添加控件通知处理程序代码
	CMFCApplication1Dlg dlg;
	dlg.DoModal();
}


void CSystem::OnBnClickedButtonDiqu2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSystem::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Reader Distr;
	Distr.DistributeKouzhao();
	Distr.DistributeMoney();
	Distr.DistributeFanghu();
	Distr.DistributeFood();
}
