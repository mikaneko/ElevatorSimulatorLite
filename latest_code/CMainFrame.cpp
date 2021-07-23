#pragma once
#include "stdafx.h"
#include "CMainFrame.h"
#include "CCmdCentre.h"
#include "CMainView.h"

IMPLEMENT_DYNCREATE(CMainFrame,CFrameWnd)

CMainFrame::CMainFrame()
{

}
CMainFrame::~CMainFrame()
{

}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_window1.CreateStatic(this,1,2);
	AfxMessageBox(CString("OnCreateClient"));
	CRect rc;
	GetClientRect(&rc);
	m_window1.CreateView(0,0,RUNTIME_CLASS(CMainView),CSize(900,500),pContext);
	m_window1.CreateView(0,1,RUNTIME_CLASS(CCmdCentre),CSize(250,500),pContext);

	return TRUE;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	if( !CFrameWnd::PreCreateWindow(cs) ) return FALSE;
	cs.style &= ~WS_MAXIMIZEBOX; //禁止窗口最大化
	cs.style &= ~WS_THICKFRAME;//使窗口不能用鼠标改变大小

	cs.cx=1150; 
	cs.cy=550;  // 改变窗口大小

	return TRUE;
}
