#ifndef __COMMONHEAADER_H_
#define __COMMONHEAADER_H_

#pragma pack(push,1)

typedef unsigned char byte;
#define MAX_ANGLE_DEF (8.0)

enum E_Cmd_Code
{
	E_Cmd_Code_Wait=0,				// 待机
	E_Cmd_Code_Work=1,				// 工作
	E_Cmd_Code_Stop=2,				// 停止
	E_Cmd_Code_Pause=3,				// 暂停

	E_Cmd_Code_NoCtrl=0x00,			// 无操作
	E_Cmd_Code_ServerOff=0x10,		// 主机关闭(上位机断开指令)

	E_Cmd_Code_NoWash = 0x00,		// 不采用洗出
	E_Cmd_Code_Wash = 0x20,			// 采用洗出
};

enum E_Boad_Status
{
	E_Boad_Status_Null=0,			// 未知（不可同行）
	E_Boad_Status_Up=1,				// 抬起（不可同行）
	E_Boad_Status_Down=2,			// 落下（可通行）
	E_Boad_Status_Error=4,			// 采集系统故障
};


typedef struct _FrameHead
{
	byte frameHead1;			// 帧头1
	byte frameHead2;			// 帧头2
}FrameHead;

/*操作数据包*/
typedef struct _SimulatorCtrlData
{
	FrameHead frameHead;		// 帧头

	float lateralOffset;		// 侧向位移
	float forwordOffset;		// 向前位移
	float heightOffset;			// 垂直升降
	float roll;					// 横滚(分辨率0.01)
	float pitch;				// 俯仰(分辨率0.01)
	float yaw;					// 航向(分辨率0.01)

	byte specialAction;			// 特殊动作规则表
	byte speedChange;			// 变速字节
	byte specialEffect;			// 特效
	byte angleHigh;				// 角度高字节
	byte angleLow;				// 角度低字节
	byte frameTail;				// 帧尾校验（从第二个字节到倒数第二个字节累加和的低 8 位）

	_SimulatorCtrlData()
	{
		memset(this, 0, sizeof(_SimulatorCtrlData));
	}

	// 1~30字节的求和取低八位
	char GetSumLow8Bit()
	{
		unsigned char cRet = 0;
		int nCount = sizeof(_SimulatorCtrlData);
		for (int i = 1; i < nCount - 1; ++i)
		{
			cRet += ((char*)this)[i];
		}

		return cRet;
	}

	void SetSumLow8Bit()
	{
		int nCount = sizeof(_SimulatorCtrlData);
		for (int i = 1; i < nCount - 1; ++i)
		{
			this->frameTail += ((char*)this)[i];
		}
	}

}SimulatorCtrlData;

typedef struct _SimulationCtrlWashInfo
{
	unsigned int time;			// 时间戳（毫秒）
	float offsetX;				// x方向偏移(mm)
	float offsetY;				// y方向偏移(mm)
	float offsetZ;				// z方向偏移(mm)
	float roll;					// x轴旋转角度(°)
	float pitch;				// y轴旋转角度(°)
	float yaw;					// z轴旋转角度(°)

	float accX;					// x轴方向加速度(°)
	float accY;					// y轴方向加速度(°)
	float accZ;					// z轴方向加速度(°)
	float rotateSpeedX;			// 绕x轴旋转角速度
	float rotateSpeedY;			// 绕y轴旋转角速度
	float rotateSpeedZ;			// 绕z轴旋转角速度

	byte retain[4];				// 预留

	byte ctrlCMD;				// 控制指令 前2bit（0：待机1：工作2：停止3：暂停），第5bit（0：无操作，1：主站关机），第6bit（0：不采用洗出，1：采用洗出）
	byte length;				// 长度
	byte velocity;				// 速度
	byte acc;					// 加速度

	byte retain1[3];			// 保留

	byte frameTail;				// 校验

	_SimulationCtrlWashInfo()
	{
		memset(this, 0, sizeof(_SimulationCtrlWashInfo));
	}

	// 0~30字节的求和取低八位
	unsigned char GetSumLow8Bit()
	{
		unsigned char cRet = 0;
		int nCount = sizeof(_SimulationCtrlWashInfo);
		for (int i = 0; i < nCount - 1; ++i)
		{
			cRet += ((char*)this)[i];
		}

		return cRet;
	}

	void SetLow8Bit()
	{
		int nCount = sizeof(_SimulationCtrlWashInfo);
		for (int i = 0; i < nCount - 1; ++i)
		{
			this->frameTail += ((char*)this)[i];
		}
	}

}SimulationCtrlWashInfo;

/*操作数据包返回模拟器状态数据 0XFBFD  OXFBF9 两个包都可以使用*/
typedef struct _SimulatorData
{
	FrameHead frameHead;		// 帧头

	float magneticLenth[6];		// 1号电缸伸缩长度

	byte retain;				// 保留
	unsigned int virsion;		// 版本
	byte frameTail;				// 帧尾校验（校验和，从第 Byte0 到 Byte30 的和校验）

	_SimulatorData()
	{
		memset(this, 0, sizeof(_SimulatorData));
	}

	// 0~30字节的求和取低八位
	unsigned char GetSumLow8Bit()
	{
		unsigned char cRet = 0;
		int nCount = sizeof(_SimulatorData);
		for (int i = 0; i < nCount - 1; ++i)
		{
			cRet += ((char*)this)[i];
		}

		return cRet;
	}

	void SetLow8Bit()
	{
		int nCount = sizeof(_SimulatorData);
		for (int i = 0; i < nCount - 1; ++i)
		{
			this->frameTail += ((char*)this)[i];
		}
	}
}SimulatorData;

typedef struct _HeartBeatData
{
	FrameHead frameHead;		// 帧头

	byte retain1;				// 保留
	byte retain2;				// 保留

	float transformer;			// 1号电缸编码器反馈值，单位为电缸总行程 / 65535；最大值为 65535。假设当前电缸总行程为 200mm，当返回 6553 时，表示当前电缸处于约 20mm 的伸长量位置。
	byte retain[19];			// 保留

	short rotatingShaft;		// 旋转轴数值 -180~+180
	byte lowMagneticSwitch;		// 下磁性开关状态
	byte highMagneticSwitch;	// 上磁性开关状态
	byte retain3;				// 保留

	_HeartBeatData()
	{
		memset(this, 0, sizeof(_HeartBeatData));
	}
}HeartBeatData;

/*模拟器请求数据  0XFBF9 */
typedef struct _SimulationStatusRequest
{

}SimulationStatusRequest;


enum E_SimulationPlatformStatus
{
	E_SimulationPlatformStatus_Unkown=0,	// 未知
	E_SimulationPlatformStatus_Awake,		// 激活
	E_SimulationPlatformStatus_Sleep,		// 关闭
};

enum E_SimulationFlat_UpDown_Type
{
	E_SimulationFlat_UpDown_Type_Unkown=-1,	// 未知
	E_SimulationFlat_UpDown_Type_Up,		// 上行
	E_SimulationFlat_UpDown_Type_Down,		// 下行
};

typedef struct _RailWayPointNodeForPitch
{
	double maxRange;				// 范围
	double rate;				// 千分度(1000米范围的高度变化率)
	double distance;			// 长度
	double height;				// 高度

	double pitch;				// 俯仰角(°)

	_RailWayPointNodeForPitch()
	{
		memset(this, 0, sizeof(_RailWayPointNodeForPitch));
	}

}RailWayPointNodeForPitch;

typedef struct _RailWayPointNodeForRoll
{
	double maxRange;				// 范围
	double distance;			// 长度(弧长)
	double radius;				// 半径
	char  side;					// 左右（0为直线）

	double roll;				// 横滚角(°)
	double yaw;					// 航向角(°)

	_RailWayPointNodeForRoll()
	{
		int nSize = sizeof(_RailWayPointNodeForRoll);
		memset(this, 0, sizeof(_RailWayPointNodeForRoll));
	}

}RailWayPointNodeForRoll;

typedef struct _RailWayPointKey
{
	double range;				// 公里标开始点
	double distance;			// 长度
	double maxRange;			// 极值

	_RailWayPointKey()
	{
		memset(this, 0, sizeof(_RailWayPointKey));
	}

	bool operator<(const _RailWayPointKey& other) const
	{
		return this->range < other.range;
	}

	bool findRight(const double& point) const
	{
		if (point >= range && point < maxRange)
		{
			return true;
		}

		return false;
	}

}RailWayPointKey;

//登车梯状态 消息ID 0x45
typedef struct stBoardingData
{
	int cmd = 0;//默认0
	int boardingUp;//1 登车梯升到位
	int boardingDown;//1 登车梯降到位
	int tractionGrade;//牵引档位 0~100
	int brakeGrade;//制动速档位 0~100
	int adsStatus;//-1采集系统故障 0正常
	int runMode;// 0 手动模式 1 自动驾驶模式
	int eb;//0 无EB 1 eb
	int dir;// 0向前 1后退
	stBoardingData()
	{
		memset(this, 0, sizeof(*this));
	}
}BoardingData;

#pragma pack(pop)
#endif
