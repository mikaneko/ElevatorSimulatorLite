#include "stdafx.h"
#include "CStdSdiApp.h"
#include "CMainDoc.h"
#include "CMainFrame.h"
#include "CMainView.h"

//only one obj
CStdSdiApp theApp;

BOOL CStdSdiApp::InitInstance()
{
	//BIND view, doc, frame
	CSingleDocTemplate *pSingleDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMainDoc),
		RUNTIME_CLASS(CMainFrame),
		RUNTIME_CLASS(CMainView)
		);
	//Add to doc template object
	AddDocTemplate(pSingleDocTemplate);

	//parse cmd info
	CCommandLineInfo cmdLineInfo;
	ParseCommandLine(cmdLineInfo);

	//run cmd 
	if(FALSE == ProcessShellCommand(cmdLineInfo))
		return FALSE;
	
	//show window
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
};