#pragma once
#define MAX_ALM_BUFFER_NUM          256
#define MAX_DAQMEMSIZE				8192

//@Begin PT运动模式
#define PT_MODE_STATIC              0//（该宏定义为 0）静态模式。默认为该模式。
#define PT_MODE_DYNAMIC             1//（该宏定义为 1）动态模式
#define PT_SEGMENT_NORMAL           0//（该宏定义为 0）普通段。默认为该类型。
#define PT_SEGMENT_EVEN             1//（该宏定义为 1）匀速段。
#define PT_SEGMENT_STOP             2//（该宏定义为 2）减速到 0 段。
#define PT_SEGMENT_END              3// 自定义结束标志
//@End PT运动模式

//
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
	unsigned int Slave_Type;
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
	bool Plimit_vol;	 			//正限位报警信号导通状态
	bool Nlimit_vol;	 			//负限位报警信号导通状态
	bool origin_vol;	 			//原点信号导通状态
	bool Encz_vol;		 			//编码器输入Z信号电平状态
	bool reached_vol;	 			//到位信号导通状态
	bool servon;		 			//伺服使能信号导通状态
	bool resalm;		 			//伺服报警清除信号导通状态
						 
	bool servo_alarm_valid;			//伺服报警信号有效状态;
	bool Plimit_valid;	 			//正限位报警信号有效状态
	bool Nlimit_valid;	 			//负限位报警信号有效状态
	bool origin_valid;	 			//原点信号有效状态
	bool Encz_valid;	 			//编码器输入Z信号有效状态
	bool reached_valid;	 			//到位信号有效状态
	bool soft_Plimit_valid;			//正软限位报警有效状态;
	bool soft_Nlimit_valid;			//负软限位报警有效状态;
						 
	bool homing;		 			//回零中有效状态
	bool homed;			 			//回零完成有效状态
	bool running;		 			//运动中有效状态
						 
	unsigned char alarm_status;		//0x01正限位，0x02负限位，0x04 soft_plimit,0x08 soft_nlimit,0x10伺服报警;
	char home_flag;		 			//回零过程标志状态

}Axis_Status; 


typedef struct
{
	int alarm_number[MAX_ALM_BUFFER_NUM];	//历史报警号
	int alarm_para[MAX_ALM_BUFFER_NUM];		//历史报警参数
	int time_tick[MAX_ALM_BUFFER_NUM];		//历史报警次数
}Alarm_History;


typedef struct 
{
    unsigned int  axis_num;             //当前控制轴个数
    int           axis_list[4];         //当前控制手脉轴号列表 axis_z,axis_x,axis_y,other
    int           up_end_pos;           //上升段终点
    unsigned int  up_offset_to_zendPos; //上升段到终点前的偏移量，到终点距离小于这个偏移量时，平移轴开始运动。
    int           xy_end_pos[2];        //水平运动段终点位置    
    unsigned int  xy_offset_to_endPos;  //水平段到终点前的偏移量，到终点距离小于这个偏移量时，下降轴开始运动。
    int           down_end_pos;         //下降段终点
    float         up_vel_array[3];      //上升段起始速度，最大速度，终点速度
    float         up_vel_acc_dec[2];    //上升段加速度，减速度
    float         xy_vel_array[3];      //上升段起始速度，最大速度，终点速度
    float         xy_vel_acc_dec[2];    //上升段加速度，减速度
    float         down_vel_array[3];    //上升段起始速度，最大速度，终点速度
    float         down_vel_acc_dec[2];  //上升段加速度，减速度

}JUMP_MOVE_PARA;

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
	unsigned int Voltage_Range;		//ADC输入电压范围: 0:±2.5V,1:±5V,2:±10V,3:±12.5V,4:±2.5V高带宽模式,5:±5V高带宽模式,6:±10V高带宽模式,7:±12.5V高带宽模式;
	unsigned int Oversampling_Rate;	//采样次数（过采样率），范围：//0:无过采样,1:2倍，2:4倍，3:8倍，4:16倍，5:32倍，6:64倍，7:128倍，>=8:过采样关闭；
	unsigned int GAIN;				//增益，范围：0-63Ω。。
	unsigned int Offset;			//偏置，范围：0-255，0：-128 LSB 失调，128：0无失调，255：127 LSB 失调。
	unsigned int Phase_Offset;		//相位偏置：范围：0-255，单位us
}ADC_PARA_CFG;


typedef struct
{
//	unsigned char en;					//[0]:采样使能，1：使能，0：不使能；
	unsigned char flag;					//[0]:采样状态指示寄存器，1：采样中，0：采样结束；
	unsigned char Voltage_Range;		//[2:1]:ADC输入电压范围,0x0:±10V,0x1:±5V,0x2:12.5V,0x3:2.5V;
	unsigned char Mode;					//[4:3]:采样触发模式，如下：0x0:编码器触发采样，0x1:时间触发采样,测试模式，固定频率采样，基于Sampling_Period设置
	unsigned char Enc_trigger_Mult;		//[6:5]:编码器采样倍率，如下：0x1:1倍频；0x2:2倍频；0x4:4倍频；（工作模式0有效）
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


typedef struct
{
	unsigned int	axis_num;             //当前控制轴个数
	unsigned int	axis_list[4];         //当前控制手脉轴号列表 axis_x,axis_y,axis_z,u
	int				z_end_pos[3];         //[0]:z轴终点位置，[1]:z轴下降开始点，，[2]:z轴上升终点
	int				xy_end_pos[2];        //水平运动段终点位置   
	int				u_end_pos;		      //旋转轴终点位置
	float           z_vel[3];             //vel_z[0]:start_vel,vel_z[1]:steady_vel,vel_z[2]:end_vel,
	float			z_acc[2];             //acc_z[0]:acc,acc_z[1]:dec
	float           xyu_vel[3];           //vel_xyu[0]:start_vel,vel_xyu[1]:steady_vel,vel_xyu[2]:end_vel,
	float			xyu_acc[2];           //acc_xyu[0]:acc,acc_xyu[1]:dec
	unsigned int	sine[2];              //sine[0]:z_sin,sine[1]:xyu_sin
	unsigned int	mode;

}PTP4_PPU_PARA;

#define E6010_DATA_ROW			300		
//#define E6010_DATA_Col			58

typedef struct    //6010参数设置结构体
{
	unsigned long delay_time_us;		//相机拍照完成到吹起口延时时间,单位us
	unsigned long blow_reverse_us;		//喷吹周期,单位us
	unsigned long frame_inc;			//帧号增量，每图片相机拍照触发信号次数
	unsigned long trigger_width_us;		//相机触发信号脉冲宽度，,单位us
	unsigned long line_frequency;		//相机行频，fps

}E6010_CONFIG;

typedef struct    //6010数据结构体
{
	unsigned int	cam_no;					//相机号
	unsigned int	frame_no;				//帧号
	unsigned int	data_row_num;			//数据行数，每行64个bit
	unsigned char	data[E6010_DATA_ROW*8];	//点位数据

}E6010_DATA;