#pragma once


// CMFCApplication1Dlg 地区需求对话框

class CMFCApplication1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCApplication1Dlg)

public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMFCApplication1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Di };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl WUZI_LIST;
	CButton WUZINEW_BUTTON;
	afx_msg void OnBnClickedButton1();
	void OnOK();
};