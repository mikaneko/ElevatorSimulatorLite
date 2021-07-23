#define DEBUGMODE 0

/////////////////////////////////////
#define QUEUE_SIZE 4096
#define ELEVATOR_NUMBER 3
#define FLOOR_NUMBER 10
#define EPSILON 10e-1

//CMD_TYPE 's var
#define CT_NOMSG 0
#define CT_ERROR 1
#define CT_WARNING 2
#define CT_TERMINAT 3
#define CT_ABORT 4
#define CT_PAUSE 5
#define CT_UNPAUSE 6
#define CT_MY_SETSPEED 7
#define CT_MY_UNDER_PAUSE_NEXT_SECOND 8
#define CT_MY_ADD_MISSION 10


//The msgType CMD_MSG and its var

typedef unsigned int CMD_TYPE;
typedef unsigned int CMD_ARG;

class CMD_MSG
{
public:
	CMD_MSG(CMD_TYPE=CT_NOMSG,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0,CMD_ARG=0);//Constructor
	CMD_TYPE cmd_type;
	CMD_ARG cmd_arg;
	CMD_ARG cmd_exarg1;
	CMD_ARG cmd_exarg2;
	CMD_ARG cmd_exarg3;
};



//Class "CmdSequence" var definition

typedef unsigned int SEQ_ERR_STATUS;
#define SEQ_OK 0
#define SEQ_OVERFLOW 1
#define SEQ_NOFLOW 2


typedef unsigned int SEQ_STO_STATUS;
#define SEQ_NORMAL 0
#define SEQ_FULL 1
#define SEQ_EMPTY 2


typedef unsigned int SEQ_IO;
#define SEQ_IN 0
#define SEQ_OUT 1


//Class "Elevator" var definition

typedef unsigned int ELE_MOV_STATUS;
#define ELE_RUNNING 0
#define ELE_WAIT 1
#define ELE_UP 2
#define ELE_DOWN 3

typedef unsigned int ELE_ERR_STATUS;
#define ELE_OK 0
#define ELE_ERROR 1

typedef unsigned int ELE_DOOR_STATUS;
#define ELE_DOOR_OPEN 0
#define ELE_DOOR_CLOSE 1

typedef unsigned int ELE_BTN_STATUS;
#define ELE_BTN_OFF 0
#define ELE_BTN_ON 1

//Class "ElevatorSystem" var definition
typedef unsigned int ELESYS_TABLE_STATUS;
#define ELESYS_NO 0
#define ELESYS_DOWN 1
#define ELESYS_UP 2
#define ELESYS_UP_AND_DOWN 3

typedef unsigned int ELESYS_ALG;
#define ELESYS_ALG0 0
#define ELESYS_ALG1 1
#define ELESYS_ALG2 2

//INS_TYPE 's var
#define IT_NOMSG 0
#define IT_INS 1

//The msgType INS_MSG and its var
typedef unsigned int INS_TYPE;
typedef unsigned int INS_ARG;

class INS_MSG
{
public:
	INS_MSG(INS_TYPE=IT_NOMSG,INS_ARG=0,INS_ARG=0,INS_ARG=0,INS_ARG=0);//Constructor
	INS_TYPE ins_type;
	INS_ARG ins_arg;
	INS_ARG ins_exarg1;
	INS_ARG ins_exarg2;
	INS_ARG ins_exarg3;
};
