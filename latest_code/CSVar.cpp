#pragma once
#include "CSVar.h"

CMD_MSG::CMD_MSG(CMD_TYPE _v1,CMD_ARG _v2,CMD_ARG _v3,CMD_ARG _v4,CMD_ARG _v5):cmd_type(_v1),cmd_arg(_v2),cmd_exarg1(_v3),cmd_exarg2(_v4),cmd_exarg3(_v5){}

INS_MSG::INS_MSG(INS_TYPE _v1,INS_ARG _v2,INS_ARG _v3,INS_ARG _v4,INS_ARG _v5):ins_type(_v1),ins_arg(_v2),ins_exarg1(_v3),ins_exarg2(_v4),ins_exarg3(_v5){}

