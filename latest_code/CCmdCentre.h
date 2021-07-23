#pragma once
#include "CMainDoc.h"


// CCmdCentre 窗体视图

class CCmdCentre : public CFormView
{
	DECLARE_DYNCREATE(CCmdCentre)

protected:
	CCmdCentre();           // 动态创建所使用的受保护的构造函数
	virtual ~CCmdCentre();
public:
	CMainDoc* pDoc;
public:
	enum { IDD = IDR_CMDCENTRE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


