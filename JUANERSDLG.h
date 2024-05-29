#pragma once


// JUANERSDLG 对话框

class JUANERSDLG : public CDialogEx
{
	DECLARE_DYNAMIC(JUANERSDLG)

public:
	JUANERSDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~JUANERSDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JUANERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 这是显示捐款者的列表
	CListCtrl m_Listjuaners;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonSave();
};
