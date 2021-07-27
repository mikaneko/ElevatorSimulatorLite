#pragma once
#include "SCElevator.h"

/*
	//ָ��INS
public:
	INS_MSG m_next_ins;
	//״̬STATUS
public:
	ELE_MOV_STATUS m_mov_status;
	ELE_ERR_STATUS m_err_status;
	ELE_DOOR_STATUS m_door_status;
	int now_floor_int;
	int now_floor_point;
	//״̬STATUS
	int m_maintain_now;
	int m_wait_time;
	//�����ڰ�ť���µı��
public:
	ELE_BTN_STATUS m_btn_status[FLOOR_NUMBER];
	//���в���
public:
	int M_sec_per_floor;
	int M_auto_wait_close_time;
	int M_max_maintain;
	double M_open_close_time;
public:
	Elevator();
	~Elevator();
	void NextSecond();
*/


Elevator::Elevator()
{
	m_ins=INS_MSG(IT_NOMSG);
	m_err_status=ELE_OK;
	m_door_status=ELE_DOOR_CLOSE;
	now_floor_int=1;
	now_floor_point=0;
	now_direction=ELE_WAIT;
	m_maintain_now=0;
	m_wait_time=0;
	for(int i=0;i<FLOOR_NUMBER;i++)
	{m_btn_status[i]=ELE_BTN_OFF;}
	M_tick_per_floor=50;
	M_auto_wait_close_time=20;
	M_max_maintain=1000;
	M_open_close_time=10;
}


Elevator::~Elevator()
{
}


void Elevator::NextTick()
{
	if(m_ins.ins_type==IT_NOMSG)
	{
#if DEBUGMODE
AfxMessageBox(CString(TEXT("����ʧȥ��ϵ(ERR04)��")));
#endif
		if(m_wait_time>0){m_wait_time--;}
		now_direction=ELE_WAIT;
		return;
	}
	else if(m_ins.ins_type==IT_INS)
	{
		if(m_ins.ins_exarg1==ELE_WAIT)
		{
			if(m_wait_time>0){m_wait_time--;return;}
			return;
		}
		if(m_wait_time>0)
		{	
#if DEBUGMODE
AfxMessageBox(CString(TEXT("����minus waiting time(DEBUG)��")));
#endif
			m_wait_time--;
			return;
		}
		else if(m_ins.ins_exarg1==ELE_UP)
		{
#if DEBUGMODE
AfxMessageBox(CString(TEXT("����received ELE_UP(DEBUG)��")));
#endif
			now_direction=ELE_UP;
			now_floor_point++;
			if(now_floor_point==M_tick_per_floor){ now_floor_point=0;now_floor_int++;}
		}
		else if(m_ins.ins_exarg1==ELE_DOWN)
		{
#if DEBUGMODE
AfxMessageBox(CString(TEXT("����received ELE_DOWN(DEBUG)��")));
#endif
			now_direction=ELE_DOWN;
			now_floor_point--;
			if(now_floor_point==-1){now_floor_point=M_tick_per_floor-1;now_floor_int--;}
		}
	}
}