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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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



//多线程任务
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
				for(int jj=0;jj<3;jj++)//到达一个楼层后对外部按钮的反应
				{
					if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)//到达一个楼层后对外部按钮的反应
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

				for(int jj=0;jj<3;jj++)//到达一个楼层后对内部按钮的反应
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

				for(int jj=0;jj<3;jj++)//开关门耗时
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
					AfxMessageBox(CString("工作线程正常中止。"));
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
					AfxMessageBox(CString(TEXT("队列中无法解析的CMD_MSG消息，程序错误请关闭(ERR03)。")));
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

					for(int jj=0;jj<3;jj++)//到达一个楼层后对外部按钮的反应
					{
						if((pDoc->elevsys.elev[jj]).m_ins.ins_type==IT_INS)//到达一个楼层后对外部按钮的反应
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

					for(int jj=0;jj<3;jj++)//到达一个楼层后对内部按钮的反应
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

					for(int jj=0;jj<3;jj++)//开关门耗时
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
					AfxMessageBox(CString(TEXT("队列中无法解析的CMD_MSG消息，程序错误请关闭(ERR02)。")));
				}
			}
		}
		//这里还需要添加！！！！
		//XXXXXXXXXXX
	}
	return 1;
}

void CMainDoc::OnBnClickedButton1()
{
	if(ThreadFlag)
	{
		ThreadFlag=FALSE;
		AfxMessageBox(CString(TEXT("线程重复创建，程序错误请关闭(ERR01)。")));
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	cmd_seq.InQ(CMD_MSG(CT_MY_UNDER_PAUSE_NEXT_SECOND));
}


void CMainDoc::OnBnClickedButton4()
{
	for(int i=0;i<ticks_in_second;++i)
	{
		cmd_seq.InQ(CMD_MSG(CT_MY_UNDER_PAUSE_NEXT_SECOND));
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMainDoc::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：CmdSequence 类");
	dlg.author=TEXT("由 haixin 最后一次修订");
	dlg.txt=TEXT("这个类由 haixin 进行编写。\r\n这个类的编写目的是在我们没有MFC的基础上，为了多线程的实现撰写的一个类。\r\n\r\n这个类的成员变量有:\r\nprivate:\r\n    CMD_MSG msg[QUEUE_SIZE];\r\n    unsigned int q_head;\r\n    unsigned int q_tail;\r\n    SEQ_ERR_STATUS err_status;\r\n    SEQ_STO_STATUS sto_status;\r\n    BOOL ValidateStatus(SEQ_IO);\r\n\r\n成员方法有:\r\npublic:\r\n    CmdSequence();\r\n    ~CmdSequence();\r\n    SEQ_ERR_STATUS GetErrStatus();\r\n    BOOL SetErrStatus(SEQ_ERR_STATUS = SEQ_OK);\r\n    SEQ_STO_STATUS GetStoStatus();\r\n    BOOL UpdateStatus();\r\n    BOOL InQ(CMD_MSG _msg);\r\n    CMD_MSG OutQ();\r\n    BOOL ClearAndInit();\r\n\r\n这个队列类的目的是将用户的命令存入这个队列，由工作线程循环抓取命令，从而使工作线程响应（例如中止、暂停、调试下一秒等）。在这个类中，重要的方法有 InQ 和 OutQ，分别代表入队和出队。入队和出队都先调用ValidateStatus方法进行errstatus的赋值并判断，在入队出队完成后，调用UpdateStatus方法进行重置sto_status。ClearAndInit用于初始化队列，在整体项目中没有用到。");
	dlg.DoModal();
}


void CMainDoc::OnDoc02()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：变量定义和MSG结构类");
	dlg.author=TEXT("由jincheng最后一次修订");
	dlg.txt=TEXT("变量定义目的是通过统一设定变量内容和含义，便于团队间合作互通，提高代码的可读性，我们在CSVar.h设定了如下的变量：\r\n(1)设定常量\r\n#define QUEUE_SIZE 4096\r\n#define ELEVATOR_NUMBER 3\r\n#define FLOOR_NUMBER 10\r\n(2)设定指令（command type）\r\n#define CT_NOMSG 0\r\n#define CT_ERROR 1\r\n#define CT_WARNING 2\r\n#define CT_TERMINAT 3\r\n#define CT_ABORT 4\r\n#define CT_PAUSE 5\r\n#define CT_UNPAUSE 6\r\n#define CT_MY_SETSPEED 7\r\n#define CT_MY_UNDER_PAUSE_NEXT_SECOND 8\r\n#define CT_MY_ADD_MISSION 10\r\n(3)设定指令消息\r\ntypedef unsigned int CMD_TYPE;（指令类型）\r\ntypedef unsigned int CMD_ARG;（指令参数）\r\n\r\nclass CMD_MSG\r\n{\r\npublic:\r\n    CMD_MSG(CMD_TYPE=CT_NOMSG,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0);（构造函数）\r\n    CMD_TYPE cmd_type;\r\n    CMD_ARG cmd_arg;\r\n    CMD_ARG cmd_exarg1;\r\n    CMD_ARG cmd_exarg2;\r\n    CMD_ARG cmd_exarg3;\r\n};\r\n\r\n\r\n(4)设定指令队列\r\ntypedef unsigned int SEQ_ERR_STATUS;（运行状态）\r\n#define SEQ_OK 0\r\n#define SEQ_OVERFLOW 1\r\n#define SEQ_NOFLOW 2\r\n\r\n\r\ntypedef unsigned int SEQ_STO_STATUS;（储存状态）\r\n#define SEQ_NORMAL 0\r\n#define SEQ_FULL 1\r\n#define SEQ_EMPTY 2\r\n\r\n\r\ntypedef unsigned int SEQ_IO;（输入输出状态）\r\n#define SEQ_IN 0\r\n#define SEQ_OUT 1\r\n(5)设定电梯类的状态变量\r\ntypedef unsigned int ELE_MOV_STATUS;\r\n#define ELE_RUNNING 0\r\n#define ELE_WAIT 1\r\n#define ELE_UP 2\r\n#define ELE_DOWN 3\r\n\r\ntypedef unsigned int ELE_ERR_STATUS;\r\n#define ELE_OK 0\r\n#define ELE_ERROR 1\r\n\r\ntypedef unsigned int ELE_DOOR_STATUS;\r\n#define ELE_DOOR_OPEN 0\r\n#define ELE_DOOR_CLOSE 1\r\n\r\ntypedef unsigned int ELE_BTN_STATUS;\r\n#define ELE_BTN_OFF 0\r\n#define ELE_BTN_ON 1\r\n(5)设定电梯系统类的状态变量\r\ntypedef unsigned int ELESYS_TABLE_STATUS;\r\n#define ELESYS_NO 0\r\n#define ELESYS_DOWN 1\r\n#define ELESYS_UP 2\r\n#define ELESYS_UP_AND_DOWN 3\r\n\r\ntypedef unsigned int ELESYS_ALG;\r\n#define ELESYS_ALG0 0\r\n#define ELESYS_ALG1 1\r\n#define ELESYS_ALG2 2\r\n(6)设定指令类型\r\n#define IT_NOMSG 0\r\n#define IT_INS 1\r\n(7)设定消息指令类型\r\ntypedef unsigned int INS_TYPE;\r\ntypedef unsigned int INS_ARG;\r\n\r\nclass INS_MSG\r\n{\r\npublic:\r\n    INS_MSG(INS_TYPE=IT_NOMSG,INS_ARG=0,INS_ARG=0,INS_ARG=0,INS_ARG=0);（构造函数）\r\n    INS_TYPE ins_type;\r\n    INS_ARG ins_arg;\r\n    INS_ARG ins_exarg1;\r\n    INS_ARG ins_exarg2;\r\n    INS_ARG ins_exarg3;\r\n};\r\n\r\n");
	dlg.DoModal();
}



void CMainDoc::OnDoc03()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：Elevator类");
	dlg.author=TEXT("由jincheng最后一次修订");
	dlg.txt=TEXT("这个类有haixin负责\r\n\r\n我们抽象出电梯类来模拟电梯的运行。\r\n这个类的成员变量有：\r\npublic:\r\n    INS_MSG m_ins;（指令INS）\r\npublic:\r\n    ELE_DOOR_STATUS m_door_status;\r\n    int now_floor_int;\r\n    int now_floor_point;\r\n    ELE_MOV_STATUS now_direction;\r\n\r\n    int m_maintain_now;\r\n    int m_wait_time;\r\n    ELE_ERR_STATUS m_err_status;（状态STATUS）\r\n\r\npublic:\r\n    ELE_BTN_STATUS m_btn_status[FLOOR_NUMBER];（电梯内按钮按下的表格）\r\n\r\npublic:\r\n    int M_tick_per_floor;\r\n    int M_auto_wait_close_time;\r\n    int M_max_maintain;\r\n    double M_open_close_time;（固有参数）\r\n\r\n成员方法有：\r\npublic:\r\n    Elevator();\r\n    ~Elevator();\r\n    void NextTick();（执行下一tick，算法可见电梯指令响应算法）\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc04()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：ElevatorSystem类");
	dlg.author=TEXT("由jincheng最后一次修订");
	dlg.txt=TEXT("这个类有haixin负责\r\n\r\n三台电梯运行同时由内部指令和外部指令决定，我们将整体封装成一个系统类（ElevatorSystem）来模拟电梯运行。\r\n其中类成员有：\r\npublic:\r\n    ELESYS_TABLE_STATUS m_request[FLOOR_NUMBER];（电梯外部按钮表格）\r\n    Elevator elev[ELEVATOR_NUMBER];（电梯台数）\r\n\r\n\r\n成员方法有：\r\npublic:\r\n    ElevatorSystem();\r\n    ~ElevatorSystem();\r\n    void UpdateInstruction(ELESYS_ALG);（更新指令）\r\n\r\n    void UsingAlg0();（使用算法1）\r\n    void UsingAlg1();（使用算法2）\r\n    void UsingAlg2();（使用算法3）\r\n\r\n\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc05()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：CCmdCentre 类");
	dlg.author=TEXT("由ji最后一次修订");
	dlg.txt=TEXT("这个类由haixin进行编写和负责\r\n这个类是为了设定电梯运行参数而撰写的类\r\n成员变量：\r\nCMainDoc* pDoc\r\n成员方法：\r\nCCmdCentre()\r\nvirtual ~CCmdCentre()\r\nvirtual void DoDataExchange(CDataExchange* pDX)\r\nvirtual void OnInitialUpdate()\r\n利用pDoc指针给予文档类视图指针，实现了Doc、View、CmdCentre三者之间的灵活调用。\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc06()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：App和Frame类");
	dlg.author=TEXT("由jincheng最后一次修订");
	dlg.txt=TEXT("我们对用户窗口框架Frame类进行了一些定义：\r\nclass CMainFrame: public CFrameWnd\r\n{\r\n    DECLARE_DYNCREATE(CMainFrame);\r\npublic:\r\n    CSplitterWnd m_window1;\r\npublic:\r\n    CMainFrame();\r\n    ~CMainFrame();\r\n    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);（分解窗口，设定窗口大小等）\r\n    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);（属性设定：禁止窗口最大化，使窗口不能用鼠标改变大小，改变窗口大小等）\r\n};\r\n\r\n我们用App类初始化：\r\nclass CStdSdiApp: public CWinApp\r\n{\r\npublic:\r\n    BOOL InitInstance();（连接视图、文档、框架，解析命令，执行命令，显示窗口等）\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc07()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：其他Dlg类");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("其他Dlg类包括CSettingDlgAlg，CSettingDlgEle，CSettingDlgInit，CSettingDlgPeo，CSettingDlgRequest，CSettingDocBox。\r\n\r\n分别用于电梯算法设置，电梯运行参数设置，电梯初始化，电梯时间参考设置，电梯调试状态下添加内外请求，以及用于记录开发文档的对话框的弹出。\r\n有关具体成员变量及内容，和文档的数据交互，请参考源代码。");
	dlg.DoModal();
}


void CMainDoc::OnDoc08()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：View类（绘图）");
	dlg.author=TEXT("由ji最后一次修订");
	dlg.txt=TEXT("窗口绘制函数是我们为了实时显示电梯运行状况和指令按钮状态而编写的一个函数。整个窗口在编写时大体分为三部分：电梯位置实时显示、外部指令按钮、内部指令按钮。我们通过pDoc指针将电梯系统相关的的参数传入绘图系统之中，然后依据传入的参数的值使用MFC的绘图工具进行绘制。同时为解决画刷、文字之间的覆盖问题，我们将文字背景设置为透明，且先使用画刷绘制出高亮区域后再输出文本文字。");
	dlg.DoModal();
}


void CMainDoc::OnDoc09()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：Doc 类：响应");
	dlg.author=TEXT("由xurui最后一次修订");
	dlg.txt=TEXT("Doc类\r\npublic:\r\nCMainDoc();\r\n~CMainDoc();\r\nDECLARE_MESSAGE_MAP()\r\nOnBnClickedButton9() 函数用作单击打开设置电梯参数对话框\r\nOnBnClickedButton10() 函数用作单击打开设置算法参数对话框\r\nOnBnClickedButton11() 函数用作单击打开设置时间参考参数对话框\r\nOnBnClickedButton12() 函数用作单击打开初始化电梯位置对话框\r\nOnBnClickedButton1() 函数用作单击开始电梯模拟\r\npublic:\r\nExeNextTick() \r\nOnBnClickedButton8() 函数用作单击命令电梯停止运行\r\nOnBnClickedButton2() 函数用作单击暂停电梯模拟\r\nOnBnClickedButton7() 函数用作单击命令电梯恢复运行\r\nOnBnClickedButton3() 函数用作单击命令电梯模拟出下一帧的状态\r\nOnBnClickedButton4() 函数用作单击命令电梯模拟出下一秒的状态\r\nOnBnClickedButton5() 函数用作单击打开更改请求状态对话框\r\nOnDoc一系列函数用于单击打开开发文档与日志中每个类的文档简介及说明\r\nOnLog一系列函数用于单击打开开发文档与日志中每一天进行的工作总结\r\nOnGpl()函数用于单击打开关于中GNU General Public License v2.0的说明文档\r\nOnOtherLs()函数用于单击打开关于中的附加协议与条约说明文档\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc10()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("");
	dlg.author=TEXT("");
	dlg.txt=TEXT("");
	dlg.DoModal();
}


void CMainDoc::OnDoc11()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("");
	dlg.author=TEXT("");
	dlg.txt=TEXT("");
	dlg.DoModal();
}


void CMainDoc::OnDoc12()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：多线程：工作线程");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("本部分由haixin负责\r\n\r\n我们设计的电梯模拟系统以tick为单位进行计算和绘制，在程序运行过程中，一旦开始执行就不会再度停止，为了实现主线程对工作线程的控制，我们运用了土方法：在工作线程中运用循环先读取主线程命令队列，如果队列中没有指令，就会进行执行下一tick的运算，并将工作线程sleep一小段时间，然后重新回到命令队列的判断。如果判断出有ABORT指令就会终止线程，将这个静态函数直接return掉。如果判断出PAUSE指令，就会将线程置于pause状态，并且在这个状态下如果队列中没有指令，就将工作线程sleep一小段时间，并回到上面的判断，但不会进行运算，直到接收到UNPAUSE指令，退出pause状态。\r\n\r\n工作线程的发出是由CmdCentre(继承于FormView)窗口的“启动”按钮按下在CMainDoc(继承于CDocument类)的响应函数中调用AfxBeginThread(ChildThread,this,THREAD_PRIORITY_IDLE)完成的。\r\n\r\n具体实现可见源代码。");
	dlg.DoModal();
}


void CMainDoc::OnDoc13()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：电梯系统即时指令算法");
	dlg.author=TEXT("由ji最后一次修订");
	dlg.txt=TEXT("本部分由ji和haixin共同维护。\r\n\r\n本部分由三组独立的算法构成，三电梯算法由Ji FAN完成。单电梯算法由Haixin ZHANG完成，另外一个独立的单电梯算法由Xurui GU完成。\r\n\r\n电梯系统即时指令算法函数意在实现利用电梯内、外部指令和电梯运行情况这三个信息来对电梯进行调度。再具体实现中，采用switch-case语句区分电梯的上升、下降、停止三种运行情况，在每一种情况内部则通过if-else语句实现对内外指令的有序响应。调度算法的总体原则是优先响应内指令、优先响应最近楼层指令，同时对于一些特殊指令情形也做了相应的优化。");
	dlg.DoModal();
}


void CMainDoc::OnDoc14()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：电梯条件响应更变算法");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("本部分由haixin编写和负责\r\n\r\n这个算法是写在工作线程中、在ExeNextTick执行下一秒函数的调用之后。\r\n目的是用于在电梯到达和电梯的m_ins(INS_MSG类型)相同的的楼层后，将电梯内的按钮灭，并且将电梯外的按钮熄灭的实现。\r\n\r\n主要的思路如下：\r\n\r\n遍历3台电梯，判断电梯是否有指令，有指令则判断电梯目前的楼层是否是整数且刚好与ElevatorSystem发出的指令的楼层一致。如果一致，就会根据电梯运行状态和到达楼层在ElevatorSystem的外部请求表中将电梯的运行状态置为合适的状态。（由于我们定义UINT类型的ELESYS_TABLE_STATUS，ELESYS_NO代表00B，ELESYS_DOWN代表01B，ELESYS_UP代表10B，ELESYS_UP_AND_DOWN代表11B，一开始想利用他们在内存中存储的二进制形式简化程序流程，但最后图方便我们还是强行枚举了）\r\n\r\n之后同样遍历三台电梯，判断电梯是否有指令，有指令则判断电梯目前的楼层是否是整数且刚好与ElevatorSystem发出的指令的楼层一致，一致就将电梯内部的按钮置为合适的状态（详情定义见文档：参变量定义）\r\n\r\n最后利用相同的方法，在判断得当后，加上开关门以及自动开关门的时间。得益于我们的电梯模拟软件的模型用的是即时指令类，因此不会重复累计这些时间。\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc15()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：电梯指令响应算法");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("本部分由haixin1编写。\r\n\r\n位于Elevator::NextTick()中，用于在ElevatorSystem调用算法后，紧接着就会执行电梯下一tick。实现为当电梯无消息时，会将开关门而附上的等待时间先减掉。如果电梯的收到指令是上升或者下降，就会将电梯的位置“小数”部分减去一个，然后取模进位或者退位，还是一样，如果有等待时间，先减去等待时间。这个算法很简单，问题是要想和上面几个算法配合使用，确实有一定难度。\r\n详情见源代码\r\n");
	dlg.DoModal();
}


void CMainDoc::OnDoc16()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("文档：控件逻辑算法");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("本部分由haixin编写\r\n控件逻辑主要是指按下“启动”后其他控件的启用状态，本部分作为CmdCentre(继承于CFormView)的按钮在Doc类中的响应，采用(pCmd->GetDlgItem(IDC_BUTTONx))->EnableWindow()的方式。由于CmdCentre控件不多且之间的逻辑关系较为简单，本部分不多赘述。\r\n详情见源代码\r\n");
	dlg.DoModal();
}


void CMainDoc::OnLog01()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog02()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog03()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog04()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog05()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog06()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog07()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog08()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog09()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog10()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnLog11()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("日志");
	dlg.author=TEXT("由haixin最后一次修订");
	dlg.txt=TEXT("记不得了，写不动了。");
	dlg.DoModal();
}


void CMainDoc::OnGpl()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("GNU GENERAL PUBLIC LICENSE");
	dlg.author=TEXT("GNU");
	dlg.txt=TEXT("GNU GENERAL PUBLIC LICENSE\r\nVersion 2, June 1991\r\n\r\nCopyright (C) 1989, 1991 Free Software Foundation, Inc.  \r\n\r\nhttp://www.gnu.org/licenses/old-licenses/gpl-2.0.html");
	dlg.DoModal();
}


void CMainDoc::OnOtherLs()
{
	// TODO: 在此添加命令处理程序代码
	CSettingDocBox dlg;
	dlg.title=TEXT("其他附加条约");
	dlg.author=TEXT("Author: haixin");
	dlg.txt=TEXT("本项目首先应用于提交2020级东南大学暑期学校作业，作者为Haixin ZHANG, Ji FAN, Xurui GU, Jincheng GAI。\r\n\r\n在2021年8月后，该项目完全开源并停止更新，其中的代码为团队共同编写，基本上无任何借鉴，具体代码由所写者保持解释权。在2021年8月后，该项目遵守GPL2.0的协议，并且根据本项目任意代码开发的项目均需要开源并保持GPL2.0协议，并保留作者信息。另外，本项目及其衍生开发项目不得用于商业用途。\r\n");
	dlg.DoModal();
}
