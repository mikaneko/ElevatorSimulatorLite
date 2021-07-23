#pragma once

class CMainFrame: public CFrameWnd
{
	DECLARE_DYNCREATE(CMainFrame);
public:
	CSplitterWnd m_window1;
public:
	CMainFrame();
	~CMainFrame();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};