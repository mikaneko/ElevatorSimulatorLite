#pragma once
#include "CMainDoc.h"


// CCmdCentre ������ͼ

class CCmdCentre : public CFormView
{
	DECLARE_DYNCREATE(CCmdCentre)

protected:
	CCmdCentre();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


