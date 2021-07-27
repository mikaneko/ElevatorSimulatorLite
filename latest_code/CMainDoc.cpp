#pragma once
#include "stdafx.h"
#include "CMainDoc.h"
#include "CSettingDlgRequest.h"


IMPLEMENT_DYNCREATE(CMainDoc,CDocument)


CMainDoc::CMainDoc()
{
	ThreadFlag=FALSE;
	//
	buf_speed="50";
	buf_maxheavy="1000";
	buf_open_close_time="10";
	buf_auto_close_time="20";
	buf_alg_sel=0;
	buf_ele1init=0;
	buf_ele2init=4;
	buf_ele3init=8;

	ticks_in_second=10;
	tickms=1000/10;

	tickc=0;
	//init elevsys



}
CMainDoc::~CMainDoc()
{

}BEGIN_MESSAGE_MAP(CMainDoc, CDocument)
	ON_BN_CLICKED(IDC_BUTTON9, &CMainDoc::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMainDoc::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMainDoc::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMainDoc::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDoc::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CMainDoc::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDoc::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &CMainDoc::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMainDoc::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMainDoc::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMainDoc::OnBnClickedButton5)
	ON_COMMAND(ID_DOC_01, &CMainDoc::OnDoc01)
	ON_COMMAND(ID_DOC_02, &CMainDoc::OnDoc02)
	ON_COMMAND(ID_DOC_03, &CMainDoc::OnDoc03)
	ON_COMMAND(ID_DOC_04, &CMainDoc::OnDoc04)
	ON_COMMAND(ID_DOC_05, &CMainDoc::OnDoc05)
	ON_COMMAND(ID_DOC_06, &CMainDoc::OnDoc06)
	ON_COMMAND(ID_DOC_07, &CMainDoc::OnDoc07)
	ON_COMMAND(ID_DOC_08, &CMainDoc::OnDoc08)
	ON_COMMAND(ID_DOC_09, &CMainDoc::OnDoc09)
	ON_COMMAND(ID_DOC_10, &CMainDoc::OnDoc10)
	ON_COMMAND(ID_DOC_11, &CMainDoc::OnDoc11)
	ON_COMMAND(ID_DOC_12, &CMainDoc::OnDoc12)
	ON_COMMAND(ID_DOC_13, &CMainDoc::OnDoc13)
	ON_COMMAND(ID_DOC_14, &CMainDoc::OnDoc14)
	ON_COMMAND(ID_DOC_15, &CMainDoc::OnDoc15)
	ON_COMMAND(ID_DOC_16, &CMainDoc::OnDoc16)
	ON_COMMAND(ID_LOG_01, &CMainDoc::OnLog01)
	ON_COMMAND(ID_LOG_02, &CMainDoc::OnLog02)
	ON_COMMAND(ID_LOG_03, &CMainDoc::OnLog03)
	ON_COMMAND(ID_LOG_04, &CMainDoc::OnLog04)
	ON_COMMAND(ID_LOG_05, &CMainDoc::OnLog05)
	ON_COMMAND(ID_LOG_06, &CMainDoc::OnLog06)
	ON_COMMAND(ID_LOG_07, &CMainDoc::OnLog07)
	ON_COMMAND(ID_LOG_08, &CMainDoc::OnLog08)
	ON_COMMAND(ID_LOG_09, &CMainDoc::OnLog09)
	ON_COMMAND(ID_LOG_10, &CMainDoc::OnLog10)
	ON_COMMAND(ID_LOG_11, &CMainDoc::OnLog11)
	ON_COMMAND(ID_GPL, &CMainDoc::OnGpl)
	ON_COMMAND(ID_OTHER_LS, &CMainDoc::OnOtherLs)
	END_MESSAGE_MAP()


void CMainDoc::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSettingDlgEle Dlg1;
	Dlg1.speed=buf_speed;
	Dlg1.maxheavy=buf_maxheavy;
	Dlg1.open_close_time=buf_open_close_time;
	Dlg1.auto_close_time=buf_auto_close_time;
	if(Dlg1.DoModal()==TRUE)
	{
		buf_speed=Dlg1.speed;
		buf_maxheavy=Dlg1.maxheavy;
		buf_open_close_time=Dlg1.open_close_time;
		buf_auto_close_time=Dlg1.auto_close_time;
	}
	else{}
}


void CMainDoc::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSettingDlgAlg Dlg2;
	Dlg2.alg_sel=buf_alg_sel;
	if(Dlg2.DoModal()==TRUE)
	{
		buf_alg_sel=Dlg2.alg_sel;
	}
	else{}
}


void CMainDoc::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSettingDlgPeo Dlg3;
	Dlg3.dlg_tickinsec=ticks_in_second;
	if(Dlg3.DoModal()==TRUE)
	{
		ticks_in_second=Dlg3.dlg_tickinsec;
		tickms=1000/ticks_in_second;
	}
	else{}
}




void CMainDoc::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSettingDlgInit Dlg4;
	Dlg4.ele1init=buf_ele1init;
	Dlg4.ele2init=buf_ele2init;
	Dlg4.ele3init=buf_ele3init;
	if(Dlg4.DoModal()==TRUE)
	{
		buf_ele1init=Dlg4.ele1init;
		buf_ele2init=Dlg4.ele2init;
		buf_ele3init=Dlg4.ele3init;
	}
	else{}
}



//���߳�����
static UINT ChildThread(LPVOID lParam)
{
	CMainDoc* pDoc = (CMainDoc*)lParam;

	BOOL isPause=FALSE;
	//
	pDoc->tickc=0;
	(pDoc->elevsys.elev[0]).now_floor_int=1+(pDoc->buf_ele1init);
	(pDoc->elevsys.elev[0]).now_floor_point=0;
	(pDoc->elevsys.elev[0]).M_tick_per_floor=_ttoi(pDoc->buf_speed);
	(pDoc->elevsys.elev[0]).M_max_maintain=_ttoi(pDoc->buf_maxheavy);
	(pDoc->elevsys.elev[0]).M_open_close_time=_ttoi(pDoc->buf_open_close_time);
	(pDoc->elevsys.elev[0]).M_auto_wait_close_time=_ttoi(pDoc->buf_auto_close_time);
	(pDoc->elevsys.elev[0]).m_maintain_now=0;
	(pDoc->elevsys.elev[0]).m_wait_time=0;
	(pDoc->elevsys.elev[0]).now_direction=ELE_WAIT;
	(pDoc->elevsys.elev[0]).m_door_status=ELE_DOOR_CLOSE;
	(pDoc->elevsys.elev[0]).m_ins=INS_MSG(IT_NOMSG);
	//
	(pDoc->elevsys.elev[1]).now_floor_int=1+(pDoc->buf_ele2init);
	(pDoc->elevsys.elev[1]).now_floor_point=0;
	(pDoc->elevsys.elev[1]).M_tick_per_floor=_ttoi(pDoc->buf_speed);
	(pDoc->elevsys.elev[1]).M_max_maintain=_ttoi(pDoc->buf_maxheavy);
	(pDoc->elevsys.elev[1]).M_open_close_time=_ttoi(pDoc->buf_open_close_time);
	(pDoc->elevsys.elev[1]).M_auto_wait_close_time=_ttoi(pDoc->buf_auto_close_time);
	(pDoc->elevsys.elev[1]).m_maintain_now=0;
	(pDoc->elevsys.elev[1]).m_wait_time=0;
	(pDoc->elevsys.elev[1]).now_direction=ELE_WAIT;
	(pDoc->elevsys.elev[1]).m_door_status=ELE_DOOR_CLOSE;
	(pDoc->elevsys.elev[1]).m_ins=INS_MSG(IT_NOMSG);
	//
	(pDoc->elevsys.elev[2]).now_floor_int=1+(pDoc->buf_ele3init);
	(pDoc->elevsys.elev[2]).now_floor_point=0;
	(pDoc->elevsys.elev[2]).M_tick_per_floor=_ttoi(pDoc->buf_speed);
	(pDoc->elevsys.elev[2]).M_max_maintain=_ttoi(pDoc->buf_maxheavy);
	(pDoc->elevsys.elev[2]).M_open_close_time=_ttoi(pDoc->buf_open_close_time);
	(pDoc->elevsys.elev[2]).M_auto_wait_close_time=_ttoi(pDoc->buf_auto_close_time);
	(pDoc->elevsys.elev[2]).m_maintain_now=0;
	(pDoc->elevsys.elev[2]).m_wait_time=0;
	(pDoc->elevsys.elev[2]).now_direction=ELE_WAIT;
	(pDoc->elevsys.elev[2]).m_door_status=ELE_DOOR_CLOSE;
	(pDoc->elevsys.elev[2]).m_ins=INS_MSG(IT_NOMSG);
	//
	

	///DEBUG::::!!!!TEST ALG

#if 0
	(pDoc->elevsys).m_request[2]=ELESYS_DOWN;
	(pDoc->elevsys).m_request[3]=ELESYS_UP_AND_DOWN;
	(pDoc->elevsys.elev[0]).m_btn_status[1]=ELE_BTN_ON;
	(pDoc->elevsys.elev[0]).m_btn_status[9]=ELE_BTN_ON;
#endif


	//!!!NEWS;END;DEBUG

	while(TRUE)
	{

		if(!isPause) // NORNMAL STATUS
		{
			if((pDoc->cmd_seq).GetStoStatus()==SEQ_EMPTY)  //MSG1
			{
				Sleep(pDoc->tickms);
				pDoc->ExeNextTick();
				++(pDoc->tickc);
				//////////TODO
				for(int jj=0;jj<3;jj++)//����һ��¥�����ⲿ��ť�ķ�Ӧ
				{
					if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)//����һ��¥�����ⲿ��ť�ķ�Ӧ
					{
						int i=(pDoc->elevsys.elev[jj]).now_floor_int-1;
						if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
						{
							if((pDoc->elevsys.elev[jj]).now_direction==ELE_UP)
							{
								if((pDoc->elevsys).m_request[i]==ELESYS_UP)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_NO;
								}
								else if((pDoc->elevsys).m_request[i]==ELESYS_DOWN)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_DOWN;
								}
								else if((pDoc->elevsys).m_request[i]==ELESYS_UP_AND_DOWN)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_DOWN;
								}
							}
							else if((pDoc->elevsys.elev[jj]).now_direction==ELE_DOWN)
							{
								if((pDoc->elevsys).m_request[i]==ELESYS_UP)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_UP;
								}
								else if((pDoc->elevsys).m_request[i]==ELESYS_DOWN)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_NO;
								}
								else if((pDoc->elevsys).m_request[i]==ELESYS_UP_AND_DOWN)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_UP;
								}
							}
							else if((pDoc->elevsys.elev[jj]).now_direction==ELE_WAIT)
							{
								(pDoc->elevsys).m_request[i]=ELESYS_NO;
							}
						}
					}
				}

				for(int jj=0;jj<3;jj++)//����һ��¥�����ڲ���ť�ķ�Ӧ
				{
					if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)
					{
						if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
						{
							int i=(pDoc->elevsys.elev[jj]).now_floor_int-1;
							(pDoc->elevsys.elev[jj]).m_btn_status[i]=ELE_BTN_OFF;
						}
					}
				}

				for(int jj=0;jj<3;jj++)//�����ź�ʱ
				{
					if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)
					{
						if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
						{
							(pDoc->elevsys.elev[jj]).m_wait_time += (pDoc->elevsys.elev[jj]).M_open_close_time*2;
							(pDoc->elevsys.elev[jj]).m_wait_time += (pDoc->elevsys.elev[jj]).M_auto_wait_close_time;
						}
					}
				}

				//refresh view

				POSITION pos= pDoc->GetFirstViewPosition();
				CView* pView=NULL;
				if(pos)
				{
					pView = pDoc->GetNextView(pos);
				}
				if(pView)
				{pView->Invalidate(TRUE);}
				
				continue;
			}
			else	//MSG2,3,4...parse msg
			{
				CMD_MSG msg1=(pDoc->cmd_seq).OutQ().cmd_type;
				if(msg1.cmd_type==CT_ABORT)
				{	
					Sleep(pDoc->tickms);
					AfxMessageBox(CString("�����߳�������ֹ��"));
					break;
				}
				else if(msg1.cmd_type==CT_PAUSE)
				{
					isPause=TRUE;
					continue;
				}
				else
				{
					Sleep(1000);
					AfxMessageBox(CString(TEXT("�������޷�������CMD_MSG��Ϣ�����������ر�(ERR03)��")));
				}
			}
		}

		else  //UNDER PAUSE
		{
			if((pDoc->cmd_seq).GetStoStatus()==SEQ_EMPTY)
			{
				Sleep(pDoc->tickms);
				continue;
			}
			else// if((pDoc->cmd_seq).OutQ().cmd_type==CT_ABORT)
			{
				CMD_MSG msg2=(pDoc->cmd_seq).OutQ().cmd_type;
				if(msg2.cmd_type==CT_ABORT)
				{
					Sleep(pDoc->tickms);
					AfxMessageBox(CString("ExitMuti"));
					break;
				}
				else if(msg2.cmd_type==CT_UNPAUSE)
				{
					isPause=FALSE;
					continue;
				}
				else if(msg2.cmd_type==CT_MY_UNDER_PAUSE_NEXT_SECOND)
				{
					Sleep(pDoc->tickms);
					pDoc->ExeNextTick();
					++(pDoc->tickc);
					/////////////////////TODO

					for(int jj=0;jj<3;jj++)//����һ��¥�����ⲿ��ť�ķ�Ӧ
					{
						if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)//����һ��¥�����ⲿ��ť�ķ�Ӧ
						{
							int i=(pDoc->elevsys.elev[jj]).now_floor_int-1;
							if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
							{
								if((pDoc->elevsys.elev[jj]).now_direction==ELE_UP)
								{
									if((pDoc->elevsys).m_request[i]==ELESYS_UP)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_NO;
									}
									else if((pDoc->elevsys).m_request[i]==ELESYS_DOWN)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_DOWN;
									}
									else if((pDoc->elevsys).m_request[i]==ELESYS_UP_AND_DOWN)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_DOWN;
									}
								}
								else if((pDoc->elevsys.elev[jj]).now_direction==ELE_DOWN)
								{
									if((pDoc->elevsys).m_request[i]==ELESYS_UP)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_UP;
									}
									else if((pDoc->elevsys).m_request[i]==ELESYS_DOWN)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_NO;
									}
									else if((pDoc->elevsys).m_request[i]==ELESYS_UP_AND_DOWN)
									{
										(pDoc->elevsys).m_request[i]=ELESYS_UP;
									}
								}
								else if((pDoc->elevsys.elev[jj]).now_direction==ELE_WAIT)
								{
									(pDoc->elevsys).m_request[i]=ELESYS_NO;
								}
							}
						}
					}

					for(int jj=0;jj<3;jj++)//����һ��¥�����ڲ���ť�ķ�Ӧ
					{
						if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)
						{
							if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
							{
								int i=(pDoc->elevsys.elev[jj]).now_floor_int-1;
								(pDoc->elevsys.elev[jj]).m_btn_status[i]=ELE_BTN_OFF;
							}
						}
					}

					for(int jj=0;jj<3;jj++)//�����ź�ʱ
					{
						if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)
						{
							if(((pDoc->elevsys.elev[jj]).now_floor_int==(pDoc->elevsys.elev[jj]).m_ins.ins_arg) &&((pDoc->elevsys.elev[jj]).now_floor_point)==0)
							{
								(pDoc->elevsys.elev[jj]).m_wait_time += (pDoc->elevsys.elev[jj]).M_open_close_time*2;
								(pDoc->elevsys.elev[jj]).m_wait_time += (pDoc->elevsys.elev[jj]).M_auto_wait_close_time;
							}
						}
					}
					//refresh view

					POSITION pos= pDoc->GetFirstViewPosition();
					CView* pView=NULL;
					if(pos)
					{
						pView = pDoc->GetNextView(pos);
					}
					if(pView)
					{pView->Invalidate(TRUE);}

					continue;
				}
				else
				{
					Sleep(1000);
					AfxMessageBox(CString(TEXT("�������޷�������CMD_MSG��Ϣ�����������ر�(ERR02)��")));
				}
			}
		}
		//���ﻹ��Ҫ��ӣ�������
		//XXXXXXXXXXX
	}
	return 1;
}

void CMainDoc::OnBnClickedButton1()
{
	if(ThreadFlag)
	{
		ThreadFlag=FALSE;
		AfxMessageBox(CString(TEXT("�߳��ظ����������������ر�(ERR01)��")));
	}
	else
	{
		ThreadFlag=TRUE;
		///////
		(pCmd->GetDlgItem(IDC_BUTTON9))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON10))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON11))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON12))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON1))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON2))->EnableWindow();
		(pCmd->GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON7))->EnableWindow(FALSE);
		(pCmd->GetDlgItem(IDC_BUTTON8))->EnableWindow();
		///////
		HANDLE hMultiThread=AfxBeginThread(ChildThread,this,THREAD_PRIORITY_IDLE);
		return;
	}
}


void CMainDoc::ExeNextTick()
{
	elevsys.UpdateInstruction(buf_alg_sel);
	elevsys.elev[0].NextTick();
	elevsys.elev[1].NextTick();
	elevsys.elev[2].NextTick();


	//AfxMessageBox(CString("nexttick"));
}


void CMainDoc::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cmd_seq.InQ(CMD_MSG(CT_ABORT));
	ThreadFlag=FALSE;
	(pCmd->GetDlgItem(IDC_BUTTON9))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON10))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON11))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON12))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON1))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON2))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON7))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON8))->EnableWindow(FALSE);
}


void CMainDoc::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cmd_seq.InQ(CMD_MSG(CT_PAUSE));
	///////
	(pCmd->GetDlgItem(IDC_BUTTON2))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON3))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON4))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON5))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON6))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON7))->EnableWindow();
	////////

}


void CMainDoc::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cmd_seq.InQ(CMD_MSG(CT_UNPAUSE));
	//////
	(pCmd->GetDlgItem(IDC_BUTTON2))->EnableWindow();
	(pCmd->GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
	(pCmd->GetDlgItem(IDC_BUTTON7))->EnableWindow(FALSE);
}


void CMainDoc::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cmd_seq.InQ(CMD_MSG(CT_MY_UNDER_PAUSE_NEXT_SECOND));
}


void CMainDoc::OnBnClickedButton4()
{
	for(int i=0;i<ticks_in_second;++i)
	{
		cmd_seq.InQ(CMD_MSG(CT_MY_UNDER_PAUSE_NEXT_SECOND));
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMainDoc::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSettingDlgRequest Dlg5;
	Dlg5.Check_0_1=elevsys.elev[0].m_btn_status[0];
	Dlg5.Check_0_2=elevsys.elev[0].m_btn_status[1];
	Dlg5.Check_0_3=elevsys.elev[0].m_btn_status[2];
	Dlg5.Check_0_4=elevsys.elev[0].m_btn_status[3];
	Dlg5.Check_0_5=elevsys.elev[0].m_btn_status[4];
	Dlg5.Check_0_6=elevsys.elev[0].m_btn_status[5];
	Dlg5.Check_0_7=elevsys.elev[0].m_btn_status[6];
	Dlg5.Check_0_8=elevsys.elev[0].m_btn_status[7];
	Dlg5.Check_0_9=elevsys.elev[0].m_btn_status[8];

	Dlg5.Check_1_1=elevsys.elev[1].m_btn_status[0];
	Dlg5.Check_1_2=elevsys.elev[1].m_btn_status[1];
	Dlg5.Check_1_3=elevsys.elev[1].m_btn_status[2];
	Dlg5.Check_1_4=elevsys.elev[1].m_btn_status[3];
	Dlg5.Check_1_5=elevsys.elev[1].m_btn_status[4];
	Dlg5.Check_1_6=elevsys.elev[1].m_btn_status[5];
	Dlg5.Check_1_7=elevsys.elev[1].m_btn_status[6];
	Dlg5.Check_1_8=elevsys.elev[1].m_btn_status[7];
	Dlg5.Check_1_9=elevsys.elev[1].m_btn_status[8];

	Dlg5.Check_2_1=elevsys.elev[2].m_btn_status[0];
	Dlg5.Check_2_2=elevsys.elev[2].m_btn_status[1];
	Dlg5.Check_2_3=elevsys.elev[2].m_btn_status[2];
	Dlg5.Check_2_4=elevsys.elev[2].m_btn_status[3];
	Dlg5.Check_2_5=elevsys.elev[2].m_btn_status[4];
	Dlg5.Check_2_6=elevsys.elev[2].m_btn_status[5];
	Dlg5.Check_2_7=elevsys.elev[2].m_btn_status[6];
	Dlg5.Check_2_8=elevsys.elev[2].m_btn_status[7];
	Dlg5.Check_2_9=elevsys.elev[2].m_btn_status[8];

	

	if(elevsys.m_request[0]==ELESYS_UP){Dlg5.Check_out_up_1=TRUE;}
	if(elevsys.m_request[1]==ELESYS_UP){Dlg5.Check_out_up_2=TRUE;}
	if(elevsys.m_request[2]==ELESYS_UP){Dlg5.Check_out_up_3=TRUE;}
	if(elevsys.m_request[3]==ELESYS_UP){Dlg5.Check_out_up_4=TRUE;}
	if(elevsys.m_request[4]==ELESYS_UP){Dlg5.Check_out_up_5=TRUE;}
	if(elevsys.m_request[5]==ELESYS_UP){Dlg5.Check_out_up_6=TRUE;}
	if(elevsys.m_request[6]==ELESYS_UP){Dlg5.Check_out_up_7=TRUE;}
	if(elevsys.m_request[7]==ELESYS_UP){Dlg5.Check_out_up_8=TRUE;}
	if(elevsys.m_request[8]==ELESYS_UP){Dlg5.Check_out_up_9=TRUE;}
	
	if(elevsys.m_request[0]==ELESYS_DOWN){Dlg5.Check_out_down_1=TRUE;}
	if(elevsys.m_request[1]==ELESYS_DOWN){Dlg5.Check_out_down_2=TRUE;}
	if(elevsys.m_request[2]==ELESYS_DOWN){Dlg5.Check_out_down_3=TRUE;}
	if(elevsys.m_request[3]==ELESYS_DOWN){Dlg5.Check_out_down_4=TRUE;}
	if(elevsys.m_request[4]==ELESYS_DOWN){Dlg5.Check_out_down_5=TRUE;}
	if(elevsys.m_request[5]==ELESYS_DOWN){Dlg5.Check_out_down_6=TRUE;}
	if(elevsys.m_request[6]==ELESYS_DOWN){Dlg5.Check_out_down_7=TRUE;}
	if(elevsys.m_request[7]==ELESYS_DOWN){Dlg5.Check_out_down_8=TRUE;}
	if(elevsys.m_request[8]==ELESYS_DOWN){Dlg5.Check_out_down_9=TRUE;}

	if(elevsys.m_request[0]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_1=TRUE;Dlg5.Check_out_up_1=TRUE;}
	if(elevsys.m_request[1]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_2=TRUE;Dlg5.Check_out_up_2=TRUE;}
	if(elevsys.m_request[2]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_3=TRUE;Dlg5.Check_out_up_3=TRUE;}
	if(elevsys.m_request[3]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_4=TRUE;Dlg5.Check_out_up_4=TRUE;}
	if(elevsys.m_request[4]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_5=TRUE;Dlg5.Check_out_up_5=TRUE;}
	if(elevsys.m_request[5]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_6=TRUE;Dlg5.Check_out_up_6=TRUE;}
	if(elevsys.m_request[6]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_7=TRUE;Dlg5.Check_out_up_7=TRUE;}
	if(elevsys.m_request[7]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_8=TRUE;Dlg5.Check_out_up_8=TRUE;}
	if(elevsys.m_request[8]==ELESYS_UP_AND_DOWN){Dlg5.Check_out_down_9=TRUE;Dlg5.Check_out_up_9=TRUE;}


	//Dlg5.UpdateData(FALSE);


	if(Dlg5.DoModal()==TRUE)
	{
		elevsys.elev[0].m_btn_status[0]=Dlg5.Check_0_1;
		elevsys.elev[0].m_btn_status[1]=Dlg5.Check_0_2;
		elevsys.elev[0].m_btn_status[2]=Dlg5.Check_0_3;
		elevsys.elev[0].m_btn_status[3]=Dlg5.Check_0_4;
		elevsys.elev[0].m_btn_status[4]=Dlg5.Check_0_5;
		elevsys.elev[0].m_btn_status[5]=Dlg5.Check_0_6;
		elevsys.elev[0].m_btn_status[6]=Dlg5.Check_0_7;
		elevsys.elev[0].m_btn_status[7]=Dlg5.Check_0_8;
		elevsys.elev[0].m_btn_status[8]=Dlg5.Check_0_9;

		elevsys.elev[1].m_btn_status[0]=Dlg5.Check_1_1;
		elevsys.elev[1].m_btn_status[1]=Dlg5.Check_1_2;
		elevsys.elev[1].m_btn_status[2]=Dlg5.Check_1_3;
		elevsys.elev[1].m_btn_status[3]=Dlg5.Check_1_4;
		elevsys.elev[1].m_btn_status[4]=Dlg5.Check_1_5;
		elevsys.elev[1].m_btn_status[5]=Dlg5.Check_1_6;
		elevsys.elev[1].m_btn_status[6]=Dlg5.Check_1_7;
		elevsys.elev[1].m_btn_status[7]=Dlg5.Check_1_8;
		elevsys.elev[1].m_btn_status[8]=Dlg5.Check_1_9;

		elevsys.elev[2].m_btn_status[0]=Dlg5.Check_2_1;
		elevsys.elev[2].m_btn_status[1]=Dlg5.Check_2_2;
		elevsys.elev[2].m_btn_status[2]=Dlg5.Check_2_3;
		elevsys.elev[2].m_btn_status[3]=Dlg5.Check_2_4;
		elevsys.elev[2].m_btn_status[4]=Dlg5.Check_2_5;
		elevsys.elev[2].m_btn_status[5]=Dlg5.Check_2_6;
		elevsys.elev[2].m_btn_status[6]=Dlg5.Check_2_7;
		elevsys.elev[2].m_btn_status[7]=Dlg5.Check_2_8;
		elevsys.elev[2].m_btn_status[8]=Dlg5.Check_2_9;

		if(Dlg5.Check_out_down_1==TRUE && Dlg5.Check_out_up_1==TRUE){elevsys.m_request[0]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_1==TRUE){elevsys.m_request[0]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_1==TRUE){elevsys.m_request[0]=ELESYS_UP;}
		else{elevsys.m_request[0]=ELESYS_NO;}

		if(Dlg5.Check_out_down_2==TRUE && Dlg5.Check_out_up_2==TRUE){elevsys.m_request[1]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_2==TRUE){elevsys.m_request[1]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_2==TRUE){elevsys.m_request[1]=ELESYS_UP;}
		else{elevsys.m_request[1]=ELESYS_NO;}

		if(Dlg5.Check_out_down_3==TRUE && Dlg5.Check_out_up_3==TRUE){elevsys.m_request[2]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_3==TRUE){elevsys.m_request[2]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_3==TRUE){elevsys.m_request[2]=ELESYS_UP;}
		else{elevsys.m_request[2]=ELESYS_NO;}

		if(Dlg5.Check_out_down_4==TRUE && Dlg5.Check_out_up_4==TRUE){elevsys.m_request[3]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_4==TRUE){elevsys.m_request[3]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_4==TRUE){elevsys.m_request[3]=ELESYS_UP;}
		else{elevsys.m_request[3]=ELESYS_NO;}

		if(Dlg5.Check_out_down_5==TRUE && Dlg5.Check_out_up_5==TRUE){elevsys.m_request[4]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_5==TRUE){elevsys.m_request[4]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_5==TRUE){elevsys.m_request[4]=ELESYS_UP;}
		else{elevsys.m_request[4]=ELESYS_NO;}

		if(Dlg5.Check_out_down_6==TRUE && Dlg5.Check_out_up_6==TRUE){elevsys.m_request[5]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_6==TRUE){elevsys.m_request[5]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_6==TRUE){elevsys.m_request[5]=ELESYS_UP;}
		else{elevsys.m_request[5]=ELESYS_NO;}

		if(Dlg5.Check_out_down_7==TRUE && Dlg5.Check_out_up_7==TRUE){elevsys.m_request[6]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_7==TRUE){elevsys.m_request[6]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_7==TRUE){elevsys.m_request[6]=ELESYS_UP;}
		else{elevsys.m_request[6]=ELESYS_NO;}

		if(Dlg5.Check_out_down_8==TRUE && Dlg5.Check_out_up_8==TRUE){elevsys.m_request[7]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_8==TRUE){elevsys.m_request[7]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_8==TRUE){elevsys.m_request[7]=ELESYS_UP;}
		else{elevsys.m_request[7]=ELESYS_NO;}

		if(Dlg5.Check_out_down_9==TRUE && Dlg5.Check_out_up_9==TRUE){elevsys.m_request[8]=ELESYS_UP_AND_DOWN;}
		else if(Dlg5.Check_out_down_9==TRUE){elevsys.m_request[8]=ELESYS_DOWN;}
		else if(Dlg5.Check_out_up_9==TRUE){elevsys.m_request[8]=ELESYS_UP;}
		else{elevsys.m_request[8]=ELESYS_NO;}

	}
	else{}
}




void CMainDoc::OnDoc01()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���CmdSequence ��");
	dlg.author=TEXT("�� haixin ���һ���޶�");
	dlg.txt=TEXT("������� haixin ���б�д��\r\n�����ı�дĿ����������û��MFC�Ļ����ϣ�Ϊ�˶��̵߳�ʵ��׫д��һ���ࡣ\r\n\r\n�����ĳ�Ա������:\r\nprivate:\r\n    CMD_MSG msg[QUEUE_SIZE];\r\n    unsigned int q_head;\r\n    unsigned int q_tail;\r\n    SEQ_ERR_STATUS err_status;\r\n    SEQ_STO_STATUS sto_status;\r\n    BOOL ValidateStatus(SEQ_IO);\r\n\r\n��Ա������:\r\npublic:\r\n    CmdSequence();\r\n    ~CmdSequence();\r\n    SEQ_ERR_STATUS GetErrStatus();\r\n    BOOL SetErrStatus(SEQ_ERR_STATUS = SEQ_OK);\r\n    SEQ_STO_STATUS GetStoStatus();\r\n    BOOL UpdateStatus();\r\n    BOOL InQ(CMD_MSG _msg);\r\n    CMD_MSG OutQ();\r\n    BOOL ClearAndInit();\r\n\r\n����������Ŀ���ǽ��û����������������У��ɹ����߳�ѭ��ץȡ����Ӷ�ʹ�����߳���Ӧ��������ֹ����ͣ��������һ��ȣ�����������У���Ҫ�ķ����� InQ �� OutQ���ֱ������Ӻͳ��ӡ���Ӻͳ��Ӷ��ȵ���ValidateStatus��������errstatus�ĸ�ֵ���жϣ�����ӳ�����ɺ󣬵���UpdateStatus������������sto_status��ClearAndInit���ڳ�ʼ�����У���������Ŀ��û���õ���");
	dlg.DoModal();
}


void CMainDoc::OnDoc02()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ������������MSG�ṹ��");
	dlg.author=TEXT("��jincheng���һ���޶�");
	dlg.txt=TEXT("��������Ŀ����ͨ��ͳһ�趨�������ݺͺ��壬�����ŶӼ������ͨ����ߴ���Ŀɶ��ԣ�������CSVar.h�趨�����µı�����\r\n(1)�趨����\r\n#define QUEUE_SIZE 4096\r\n#define ELEVATOR_NUMBER 3\r\n#define FLOOR_NUMBER 10\r\n(2)�趨ָ�command type��\r\n#define CT_NOMSG 0\r\n#define CT_ERROR 1\r\n#define CT_WARNING 2\r\n#define CT_TERMINAT 3\r\n#define CT_ABORT 4\r\n#define CT_PAUSE 5\r\n#define CT_UNPAUSE 6\r\n#define CT_MY_SETSPEED 7\r\n#define CT_MY_UNDER_PAUSE_NEXT_SECOND 8\r\n#define CT_MY_ADD_MISSION 10\r\n(3)�趨ָ����Ϣ\r\ntypedef unsigned int CMD_TYPE;��ָ�����ͣ�\r\ntypedef unsigned int CMD_ARG;��ָ�������\r\n\r\nclass CMD_MSG\r\n{\r\npublic:\r\n    CMD_MSG(CMD_TYPE=CT_NOMSG,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0);�����캯����\r\n    CMD_TYPE cmd_type;\r\n    CMD_ARG cmd_arg;\r\n    CMD_ARG cmd_exarg1;\r\n    CMD_ARG cmd_exarg2;\r\n    CMD_ARG cmd_exarg3;\r\n};\r\n\r\n\r\n(4)�趨ָ�����\r\ntypedef unsigned int SEQ_ERR_STATUS;������״̬��\r\n#define SEQ_OK 0\r\n#define SEQ_OVERFLOW 1\r\n#define SEQ_NOFLOW 2\r\n\r\n\r\ntypedef unsigned int SEQ_STO_STATUS;������״̬��\r\n#define SEQ_NORMAL 0\r\n#define SEQ_FULL 1\r\n#define SEQ_EMPTY 2\r\n\r\n\r\ntypedef unsigned int SEQ_IO;���������״̬��\r\n#define SEQ_IN 0\r\n#define SEQ_OUT 1\r\n(5)�趨�������״̬����\r\ntypedef unsigned int ELE_MOV_STATUS;\r\n#define ELE_RUNNING 0\r\n#define ELE_WAIT 1\r\n#define ELE_UP 2\r\n#define ELE_DOWN 3\r\n\r\ntypedef unsigned int ELE_ERR_STATUS;\r\n#define ELE_OK 0\r\n#define ELE_ERROR 1\r\n\r\ntypedef unsigned int ELE_DOOR_STATUS;\r\n#define ELE_DOOR_OPEN 0\r\n#define ELE_DOOR_CLOSE 1\r\n\r\ntypedef unsigned int ELE_BTN_STATUS;\r\n#define ELE_BTN_OFF 0\r\n#define ELE_BTN_ON 1\r\n(5)�趨����ϵͳ���״̬����\r\ntypedef unsigned int ELESYS_TABLE_STATUS;\r\n#define ELESYS_NO 0\r\n#define ELESYS_DOWN 1\r\n#define ELESYS_UP 2\r\n#define ELESYS_UP_AND_DOWN 3\r\n\r\ntypedef unsigned int ELESYS_ALG;\r\n#define ELESYS_ALG0 0\r\n#define ELESYS_ALG1 1\r\n#define ELESYS_ALG2 2\r\n(6)�趨ָ������\r\n#define IT_NOMSG 0\r\n#define IT_INS 1\r\n(7)�趨��Ϣָ������\r\ntypedef unsigned int INS_TYPE;\r\ntypedef unsigned int INS_ARG;\r\n\r\nclass INS_MSG\r\n{\r\npublic:\r\n    INS_MSG(INS_TYPE=IT_NOMSG,INS_ARG=0,INS_ARG=0,INS_ARG=0,INS_ARG=0);�����캯����\r\n    INS_TYPE ins_type;\r\n    INS_ARG ins_arg;\r\n    INS_ARG ins_exarg1;\r\n    INS_ARG ins_exarg2;\r\n    INS_ARG ins_exarg3;\r\n};\r\n\r\n");
	dlg.DoModal();
}



void CMainDoc::OnDoc03()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���Elevator��");
	dlg.author=TEXT("��jincheng���һ���޶�");
	dlg.txt=TEXT("�������haixin����\r\n\r\n���ǳ������������ģ����ݵ����С�\r\n�����ĳ�Ա�����У�\r\npublic:\r\n    INS_MSG m_ins;��ָ��INS��\r\npublic:\r\n    ELE_DOOR_STATUS m_door_status;\r\n    int now_floor_int;\r\n    int now_floor_point;\r\n    ELE_MOV_STATUS now_direction;\r\n\r\n    int m_maintain_now;\r\n    int m_wait_time;\r\n    ELE_ERR_STATUS m_err_status;��״̬STATUS��\r\n\r\npublic:\r\n    ELE_BTN_STATUS m_btn_status[FLOOR_NUMBER];�������ڰ�ť���µı��\r\n\r\npublic:\r\n    int M_tick_per_floor;\r\n    int M_auto_wait_close_time;\r\n    int M_max_maintain;\r\n    double M_open_close_time;�����в�����\r\n\r\n��Ա�����У�\r\npublic:\r\n    Elevator();\r\n    ~Elevator();\r\n    void NextTick();��ִ����һtick���㷨�ɼ�����ָ����Ӧ�㷨��\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc04()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���ElevatorSystem��");
	dlg.author=TEXT("��jincheng���һ���޶�");
	dlg.txt=TEXT("�������haixin����\r\n\r\n��̨��������ͬʱ���ڲ�ָ����ⲿָ����������ǽ������װ��һ��ϵͳ�ࣨElevatorSystem����ģ��������С�\r\n�������Ա�У�\r\npublic:\r\n    ELESYS_TABLE_STATUS m_request[FLOOR_NUMBER];�������ⲿ��ť���\r\n    Elevator elev[ELEVATOR_NUMBER];������̨����\r\n\r\n\r\n��Ա�����У�\r\npublic:\r\n    ElevatorSystem();\r\n    ~ElevatorSystem();\r\n    void UpdateInstruction(ELESYS_ALG);������ָ�\r\n\r\n    void UsingAlg0();��ʹ���㷨1��\r\n    void UsingAlg1();��ʹ���㷨2��\r\n    void UsingAlg2();��ʹ���㷨3��\r\n\r\n\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc05()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���CCmdCentre ��");
	dlg.author=TEXT("��ji���һ���޶�");
	dlg.txt=TEXT("�������haixin���б�д�͸���\r\n�������Ϊ���趨�������в�����׫д����\r\n��Ա������\r\nCMainDoc* pDoc\r\n��Ա������\r\nCCmdCentre()\r\nvirtual ~CCmdCentre()\r\nvirtual void DoDataExchange(CDataExchange* pDX)\r\nvirtual void OnInitialUpdate()\r\n����pDocָ������ĵ�����ͼָ�룬ʵ����Doc��View��CmdCentre����֮��������á�\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc06()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���App��Frame��");
	dlg.author=TEXT("��jincheng���һ���޶�");
	dlg.txt=TEXT("���Ƕ��û����ڿ��Frame�������һЩ���壺\r\nclass CMainFrame: public CFrameWnd\r\n{\r\n    DECLARE_DYNCREATE(CMainFrame);\r\npublic:\r\n    CSplitterWnd m_window1;\r\npublic:\r\n    CMainFrame();\r\n    ~CMainFrame();\r\n    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);���ֽⴰ�ڣ��趨���ڴ�С�ȣ�\r\n    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);�������趨����ֹ������󻯣�ʹ���ڲ��������ı��С���ı䴰�ڴ�С�ȣ�\r\n};\r\n\r\n������App���ʼ����\r\nclass CStdSdiApp: public CWinApp\r\n{\r\npublic:\r\n    BOOL InitInstance();��������ͼ���ĵ�����ܣ��������ִ�������ʾ���ڵȣ�\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc07()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ�������Dlg��");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("����Dlg�����CSettingDlgAlg��CSettingDlgEle��CSettingDlgInit��CSettingDlgPeo��CSettingDlgRequest��CSettingDocBox��\r\n\r\n�ֱ����ڵ����㷨���ã��������в������ã����ݳ�ʼ��������ʱ��ο����ã����ݵ���״̬��������������Լ����ڼ�¼�����ĵ��ĶԻ���ĵ�����\r\n�йؾ����Ա���������ݣ����ĵ������ݽ�������ο�Դ���롣");
	dlg.DoModal();
}


void CMainDoc::OnDoc08()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���View�ࣨ��ͼ��");
	dlg.author=TEXT("��ji���һ���޶�");
	dlg.txt=TEXT("���ڻ��ƺ���������Ϊ��ʵʱ��ʾ��������״����ָ�ť״̬����д��һ�����������������ڱ�дʱ�����Ϊ�����֣�����λ��ʵʱ��ʾ���ⲿָ�ť���ڲ�ָ�ť������ͨ��pDocָ�뽫����ϵͳ��صĵĲ��������ͼϵͳ֮�У�Ȼ�����ݴ���Ĳ�����ֵʹ��MFC�Ļ�ͼ���߽��л��ơ�ͬʱΪ�����ˢ������֮��ĸ������⣬���ǽ����ֱ�������Ϊ͸��������ʹ�û�ˢ���Ƴ����������������ı����֡�");
	dlg.DoModal();
}


void CMainDoc::OnDoc09()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ���Doc �ࣺ��Ӧ");
	dlg.author=TEXT("��xurui���һ���޶�");
	dlg.txt=TEXT("Doc��\r\npublic:\r\nCMainDoc();\r\n~CMainDoc();\r\nDECLARE_MESSAGE_MAP()\r\nOnBnClickedButton9() �����������������õ��ݲ����Ի���\r\nOnBnClickedButton10() �������������������㷨�����Ի���\r\nOnBnClickedButton11() ������������������ʱ��ο������Ի���\r\nOnBnClickedButton12() �������������򿪳�ʼ������λ�öԻ���\r\nOnBnClickedButton1() ��������������ʼ����ģ��\r\npublic:\r\nExeNextTick() \r\nOnBnClickedButton8() �������������������ֹͣ����\r\nOnBnClickedButton2() ��������������ͣ����ģ��\r\nOnBnClickedButton7() ������������������ݻָ�����\r\nOnBnClickedButton3() �������������������ģ�����һ֡��״̬\r\nOnBnClickedButton4() �������������������ģ�����һ���״̬\r\nOnBnClickedButton5() �������������򿪸�������״̬�Ի���\r\nOnDocһϵ�к������ڵ����򿪿����ĵ�����־��ÿ������ĵ���鼰˵��\r\nOnLogһϵ�к������ڵ����򿪿����ĵ�����־��ÿһ����еĹ����ܽ�\r\nOnGpl()�������ڵ����򿪹�����GNU General Public License v2.0��˵���ĵ�\r\nOnOtherLs()�������ڵ����򿪹����еĸ���Э������Լ˵���ĵ�\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc10()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("");
	dlg.author=TEXT("");
	dlg.txt=TEXT("");
	dlg.DoModal();
}


void CMainDoc::OnDoc11()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("");
	dlg.author=TEXT("");
	dlg.txt=TEXT("");
	dlg.DoModal();
}


void CMainDoc::OnDoc12()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ������̣߳������߳�");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("��������haixin����\r\n\r\n������Ƶĵ���ģ��ϵͳ��tickΪ��λ���м���ͻ��ƣ��ڳ������й����У�һ����ʼִ�оͲ����ٶ�ֹͣ��Ϊ��ʵ�����̶߳Թ����̵߳Ŀ��ƣ��������������������ڹ����߳�������ѭ���ȶ�ȡ���߳�������У����������û��ָ��ͻ����ִ����һtick�����㣬���������߳�sleepһС��ʱ�䣬Ȼ�����»ص�������е��жϡ�����жϳ���ABORTָ��ͻ���ֹ�̣߳��������̬����ֱ��return��������жϳ�PAUSEָ��ͻὫ�߳�����pause״̬�����������״̬�����������û��ָ��ͽ������߳�sleepһС��ʱ�䣬���ص�������жϣ�������������㣬ֱ�����յ�UNPAUSEָ��˳�pause״̬��\r\n\r\n�����̵߳ķ�������CmdCentre(�̳���FormView)���ڵġ���������ť������CMainDoc(�̳���CDocument��)����Ӧ�����е���AfxBeginThread(ChildThread,this,THREAD_PRIORITY_IDLE)��ɵġ�\r\n\r\n����ʵ�ֿɼ�Դ���롣");
	dlg.DoModal();
}


void CMainDoc::OnDoc13()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ�������ϵͳ��ʱָ���㷨");
	dlg.author=TEXT("��ji���һ���޶�");
	dlg.txt=TEXT("��������ji��haixin��ͬά����\r\n\r\n������������������㷨���ɣ��������㷨��Ji FAN��ɡ��������㷨��Haixin ZHANG��ɣ�����һ�������ĵ������㷨��Xurui GU��ɡ�\r\n\r\n����ϵͳ��ʱָ���㷨��������ʵ�����õ����ڡ��ⲿָ��͵������������������Ϣ���Ե��ݽ��е��ȡ��پ���ʵ���У�����switch-case������ֵ��ݵ��������½���ֹͣ���������������ÿһ������ڲ���ͨ��if-else���ʵ�ֶ�����ָ���������Ӧ�������㷨������ԭ����������Ӧ��ָ�������Ӧ���¥��ָ�ͬʱ����һЩ����ָ������Ҳ������Ӧ���Ż���");
	dlg.DoModal();
}


void CMainDoc::OnDoc14()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ�������������Ӧ�����㷨");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("��������haixin��д�͸���\r\n\r\n����㷨��д�ڹ����߳��С���ExeNextTickִ����һ�뺯���ĵ���֮��\r\nĿ���������ڵ��ݵ���͵��ݵ�m_ins(INS_MSG����)��ͬ�ĵ�¥��󣬽������ڵİ�ť�𣬲��ҽ�������İ�ťϨ���ʵ�֡�\r\n\r\n��Ҫ��˼·���£�\r\n\r\n����3̨���ݣ��жϵ����Ƿ���ָ���ָ�����жϵ���Ŀǰ��¥���Ƿ��������Ҹպ���ElevatorSystem������ָ���¥��һ�¡����һ�£��ͻ���ݵ�������״̬�͵���¥����ElevatorSystem���ⲿ������н����ݵ�����״̬��Ϊ���ʵ�״̬�����������Ƕ���UINT���͵�ELESYS_TABLE_STATUS��ELESYS_NO����00B��ELESYS_DOWN����01B��ELESYS_UP����10B��ELESYS_UP_AND_DOWN����11B��һ��ʼ�������������ڴ��д洢�Ķ�������ʽ�򻯳������̣������ͼ�������ǻ���ǿ��ö���ˣ�\r\n\r\n֮��ͬ��������̨���ݣ��жϵ����Ƿ���ָ���ָ�����жϵ���Ŀǰ��¥���Ƿ��������Ҹպ���ElevatorSystem������ָ���¥��һ�£�һ�¾ͽ������ڲ��İ�ť��Ϊ���ʵ�״̬�����鶨����ĵ����α������壩\r\n\r\n���������ͬ�ķ��������жϵõ��󣬼��Ͽ������Լ��Զ������ŵ�ʱ�䡣���������ǵĵ���ģ�������ģ���õ��Ǽ�ʱָ���࣬��˲����ظ��ۼ���Щʱ�䡣\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc15()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ�������ָ����Ӧ�㷨");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("��������haixin1��д��\r\n\r\nλ��Elevator::NextTick()�У�������ElevatorSystem�����㷨�󣬽����žͻ�ִ�е�����һtick��ʵ��Ϊ����������Ϣʱ���Ὣ�����Ŷ����ϵĵȴ�ʱ���ȼ�����������ݵ��յ�ָ�������������½����ͻὫ���ݵ�λ�á�С�������ּ�ȥһ����Ȼ��ȡģ��λ������λ������һ��������еȴ�ʱ�䣬�ȼ�ȥ�ȴ�ʱ�䡣����㷨�ܼ򵥣�������Ҫ������漸���㷨���ʹ�ã�ȷʵ��һ���Ѷȡ�\r\n�����Դ����\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc16()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("�ĵ����ؼ��߼��㷨");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("��������haixin��д\r\n�ؼ��߼���Ҫ��ָ���¡��������������ؼ�������״̬����������ΪCmdCentre(�̳���CFormView)�İ�ť��Doc���е���Ӧ������(pCmd->GetDlgItem(IDC_BUTTONx))->EnableWindow()�ķ�ʽ������CmdCentre�ؼ�������֮����߼���ϵ��Ϊ�򵥣������ֲ���׸����\r\n�����Դ����\r\n");
	dlg.DoModal();
}


void CMainDoc::OnLog01()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog02()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog03()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog04()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog05()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog06()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog07()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog08()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog09()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog10()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnLog11()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("��־");
	dlg.author=TEXT("��haixin���һ���޶�");
	dlg.txt=TEXT("�ǲ����ˣ�д�����ˡ�");
	dlg.DoModal();
}


void CMainDoc::OnGpl()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("GNU GENERAL PUBLIC LICENSE");
	dlg.author=TEXT("GNU");
	dlg.txt=TEXT("GNU GENERAL PUBLIC LICENSE\r\nVersion 2, June 1991\r\n\r\nCopyright (C) 1989, 1991 Free Software Foundation, Inc.  \r\n\r\nhttp://www.gnu.org/licenses/old-licenses/gpl-2.0.html");
	dlg.DoModal();
}


void CMainDoc::OnOtherLs()
{
	// TODO: �ڴ���������������
	CSettingDocBox dlg;
	dlg.title=TEXT("����������Լ");
	dlg.author=TEXT("Author: haixin");
	dlg.txt=TEXT("����Ŀ����Ӧ�����ύ2020�����ϴ�ѧ����ѧУ��ҵ������ΪHaixin ZHANG, Ji FAN, Xurui GU, Jincheng GAI��\r\n\r\n��2021��8�º󣬸���Ŀ��ȫ��Դ��ֹͣ���£����еĴ���Ϊ�Ŷӹ�ͬ��д�����������κν���������������д�߱��ֽ���Ȩ����2021��8�º󣬸���Ŀ����GPL2.0��Э�飬���Ҹ��ݱ���Ŀ������뿪������Ŀ����Ҫ��Դ������GPL2.0Э�飬������������Ϣ�����⣬����Ŀ��������������Ŀ����������ҵ��;��\r\n");
	dlg.DoModal();
}
