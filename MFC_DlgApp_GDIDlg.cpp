
// MFC_DlgApp_GDIDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCDlgGDIDlg 对话框

CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DLGAPP_GDI_DIALOG2, pParent)
	
{
	if (o == 2) {

		m_statictitle = "口罩剩余";
		m_statictitle2 = "防护服剩余";
		m_statictitle3 = "食物剩余";
	}
	else {

		m_statictitle = "总金额";
		m_statictitle2 = "已用金额";
		m_statictitle3 = "剩余金额";
	}
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_X_STATIC, m_XPIC);
	DDX_Control(pDX, IDC_APIC_STATIC, m_APIC);
	DDX_Control(pDX, IDC_BPIC_STATIC, m_BPIC);
	DDX_Control(pDX, IDC_CPIC_STATIC, m_CPIC);
	
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DRAW_BUTTON, &CMFCApplication6Dlg::OnBnClickedDrawButton)
END_MESSAGE_MAP()


// CMFCDlgGDIDlg 消息处理程序

BOOL CMFCApplication6Dlg::OnInitDialog1()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
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
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication6Dlg::OnSysCommand1(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication6Dlg::OnPaint1()
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6Dlg::OnBnClickedDrawButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Draw();
}


void CMFCApplication6Dlg::Draw()
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
	int iHa = (iH * m_iA) / max;
	int iHb = (iH * m_iB) / max;
	int iHc = (iH * m_iC) / max;

	rectX.top = rectA.bottom;
	rectX.bottom = rectX.top + 2;
	rectA.top = rectA.bottom - iHa;
	rectB.top = rectB.bottom - iHb;
	rectC.top = rectC.bottom - iHc;

	//m_APIC.SetWindowTextA(TEXT(""));
	//m_BPIC.SetWindowTextA(TEXT(""));
	//m_CPIC.SetWindowTextA(TEXT(""));

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

}
	