#ifndef __3DCMD_H__
#define __3DCMD_H__
#pragma pack(push,1)







namespace _3Dcmd
{

	enum NetType :int
	{
		DT_Null = 0,
		DT_CreateTran,//创建车辆1
		DT_RemoveTran,//移除车辆2
		DT_SetTran,//设置车辆信息3
		DT_SetTranSpeed,//设置车辆速度4
		DT_SetTranStatus,//设置车辆状态5
		DT_SetTranDir,//设置车辆方向6
		DT_SetTranDes,//设置车辆方向7
		DT_LocalCamera,//锁定车辆摄像头8
		DT_SetXHJ,//设置信号机9
		DT_SetSwitch,//设置道岔10
		DT_CleanSwitch,//清除道岔11
		DT_SetWeather,//设置天气12
		DT_SetTrouble,//设置故障13
		DT_SetTranLight,//开关车灯14
		RT_CMDResult,//反馈命令15
		RT_TranInfo,//反馈车辆信息16
		RT_YDQ,//反馈触发应答器17
		RT_XHJ,//反馈信号机状态18
		RT_Switch,//反馈道岔19
		DQ_Device,//查询命令20
		DM_Close,//关闭实景21
		DT_SetAllStatus,//设置所有车状态22
		DT_OpenThirdCamera,//开启第三方漫游23
		DT_RoamStation,//开启场景漫游24
		DT_ONLINE,//在线25
		DT_OpenTWnd,//对标窗口26
		DT_GLB,//公里标27
		RT_SwitchCheck,//道岔检测 28
		DT_SetDistance,//设置距离 29
		RT_Hang,//车辆连挂30
		DT_CleanTran,//清除车辆31
		DT_Help,//救援32
		DT_HelpProcess,//救援过程命令33
		DT_UIControl,//界面按钮响应34
		DT_XiChe, //洗车作业35
		DT_Notify, //显示通知36
		DT_Wiper,//雨刮器37
		DT_Door, //开关车门 38
		DT_BoradInPassenger, //上客 39
		DT_BoradOutPassenger,//下客 40
		DT_ClearPassenger, //清客41
		DT_FlushArrive,    // 刷新抵达位置42
		DT_SetCourse,//课程设置 43
		DT_StationPBM,//站台pbm 44
		DT_SetAllXHJ,//设置所有信号机45
		DT_BindTrainNumber,//绑定车次号 46
		DT_CountDown,//倒计时47
		DT_OperateRoom,//房间操作48
		DT_PassengerFlow = 49,	//     客流 49
		DT_QiDi = 50, //     汽笛 50
		DT_ChangeMonitor = 51,// 转变监视器 51
		DT_SetTrainFault = 52,//设置机车故障
		/// <summary>
		/// 监控车号 53
		/// </summary>
		DT_MonitorTrain = 53,
		/// <summary>
		/// 操作台设备 54
		/// </summary>
		DT_OperateCaoZuoTaiDevice = 54,
		/// <summary>
		/// 操作台指针 55
		/// </summary>
		DT_CaozuotaiPointer = 55,
		/// <summary>
		/// 操作台图片 56
		/// </summary>
		DT_CaozuotaiPic = 56,

		/// <summary>
		/// 操作台按钮颜色 57
		/// </summary>
		DT_CaozuotaiButtonColor = 57,

		/*2020-4-2*/
		DT_CorrectionTrain = 62,//纠正车位置
		/*2020-4-2*/


		DT_UIText = 74,//UI显示当前的停止位置=88

		DT_VehicleCollision=88,//碰撞消息

		DT_Exam = 105,//考试消息2021 12 13 wmj add

		DT_SyncTrainDirction = 111,	// 列车车头向量
	};

enum WeatherOptions :int
{
	Clear = 0,//晴朗
	Cloudy,//多云 1
	LightRain,//小雨 2
	Overcast,//阴天3      
	Snow,//小雪4
	Haze,//阴霾5
	Fog,//雾6
	Dawn,//黎明7
	Morning,//早晨8
	Afternoon,//中午9
	Dusk,//黄昏10
	Night,//夜晚11
	Sandstorm,//沙尘暴12
	Thunderstorm,//雷暴13
	SuiDao
};

enum SingleType
{
	Black = 0,
	Red,
	Yellow,
	Green,
	White,
	Blue
};



///命令头
typedef struct stCMD
{
	NetType nType;
}TCMD;


//2021-12-7
//typedef struct stCsCirProtReq
//{
//	byte head1;//起始位 0x55
//	byte head2;//起始位 0xaa
//	byte pack_flag;//数据包标识 1 请求
//
//	/*req_type
//	1:请求设置元件值；
//	2 设置元件状态；
//	3 设置元件导通故障；
//	4 设置元件状态故障；
//	5 取消元件导通故障；
//	6 取消元件状态故障；
//	7 清除故障；
//	8 获取元件值；
//	9 获取元件状态
//	10 设置窗口显示隐藏
//	*/
//	byte req_type;//请求类型 
//
//	char cir_name[50];//元件名称
//	byte req_val;//填写附加数据如 设置元件值 状态故障时的状态值，req_type为10时，req_val=1显示窗口，req_val=0隐藏窗口
//
//	byte end;//0xab//包尾
//	stCsCirProtReq()
//	{
//		memset(this, 0, sizeof(*this));
//	}
//}CsCirProtReq;

//2021-12-7

enum TranStatus
{
	TranStop = 0,//车撞到一起后发生到ATS 
	TranRun,//车运行需发送1
	TranBroken
};
/*2020-4-20*///车碰撞
typedef struct stTrainRunInto :TCMD
{
	TranStatus m_TrainState;
	char TrainOrder1[16];//车编号
	char TrainOrder2[16];//车编号

}TrainRunInto;
/// <summary>
/// 图片操作
/// </summary>
//[StructLayout(LayoutKind.Sequential, Pack = 1)]
struct CaoZuoTaiPicture
{
	CaoZuoTaiPicture(const char* devicenm, int index, int sz, byte* buffer)
	{
		nType = NetType::DT_CaozuotaiPic;
		strcpy_s(devicename, devicenm);
		packindex = index;
		datasize = sz;
		memcpy(data, buffer, sz);
		//data = new byte[512];
		//Array.Copy(buffer, data, buffer.Length);
	}
	//[MarshalAsAttribute(UnmanagedType.I4)]
	NetType nType;
	//[MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 32)]
	char devicename[32];
	int packindex;
	int datasize;
	//[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 512)]
	byte data[512];
};
/// <summary>
/// 创建车辆
/// </summary>
/// <param name="nType">命令头 DT_CreateTran</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="strTranNum">车次号</param>
/// <param name="strCurPath">初始轨道</param>
/// <param name="dir">前进后退标识 1前进0后退</param>
/// <param name="des">上下行标识 1上行，0下行</param>
/// <param name="speed">初始速度</param>
/// <param name="tf">机车在轨道初始位置</param>
typedef struct stCreateTran :TCMD
{
	char trainSernubmer[16];
	char strTranNum[16];
	char strCurPath[16];
	int dir;
	int des;
	float speed;
	float tf;
}TCreateTran;



/*2020-4-2*/
/// <summary>
/// 救援过程
/// </summary>
/// <param name="nType">命令头 DT_HelpProcess</param>
/// <param name="process">处理过程</param>
/// <param name="trainSernumber">车辆编号（设备号）</param>
/// <param name="process">救援选项</param>
/// 准备0
/// 启动1
/// 靠近2 15m处
/// 挂靠3 2m处
/// 挂接4 0m 晃动
/// 返回5
//[StructLayout(LayoutKind.Sequential, Pack = 1)]
//public struct HelpProcess
//{
//	public HelpProcess(string sernumber, int ip, bool helpCamera)
//	{
//		nType = OpNetWorkDataType.DT_HelpProcess;
//		trainSernumber = sernumber;
//		process = ip;
//		HelpCamera = helpCamera;
//	}
//	[MarshalAsAttribute(UnmanagedType.I4)]
//	public OpNetWorkDataType nType;
//	[MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 16)]
//	public string trainSernumber;
//	public int process;
//	public bool HelpCamera;
/// <summary>
/// 矫正车辆位置
/// </summary>
typedef struct stHelpTrain :TCMD
{
	char trainSernubmer[16];//车物理号
	int nProcess;
	bool bHelpCamera;//真打开 假关闭


}HelpTrain;

typedef struct stCorrectionTrain :TCMD
{
	char trainSernubmer[16];//车物理号
	char trainRoadName[16];//轨道号名字
	float fKio;
	int nTrainDir;//车方向1上行2下行
	float f_TrainSpeed;
	

}CorrectionTrain;

/// <summary>
/// 移除车辆 
/// <param name="nType">命令头 DT_RemoveTran</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// </summary>
typedef struct stNetRemoveTran :TCMD
{
	char trainSernubmer[16];
}TNetRemoveTran;

/// <summary>
/// 设置车辆数据
/// <param name="nType">命令头 DT_SetTran</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="strCurPath">车辆所在轨道名称</param>
/// <param name="ts">列车状态</param>
/// <param name="dir">行车方向 1前进，0后退</param>
/// <param name="des">上下行标识1下行，0上行</param>
/// <param name="speed">行车速度</param>
/// <param name="tf">列车所在轨道轨道位置</param>
/// </summary>
typedef struct stNetSetTran :TCMD
{
	char trainSernubmer[16];
	char strCurPath[16];
	int ts;
	int dir;
	int des;
	float speed;
	float tf;
}TNetSetTran;


/*2019-11-7*/
typedef struct stTUITEXT :TCMD
{
	char trainSernubmer[16];
	float stopDistance;//停车距离
	int dir;//车方向 0左 1右

}TUITEXT;

/*2019-11-7*/
/// <summary>
/// 设置车辆状态
/// <param name="nType">命令头 DT_SetTranStatus</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="ts">状态</param>
/// </summary>
typedef struct stSetTranStatus :TCMD
{
	char trainSernubmer[16];
	int ts;
}TSetTranStatus;

/// <summary>
/// 设置车速度
/// <param name="nType">命令头 DT_SetTranSpeed</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="speed">行车速度</param>
/// </summary>
typedef struct stSetTranSpeed :TCMD
{
	char trainSernubmer[16];
	float speed;
}TSetTranSpeed;

/// <summary>
/// 设置车运行方向
/// <param name="nType">命令头 DT_SetTranDir</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="dir">行驶方向 1前进，0后退</param>
/// </summary>
typedef struct stSetTranDir :TCMD
{
	char trainSernubmer[16];
	int dir;
}TSetTranDir;

/// <summary>
/// 设置车辆目标方向
/// <param name="nType">命令头 DT_SetTranDes</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="des">上下行方向 1下行，0上行</param>
/// </summary>
typedef struct stSetTranDes :TCMD
{
	char trainSernubmer[16];
	int des;
}TSetTranDes;


/// <summary>
/// 锁定摄像机
/// <param name="nType">命令头 DT_LocalCamera</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="beLocalBefore">镜头位置 1,前端镜头，0后方镜头</param>
/// </summary>
typedef struct stLocalCamera :TCMD
{
	char trainSernubmer[16];
	int beLocalBefore;
}TLocalCamera;


/// <summary>
/// 设置信号机
/// <param name="nType">命令头 DT_SetTranDes</param>
/// <param name="strXHJ">信号机</param>
/// <param name="uClr">0位灯</param>
/// <param name="cClr">1灯位</param>
/// <param name="dClr">2灯位</param>
/// 颜色值 Black =0 Red =1  Yellow= 2 Green=3 White=4 Blue =5;
/// </summary>
typedef struct stSetXHJ :TCMD
{
	char TrainPhNumber[16];
	char strXHJ[16];
	int uClr;
	int cClr;
	int dClr;
}TSetXHJ;


/// <summary>
/// 设置转辙机
/// <param name="nType">命令头 DT_SetSwitch</param>
/// <param name="strSwitch">道岔名称</param>
/// <param name="switchStatus">道岔状态</param>
///故障位(中间位)= 0;
///定位 =1;
///反位 =2 ;
/// </summary>   
typedef struct stSetSwitch :TCMD
{
	char TrainPhNumber[16];
	char strSwitch[16];
	int switchStatus;
}TSetSwitch;

/// <summary>
/// 复位转辙机
/// <param name="nType">命令头 DT_CleanSwitch</param>
/// <param name="iClean">清除状态 0定位，1反位</param>
/// </summary>y>
typedef struct stCleanSwitch :TCMD
{
	int iclean;
}TCleanSwitch;


/// <summary>
/// 设置天气
/// <param name="nType">命令头 DT_SetWeather</param>
/// <param name="weather">天气选项状态</param>
/// Clear = 0,//晴朗
///Cloudy,//多云 1
///LightRain,//小雨 2
///Overcast,//阴天3      
///Snow,//小雪4
///Haze,//阴霾5
///Fog,//雾6
///Dawn,//黎明7
///Morning,//早晨8
///Afternoon,//中午9
///Dusk,//黄昏10
///Night,//夜晚11
///Sandstorm,//沙尘暴12
///Thunderstorm,//雷暴13
///SuiDao
/// </summary>
typedef struct stSetWeather :TCMD
{
	int weather;
}TSetWeather;

/// <summary>
///  设置故障
/// <param name="nType">命令头 DT_SetTrouble</param>
/// <param name="trouble">故障类型</param>
/// <param name="nID">故障ID</param> 
/// <param name="bs">故障开关</param>
/// <param name="tf">轨道位置</param>
/// <param name="strPath">轨道名</param>
/// </summary>
typedef struct stSetTrouble :TCMD
{
	int trouble;
	int nID;
	int bs;
	float tf;
	char strPath[16];
}TSetTrouble;

/// <summary>
/// 设置车灯
/// <param name="nType">命令头 DT_SetTranLight</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="lightType">灯类型 1小，2大</param>
/// <param name="lightValue">值 1，0</param>
/// </summary>

typedef struct stSetTranLight :TCMD
{
	char trainSernubmer[16];
	int lightType;
	int lightValue;
}TSetTranLight;


/// <summary>
/// 命令反馈
/// <param name="nType">命令头 RT_CMDResult</param>
/// <param name="nTypeCmdBack">响应命令(唯一标识)</param>
/// <param name="backValue">结果标识 true 成功,false  失败</param>
/// <param name="strRSInfor">附带信息</param>
/// </summary>
typedef struct stCMDResult :TCMD
{
	char strTranPhNumber[16];
	NetType nTypeCmdBack;
	int backValue; //1 创车2 删除车 3屏蔽门 4车门  
	char strRSInfor[16];
	byte DoorState[10];//0-7中间 最后两个是车头
	int nDoorDir;//1左2右
}TCMDResult;

/// <summary>
/// 应答器反馈
/// <param name="nType">命令头 RT_YDQ</param>
/// <param name="strYDQ">应答器名称(唯一标识)</param>
/// <param name="trainSernubmer">触发应答器车编码</param>
/// <summary>
typedef struct stRTYDQ :TCMD
{
	char strYDQ[16];
	char trainSernubmer[16];
}TRTYDQ;

/// <summary>
/// 车辆信息反馈
/// <param name="nType">命令头 RT_TranInfo</param>
/// <param name="strTranSernumber">车辆编号（设备号）</param>
/// <param name="strTranNumber">车次号(唯一标识)</param>
/// <param name="strPath">初始轨道位置</param>
/// <param name="dir">初始行车方向</param>
/// <param name="speed">初始行车速度</param>
/// <param name="tf">当前轨道位置0，1</param>
/// <param name="ts">车辆状态</param>
/// <summary>
typedef struct stRTTranInfo :TCMD
{
	char strTranSernumber[16];
	char strTranNumber[16];
	char strPath[16];
	int dir;
	float speed;
	float tf;//当前轨道米 头压轨道米数 
	int ts;
}RTTranInfo;

/// <summary>
/// 反馈公里标
/// <param name="nType">命令头 DT_GLB</param>
/// <param name="strTranNum">车辆编号（设备号）</param>
/// <param name="strCurPath">线路</param>
/// <param name="dir">行驶方向1前进，0后退</param>
/// <param name="des">上下行 1下行，0上行</param>
/// <param name="speed">行驶速度</param>
/// <param name="tf">线路位置</param>
/// <param name="ts">车辆状态</param>
/// <param name="region">区间</param>
/// </summary>
typedef struct stRTGLBInfo :TCMD
{
	char strTranNum[16];
	char strCurPath[16];

	char sCarriage1[16];
	char sCarriage2[16];
	char sCarriage3[16];
	char sCarriage4[16];
	char sCarriage5[16];
	char sCarriage6[16];
	int dir;	
	int des;
	float speed;
	float tf;
	int ts;
	int region;
}RTGLBInfoInfo;

typedef struct stSimulatiorVector :TCMD
{
	/// <summary>
	/// 上一帧方向单位向量的坐标值
	/// </summary>
	float lastForwardX;
	float lastForwardY;
	float lastForwardZ;
	/// <summary>
	/// 当前帧方向单位向量的坐标值
	/// </summary>
	float curForwardX;
	float curForwardY;
	float curForwardZ;

	stSimulatiorVector()
	{
		nType = NetType::DT_SyncTrainDirction;
		lastForwardX = 0.0f;
		lastForwardY = 0.0f;
		lastForwardZ = 0.0f;
		curForwardX = 0.0f;
		curForwardY = 0.0f;
		curForwardZ = 0.0f;
	}

	void SetSimulatiorVector(float lx, float ly, float lz, float cx, float cy, float cz)
	{
		nType = NetType::DT_SyncTrainDirction;
		lastForwardX = lx;
		lastForwardY = ly;
		lastForwardZ = lz;
		curForwardX = cx;
		curForwardY = cy;
		curForwardZ = cz;
	}
}SimulatiorVector;

/// <summary>
/// 设置所有车辆状态
/// <param name="nType">命令头 DT_SetAllStatus</param>
/// <param name="ts">车辆状态</param>
/// </summary>
typedef struct stSetAllST :TCMD
{
	int ts;
}TSetAllST;

/// <summary>
/// 关闭程序 
/// <param name="nType">命令头 DM_Close</param>
/// <param name="timeDelay">延时值</param>
/// time 延时时间s
/// </summary>
typedef struct stCmdClose :TCMD
{
	int timeDelay;
}TCmdClose;


/// <summary>
/// 道岔触发反馈
/// <param name="nType">命令头 RT_SwitchCheck</param>
/// <param name="trainSernubmer">车辆编号（设备号）</param>
/// <param name="strSwitchName">道岔名称</param>
/// <summary>
typedef struct stRTSwCheck :TCMD
{
	char trainSernubmer[16];
	char strSwitchName[16];
}RTSwCheck;



/// <summary>
/// 雨刮器开关
/// <param name="nType">命令头 DT_Wiper</param>
/// <param name="open"> mopen=1 开,0 关</param>
/// </summary>
typedef struct stOpenWiper :TCMD
{
	int mopen;
}TOpenWiper;

/// <summary>
/// 课程设置
/// <param name="nType">命令头 DT_SetCourse</param>         
/// <param name="courseSet">1开始课程，0回到等待界面</param>    
/// <param name="strContent">文字内容 unicode编码</param>
/// </summary>
typedef struct stCourseSet :TCMD
{
	int courseSet;
	char strContent[128];
}TCourseSet;

/// <summary>
/// 车门开关
/// <param name="nType">命令头 DT_Door</param>      
/// <param name="doortype">车门类型 0 右，1左</param>
/// <param name="open">开关选项1开0关</param>
/// </summary>
typedef struct stOpenDoor :TCMD
{
	int doortype;
	int mopen;
}OpenDoor;

/// </summary>
/// 设置所有信号机
/// <param name="nType">命令头 DT_SetAllXHJ</param>   
/// <param name="uclr">1灯</param>
/// <param name="cclr">2灯</param>
/// <param name="dclr">3灯</param>
/// 颜色值 Black =0 Red =1  Yellow= 2 Green=3 White=4 Blue =5;
/// </summary>
typedef struct stSetAllSignal :TCMD
{
	char TrainPhNumber[16];
	
	int uClr;
	int cClr;
	int dClr;
}SetAllSignal;

/// <summary>
/// 房间操作
/// <param name="nType">命令头 DT_OperateRoom</param>    
/// <param name="operate">操作 1,请求加入2,请求离开</param>   
/// </summary>
typedef struct stOperateRoom :TCMD
{
	int operate;
}OperateRoom;

/// <summary>
/// 汽笛
/// <param name="nType">命令头 DT_QiDi</param>   
/// <param name="raise">1开启 0关闭</param>    
/// </summary>
typedef struct stTrainQidi :TCMD
{
	int raise;
}TrainQidi;

/// <summary>
/// <param name="nType">命令头 DT_ChangeMonitor</param> 
/// <param name="swState"> 转变监视器状态 swState 1开启侧视景，2开启站台监视器画面（画面互斥，开启侧视镜关闭监视器，开启监视器关闭侧视镜）</param> 
/// </summary>
typedef struct stChangMonitor :TCMD
{
	char TrainPhNumber[16];
	int swState;
	int n3DStationId;
}ChangMonitor;


/// <summary>
/// 倒计时
/// <param name="nType">命令头 DT_CountDown</param>   
/// <param name="timebase">时间基数</param>
/// <param name="timeCount">步数</param>
/// <param name="timeOps">选项 0 减数,1加数,2扣车,-1取消</param>
/// </summary>
typedef struct stCountDown :TCMD
{
	char TrainPhNumber[16];
	int timeCount;
	int timeBase;
	int timeOps;
	char TimeName[16];
}CountDown;

//考试信息显示
typedef struct stExamInfo :TCMD
{
	char trainSernubmer[16];
	int bShow;//0关闭显示 1考试文字显示
	char content[200];//左上角显示文字如 单侧车门故障考试 utf8编码
	int minute;//考试时间 分钟数如120分钟；左上角 3d显示一个倒计时：01:29:55 表示还有1小时29分钟55秒 
	stExamInfo()
	{
		memset(this, 0, sizeof(*this));
		nType = DT_Exam;
	}
}ExamInfo;

}
#pragma pack(pop)
#endif	
