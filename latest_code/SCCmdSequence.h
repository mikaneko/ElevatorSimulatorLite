#pragma once
#include "stdafx.h"


class CmdSequence
{
private:
	CMD_MSG msg[QUEUE_SIZE];
	unsigned int q_head;
	unsigned int q_tail;
	SEQ_ERR_STATUS err_status;
	SEQ_STO_STATUS sto_status;
private:
	BOOL ValidateStatus(SEQ_IO);

public:
	CmdSequence();
	~CmdSequence();
	SEQ_ERR_STATUS GetErrStatus();
	BOOL SetErrStatus(SEQ_ERR_STATUS = SEQ_OK);
	SEQ_STO_STATUS GetStoStatus();
	BOOL UpdateStatus();
	BOOL InQ(CMD_MSG _msg);
	CMD_MSG OutQ();
	BOOL ClearAndInit();
};

