
#pragma once
#include "stdafx.h"
#include "SCElevator.h"


class ElevatorSystem
{
public:
	ELESYS_TABLE_STATUS m_request[FLOOR_NUMBER];//Table of outside
	Elevator elev[ELEVATOR_NUMBER];
public:
	ElevatorSystem();
	~ElevatorSystem();
	void UpdateInstruction(ELESYS_ALG);

	void UsingAlg0();
	void UsingAlg1();
	void UsingAlg2();
};

