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
	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO: �ڴ����ר�ô����/����û���
	if( !CFrameWnd::PreCreateWindow(cs) ) return FALSE;
	cs.style &= ~WS_MAXIMIZEBOX; //��ֹ�������
	cs.style &= ~WS_THICKFRAME;//ʹ���ڲ��������ı��С

	cs.cx=1150; 
	cs.cy=550;  // �ı䴰�ڴ�С

	return TRUE;
}
