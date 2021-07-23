#pragma once
#include "stdafx.h"

class Elevator
{
	//指令INS
public:
	INS_MSG m_ins;

	//状态STATUS
public:
	ELE_DOOR_STATUS m_door_status;
	int now_floor_int;
	int now_floor_point;
	ELE_MOV_STATUS now_direction;

	//状态STATUS
	int m_maintain_now;
	int m_wait_time;
	ELE_ERR_STATUS m_err_status;

	//电梯内按钮按下的表格
public:
	ELE_BTN_STATUS m_btn_status[FLOOR_NUMBER];

	//固有参数
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

