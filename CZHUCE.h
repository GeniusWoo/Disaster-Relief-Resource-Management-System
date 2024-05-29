#pragma once


// CZHUCE 对话框

class CZHUCE : public CDialogEx
{
	DECLARE_DYNAMIC(CZHUCE)

public:
	CZHUCE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CZHUCE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	
	CString m_zcyonghu;
	CString m_zcmima;
	CString m_zcmimaqr;
public:
	afx_msg void OnBnClickedButtonZc();
	void OnOK();
private:
	CButton zcjuan;
	CButton zcguan;
};
