// DRAWIDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "DRAWIDlg.h"
#include "afxdialogex.h"
#include "framework.h"
#include "MFCApplication6Dlg.h"
#include "CSystem.h"
#include"SHUJU.h"
// DRAWIDlg 对话框

IMPLEMENT_DYNAMIC(DRAWIDlg, CDialogEx)

DRAWIDlg::DRAWIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

DRAWIDlg::~DRAWIDlg()
{
}

void DRAWIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DRAWIDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &DRAWIDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &DRAWIDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// DRAWIDlg 消息处理程序


BOOL DRAWIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
		}
	}	
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//获取控件位置
	GetDlgItem(IDC_X_STATIC)->GetWindowRect(&m_rectX);//获取控件相对于屏幕的位置
	ScreenToClient(m_rectX);							//转化为对话框上的相对位置
	GetDlgItem(IDC_APIC_STATIC)->GetWindowRect(&m_rectA);
	ScreenToClient(m_rectA);
	GetDlgItem(IDC_BPIC_STATIC)->GetWindowRect(&m_rectB);
	ScreenToClient(m_rectB);
	GetDlgItem(IDC_CPIC_STATIC)->GetWindowRect(&m_rectC);
	ScreenToClient(m_rectC);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DRAWIDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	//Draw();
}


void DRAWIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnSysCommand(nID, lParam);
}


HCURSOR DRAWIDlg::OnQueryDragIcon()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return static_cast<HCURSOR>(m_hIcon);
}

void DRAWIDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CSystem dlg;
	dlg.DoModal();
}


void DRAWIDlg::OnBnClickedButton1()
{
	Draw();
	// TODO: 在此添加控件通知处理程序代码
}
void DRAWIDlg::Draw()
{
	Money a, b, c;
	Wuzi m, n, z;
	//a.SetNum(100);
	//b.SetNum(40);
	//c.SetNum(60);
	//m.SetNum2(300);
	//n.SetNum2(100);
	//z.SetNum2(350);
	UpdateData(TRUE);
	//计算棒图高度
	CRect rectX = m_rectX, rectA = m_rectA, rectB = m_rectB, rectC = m_rectC;
	//m_iA=a.GetNum1();
	//m_iB= b.GetNum1();
	//m_iC = c.GetNum1();
	int iH = m_rectA.Height();
	int max = max(max(m_iA, m_iB), m_iC);
	if (max == 0) {
		max = 1;
	}
	int iHa = (iH * m_iA) / max;
	int iHb = (iH * m_iB) / max;
	int iHc = (iH * m_iC) / max;

	rectX.top = rectA.bottom;
	rectX.bottom = rectX.top + 2;
	rectA.top = rectA.bottom - iHa;
	rectB.top = rectB.bottom - iHb;
	rectC.top = rectC.bottom - iHc;/*

	m_APIC.SetWindowTextA(TEXT(""));
	m_BPIC.SetWindowTextA(TEXT(""));
	m_CPIC.SetWindowTextA(TEXT(""));*/

	//设置作图GDI
	CDC* pDC = GetDC();
	COLORREF clrA = RGB(0, 0, 192);		//设置颜色A
	COLORREF clrB = RGB(0, 255, 0);		//设置颜色B
	COLORREF clrC = RGB(255, 0, 0);		//设置颜色C
	CBrush brushA(HS_FDIAGONAL, clrA);	//设置画刷A
	CBrush brushB(HS_BDIAGONAL, clrB);	//设置画刷B
	CBrush brushC(HS_FDIAGONAL, clrC);	//设置画刷C
	CPen pen(PS_INSIDEFRAME, 4, clrA);	//设置画笔
	CBrush* oldBrush = pDC->SelectObject(&brushA);
	CPen* oldPen = pDC->SelectObject(&pen);

	//作图
	pDC->MoveTo(rectX.left, rectA.bottom);
	pDC->LineTo(rectX.right, rectA.bottom);

	pDC->Rectangle(rectA);
	pDC->SelectObject(&brushB); pDC->Rectangle(rectB);
	pDC->SelectObject(&brushC); pDC->Rectangle(rectC);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);
	pen.DeleteObject();
	brushA.DeleteObject();
	brushB.DeleteObject();
	brushC.DeleteObject();
	Sleep(0);
}


