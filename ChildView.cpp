
// ChildView.cpp: CChildView 类的实现
//

#include "pch.h"
#include "framework.h"
#include "72singleDocument.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Config.h"

// CChildView

CChildView::CChildView()
{
	m_bDraw = false;
	m_drawType = DRAW_TYPE::DT_LINE;
	m_nLineWidth = 1;
	m_nLineStyle = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_DRAW_CL, CChildView::OnDrawCl)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CChildView::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, &CChildView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &CChildView::OnDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CL, &CChildView::OnUpdateDrawCl)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CChildView::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CChildView::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CChildView::OnUpdateDrawRect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_MENU_CONFIG, &CChildView::OnMenuConfig)
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	//m_menu.LoadMenu(IDR_MENU1);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnDrawCl()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_PEN;
}


void CChildView::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_ELLIPSE;
}


void CChildView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_LINE;
}


void CChildView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_RECT;
}


void CChildView::OnUpdateDrawCl(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_PEN);
}


void CChildView::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_ELLIPSE);
}


void CChildView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_LINE);
}


void CChildView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_RECT);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pOrigin = point;
	m_bDraw = true;

	
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	CPen* pOldPen = dc.SelectObject(&pen);

	CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(brush);

	switch (m_drawType) {
	case DT_LINE:
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
		break;
	case DT_RECT:
		dc.Rectangle(CRect(m_pOrigin,point));
		break;
	case DT_ELLIPSE:
		dc.Ellipse(CRect(m_pOrigin, point));
		break;
	case DT_PEN:
		break;
	default:
		break;
	}

	m_bDraw = false;
	CWnd::OnLButtonUp(nFlags, point);

}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bDraw && m_drawType == DT_PEN) {
		CClientDC dc(this);
		CPen pen(m_nLineStyle, m_nLineWidth, m_color);
		CPen* pOldPen = dc.SelectObject(&pen);

		CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		dc.SelectObject(brush);

		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
		m_pOrigin = point;

	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//第一种方法
	//m_menu.LoadMenu(IDR_MENU1);//必须得放到PreCreate 函数里面
	//CMenu* pPopMenu = m_menu.GetSubMenu(0);
	//

	//第二种方法
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pPopMenu = menu.GetSubMenu(0);

	ClientToScreen(&point);
	pPopMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTALIGN, point.x, point.y, this);


	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnMenuConfig()//
{
	// TODO: 在此添加命令处理程序代码
	Config dlg;
	dlg.m_nLineWidth = m_nLineWidth;
	dlg.m_color = m_color;
	dlg.m_nLineStyle = m_nLineStyle;
	if (IDOK == dlg.DoModal()) {
		m_nLineWidth = dlg.m_nLineWidth;
		m_color = dlg.m_color;
		m_nLineStyle = dlg.m_nLineStyle;
	}
}
