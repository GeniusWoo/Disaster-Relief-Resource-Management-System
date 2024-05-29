#pragma once


// GUANERSDLG 对话框

class GUANERSDLG : public CDialogEx
{
	DECLARE_DYNAMIC(GUANERSDLG)

public:
	GUANERSDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GUANERSDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GUANERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_Listguaners;
	virtual BOOL OnInitDialog();



};
