#pragma once


// CSystem 对话框

class CSystem : public CDialogEx
{
	DECLARE_DYNAMIC(CSystem)

public:
	CSystem(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSystem();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINMENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonRenyuan();
	afx_msg void OnBnClickedButtonWuzi();
	afx_msg void OnBnClickedButtonDiqu();
	afx_msg void OnBnClickedButtonDiqu2();
	CButton Adding;
	afx_msg void OnBnClickedButton1();
};
