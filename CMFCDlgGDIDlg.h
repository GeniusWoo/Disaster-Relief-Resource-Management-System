#pragma once


// CMFCDlgGDIDlg 对话框

class CMFCDlgGDIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCDlgGDIDlg)

public:
	CMFCDlgGDIDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMFCDlgGDIDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
   /* DECLARE_MESSAGE_MAP();*/
public:
	int m_iA;
	int m_iB;
	int m_iC;
	int o;
	afx_msg void OnBnClickedDrawButton();
	CStatic m_XPIC;
	CStatic m_APIC;
	CStatic m_BPIC;
	CStatic m_CPIC;
	CRect m_rectX, m_rectA, m_rectB, m_rectC;
	void Setia(int ia) { m_iA = ia; }
	void Setib(int ib) { m_iB = ib; }
	void Setic(int ic) { m_iC = ic; }
	void Seto(int O) { o = O; }
	void Draw();
	CString m_statictitle;
	CString m_statictitle2;
	CString m_statictitle3;
	afx_msg void OnBnClickedCancel();
};
