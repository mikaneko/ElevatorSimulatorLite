#pragma once
#include "stdafx.h"

class Elevator
{
	//ָ��INS
public:
	INS_MSG m_ins;

	//״̬STATUS
public:
	ELE_DOOR_STATUS m_door_status;
	int now_floor_int;
	int now_floor_point;
	ELE_MOV_STATUS now_direction;

	//״̬STATUS
	int m_maintain_now;
	int m_wait_time;
	ELE_ERR_STATUS m_err_status;

	//�����ڰ�ť���µı��
public:
	ELE_BTN_STATUS m_btn_status[FLOOR_NUMBER];

	//���в���
public:
	int M_tick_per_floor;
	int M_auto_wait_close_time;
	int M_max_maintain;
	double M_open_close_time;
public:
	Elevator();
	~Elevator();
	void NextTick();
};

