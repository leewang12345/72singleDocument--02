// Config.cpp: 实现文件
//

#include "pch.h"
#include "72singleDocument.h"
#include "Config.h"
#include "afxdialogex.h"


// Config 对话框

IMPLEMENT_DYNAMIC(Config, CDialogEx)

Config::Config(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONFIG_DLG, pParent)	
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	
}

Config::~Config()
{
}

void Config::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Slider(pDX, IDC_SLIDER, m_nLineWidth);
	DDV_MinMaxInt(pDX, m_nLineWidth, 1, 30);
	DDX_Radio(pDX, IDC_RADIO1, m_nLineStyle);
}


BEGIN_MESSAGE_MAP(Config, CDialogEx)
	
	
	ON_BN_CLICKED(IDC_BUTTON1, &Config::OnBnClickedButton1)
END_MESSAGE_MAP()


// Config 消息处理程序


BOOL Config::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CSliderCtrl* pslider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER);
	pslider->SetRange(1, 30);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Config::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT;
	dlg.m_cc.rgbResult = m_color;
	if (IDOK == dlg.DoModal()) {
		m_color = dlg.m_cc.rgbResult;
	}
}
