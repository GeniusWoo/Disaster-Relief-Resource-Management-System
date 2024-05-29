// CMFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6.h"
#include "CMFCApplication1Dlg.h"
#include "afxdialogex.h"
#include<list>
#include"CInfoFile.h"
#include "MFCAPPLICATION1_DIG_DNEW.h"

// CMFCApplication1Dlg 对话框

IMPLEMENT_DYNAMIC(CMFCApplication1Dlg, CDialogEx)

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Di, pParent)
{

}

CMFCApplication1Dlg::~CMFCApplication1Dlg()
{
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, WUZI_LIST);
	DDX_Control(pDX, IDC_BUTTON1, WUZINEW_BUTTON);
}


BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CMFCApplication1Dlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序
BOOL CMFCApplication1Dlg::OnInitDialog()
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


	// TODO: 在此添加额外的初始化代码
	//插入标题
	CString head[] = { TEXT("地区"), TEXT("需求内容"), TEXT("数目/（万）"), TEXT("是否满足") };

	//插入列
	WUZI_LIST.InsertColumn(0, head[0], LVCFMT_LEFT, 150);
	WUZI_LIST.InsertColumn(1, head[1], LVCFMT_LEFT, 150);
	WUZI_LIST.InsertColumn(2, head[2], LVCFMT_LEFT, 150);
	WUZI_LIST.InsertColumn(3, head[3], LVCFMT_LEFT, 150);
	//插入正文内容，先确定行，再确定列
	int i = 0;
	CInfoFile file;
	file.ReadDocline(); //读取地区信息
	for (list<Diqu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		CString str;
		str.Format(it->GetName(), i);
		WUZI_LIST.InsertItem(i, str);
		int j = 0;
		WUZI_LIST.SetItemText(i, ++j, it->GetThingname());
		CString te;
		te.Format(_T("%d"), it->GetNum());
		WUZI_LIST.SetItemText(i, ++j, te);
		if (it->GetZhaungtai() == true) WUZI_LIST.SetItemText(i, ++j, TEXT("是"));
		else WUZI_LIST.SetItemText(i, ++j, TEXT("否"));
		i++;
	}

	file.ls.clear(); //清空list的内容


	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//设置风格样式
			//LVS_EX_GRIDLINES 网格
			//LVS_EX_FULLROWSELECT 选中整行
	WUZI_LIST.SetExtendedStyle(WUZI_LIST.GetExtendedStyle()
		| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	*pResult = 0;
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MFCAPPLICATION1_DIG_DNEW dig;
	dig.DoModal();
}

void CMFCApplication1Dlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}