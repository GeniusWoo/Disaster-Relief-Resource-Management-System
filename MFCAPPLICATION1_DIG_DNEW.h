#pragma once


// MFCAPPLICATION1_DIG_DNEW 对话框

class MFCAPPLICATION1_DIG_DNEW : public CDialogEx
{
	DECLARE_DYNAMIC(MFCAPPLICATION1_DIG_DNEW)

public:
	MFCAPPLICATION1_DIG_DNEW(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCAPPLICATION1_DIG_DNEW();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox DIQUNEW_COM;
	CComboBox DIQUNEW_WUP;
	int DIQUNEW_NUM;
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnDropdownCombo2();
	afx_msg void OnEnChangeEdit1();
	void OnOK();
	afx_msg void OnCbnSelchangeCombo2();
};
