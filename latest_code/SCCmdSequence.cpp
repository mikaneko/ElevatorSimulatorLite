#pragma once
#include "SCCmdSequence.h"

//head and tail dont contain message

CmdSequence::CmdSequence():q_head(0),q_tail(1),err_status(SEQ_OK),sto_status(SEQ_EMPTY)
{}


CmdSequence::~CmdSequence()
{}

BOOL CmdSequence::UpdateStatus()
{
	if((q_head+1)%QUEUE_SIZE==q_tail) {sto_status=SEQ_EMPTY;}
	else if((q_tail+1)%QUEUE_SIZE==q_head) {sto_status=SEQ_FULL;}
	else sto_status=SEQ_NORMAL;
	return TRUE;
}

BOOL CmdSequence::ValidateStatus(SEQ_IO _io)
{
	if(SEQ_IN)
	{
		if((q_head+1)%QUEUE_SIZE==q_tail) {err_status=SEQ_OVERFLOW;}
	}
	if(SEQ_OUT)
	{
		if((q_tail+1)%QUEUE_SIZE==q_head) {err_status=SEQ_NOFLOW;}
	}
	return !err_status;
}

SEQ_ERR_STATUS CmdSequence::GetErrStatus()
{
	return err_status;
}

BOOL CmdSequence::SetErrStatus(SEQ_ERR_STATUS _value)
{
	if(_value>2){return FALSE;} //number "2" is the max define SEQ_ERR_STATUS value
	else{
		err_status=_value;
		return TRUE;
	}
}

SEQ_STO_STATUS CmdSequence::GetStoStatus()
{
	return sto_status;
}

BOOL CmdSequence::InQ(CMD_MSG _msg)
{
	if(!ValidateStatus(SEQ_IN)){return FALSE;}
	//CodeStart

	msg[q_tail]=_msg;
	++q_tail;
	q_tail%=QUEUE_SIZE;

	//CodeEnd
	UpdateStatus();
	return TRUE;
}

CMD_MSG CmdSequence::OutQ()
{
	if(!ValidateStatus(SEQ_OUT)){return CMD_MSG(CT_NOMSG);}
	//CodeStart

	
	++q_head;
	q_head%=QUEUE_SIZE;
	CMD_MSG ret=msg[q_head];

	//CodeEnd
	UpdateStatus();
	return ret;
}

BOOL CmdSequence::ClearAndInit()
{
	q_head=0;
	q_tail=1;
	err_status=SEQ_OK;
	sto_status=SEQ_EMPTY;

	UpdateStatus();
	return TRUE;
}
