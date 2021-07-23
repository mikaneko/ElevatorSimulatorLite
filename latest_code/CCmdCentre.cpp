// CCmdCentre.cpp : 实现文件
//

#include "stdafx.h"
#include "resource.h"
#include "CCmdCentre.h"


// CCmdCentre

IMPLEMENT_DYNCREATE(CCmdCentre, CFormView)

CCmdCentre::CCmdCentre()
	: CFormView(CCmdCentre::IDD)
{

}

CCmdCentre::~CCmdCentre()
{
}

void CCmdCentre::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCmdCentre, CFormView)
END_MESSAGE_MAP()


// CCmdCentre 诊断

#ifdef _DEBUG
void CCmdCentre::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCmdCentre::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCmdCentre 消息处理程序


void CCmdCentre::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	pDoc=(CMainDoc*)GetDocument();
	pDoc->pCmd=this;
	AfxMessageBox(CString("on cmd view init"));
	// TODO: 在此添加专用代码和/或调用基类
}
