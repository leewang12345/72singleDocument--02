
// ChildView.h: CChildView 类的接口
//


#pragma once
enum DRAW_TYPE {
	DT_LINE,
	DT_RECT,
	DT_ELLIPSE,
	DT_PEN,
	ALL_DT
};

// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawCl();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnUpdateDrawCl(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_pOrigin;
	enum DRAW_TYPE m_drawType;
public:
	bool m_bDraw;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CMenu m_menu;
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenuConfig();
protected:
	UINT m_nLineWidth;
	COLORREF m_color;
	int m_nLineStyle;
};

