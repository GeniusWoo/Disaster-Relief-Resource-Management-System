#pragma once


// DRAWIDlg 对话框

class DRAWIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DRAWIDlg)

public:
	DRAWIDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DRAWIDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
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
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
};