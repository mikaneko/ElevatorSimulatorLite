#pragma once
#include "SCElevator.h"
#include "SCElevatorSystem.h"
#include "SCCmdSequence.h"
#include "CSettingDlgEle.h"
#include "CSettingDlgAlg.h"
#include "CSettingDlgPeo.h"
#include "CSettingDlgInit.h"
//#include "CCmdCentre.h"

class CMainDoc: public CDocument
{
	DECLARE_DYNCREATE(CMainDoc);
public:

	ElevatorSystem elevsys;
	CmdSequence cmd_seq;
public:
	CString buf_speed;
	CString buf_maxheavy;
	CString buf_open_close_time;
	CString buf_auto_close_time;
	int buf_alg_sel;
	CString ele1startfloor;
	CString ele2startfloor;
	CString ele3startfloor;
	int buf_ele1init;
	int buf_ele2init;
	int buf_ele3init;
	int ticks_in_second;
	int tickms;

	int tickc;
	BOOL ThreadFlag;

	CFormView* pCmd;
public:
	CMainDoc();
	~CMainDoc();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton1();
public:
	void ExeNextTick();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};