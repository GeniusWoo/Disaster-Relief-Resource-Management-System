#pragma once


// CNewREN 对话框

class CNewREN : public CDialogEx
{
	DECLARE_DYNAMIC(CNewREN)

public:
	CNewREN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CNewREN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RENYUANZENG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox newwupin;
	CString m_renyuan;
	CString m_shuliang;
	CString m_time;
public:
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeComboxinwu();
};
