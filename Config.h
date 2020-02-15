#pragma once


// Config 对话框

class Config : public CDialogEx
{
	DECLARE_DYNAMIC(Config)

public:
	Config(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Config();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONFIG_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	
public:
	int m_nLineWidth;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	COLORREF m_color;
	int m_nLineStyle;
};
