
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
	//Ëã·¨1
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
	//Ëã·¨2
	elev[0].m_ins=INS_MSG(IT_INS,8,ELE_UP);
	//AfxMessageBox(CString("haha"));
}

void ElevatorSystem::UsingAlg2()
{
	//Ëã·¨3
}
