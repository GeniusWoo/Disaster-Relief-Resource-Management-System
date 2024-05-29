#pragma once
#include"JUANERSDLG.h"
#include"GUANERSDLG.h"

// RENYUANDLG 对话框

class RENYUANDLG : public CDialogEx
{
	DECLARE_DYNAMIC(RENYUANDLG)

public:
	RENYUANDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RENYUANDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIG_RENYUAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	// 这是人员列表
	CTabCtrl m_tab;
	GUANERSDLG m_guaners;
	JUANERSDLG m_juaners;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
private:
	CListCtrl m_ListRenyuan;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedListRenyuan(NMHDR* pNMHDR, LRESULT* pResult);
};
