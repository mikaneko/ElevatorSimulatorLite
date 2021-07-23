#pragma once



class CMainView: public CView
{
	DECLARE_DYNCREATE(CMainView)
public:
	CMainView();
	~CMainView();
	virtual void OnDraw(CDC* /*pDC*/);
};