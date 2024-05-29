#pragma once


// SHUJU 对话框

class SHUJU : public CDialogEx
{
	DECLARE_DYNAMIC(SHUJU)

public:
	SHUJU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SHUJU();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl M_LIST2;
	CListCtrl M_LIST1;
	afx_msg void OnBnClickedButtona();
	afx_msg void OnBnClickedButtonb();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonc();
	afx_msg void OnBnClickedButtond();
	CListCtrl M_LIST3;
	CListCtrl M_LIST4;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
