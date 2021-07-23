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
					AfxMessageBox(CString("ExitMuti"));
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
