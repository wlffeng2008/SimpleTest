/****************************************************************************************************
*  SolidTech Motion Library									    									*
*  Copyright (C) 2022 Shenzhen Solid Technology Co.,Ltd			            						*
*																									*
*																									*
*  @file     E450lib.h																				*
*  @brief    defs of struct and function															*
*																									*
*																									*
*  @version  20241014(版本号)																		*
*  @date     2024.10.14																				*
*																									*
*																									*
****************************************************************************************************/



/***************************************************************************************************
*			函数返回值及其含义
***************************************************************************************************/
/*数据结构*/
#define SLDM_ERR_OK				  	0				/*无错误*/
#define SLDM_ERR_PMVAL				-1				/*参数值错误*/
#define SLDM_ERR_PULSEOVERFLOW		-2				/*脉冲发生器溢出*/
#define SLDM_ERR_PMID				-3		 		/*参数ID不存在，无此参数*/
#define SLDM_ERR_MCMAX				-4				/*控制器不存在，超出系统支持的最大控制器索引号*/
#define SLDM_ERR_CHMAX				-5				/*通道号不存在，超出系统最大通道数*/
#define SLDM_ERR_AXISMAX			-6				/*轴号不存在，超出系统最大轴数*/
#define SLDM_ERR_NOAUTH				-7				/*控制器无授权*/
#define SLDM_ERR_ADDROVERFLOW		-8				/*参数地址溢出*/
#define SLDM_ERR_NOFLAG				-9				/*没有此状态或标志*/
#define SLDM_ERR_NONSTOPPED			-10				/*运动没有停止*/
#define SLDM_ERR_MCNOFILE			-11				/*文件号打开失败。文件号不存在，或SD卡不存在。*/
#define SLDM_ERR_HOSTNOFILE			-12				/*HOST打开文件失败*/
#define SLDM_ERR_AXISALM			-13				/*轴伺服报警*/
#define SLDM_ERR_AXISPOT			-14				/*轴正向硬限位*/
#define SLDM_ERR_AXISNOT			-15				/*轴负向硬限位*/
#define SLDM_ERR_AXISPSL			-16				/*轴正向软限位*/
#define SLDM_ERR_AXISNSL			-17				/*轴负向软限位*/
#define SLDM_ERR_AXISESTOP			-18				/*硬急停*/
#define SLDM_ERR_AXISOT				-19				/*轴硬限位*/
#define SLDM_ERR_AXISSL				-20				/*轴软限位*/
#define SLDM_ERR_PARANUM         	-25				/*函数参数个数错误*/

#define SLDM_ERR_CURRENTPOS			-30				/*脉冲位置与插补位置误差过大*/
#define SLDM_ERR_ARCRADIUS			-32				/*圆弧半径误差过大*/
#define SLDM_ERR_ENDPOS             -33				/*终点位置错误*/
#define SLDM_ERR_INDEXMAX           -34				/*参数索引号错误，超出最大索引号*/
#define SLDM_ERR_ADDRMAX			-35				/*参数地址号错误，超出最大地址号*/
#define SLDM_ERR_FUNCTIONEN			-36				/*模式功能没有使能或初始化*/
#define SLDM_ERR_BUFFENABLE			-37				/*缓冲区禁止操作*/
#define SLDM_ERR_BUFFMAX			-39				/*超过最大缓冲区容量*/
#define SLDM_ERR_SPITIMEOVER		-40				/*spi通讯超时*/
#define SLDM_ERR_SPISYSTICKS		-41				/*spi心跳错误*/

#define PULSE_NUM_LESS_1            -57				/*脉冲个数小于1*/
#define PULSE_PERIOD_LESS_1         -58				/*脉冲周期小于1*/
#define OVERPPOS                    -59				/*正向位置溢出*/
#define OVERNPOS                    -60				/*负向位置溢出*/
#define PT_PLAN_OUT                 -61				/*PT运动数字输出错误*/
#define HOMEING_MOVE                -62				/*回零中，反向限位报警*/
#define BLOCK_EDGE_OUT              -63				/*缓冲区运动数字输出错误*/
#define BLOCK_EDGE_PTP1             -64				/*缓冲区运动直线插补错误*/
#define BLOCK_EDGE_ARC              -65				/*缓冲区运动圆弧插补错误*/
#define BLOCK_EDGE_RESTARTMOVE      -66				/*缓冲区运动启动函数错误*/
#define BLOCK_ADD_POS               -67				/*缓冲区运动合成距离为0错误*/

#define SLDM_ERR_OPEN            	-90				/*控制卡打开失败*/
#define SLDM_ERR_OPENED           	-91				/*控制卡已经打开*/
#define SLDM_ERR_FREE           	-92				/*函数直接退出*/
#define SLDM_ERR_IO_OVERTIME		-93				/*控制器IO通讯超时*/
#define SLDM_ERR_PC_IPADDR			-99				/*PC IP地址错误,或未连接*/

#define SLDM_ERR_FPGA_CMDBUFFFULL   -100			/*FPGA指令缓冲区满*/
#define SLDM_ERR_COM_ADDR			-101			/*与HOST通讯的设备地址错误*/
#define SLDM_ERR_COM_CHECKSUM		-102			/*与HOST通讯的校验和错误*/
#define SLDM_ERR_COM_INVCMD			-103			/*与HOST通讯的命令ID错误*/
#define SLDM_ERR_SOCKET				-104			/*HOST库中，SOCKET初始化失败*/
#define SLDM_ERR_SHM				-105			/*HOST库中，SHM初始化失败*/
#define SLDM_ERR_PIPE				-106			/*HOST库中，PIPE初始化失败*/
#define SLDM_ERR_NOLIBINITD			-107			/*HOST库没有初始化*/
#define SLDM_ERR_NOMCOPEN			-108			/*控制器未打开,或控制器关闭失败*/
#define SLDM_ERR_MCOPEND			-109			/*HOST库中，控制器已打开*/
#define SLDM_ERR_MC_NONCONNECT		-110			/*HOST与控制器通讯超时，未连接*/
#define SLDM_ERR_MC_CONNECTING		-111			/*HOST与控制器正在连接*/
#define SLDM_ERR_THREAD				-112			/*HOST库中，线程初始化失败*/
#define SLDM_ERR_BUFFIDX			-113			/*命令缓冲区索引号错误*/
#define SLDM_ERR_REFMESSAGE			-114			/*收到错误报文*/
#define SLDM_ERR_PREBUFFFULL        -115            /*标准命令块的预缓冲区满*/
#define SLDM_ERR_BUFFFULL			-116			/*标准命令块缓冲区满*/

#define SLDM_ERR_FB_TIMEOUT			-121			/*伺服现场总线超时*/
#define SLDM_ERR_FB_NCYCWNG			-122			/*伺服总线中非周期命令执行报警*/
#define SLDM_ERR_FB_CCYCERR			-123			/*伺服总线中非周期命令执行错误*/

#define SLDM_ERR_SERVICE_STOP		-230			/*控制器服务程序停止*/
#define SLDM_ERR_UPDATE				-255			/*内部使用，更新命令*/

//@Begin 返回错误ID的函数名称 编码
#define SLDM_OPEN_CODE								0X01	//1
#define	SLDM_CLOSE_CODE								0X02	//2
#define	SLDM_SET_IP									0X03	//3
#define	SLDM_WRITE_TOUART							0X04	//4
#define	SLDM_READ_FROMUART							0x05	//5
#define	SLDM_E2PROM_WRITE_CODE						0X06	//6
#define	SLDM_E2PROM_READ_CODE						0X07	//7
#define	SLDM_WRITE_REGCODE_CODE						0X08	//8
#define	SLDM_READ_REGCODE_CODE						0X09	//9
#define	SLDM_EXE2PROM_WRITE_CODE					0X0A	//10
#define	SLDM_EXE2PROM_READ_CODE						0X0B	//11
#define	SLDM_FLASH_WRITE_CODE						0X0C	//12
#define	SLDM_ERASE_NEWAPP							0X0D	//13
#define SLDM_SET_COMM_PERIOD						0X0E	//14
#define	SLDM_SET_DEBUG_MODE_CODE					0X0F	//15

#define	SLDM_SET_DIR_POL_CODE						0X10	//16
#define	SLDM_SET_ENC_POL_CODE						0X11	//17
#define	SLDM_SET_CPOS_CODE							0X12	//18
#define	SLDM_SET_ENC_ENABLE							0X13	//19
#define	SLDM_SET_ENC_CODE							0X14	//20
#define SLDM_SET_FPGA_REGISTER						0X15	//21
#define	SLDM_SET_SERVOON_POL						0X1A	//26
#define	SLDM_SET_SERVOON_CODE						0X1B	//27
#define	SLDM_SET_RSTALM_POL							0X1C	//28
#define	SLDM_SET_RSTALM_CODE						0X1D	//29
#define	SLDM_UART_TRANS_ENABLE						0x1F	//31
 
#define	SLDM_SET_PLIMIT_CONFIG_CODE					0X20	//32
#define	SLDM_SET_NLIMIT_CONFIG_CODE					0X21	//33
#define	SLDM_SET_ORG_CONFIG_CODE					0X22	//34
#define	SLDM_SET_SERVOALM_CONFIG_CODE				0X23	//35
#define	SLDM_SET_SOFT_LIMIT_CODE					0X24	//36
#define	SLDM_RESET_CODE								0X2E	//46
#define	SLDM_CLEAR_ALARM_HISTORY_CODE				0X30	//48
#define	SLDM_SET_ENCZ_POL_CODE						0X32	//50
#define	SLDM_SET_EMG_CONFIG_CODE					0X33	//51
#define	SLDM_SET_PULSE_MODE_CODE					0X35	//53
#define	SLDM_SET_PULSE_POL_CODE						0X36	//54
#define	SLDM_SET_ENC_FILTER_CODE					0X37	//55
#define	SLDM_SET_DI_FILTER_CODE						0x7B	//56  
#define	SLDM_SET_SPEC_INPUT_FILTER_CODE				0X39	//57
#define	SLDM_SET_AXIS_INPUT_FILTER_CODE				0X3A	//58

#define	SLDM_PTPN_GROUP								0x3E	//62
#define	SLDM_PTPN_STOP_GROUP						0x3F	//63

#define SLDM_SET_AD_CONFIG							0X40	//64

#define	SLDM_SET_HOME_PARA_CODE						0X50	//80
#define	SLDM_JOGA_CODE								0X51	//81
#define	SLDM_PTP1_CODE								0X52	//82
#define	SLDM_PTP1R_CODE								0X53	//83
#define	SLDM_JOGP_CODE								0X54	//84
#define	SLDM_JOGM_CODE								0X55	//85
#define	SLDM_SET_HOME_OFT_CODE						0X56	//86
#define	SLDM_PTP1_IMM								0X57	//87
#define	SLDM_STOP_CODE								0X58	//88
#define	SLDM_ESTOP_CODE								0X59	//89
#define	SLDM_CHANGE_POS_CODE						0X5A	//90
#define	SLDM_CHANGE_VEL_CODE						0X5B	//91
#define	SLDM_PTPN_CODE								0X5C	//92
#define	SLDM_PTPN_STOP_CODE							0X5D	//93
#define	SLDM_PMOVE_EXTERN_CODE						0X5E	//94
#define	SLDM_HOME_MOVE_CODE							0X5F	//95

#define	SLDM_SET_BUFF_ENABLE_CODE					0X60	//96
#define	SLDM_START_BUFF_MOVE_CODE					0X61	//97
#define	SLDM_ADD_BUFF_SEGMENT_CODE					0X62	//98
#define	SLDM_RESET_BUFF_SEGMENT_P_CODE				0X67	//103
#define	SLDM_SET_BUFF_MOVE_CURENT_P_CODE			0X68	//104
#define	SLDM_STOP_BUFF_MOVE_CODE					0X69	//105
#define	SLDM_SET_BUFF_MOVE_SINGLE_STEP_CODE			0X6A	//106
#define	SLDM_RESET_BUFF_MOVE_CODE					0X6B	//107
#define	SLDM_SETBUFFLOOP_CODE						0X6D	//109
#define	SLDM_BUFF_WAIT_INPUT_CODE					0X6E	//110

#define SLDM_TOGGLE_OUTBIT							0X70	//112
#define	SLDM_SETOUTBIT_CODE							0X73	//115
#define	SLDM_SETOUTBYTE_CODE						0X76	//118
#define	SLDM_SETOUTWORD								0X7C	//124
#define	SLDM_SETOUTDWORD							0X7D	//125
#define	SLDM_IO_TRIGGER								0x7E	//126
#define	SLDM_REVERSE_OUTBIT							0X7F	//127


#define	SLDM_ARC_2D_CODE							0X80	//128
#define	SLDM_ARC_RADIUS_CODE						0X81	//129
#define	SLDM_ARC_STOP_CODE							0X82	//130
#define	SLDM_ADD_MIX_SEGMENT_CODE					0X83	//131
#define	SLDM_ADD_MIX_SEG_CODE						0X84	//132
#define	SLDM_BUFF_DELAY_OUTBIT_TO_START_CODE		0X85	//133
#define	SLDM_BUFF_DELAY_OUTBIT_TO_STOP_CODE			0X86	//134
#define	SLDM_BUFF_AHEAD_OUTBIT_TO_STOP_CODE			0X87	//135
#define	SLDM_BUFF_CLEAR_IO_ACTION_CODE				0X88	//136
#define	SLDM_ARC_3POINTS_CODE						0X8A	//138
#define	SLDM_SET_GEAR_FOLLOW_CODE					0X8B	//139
#define	SLDM_ARC_2DEX_CODE							0X8C	//140

#define	SLDM_PTPN_PLUS_CODE							0X8E	//142
#define	SLDM_PTPN_STOP_PLUS_CODE					0X8F	//143

#define	SLDM_CMPR_ENABLE_CODE						0X90	//144
#define	SLDM_CMPR_ADD_POINT_CODE					0X91	//145
#define	SLDM_CLEAR_CMPR_CODE						0X93	//147
#define	SLDM_START_CMPR_CODE						0X94	//148
#define	SLDM_COMPARELINEAR_CODE						0X96	//150
#define	SLDM_CMPR_MOD_CODE							0X97	//151
#define	SLDM_CMPR_2D_CODE							0X98	//152
#define	SLDM_START_LATCH_CODE						0X99	//153
#define	SLDM_SET_LATCH_PARA_CODE					0X9A	//154
#define	SLDM_CLEAR_LATCH_FIFO_CODE					0X9C	//156
#define	SLDM_CMPR_3D_CODE							0X9F	//159

#define	SLDM_PTINIT_CODE							0XA0	//160
#define	SLDM_PRFPT_CODE								0XA1	//161
#define	SLDM_PTSTART_CODE							0XA3	//163
#define	SLDM_PTDATA_CODE							0XA4	//164
#define	SLDM_PTCLEAR_CODE							0XA5	//165
#define	SLDM_SETPTLOOP_CODE							0XA6	//166
#define	SLDM_SETPTMEMORY_CODE						0XAB	//171

#define	SLDM_SET_PWM_ENABLE_CODE					0XB0	//176
#define	SLDM_PWM_START_CODE							0XB1	//177
#define	SLDM_SET_PWM_CONFIG_CODE					0XB2	//178
#define	SLDM_BUFF_SET_PWM_OUTPUT					0XB4	//180
#define	SLDM_BUFF_SET_PWM_ONOFF_DUTY				0XB5	//181
#define	SLDM_BUFF_SET_PWM_FOLLOW_SPEED				0XB6	//182
#define	SLDM_BUFF_DELAY_PWM_TO_START				0XB7	//183
#define	SLDM_BUFF_AHEAD_PWM_TO_STOP					0XB8	//184

#define	SLDM_SET_HANDWHEEL_CONFIG					0XBD	//189
#define	SLDM_SET_HANDWHEEL_MAXVEL					0XBE	//190
#define	SLDM_SET_HANDWHEEL_ENABLE					0XBF	//191

#define	SLDM_SET_ECAT_AXIS							0XC0	//192
#define	SLDM_ECAT_RESET								0XC1	//193

#define	SLDM_START_BUFF2_MOVE						0XD0	//208
#define	SLDM_SET_BUFF2_ENABLE						0XD1	//209
#define	SLDM_ADD_BUFF2_SEGMENT						0XD2	//210
#define	SLDM_ADD_BUFF2_SEG_SMOOTH					0XD3	//211
#define	SLDM_RESET_BUFF2_MOVE						0XD4	//212
#define	SLDM_STOP_BUFF2_MOVE						0XD5	//213
#define	SLDM_SET_BUFF2_LOOP							0XD6	//214
#define	SLDM_SET_BUFF2_MOVE_SINGLE_STEP				0XD7	//215

#define	SLDM_BUFF2_WAIT_INPUT						0XD9	//217
#define	SLDM_BUFF2_DELAY_OUTBIT_TO_START			0XDA	//218
#define	SLDM_BUFF2_DELAY_OUTBIT_TO_STOP				0XDB	//219
#define	SLDM_BUFF2_AHEAD_OUTBIT_TO_STOP				0XDC	//220
#define	SLDM_BUFF2_CLEAR_IO_ACTION					0XDD	//221
#define	SLDM_BUFF2_DELAY							0XDE	//222

#define	SLDM_TEST_FUNCTION_CODE						0XFF	//255
//@End 返回错误ID的函数名称 编码


//@Begin PT运动模式
#define PT_MODE_STATIC              0//（该宏定义为 0）静态模式。默认为该模式。
#define PT_MODE_DYNAMIC             1//（该宏定义为 1）动态模式
#define PT_SEGMENT_NORMAL           0//（该宏定义为 0）普通段。默认为该类型。
#define PT_SEGMENT_EVEN             1//（该宏定义为 1）匀速段。
#define PT_SEGMENT_STOP             2//（该宏定义为 2）减速到 0 段。
#define PT_SEGMENT_END              3// 自定义结束标志
//@End PT运动模式

#define MAX_ALM_BUFFER_NUM          256



typedef struct 
{
	unsigned int Card_ID;			//控制器产品序列号
	unsigned int Lib_SoftVer;		//软件库版本号
	unsigned int Arm_SoftVer;		//Arm软件版本号
	unsigned int Arm_GitCommit;		//Arm软件 Git号
	unsigned int FPGA_SoftVer;		//FPGA软件版本号
	unsigned int FPGA_GitCommit;	//FPGA软件 Git号
	unsigned int FPGA_UID[4];		//FPGA产品序列号
	unsigned int Arm_UID[3];		//Arm产品序列号
	unsigned int PCB_Ver;			//PCB版本号
	unsigned int PCB_GitCommit;		//PCB版本Git号
	unsigned int BOM_Ver;			//BOM版本号
	unsigned int BOM_GitCommit;		//BOM版本Git号
}CARD_INFO; 

typedef struct						//读回轴设置参数
{
	bool servo_alarm_en;			//伺服报警使能
	bool Plimit_en;					//正限位报警使能
	bool Nlimit_en;					//负限位报警使能
	bool origin_en;					//原点信号使能

	bool servo_alarm_pol;			//伺服报警输入信号极性
	bool Plimit_pol;				//正限位输入信号极性
	bool Nlimit_pol;				//负限位输入信号极性
	bool origin_pol;				//原点输入信号极性

	bool Dir_pol;					//脉冲方向信号极性
	bool Enc_pol;					//编码器输入信号计数方向极性
	bool Encz_pol;					//编码器输入Z信号极性

	bool soft_Plimit_en;			//正软限位使能
	bool soft_Nlimit_en;			//负软限位使能
	bool pulse_Pol;					//脉冲信号极性
	unsigned char pulse_Mode;		//脉冲模式
	
	int soft_Plimit_pos;			//正软限位位置
	int soft_Nlimit_pos;			//负软限位位置
	int home_oft_pos;				//回零偏置位置
	int i_zcap_pulse;				//Etheat控制器z信号锁存位置
}Axis_Para;						


typedef struct						//读回轴状态
{
	bool servo_alarm_vol;			//伺服报警信号导通状态
	bool Plimit_vol;				//正限位报警信号导通状态
	bool Nlimit_vol;				//负限位报警信号导通状态
	bool origin_vol;				//原点信号导通状态
	bool Encz_vol;					//编码器输入Z信号电平状态
	bool reached_vol;				//到位信号导通状态
	bool servon;					//伺服使能信号导通状态
	bool resalm;					//伺服报警清除信号导通状态

	bool servo_alarm_valid;			//伺服报警信号有效状态
	bool Plimit_valid;				//正限位报警信号有效状态
	bool Nlimit_valid;				//负限位报警信号有效状态
	bool origin_valid;				//原点信号有效状态
	bool Encz_valid;				//编码器输入Z信号有效状态
	bool reached_valid;				//到位信号有效状态
	bool soft_Plimit_valid;			//正软限位报警有效状态
	bool soft_Nlimit_valid;			//负软限位报警有效状态

	bool homing;					//回零中有效状态
	bool homed;						//回零完成有效状态
	bool running;					//运动中有效状态

	unsigned char alarm_status;		//0x01正限位，0x02负限位，0x04 soft_plimit,0x08 soft_nlimit,0x10伺服报警
	char home_flag;					//回零过程标志状态

}Axis_Status; 

typedef struct
{
	int alarm_number[MAX_ALM_BUFFER_NUM];	//历史报警号
	int alarm_para[MAX_ALM_BUFFER_NUM];		//历史报警参数
	int time_tick[MAX_ALM_BUFFER_NUM];		//历史报警次数
}Alarm_History;

typedef struct 
{
	short axis_count;				//3,固定3轴
	unsigned long  axis_list[4];	//当前指令最多可以对3个轴进行操作;

	long target_pos[4];				//最终目标位置，绝对坐标
	long start_pos[4];				//起点位置，绝对坐标

	short soft_en[2];				//是否启用软启动和软着陆标志，soft_en[0]-软启动,soft_en[0]-软着陆。
	long soft_upZPos;				//抬起过程中，软启动Z轴位置数据
	long soft_downZPos;				//下降过程中，软着陆Z轴位置数据
	float soft_upVel;				//抬起过程中，软启动终点速度
	float soft_downVel;				//下降过程中，软着陆终点速度

	long z_sofePos;					//Z轴在下降和抬起过程中，安全位置
	long z_steadyPos;				//Z轴横移高度
	
	float start_vel;				//整个门运动的起始速度
	float end_vel;					//整个门运动的终点速度
	float steady_vel;				//整个门运动的最大速度
	float move_acc;					//运动过程中的加速度，pulse/ms^2
	float move_dec;					//运动过程中的加速度，pulse/ms^2

}Jump_Data;

typedef struct
{
	unsigned int Voltage_Range;		//ADC输入电压范围,0x0:±10V,0x1:±5V,0x2:±12.5V,0x3:±2.5V;
	unsigned int Oversampling_Rate;	//采样次数（过采样率），范围：0、2、4、8.....64 
	unsigned int Mode;				//工作模式，0：编码器触发，1：测试模式，固定频率采样，基于Sampling_Period设置
	unsigned int Enc_trigger_Mult;	//编码器采样倍率，如下：0x0:1倍频；0x1:2倍频；0x2:4倍频；编码器触发倍率，范围：1，2，4，（工作模式0有效）
	unsigned int Enc_Dir;			//编码器触发的采样方向，范围：0：正方向，1：负方向（工作模式0有效）
	unsigned int Sampling_Period;	//采样周期,单位us，范围：1-10000000（工作模式1有效）
	unsigned int Sampling_Time;		//采样时间,单位us，范围：1-10000000（工作模式1有效）
}DAQ_TASK_PARA;

typedef struct
{
	//	unsigned char en;				//[0]:采样使能，1：使能，0：不使能；
	unsigned char flag;					//[0]:采样状态指示寄存器，1：采样中，0：采样结束；
	unsigned char Voltage_Range;		//[2:1]:ADC输入电压范围,0x0:±10V,0x1:±5V,0x2:12.5V,0x3:2.5V;
	unsigned char Mode;					//[4:3]:采样触发模式，如下：0x0:编码器触发采样，0x1:时间触发采样,测试模式，固定频率采样，基于Sampling_Period设置
	unsigned char Enc_trigger_Mult;		//[6:5]:编码器采样倍率，如下：0x0:1倍频；0x1:2倍频；0x2:4倍频；（工作模式0有效）
	unsigned char Enc_Dir;				//[7]:编码器采样方向,0:正向采样；1：负向采样；（工作模式0有效）
	unsigned char Oversampling_Rate;	//[3:0]:过采样率,[7:4]:保留；
	short adc_data;						//16位，ADC实时采样的值，也即是当前采样得到的ADC值；
	unsigned short data_num;			//16位，在报文中加载的ADC采样数组数，最大值237组。
	unsigned char Reserved_Part[4];		//32位，预留数据段。
	int check_code;						//校验码

}DAQ_RECV_PARA;

typedef struct
{
	unsigned int data_no;						//回调编号
	int data_p;									//数据指针
	int Enc_Data[MAX_DAQMEMSIZE];				//编码器计数
	float AD_data[MAX_DAQMEMSIZE];				//模拟量采集数据
}DAQ_Sampling_Data;


/**********************************************************************************
* @Begin E450
***********************************************************************************/
SLDM_API SLDM_Set_Card_List(unsigned long IP_4,unsigned long card_num,unsigned long *type);
SLDM_API SLDM_Get_Card_List(unsigned long IP_4,unsigned long *card_num,unsigned long *type);
SLDM_API SLDM_Set_Card_List_IP(unsigned long card_num,unsigned long *type);
SLDM_API SLDM_Get_Card_List_IP(unsigned long PC_IP_1,unsigned long PC_IP_2,unsigned long PC_IP_3,unsigned long PC_IP_4,unsigned long Card_IP_4,unsigned long *card_num,unsigned long *type);

/**********************************************************************************
* @End E450
***********************************************************************************/

/***************************************************************************************************
*		函数接口
***************************************************************************************************/

/**********************************************************************************
* @Begin 控制器操作
***********************************************************************************/
SLDM_API SLDM_Open(unsigned long IP_4,unsigned long type = 0);
SLDM_API SLDM_Open_IP(unsigned long PC_IP_1, unsigned long PC_IP_2, unsigned long PC_IP_3, unsigned long PC_IP_4, unsigned long Card_IP_4, unsigned long type = 0);
SLDM_API SLDM_Close(unsigned long card_no);
SLDM_API SLDM_Set_IP(unsigned long card_no,unsigned long IP_1=192,unsigned long IP_2=168,unsigned long IP_3=100,unsigned long IP_4=1);
SLDM_API SLDM_Set_Debug_Mode(unsigned long card_no,unsigned long mode);
SLDM_API SLDM_Set_Comm_Period(unsigned long card_no,unsigned long period);//0us-10000us
SLDM_API SLDM_Get_SysTicks(unsigned long card_no,unsigned long * ticks);	
SLDM_API SLDM_Get_ConnStatus(unsigned long card_no, long * status);
/**********************************************************************************
* @End 控制器操作
***********************************************************************************/

/**********************************************************************************
* @Begin 轴参数、状态读写
***********************************************************************************/
SLDM_API SLDM_Set_Pulse_Mode(unsigned long card_no,unsigned long axis,unsigned long mode);
SLDM_API SLDM_Set_Pulse_Pol(unsigned long card_no,unsigned long axis,unsigned long pol);
SLDM_API SLDM_Set_Dir_Pol(unsigned long card_no,unsigned long axis,unsigned long pol);
SLDM_API SLDM_Set_Enc_Pol(unsigned long card_no,unsigned long axis,unsigned long pol);
SLDM_API SLDM_Set_Enc_Enable(unsigned long card_no,unsigned long axis,unsigned long en);
SLDM_API SLDM_Set_Enc_Mult(unsigned long card_no,unsigned long axis,unsigned long mult);
SLDM_API SLDM_Set_Cpos(unsigned long card_no,unsigned long axis,long pos);
SLDM_API SLDM_Get_Pos(unsigned long card_no,unsigned long axis,long *pos);
SLDM_API SLDM_Set_Enc(unsigned long card_no,unsigned long axis,long pos);
SLDM_API SLDM_Get_Enc(unsigned long card_no,unsigned long axis,long *pos);
SLDM_API SLDM_Set_EncZ_Pol(unsigned long card_no,unsigned long axis,unsigned long pol);
SLDM_API SLDM_Get_Enc_Z(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Set_EMG_Config(unsigned long card_no,unsigned long en,unsigned long pol);
SLDM_API SLDM_Get_EMG_Config(unsigned long card_no,unsigned long *en,unsigned long *pol);
SLDM_API SLDM_Get_EMG(unsigned long card_no,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Set_ServoOn_Pol(unsigned long card_no, unsigned long axis, unsigned long pol);
SLDM_API SLDM_Set_ServoOn(unsigned long card_no,unsigned long axis,unsigned long on);
SLDM_API SLDM_Get_ServoOn(unsigned long card_no,unsigned long axis,unsigned long *on);
SLDM_API SLDM_Set_RstAlm_Pol(unsigned long card_no, unsigned long axis, unsigned long pol);
SLDM_API SLDM_Set_RstAlm(unsigned long card_no,unsigned long axis,unsigned long on);
SLDM_API SLDM_Get_RstAlm(unsigned long card_no,unsigned long axis,unsigned long *on);
SLDM_API SLDM_Set_Plimit_Config(unsigned long card_no,unsigned long axis,unsigned long en,unsigned long pol);
SLDM_API SLDM_Get_Plimit_Config(unsigned long card_no,unsigned long axis,unsigned long *en,unsigned long *pol);
SLDM_API SLDM_Get_POT(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Set_Nlimit_Config(unsigned long card_no,unsigned long axis,unsigned long en,unsigned long pol);
SLDM_API SLDM_Get_Nlimit_Config(unsigned long card_no,unsigned long axis,unsigned long *en,unsigned long *pol);
SLDM_API SLDM_Get_NOT(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Set_Org_Config(unsigned long card_no,unsigned long axis,unsigned long en,unsigned long pol);
SLDM_API SLDM_Get_Org_Config(unsigned long card_no,unsigned long axis,unsigned long *en,unsigned long *pol);
SLDM_API SLDM_Get_Org(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Set_ServoAlm_Config(unsigned long card_no,unsigned long axis,unsigned long en,unsigned long pol);
SLDM_API SLDM_Get_ServoAlm_Config(unsigned long card_no,unsigned long axis,unsigned long *en,unsigned long *pol);
SLDM_API SLDM_Get_Servo_Alarm(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Get_AxisPol_Config(unsigned long card_no,unsigned long axis,unsigned long *Dir_pol,unsigned long *Pulse_Pol,unsigned long *Enc_pol,unsigned long *Encz_pol);
SLDM_API SLDM_Get_Axis_Para(unsigned long card_no,unsigned long axis,Axis_Para *p_axispara);
SLDM_API SLDM_Set_Enc_Filter(unsigned long card_no,unsigned long axis,float filter_time);
SLDM_API SLDM_Set_DI_Filter(unsigned long card_no,unsigned long input_bit,float filter_time);
SLDM_API SLDM_Set_Spec_Input_Filter(unsigned long card_no,unsigned long axis,float filter_time);
SLDM_API SLDM_Set_Axis_Input_Filter(unsigned long card_no,unsigned long axis,float filter_time);
SLDM_API SLDM_Get_PosT(unsigned long card_no,unsigned long axis, long *pos);
SLDM_API SLDM_Get_PosA(unsigned long card_no,unsigned long axis,long *pos);
SLDM_API SLDM_Get_Vel(unsigned long card_no,unsigned long axis,float *vel);
SLDM_API SLDM_Get_ExVel(unsigned long card_no,float *line_vel,float *arc_vel);
SLDM_API SLDM_Get_Axis_Status(unsigned long card_no,unsigned long axis,Axis_Status *p_axissatus);
SLDM_API SLDM_Get_Reached(unsigned long card_no,unsigned long axis,unsigned long *valid,unsigned long *el);
SLDM_API SLDM_Get_Running(unsigned long card_no,unsigned long axis,unsigned long *running);
SLDM_API SLDM_Reset(unsigned long card_no,unsigned long axis);
SLDM_API SLDM_Get_Axis_AlmStatus(unsigned long card_no,unsigned long axis,unsigned long  *p_almstatus);
SLDM_API SLDM_Get_Alarm_History(unsigned long card_no,Alarm_History *p_alarmhistory);
SLDM_API SLDM_Clear_Alarm_History(unsigned long card_no);
SLDM_API SLDM_Get_AlarmHistory(unsigned long card_no,int *p_Alarm_number,int *p_Alarm_para,int *p_time_tick);
SLDM_API SLDM_Get_Move_Error(unsigned long card_no,long *err);

/**********************************************************************************
* @End 轴参数、状态读写
***********************************************************************************/

/**********************************************************************************
* @Begin 回零
***********************************************************************************/
SLDM_API SLDM_Set_Home_Oft(unsigned long card_no,unsigned long axis,long pos);
SLDM_API SLDM_Set_Soft_Limit(unsigned long card_no,unsigned long axis,unsigned long en,long p_pos,long n_pos);
SLDM_API SLDM_Get_Soft_Limit(unsigned long card_no,unsigned long axis,unsigned long *en,long *p_pos,long *n_pos);
SLDM_API SLDM_Set_Home_Para(unsigned long card_no,unsigned long axis,unsigned long h_dir,float low_vel,float high_vel,float acc,unsigned long mode,unsigned long enc_en);
SLDM_API SLDM_Home_Move(unsigned long card_no,unsigned long  axis);
SLDM_API SLDM_Get_Homing(unsigned long card_no,unsigned long axis,unsigned long *homing,unsigned long *homed);
/**********************************************************************************
* @End  回零
***********************************************************************************/

/**********************************************************************************
* @Begin 单轴运动
***********************************************************************************/
SLDM_API SLDM_JogA(unsigned long card_no,unsigned long axis,long pos,float start_vel,float steady_vel,float acc,unsigned long sine);
SLDM_API SLDM_PTP1(unsigned long card_no,unsigned long axis,long pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_PTP1R(unsigned long card_no,unsigned long axis,long pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_JogP(unsigned long card_no,unsigned long axis,float start_vel,float steady_vel,float acc);
SLDM_API SLDM_JogM(unsigned long card_no,unsigned long axis,float start_vel,float steady_vel,float acc);
SLDM_API SLDM_Stop(unsigned long card_no,unsigned long axis,float stop_dec);
SLDM_API SLDM_Estop(unsigned long card_no,unsigned long axis);
SLDM_API SLDM_Change_Pos(unsigned long card_no,unsigned long axis,long pos);
SLDM_API SLDM_Change_Vel(unsigned long card_no,unsigned long axis,float vel);
SLDM_API SLDM_PTP1_Imm(unsigned long card_no, unsigned long axis, long pos, float start_vel, float steady_vel, float end_vel, float acc, float dec, unsigned long sine);
/**********************************************************************************
* @End 单轴运动
***********************************************************************************/

/**********************************************************************************
* @Begin 多轴运动
***********************************************************************************/
SLDM_API SLDM_PTPn(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_PTPn_Stop(unsigned long card_no,float stop_dec);
SLDM_API SLDM_PTPn_Group(unsigned long card_no,unsigned long group_id,unsigned long n_axis,unsigned long *axislist,long *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_PTPn_Stop_Group(unsigned long card_no,unsigned long group_id,float stop_dec);
SLDM_API SLDM_PTPn_Plus(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_PTPn_Stop_Plus(unsigned long card_no,float stop_dec);
/**********************************************************************************
* @End 多轴运动
***********************************************************************************/

/**********************************************************************************
* @Begin 圆弧运动
***********************************************************************************/
SLDM_API SLDM_Arc_2D(unsigned long card_no,unsigned long *axislist, float *center_pos, long *end_pos, unsigned long ccw_dir, float start_vel,float steady_vel,float end_vel, float acc,float dec);
SLDM_API SLDM_Arc_2DEx(unsigned long card_no,unsigned long *axislist, float *center_pos, long *end_pos, long circle, long oft_pos,unsigned long ccw_dir, float start_vel,float steady_vel,float end_vel, float acc,float dec);
SLDM_API SLDM_Arc_Radius(unsigned long card_no,unsigned long *axislist, long *end_pos, float arc_Radius,unsigned long ccw_dir, float start_vel,float steady_vel,float end_vel, float acc,float dec);
SLDM_API SLDM_Arc_3Points(unsigned long card_no,unsigned long *axislist,float *mid_pos, long *target_pos, float start_vel,float steady_vel,float end_vel, float acc,float dec);
SLDM_API SLDM_Arc_Stop(unsigned long card_no,float stop_dec);

/**********************************************************************************
* @End 圆弧运动
***********************************************************************************/

/**********************************************************************************
* @Begin 高级运动功能
***********************************************************************************/
SLDM_API SLDM_Pmove_Extern(unsigned long card_no,unsigned long axis, long mid_pos, long target_pos, float start_vel,float steady_vel,float stop_vel, 
						   unsigned long delay_ms, float steady_vel2,float end_vel,  unsigned long acc_ms, unsigned long dec_ms, unsigned long posi_mode);
SLDM_API SLDM_Set_Gear_Follow(unsigned long card_no, unsigned long axis,unsigned long enable,unsigned long master_axis,float ratio,unsigned long src,unsigned long delay);
/**********************************************************************************
* @End 高级运动功能
***********************************************************************************/

/**********************************************************************************
* @Begin 缓冲区运动
***********************************************************************************/
SLDM_API SLDM_Set_Buff_Enable(unsigned long card_no,unsigned long enable);
SLDM_API SLDM_Start_Buff_Move(unsigned long card_no);
//SLDM_API SLDM_Add_Buff_Segment(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine,long out_bit,unsigned long out_data, long delaytime);
SLDM_API SLDM_Add_Buff_Segment(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine);
SLDM_API SLDM_Get_Buff_Move_Curent_P(unsigned long card_no,unsigned long *p);
SLDM_API SLDM_Get_Buff_Move_Total_P(unsigned long card_no,unsigned long *p);
SLDM_API SLDM_Get_Buff_Segment_P(unsigned long card_no,unsigned long *p);
SLDM_API SLDM_Get_Buff_Block_Space(unsigned long card_no,unsigned long *space);
SLDM_API SLDM_ReSet_Buff_Segment_P(unsigned long card_no);
SLDM_API SLDM_Set_Buff_Move_Curent_P(unsigned long card_no,unsigned long run_buffer,unsigned long curent_p);
SLDM_API SLDM_Stop_Buff_Move(unsigned long card_no,float stop_dec);
SLDM_API SLDM_Set_Buff_Move_Single_Step(unsigned long card_no,unsigned long one_step);
SLDM_API SLDM_Reset_Buff_Move(unsigned long card_no);
SLDM_API SLDM_Get_Running_BuffMove(unsigned long card_no,unsigned long *running);
SLDM_API SLDM_Set_Buff_Loop(unsigned long card_no,unsigned long loop);
SLDM_API SLDM_Add_Mix_Segment(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long  *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine,unsigned long type,float *center_pos,unsigned long ccw_dir);
SLDM_API SLDM_Add_Mix_Seg(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float steady_vel,float acc,unsigned long sine,unsigned long type,float *center_pos,unsigned long ccw_dir);
SLDM_API SLDM_Buff_Wait_Input(unsigned long card_no, unsigned long in_bit, unsigned long on_off,unsigned long delaytime);
SLDM_API SLDM_Buff_Delay_Outbit_To_Start(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long delay_value, unsigned long delay_mode, unsigned long reverse_time);
SLDM_API SLDM_Buff_Delay_Outbit_To_Stop(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long delay_time, unsigned long reverse_time);
SLDM_API SLDM_Buff_Ahead_Outbit_To_Stop(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long ahead_value, unsigned long ahead_mode, unsigned long reverse_time);
SLDM_API SLDM_Buff_Clear_Io_Action(unsigned long card_no, unsigned long io_bit);
SLDM_API SLDM_Buff_delay(unsigned long card_no,  long delaytime);//连续插补中暂停延时指令


//设置缓冲区运动上位机缓存使能
SLDM_API SLDM_Buff_Move_ListEn(unsigned long card_no,unsigned long en);
//清空缓冲区运动上位机缓存
SLDM_API SLDM_Buff_Move_ListClear(unsigned long card_no);
SLDM_API SLDM_Get_Buff_Move_ListSpace(unsigned long card_no,unsigned long *space);

/**********************************************************************************
* @End 缓冲区运动
***********************************************************************************/

/**********************************************************************************
* @Begin IO功能
***********************************************************************************/
SLDM_API SLDM_Set_OutBit (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data);
SLDM_API SLDM_Get_OutBit (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Get_InBit(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Set_OutByte(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data);
SLDM_API SLDM_Get_InByte(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Get_OutByte(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);

SLDM_API SLDM_Set_OutWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data);
SLDM_API SLDM_Set_OutDWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data);
SLDM_API SLDM_Get_OutWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Get_OutDWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Get_InWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);
SLDM_API SLDM_Get_InDWord (unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);

SLDM_API SLDM_Register_Callback(unsigned long card_no,void(*fn)(), unsigned long addr, unsigned long in_bit, unsigned long edge);
SLDM_API SLDM_Unregister_Callback(unsigned long card_no,unsigned long addr, unsigned long in_bit, unsigned long edge);
SLDM_API SLDM_Reverse_OutBit(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data, unsigned long reverse_time);
SLDM_API SLDM_Toggle_OutBit(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long data, unsigned long delay_time , unsigned long reverse_time);
SLDM_API SLDM_Reset_InBit_Counter(unsigned long card_no, unsigned long addr, unsigned long group, unsigned long index_mask);
SLDM_API SLDM_Get_InBit_Counter(unsigned long card_no, unsigned long addr, unsigned long index, unsigned long * data);

/**********************************************************************************
* @End IO功能
***********************************************************************************/

/********************************************************************************
* @Begin 位置比较
*******************************************************************************/
SLDM_API SLDM_Cmpr_Enable(unsigned long card_no,unsigned long fifo,unsigned long en);
SLDM_API SLDM_Get_Cmpr_Enable(unsigned long card_no,unsigned long fifo,unsigned long *en);
SLDM_API SLDM_Cmpr_Add_Point(unsigned long card_no,unsigned long axis, long cmpr_pos,unsigned long fifo,unsigned long width,unsigned long out_level,unsigned long src);
SLDM_API SLDM_Get_Cmpr_Fifo_Space(unsigned long card_no,unsigned long fifo,unsigned long *space);
SLDM_API SLDM_Clear_Cmpr(unsigned long card_no,unsigned long fifo,unsigned long fifo_data_en,unsigned long complete_num_en);
SLDM_API SLDM_Start_Cmpr(unsigned long card_no,unsigned long fifo,unsigned long start);
SLDM_API SLDM_Get_Cmpr_Num(unsigned long card_no,unsigned long fifo,unsigned long *num);
SLDM_API SLDM_Compare_Linear(unsigned long card_no,unsigned long axis, long startPos, long interval,unsigned long fifo,unsigned long  width,unsigned long out_level, unsigned long src);
SLDM_API SLDM_Cmpr_Mod(unsigned long card_no,unsigned long fifo,unsigned long mod);
SLDM_API SLDM_Cmpr_2D(unsigned long card_no,unsigned long *axislist, long *cmpr_pos, unsigned long max_err, unsigned long threshould, unsigned long fifo, unsigned long  width, unsigned long out_level, unsigned long src);
SLDM_API SLDM_Cmpr_3D(unsigned long card_no,unsigned long *axislist, long *cmpr_pos, unsigned long max_err, unsigned long threshould, unsigned long fifo, unsigned long  width, unsigned long out_level, unsigned long src);

/**********************************************************************************
* @End 位置比较
***********************************************************************************/

/**********************************************************************************
* @Begin 位置锁存
***********************************************************************************/
SLDM_API SLDM_Start_Latch(unsigned long card_no,unsigned long fifo,unsigned long start);
SLDM_API SLDM_Set_Latch_Para(unsigned long card_no,unsigned long fifo,unsigned long axis, unsigned long src);//,unsigned short trigger);
SLDM_API SLDM_Get_Latch_Pos(unsigned long card_no,unsigned long fifo,int * pos, unsigned int *hold_time,unsigned long * numofcapt);
SLDM_API SLDM_Clear_Latch_Fifo(unsigned long card_no,unsigned long fifo);
SLDM_API SLDM_Register_Latch_Callback(unsigned long card_no,void(*fn)(), unsigned long fifo,unsigned long hold_time);
SLDM_API SLDM_Unregister_Latch_Callback(unsigned long card_no,unsigned long fifo);

/**********************************************************************************
* @End 位置锁存
***********************************************************************************/

/**********************************************************************************
* @Begin PT运动
***********************************************************************************/
SLDM_API SLDM_PtInit(unsigned long card_no);
SLDM_API SLDM_PrfPt(unsigned long card_no,unsigned long axis, unsigned long mode=PT_MODE_STATIC);
SLDM_API SLDM_PtSpace(unsigned long card_no,unsigned long axis, unsigned long *pspace, unsigned long fifo=0);
SLDM_API SLDM_PtStart(unsigned long card_no,unsigned long axis, unsigned long start,unsigned long option);
SLDM_API SLDM_PtData(unsigned long card_no,unsigned long axis, long pos, unsigned long time, unsigned long type, unsigned long fifo=0,unsigned long move_delay=0,long out_bit=-1,unsigned long out_data=0,unsigned long out_delay =0 );
SLDM_API SLDM_PtClear(unsigned long card_no,unsigned long axis, unsigned long fifo);
SLDM_API SLDM_SetPtLoop(unsigned long card_no,unsigned long axis, unsigned long loop);
SLDM_API SLDM_GetPtLoop(unsigned long card_no,unsigned long axis, unsigned long *ploop);
SLDM_API SLDM_SetPtMemory(unsigned long card_no,unsigned long memory);
SLDM_API SLDM_GetPtMemory(unsigned long card_no,unsigned long *pmemory);
SLDM_API SLDM_GetPtMoveP(unsigned long card_no,unsigned long axis, unsigned long *move_p);

SLDM_API SLDM_Pt_ListEn(unsigned long card_no,unsigned long en);
SLDM_API SLDM_Pt_ListClear(unsigned long card_no,unsigned long axis);
SLDM_API SLDM_Get_Pt_ListSpace(unsigned long card_no,unsigned long *space);
/**********************************************************************************
* @End PT运动
***********************************************************************************/

/**********************************************************************************
* @Begin PWM功能
***********************************************************************************/
SLDM_API SLDM_Set_PWM_Enable(unsigned long card_no,unsigned long pwm,unsigned long en);
SLDM_API SLDM_PWM_Start(unsigned long card_no,unsigned long pwm,unsigned long start);
SLDM_API SLDM_Set_PWM_Config(unsigned long card_no,unsigned long pwm, float duty, float fre, unsigned long pol);
SLDM_API SLDM_Get_PWM(unsigned long card_no,unsigned long pwm, float *duty, float *fre);

//不使用跟随模式，输出PWM,适用跟随模式时，只设置参数，不输出
//功 能：连续插补中 PWM 输出设置
SLDM_API SLDM_Buff_Set_PWM_Output(unsigned long card_no,unsigned long pwm, float fDuty,float fFre);
//功 能：设置 PWM 开关状态对应的占空比
SLDM_API SLDM_Buff_Set_PWM_Onoff_Duty( unsigned long card_no,unsigned long pwm,float fOnDuty, float fOffDuty);
//功 能：连续插补中 PWM 速度跟随
SLDM_API SLDM_Buff_Set_PWM_Follow_Speed(unsigned long card_no,unsigned long pwm, unsigned long mode, float maxVel, float maxValue, float outValue);
//功 能：连续插补中相对于轨迹段起点 PWM 滞后输出
SLDM_API SLDM_Buff_Delay_PWM_To_Start(unsigned long card_no,unsigned long pwm, unsigned long on_off,unsigned long delay_value, unsigned long delay_mode, float reverse_time);
//功 能：连续插补中相对于轨迹段终点 PWM 提前输出
SLDM_API SLDM_Buff_Ahead_PWM_To_Stop(unsigned long card_no,unsigned long pwm, unsigned long on_off,unsigned long ahead_value, unsigned long ahead_mode, float reverse_time);


/**********************************************************************************
* @End PWM功能
***********************************************************************************/

/**********************************************************************************
* @Begin 控制器辅助功能
***********************************************************************************/
SLDM_API SLDM_Get_SysVersion(unsigned long card_no,unsigned long * softver,unsigned long * fpgaver);	
SLDM_API SLDM_Get_ArmID(unsigned long card_no,unsigned long * id);
SLDM_API SLDM_Get_CardID(unsigned long card_no,unsigned long * id);
SLDM_API SLDM_Get_CardInfo(unsigned long card_no,CARD_INFO * card_info);
SLDM_API SLDM_Get_Card_IOResource(unsigned long card_no,unsigned long *axis_num,unsigned long *di_num,unsigned long *do_num,unsigned long *ad_num,unsigned long *da_num,unsigned long *pwm_num);
SLDM_API SLDM_Get_Card_EXResource(unsigned long card_no,unsigned long *cmpr1_num,unsigned long *cmprline_num,unsigned long *cmpr2_num,unsigned long *latch_num);
SLDM_API SLDM_Get_Card_Model(unsigned long card_no,unsigned long *model,unsigned long *type,unsigned long *period);
SLDM_API SLDM_Write_Regcode(unsigned long card_no,unsigned char* reg_code,unsigned char* reg_code_md5);
SLDM_API SLDM_Read_Regcode(unsigned long card_no,unsigned char* reg_code);
SLDM_API SLDM_E2prom_Write(unsigned long card_no,unsigned long addr,unsigned long num,long *pData);
SLDM_API SLDM_E2prom_Read(unsigned long card_no,unsigned long addr,unsigned long num,long *pData);
SLDM_API SLDM_ExE2prom_Write(unsigned long card_no,unsigned long addr,unsigned long num,long *pData);
SLDM_API SLDM_ExE2prom_Read(unsigned long card_no,unsigned long addr,unsigned long num,long *pData);

SLDM_API SLDM_Uart_Trans_Enable(unsigned long card_no,unsigned long uart_no,unsigned long en,unsigned long BaudRate);
SLDM_API SLDM_Write_ToUart(unsigned long card_no,unsigned long uart_no,unsigned long num,unsigned char* data);
SLDM_API SLDM_Read_FromUart(unsigned long card_no,unsigned long uart_no,unsigned long *num,unsigned char* data);

SLDM_API SLDM_Load_ParaFile(unsigned long card_no);
SLDM_API SLDM_Save_ParaFile(unsigned long card_no);

/**********************************************************************************
* @End 控制器辅助功能
***********************************************************************************/



/**********************************************************************************
* @Begin ETHERCAT功能
***********************************************************************************/

SLDM_API SLDM_Set_Ecat_Axis(unsigned long card_no,unsigned long axis_num,unsigned long *type);
SLDM_API SLDM_Ecat_Reset(unsigned long card_no);
SLDM_API SLDM_Get_Ecat_Status(unsigned long card_no,unsigned long *cur_axisnum,unsigned long *online_flag,unsigned long *link_ok);
SLDM_API SLDM_Get_Ecat_ZCap_pos(unsigned long card_no,unsigned long axis,long *pos);
SLDM_API SLDM_Get_Ecat_Release_AxisNum(unsigned long card_no,unsigned long *axisnum);
SLDM_API SLDM_Get_EcatEx_Enc(unsigned long card_no,unsigned long exenc_num,long *pos);
SLDM_API SLDM_Ecat_OFF(unsigned long card_no);

/**********************************************************************************
* @End ETHERCAT功能
***********************************************************************************/

/**********************************************************************************
* @Begin 手轮功能
***********************************************************************************/
SLDM_API SLDM_Set_HandWheel_Config(unsigned long card_no,unsigned long axis_num,unsigned long *axis_list,unsigned long *mult_list,unsigned long dir_pol);
SLDM_API SLDM_Set_HandWheel_MaxVel(unsigned long card_no,unsigned long max_vel,unsigned long max_acc);
SLDM_API SLDM_Set_HandWheel_Enable(unsigned long card_no,unsigned long enable);
SLDM_API SLDM_Get_HandWheel_Status(unsigned long card_no,unsigned long *di_status,long *enc_data);
/**********************************************************************************
* @End 手轮功能
***********************************************************************************/


/**********************************************************************************
* @Begin 开发调试函数
***********************************************************************************/

SLDM_API SLDM_Set_commthread_debug(unsigned long card_no, short debug_mode,short debug_key);
SLDM_API SLDM_Get_CommTime(float *cur_time,float *max_time);
SLDM_API SLDM_Get_CommTime_10000(float *time);
SLDM_API SLDM_Get_udp_complete_num(int *write_num,int *read_num);
SLDM_API SLDM_Get_Home_flag(unsigned long card_no,unsigned long axis,int *flag);

SLDM_API SLDM_Jump_Move(unsigned long card_no, JUMP_MOVE_PARA *jump_move_para);
SLDM_API SLDM_Jump_Stop(unsigned long card_no, float stop_dec);
SLDM_API SLDM_Jump_Reset(unsigned long card_no);
SLDM_API SLDM_Get_Jump_Running(unsigned long card_no, unsigned long *running);

SLDM_API SLDM_PTPn_Ex_Register(unsigned long id, unsigned long n_axis, unsigned long *cardlist, unsigned long *axislist);
SLDM_API SLDM_PTPn_Ex(unsigned long id, long *pos, float start_vel, float steady_vel, float end_vel, float acc, float dec, unsigned long sine, int dist_mode);
SLDM_API SLDM_PTPn_Ex_GetRunning(unsigned long id, unsigned long *running);
SLDM_API SLDM_PTPn_Ex_Stop(unsigned long id, float stop_dec);

SLDM_API Unit_TO_Pulse(int axis, float PPR, float pitch, float unit_value, int * pulse_value);
SLDM_API SLDM_Get_Move_Complete(unsigned long card_no, unsigned long axis, long pos, long *Status);
SLDM_API SLDM_Get_Homed_Complete(unsigned long card_no, unsigned long axis, long *Status);
/**********************************************************************************
* @End 开发调试函数
***********************************************************************************/


/**********************************************************************************
* @Begin 扩展缓冲区运动函数开始，函数说明参照缓冲区运动函数
***********************************************************************************/
SLDM_API SLDM_Start_Buff2_Move(unsigned long card_no);
SLDM_API SLDM_Set_Buff2_Enable(unsigned long card_no,unsigned long enable);
SLDM_API SLDM_Add_Buff2_Segment(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long  *pos,float start_vel,float steady_vel,float end_vel,float acc,float dec,unsigned long sine,unsigned long type,float *center_pos,unsigned long ccw_dir);
SLDM_API SLDM_Add_Buff2_Seg_Smooth(unsigned long card_no,unsigned long n_axis,unsigned long *axislist,long *pos,float steady_vel,float acc,unsigned long sine,unsigned long type,float *center_pos,unsigned long ccw_dir);
SLDM_API SLDM_Reset_Buff2_move(unsigned long card_no);
SLDM_API SLDM_Stop_Buff2_Move(unsigned long card_no,float stop_dec);
SLDM_API SLDM_Set_Buff2_Loop(unsigned long card_no,unsigned long loop);
SLDM_API SLDM_Set_Buff2_Move_Single_Step(unsigned long card_no,unsigned long one_step);
SLDM_API SLDM_Get_Running_Buffmove2(unsigned long card_no,unsigned long *running);
SLDM_API SLDM_Get_Buff2_Block_Spare(unsigned long card_no,unsigned long *space);
SLDM_API SLDM_Get_Buff2_Move_Curent_P(unsigned long card_no,unsigned long *p);
SLDM_API SLDM_Set_Buff2_Move_Curent_P(unsigned long card_no,unsigned long curent_p);
SLDM_API SLDM_Buff2_wait_input(unsigned long card_no, unsigned long in_bit, unsigned long on_off,unsigned long delaytime);
SLDM_API SLDM_Buff2_Delay_Outbit_To_Start(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long delay_value, unsigned long delay_mode, unsigned long reverse_time);
SLDM_API SLDM_Buff2_Delay_Outbit_To_Stop(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long delay_time, unsigned long reverse_time);
SLDM_API SLDM_Buff2_Ahead_Outbit_To_Stop(unsigned long card_no, unsigned long out_bit, unsigned long on_off,unsigned long ahead_value, unsigned long ahead_mode, unsigned long reverse_time);
SLDM_API SLDM_Buff2_Clear_Io_Action(unsigned long card_no, unsigned long io_bit);
SLDM_API SLDM_Buff2_delay(unsigned long card_no,  long delaytime);
/**********************************************************************************
* @End 扩展缓冲区运动函数结束
***********************************************************************************/

SLDM_API SLDM_PTPn_PPU(unsigned long card_no, PTP4_PPU_PARA *ptp4_ppu_para);
SLDM_API SLDM_PTPn_PPU_Stop(unsigned long card_no, float stop_dec);
//时间单位 毫秒
SLDM_API SLDM_PTP1_Time(unsigned long card_no, unsigned long axis, unsigned long tStart, unsigned long tEnd, long posEnd, float velStart, float velEnd, float accStart, float accEnd, unsigned long mode);

/**********************************************************************************
* @Begin 通用模拟量采集卡函数开始
***********************************************************************************/
SLDM_API SLDM_Set_AD_Config(unsigned long card_no, unsigned long group, unsigned long en, unsigned long range, unsigned long oversample_rate);
SLDM_API SLDM_Set_ADCfg(unsigned long card_no, unsigned long adc_bit, ADC_PARA_CFG *adc_para_cfg);
SLDM_API SLDM_Get_AD(unsigned long card_no, unsigned long index, float *data, unsigned long *range);
/**********************************************************************************
* @Begin 通用模拟量采集卡函数结束
***********************************************************************************/

/**********************************************************************************
* @Begin 3x4x系列 DAQ模拟量采集卡函数开始
***********************************************************************************/
SLDM_API SLDM_DAQ_Task_Cfg(unsigned long card_no, DAQ_TASK_PARA daq_task_para);
SLDM_API SLDM_DAQ_Task_GetCfg(unsigned long card_no, DAQ_RECV_PARA *daq_recv_para);
SLDM_API SLDM_DAQ_Task_Start(unsigned long card_no);
SLDM_API SLDM_DAQ_Task_Stop(unsigned long card_no);//工作模式1时，不需要调用，如果调用，就停止采样。
SLDM_API SLDM_DAQ_Set_MEMSize(unsigned long card_no, unsigned size);//设置采集缓冲区大小，最大8k个采样组数据，缓冲区数据满后，自动触发回调函数。
SLDM_API SLDM_DAQ_Register_Callback(unsigned long card_no, void(*fn)(void *data));
SLDM_API SLDM_DAQ_Unregister_Callback(unsigned long card_no);
SLDM_API SLDM_DAQ_ReSet_Callback_Counter(unsigned long card_no);
SLDM_API SLDM_DAQ_Get_Callback_Counter(unsigned long card_no, unsigned long* counter);
SLDM_API SLDM_Set_IN_Multiplex(unsigned long card_no, unsigned long input_bit, unsigned long axis, unsigned long type);
SLDM_API SLDM_Set_OUT_Multiplex(unsigned long card_no, unsigned long out_bit, unsigned long axis, unsigned long type);

/**********************************************************************************
* @Begin 3x4x系列 DAQ模拟量采集卡函数结束
***********************************************************************************/



