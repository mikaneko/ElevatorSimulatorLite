
#pragma once
#include "SCElevatorSystem.h"


ElevatorSystem::ElevatorSystem()
{
	for(int i=0;i<FLOOR_NUMBER;i++)
	{
		m_request[i]=ELESYS_NO;
	}

}


ElevatorSystem::~ElevatorSystem()
{

}


void ElevatorSystem::UpdateInstruction(ELESYS_ALG alg_num)
{
	switch(alg_num)
	{
		case ELESYS_ALG0: UsingAlg0();break;
		case ELESYS_ALG1: UsingAlg1();break;
		case ELESYS_ALG2: UsingAlg2();break;
	}
}

void ElevatorSystem::UsingAlg0()
{
	//算法1
	bool btnIn=false;
	bool btnOut=false;
	int temp=8;
	int target=1;
	for(int j=0;j<=2;j++){
		btnIn=false;
		btnOut=false;
		temp=8;
		target=1;
		if(elev[j]. m_err_status!=ELE_ERROR)
		switch(elev[j].now_direction){
			case ELE_WAIT:{
				for(int i=0;i<9;i++){
					if(elev[j]. m_btn_status[i]==ELE_BTN_ON) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
						btnIn=true;
					}
				}
				if(btnIn==true){
					if(target>elev[j]. now_floor_int) elev[j].m_ins=INS_MSG(IT_INS,target,ELE_UP);
					else if(target<elev[j]. now_floor_int) elev[j].m_ins=INS_MSG(IT_INS,target,ELE_DOWN);
					else elev[j].m_ins=INS_MSG(IT_INS,target,ELE_WAIT);
					break;}
				for(int i=0;i<9;i++){
					if( m_request[i]!=ELESYS_NO) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
						btnOut=true;
					}	
				}
				if(btnOut==true){
					if(target>elev[j]. now_floor_int) elev[j].m_ins=INS_MSG(IT_INS,target,ELE_UP);
					else elev[j].m_ins=INS_MSG(IT_INS,target,ELE_DOWN);
					break;}
				else elev[j].m_ins=INS_MSG(IT_NOMSG);
			}break;
			case ELE_UP:{
				for(int i=elev[j].now_floor_int-1;i<9;i++){
					if(elev[j]. m_btn_status[i]==ELE_BTN_ON) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
						btnIn=true;
					}
				}
				for(int i=elev[j].now_floor_int-1;i<9;i++){
					if(m_request[i]==ELESYS_UP|| m_request[i]==ELESYS_UP_AND_DOWN) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
						btnOut=true;
					}	
				}
				if(btnIn==true||btnOut==true) elev[j].m_ins=INS_MSG(IT_INS,target,ELE_UP);
				else if(elev[j].now_floor_point!=0) elev[j].m_ins=INS_MSG(IT_INS,elev[j].now_floor_int+1,ELE_UP);
				else elev[j].m_ins=INS_MSG(IT_NOMSG);
			}break;
			case ELE_DOWN:{
				for(int i=0;i<=elev[j].now_floor_int-1;i++){
					if(elev[j]. m_btn_status[i]==ELE_BTN_ON) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
					btnIn=true;
					}
				}
				for(int i=0;i<=elev[j].now_floor_int-1;i++){
					if( m_request[i]==ELESYS_DOWN||m_request[i]==ELESYS_UP_AND_DOWN) {
						if(abs(i+1-elev[j]. now_floor_int)<=temp){
							temp=abs(i+1-elev[j]. now_floor_int);
							target=i+1;
						}
						btnOut=true;
					}	
				}
				if(btnIn==true||btnOut==true) elev[j].m_ins=INS_MSG(IT_INS,target,ELE_DOWN);
				else if(elev[j].now_floor_point!=0) elev[j].m_ins=INS_MSG(IT_INS,elev[j].now_floor_int,ELE_DOWN);
				else elev[j].m_ins=INS_MSG(IT_NOMSG);
			}break;
		}
	}
}

void ElevatorSystem::UsingAlg1()
{
	//haixin单电梯算法

	//没任何外部请求
	BOOL waitflag = TRUE;
	for (int i = 0; i < 9; ++i) {
		if (m_request[i]==ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_UP || m_request[i] == ELESYS_DOWN) {
			waitflag = FALSE;
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (elev[0].m_btn_status[i] == ELE_BTN_ON)
		{
			waitflag = FALSE;
			break;
		}
	}
	if (waitflag) {
		elev[0].m_ins = INS_MSG(IT_NOMSG);
		return;
	}
	//内部请求刚好在本楼层
	if (elev[0].m_btn_status[elev[0].now_floor_int - 1] == ELE_BTN_ON &&elev[0].now_floor_point==0)
	{
		elev[0].m_ins = INS_MSG(IT_INS, elev[0].now_floor_int, ELE_WAIT);
		return;
	}

	//正常情况

	switch (elev[0].now_direction)
	{
	case ELE_WAIT: {
		//先相应楼上：
		for (int i = elev[0].now_floor_int - 1+1; i < 9; i++) {
			if (elev[0].m_btn_status[i] == ELE_BTN_ON || m_request[i] != ELESYS_NO) {
				elev[0].m_ins = INS_MSG(IT_INS, i+1, ELE_UP);
				return;
			}
		}
		//再相应楼下：
		for (int i = elev[0].now_floor_int; i >= 0; i--) {
			if (elev[0].m_btn_status[i] == ELE_BTN_ON || m_request[i] != ELESYS_NO) {
				elev[0].m_ins = INS_MSG(IT_INS, i + 1, ELE_DOWN);
				return;
			}
		}



		
		break; }
	case ELE_UP: {
		BOOL shouldUp1 = FALSE;
		BOOL shouldUp2 = FALSE;
		int minUp1 = 8;//0-8
		int minUp2 = 8;//0-8
		int upwantdown=0;
		int minUp = 8;//0-8

		//如果向上，且顺路。
		for (int i = elev[0].now_floor_int-1; i < 9; i++) {
			if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_UP) {
				shouldUp1 = 1;
				minUp1 = i;
				break;
			}
		}
		for (int i = elev[0].now_floor_int - 1; i < 9; i++) {
			if (elev[0].m_btn_status[i] == ELE_BTN_ON) {
				shouldUp1 = TRUE;
				minUp2 = i;
				break;
			}
		}
		for (int i = 8; i > elev[0].now_floor_int-1; i--) {////
			if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_DOWN) {
				shouldUp2 = 1;
				upwantdown = i;
				break;
			}
		}
		if (shouldUp1) {   
			minUp = minUp1 > minUp2 ? minUp2 : minUp1;
			elev[0].m_ins= INS_MSG(IT_INS, minUp+1, ELE_UP);
			return;
		}
		if(shouldUp2){
			elev[0].m_ins= INS_MSG(IT_INS, upwantdown+1, ELE_UP);
			return;
		}
		else {
			elev[0].m_ins= INS_MSG(IT_NOMSG);
		}
			
			/*
			//如果不顺路。看看向下顺不顺路
			int BtnTop1=0;//0-8
			int BtnTop2 = 0;//0-8
			int BtnTop = 0;//0-8
			BOOL shouldDown = FALSE;
			for (int i = elev[0].now_floor_int - 1; i >= 0; i--) {
				if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_DOWN) {
					shouldDown = TRUE;
					BtnTop1 = i;
					break;
				}
			}
			for (int i = elev[0].now_floor_int - 1; i >= 0; i--) {
				if (elev[0].m_btn_status[i] == ELE_BTN_ON) {
					shouldDown = TRUE;
					BtnTop2 = i;
					break;
				}
			}
			BtnTop = BtnTop1 > BtnTop2 ? BtnTop1 : BtnTop2;

			if (shouldDown) {
				elev[0].m_ins = INS_MSG(IT_INS, BtnTop + 1, ELE_DOWN);
				return;
			}
			else {//向上也不顺路，向下也不顺路，找楼下向上的最大
				int highrequestup=0; //0-8
				for (int i = elev[0].now_floor_int - 1; i >= 0; i--) {
					if (m_request[i] == ELESYS_UP) {
						highrequestup = i;
						break;
					}
				}
				elev[0].m_ins = INS_MSG(IT_INS, highrequestup + 1, ELE_DOWN);
				return;}*/
		break; }
	case ELE_DOWN: {
		BOOL shouldDown1 = FALSE;
		BOOL shouldDown2 = FALSE;
		int maxDown1 = 0;//0-8
		int maxDown2 = 0;//0-8
		int maxDown = 0;//0-8
		int downwantup=8;
		//如果向下，且顺路。
		for (int i = elev[0].now_floor_int; i >=0; i--) {
			if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_DOWN) {
				shouldDown1 = TRUE;
				maxDown1 = i;
				break;
			}
		}
		for (int i = elev[0].now_floor_int; i >= 0; i--) {
			if (elev[0].m_btn_status[i] == ELE_BTN_ON) {
				shouldDown1 = TRUE;
				maxDown2 = i;
				break;
			}
		}
		for (int i = 0; i <elev[0].now_floor_int-1; i++) {/////////////////
			if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_UP) {
				shouldDown2 = TRUE;
				downwantup = i;
				break;
			}
		}
		if (shouldDown1) {
			maxDown = maxDown1 > maxDown2 ? maxDown1 : maxDown2;
			elev[0].m_ins = INS_MSG(IT_INS, maxDown + 1, ELE_DOWN);
			break;
		}
		if(shouldDown2){
			elev[0].m_ins = INS_MSG(IT_INS, downwantup + 1, ELE_DOWN);
			break;
		}
		else {
			elev[0].m_ins= INS_MSG(IT_NOMSG);
		}
		/*
		{        //如果不顺路。看看向上顺不顺路
			int BtnLow1 = 8;//0-8
			int BtnLow2 = 8;//0-8
			int BtnLow = 8;//0-8
			BOOL shouldUp = FALSE;
			for (int i = elev[0].now_floor_int - 1; i <9; i++) {
				if (m_request[i] == ELESYS_UP_AND_DOWN || m_request[i] == ELESYS_UP) {
					shouldUp = TRUE;
					BtnLow1 = i;
					break;
				}
			}
			for (int i = elev[0].now_floor_int - 1; i < 9; i++) {
				if (elev[0].m_btn_status[i] == ELE_BTN_ON) {
					shouldUp = TRUE;
					BtnLow2 = i;
					break;
				}
			}
			BtnLow = BtnLow1 > BtnLow2 ? BtnLow2 : BtnLow1;

			if (shouldUp) {
				elev[0].m_ins = INS_MSG(IT_INS, BtnLow + 1, ELE_UP);
				return;
			}
			else {//向下也不顺路，向上也不顺路，找楼上向下的最小
				int lowrequestdown = 8; //0-8
				for (int i = elev[0].now_floor_int - 1; i < 9; i++) {
					if (m_request[i] == ELESYS_DOWN) {
						lowrequestdown = i;
						break;
					}
				}
				elev[0].m_ins = INS_MSG(IT_INS, lowrequestdown + 1, ELE_UP);
				return;
			}

		}
		*/
		break; }
	}
 }


void ElevatorSystem::UsingAlg2()
{
	//算法3
}
