#ifndef __COMMONHEAADER_H_
#define __COMMONHEAADER_H_

#pragma pack(push,1)

typedef unsigned char byte;
#define MAX_ANGLE_DEF (8.0)

enum E_Cmd_Code
{
	E_Cmd_Code_Wait=0,				// ����
	E_Cmd_Code_Work=1,				// ����
	E_Cmd_Code_Stop=2,				// ֹͣ
	E_Cmd_Code_Pause=3,				// ��ͣ

	E_Cmd_Code_NoCtrl=0x00,			// �޲���
	E_Cmd_Code_ServerOff=0x10,		// �����ر�(��λ���Ͽ�ָ��)

	E_Cmd_Code_NoWash = 0x00,		// ������ϴ��
	E_Cmd_Code_Wash = 0x20,			// ����ϴ��
};

enum E_Boad_Status
{
	E_Boad_Status_Null=0,			// δ֪������ͬ�У�
	E_Boad_Status_Up=1,				// ̧�𣨲���ͬ�У�
	E_Boad_Status_Down=2,			// ���£���ͨ�У�
	E_Boad_Status_Error=4,			// �ɼ�ϵͳ����
};


typedef struct _FrameHead
{
	byte frameHead1;			// ֡ͷ1
	byte frameHead2;			// ֡ͷ2
}FrameHead;

/*�������ݰ�*/
typedef struct _SimulatorCtrlData
{
	FrameHead frameHead;		// ֡ͷ

	float lateralOffset;		// ����λ��
	float forwordOffset;		// ��ǰλ��
	float heightOffset;			// ��ֱ����
	float roll;					// ���(�ֱ���0.01)
	float pitch;				// ����(�ֱ���0.01)
	float yaw;					// ����(�ֱ���0.01)

	byte specialAction;			// ���⶯�������
	byte speedChange;			// �����ֽ�
	byte specialEffect;			// ��Ч
	byte angleHigh;				// �Ƕȸ��ֽ�
	byte angleLow;				// �Ƕȵ��ֽ�
	byte frameTail;				// ֡βУ�飨�ӵڶ����ֽڵ������ڶ����ֽ��ۼӺ͵ĵ� 8 λ��

	_SimulatorCtrlData()
	{
		memset(this, 0, sizeof(_SimulatorCtrlData));
	}

	// 1~30�ֽڵ����ȡ�Ͱ�λ
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
	unsigned int time;			// ʱ��������룩
	float offsetX;				// x����ƫ��(mm)
	float offsetY;				// y����ƫ��(mm)
	float offsetZ;				// z����ƫ��(mm)
	float roll;					// x����ת�Ƕ�(��)
	float pitch;				// y����ת�Ƕ�(��)
	float yaw;					// z����ת�Ƕ�(��)

	float accX;					// x�᷽����ٶ�(��)
	float accY;					// y�᷽����ٶ�(��)
	float accZ;					// z�᷽����ٶ�(��)
	float rotateSpeedX;			// ��x����ת���ٶ�
	float rotateSpeedY;			// ��y����ת���ٶ�
	float rotateSpeedZ;			// ��z����ת���ٶ�

	byte retain[4];				// Ԥ��

	byte ctrlCMD;				// ����ָ�� ǰ2bit��0������1������2��ֹͣ3����ͣ������5bit��0���޲�����1����վ�ػ�������6bit��0��������ϴ����1������ϴ����
	byte length;				// ����
	byte velocity;				// �ٶ�
	byte acc;					// ���ٶ�

	byte retain1[3];			// ����

	byte frameTail;				// У��

	_SimulationCtrlWashInfo()
	{
		memset(this, 0, sizeof(_SimulationCtrlWashInfo));
	}

	// 0~30�ֽڵ����ȡ�Ͱ�λ
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

/*�������ݰ�����ģ����״̬���� 0XFBFD  OXFBF9 ������������ʹ��*/
typedef struct _SimulatorData
{
	FrameHead frameHead;		// ֡ͷ

	float magneticLenth[6];		// 1�ŵ����������

	byte retain;				// ����
	unsigned int virsion;		// �汾
	byte frameTail;				// ֡βУ�飨У��ͣ��ӵ� Byte0 �� Byte30 �ĺ�У�飩

	_SimulatorData()
	{
		memset(this, 0, sizeof(_SimulatorData));
	}

	// 0~30�ֽڵ����ȡ�Ͱ�λ
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
	FrameHead frameHead;		// ֡ͷ

	byte retain1;				// ����
	byte retain2;				// ����

	float transformer;			// 1�ŵ�ױ���������ֵ����λΪ������г� / 65535�����ֵΪ 65535�����赱ǰ������г�Ϊ 200mm�������� 6553 ʱ����ʾ��ǰ��״���Լ 20mm ���쳤��λ�á�
	byte retain[19];			// ����

	short rotatingShaft;		// ��ת����ֵ -180~+180
	byte lowMagneticSwitch;		// �´��Կ���״̬
	byte highMagneticSwitch;	// �ϴ��Կ���״̬
	byte retain3;				// ����

	_HeartBeatData()
	{
		memset(this, 0, sizeof(_HeartBeatData));
	}
}HeartBeatData;

/*ģ������������  0XFBF9 */
typedef struct _SimulationStatusRequest
{

}SimulationStatusRequest;


enum E_SimulationPlatformStatus
{
	E_SimulationPlatformStatus_Unkown=0,	// δ֪
	E_SimulationPlatformStatus_Awake,		// ����
	E_SimulationPlatformStatus_Sleep,		// �ر�
};

enum E_SimulationFlat_UpDown_Type
{
	E_SimulationFlat_UpDown_Type_Unkown=-1,	// δ֪
	E_SimulationFlat_UpDown_Type_Up,		// ����
	E_SimulationFlat_UpDown_Type_Down,		// ����
};

typedef struct _RailWayPointNodeForPitch
{
	double maxRange;				// ��Χ
	double rate;				// ǧ�ֶ�(1000�׷�Χ�ĸ߶ȱ仯��)
	double distance;			// ����
	double height;				// �߶�

	double pitch;				// ������(��)

	_RailWayPointNodeForPitch()
	{
		memset(this, 0, sizeof(_RailWayPointNodeForPitch));
	}

}RailWayPointNodeForPitch;

typedef struct _RailWayPointNodeForRoll
{
	double maxRange;				// ��Χ
	double distance;			// ����(����)
	double radius;				// �뾶
	char  side;					// ���ң�0Ϊֱ�ߣ�

	double roll;				// �����(��)
	double yaw;					// �����(��)

	_RailWayPointNodeForRoll()
	{
		int nSize = sizeof(_RailWayPointNodeForRoll);
		memset(this, 0, sizeof(_RailWayPointNodeForRoll));
	}

}RailWayPointNodeForRoll;

typedef struct _RailWayPointKey
{
	double range;				// ����꿪ʼ��
	double distance;			// ����
	double maxRange;			// ��ֵ

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

//�ǳ���״̬ ��ϢID 0x45
typedef struct stBoardingData
{
	int cmd = 0;//Ĭ��0
	int boardingUp;//1 �ǳ�������λ
	int boardingDown;//1 �ǳ��ݽ���λ
	int tractionGrade;//ǣ����λ 0~100
	int brakeGrade;//�ƶ��ٵ�λ 0~100
	int adsStatus;//-1�ɼ�ϵͳ���� 0����
	int runMode;// 0 �ֶ�ģʽ 1 �Զ���ʻģʽ
	int eb;//0 ��EB 1 eb
	int dir;// 0��ǰ 1����
	stBoardingData()
	{
		memset(this, 0, sizeof(*this));
	}
}BoardingData;

#pragma pack(pop)
#endif
