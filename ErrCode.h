#pragma once
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

#define SLDM_ERR_PCIE_INIT			-130			/*PCIE总线初始化失败*/
#define SLDM_ERR_PCIE_READ			-131			/*PCIE总线读错误*/
#define SLDM_ERR_PCIE_WRITE			-132			/*PCIE总线写错误*/
#define SLDM_ERR_PCIE_PARA_ADDR		-140			/*PCIE总线参数地址解析错误*/

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
#define	SLDM_SET_SPEC_INPUT_FILTER_CODE				0X39	//57
#define	SLDM_SET_AXIS_INPUT_FILTER_CODE				0X3A	//58
#define	SLDM_PTP1_TIME								0X3B	//59

#define	SLDM_PTPN_GROUP								0x3E	//62
#define	SLDM_PTPN_STOP_GROUP						0x3F	//63

#define SLDM_SET_AD_CONFIG							0X40	//64
#define SLDM_6010_CONFIG							0X41	//65
#define SLDM_6010_DATA								0X42	//66
#define SLDM_6010_EN								0X43	//67


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
#define	SLDM_BUFF_DELAY								0X6F	//111

#define SLDM_TOGGLE_OUTBIT							0X70	//112
#define SLDM_RESET_INBIT_COUNTER					0X71	//113
#define	SLDM_SETOUTBIT_CODE							0X73	//115
#define	SLDM_SETOUTBYTE_CODE						0X76	//118
#define	SLDM_SET_DI_FILTER_CODE						0x7B	//123
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
#define	SLDM_ECAT_OFF								0XC2	//194

#define SLDM_JUMP_MOVE								0XC8	//200
#define SLDM_JUMP_STOP								0XC9	//201
#define SLDM_JUMP_RESET								0XCA	//202
#define SLDM_PTPN_PPU								0XCB	//203

#define	SLDM_START_BUFF2_MOVE						0XD0	//208
#define	SLDM_SET_BUFF2_ENABLE						0XD1	//209
#define	SLDM_ADD_BUFF2_SEGMENT						0XD2	//210
#define	SLDM_ADD_BUFF2_SEG_SMOOTH					0XD3	//211
#define	SLDM_RESET_BUFF2_MOVE						0XD4	//212
#define	SLDM_STOP_BUFF2_MOVE						0XD5	//213
#define	SLDM_SET_BUFF2_LOOP							0XD6	//214
#define	SLDM_SET_BUFF2_MOVE_SINGLE_STEP				0XD7	//215
#define	SLDM_SET_BUFF2_MOVE_CURENT_P				0XD8	//216
#define	SLDM_BUFF2_WAIT_INPUT						0XD9	//217
#define	SLDM_BUFF2_DELAY_OUTBIT_TO_START			0XDA	//218
#define	SLDM_BUFF2_DELAY_OUTBIT_TO_STOP				0XDB	//219
#define	SLDM_BUFF2_AHEAD_OUTBIT_TO_STOP				0XDC	//220
#define	SLDM_BUFF2_CLEAR_IO_ACTION					0XDD	//221
#define	SLDM_BUFF2_DELAY							0XDE	//222

#define	SLDMDAQ_TASK_CFG							0XF0	//240
#define	SLDMDAQ_TASK_START							0XF1	//241
#define	SLDMDAQ_TASK_STOP							0XF2	//242
#define	SLDM_SET_DI_MULTIPLEX						0XF3	//243
#define	SLDM_SET_OUT_MULTIPLEX						0XF4	//244

#define	SLDM_TEST_FUNCTION_CODE						0XFF	//255
//@End 返回错误ID的函数名称 编码

