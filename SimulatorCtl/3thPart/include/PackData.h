#ifndef __STCLIENTPACKDATA_H__
#define __STCLIENTPACKDATA_H__
#include <string.h>
//客户端数据发送包定义
#ifndef safeDelete
#define safeDelete(p) {if((p)!=NULL){ delete (p);(p)=NULL; }}
#endif

#ifndef safeDeleteArr
#define safeDeleteArr(p) {if((p)!=NULL){ delete [](p);(p)=NULL; }}
#endif

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;

#define MAXPACK_LEN   4096 //每个数据包最长字节数目


#pragma pack(push,1)


//包头定义
typedef struct stPackHead
{
	byte head1;//包头0xaa
	byte head2;//包头0xff
	byte cmd;//消息类型 0x00 普通数据 ;0xaf 订阅消息; 0x01 打洞消息 ;0x02 心跳消息 ;0x03 控制消息;0x04 设置id
	byte id;//数据标识0~0xFF
	char ip[16];//发送者ip
	uint idCode;//客户端id v3新增
	uint port;//发送者端口
	stPackHead()
	{
		head1 = 0xaa;
		head2 = 0xff;
		cmd = 0;
		id = 0;
		idCode = 0;
		memset(ip, 0, sizeof(ip));
	}
}PackHead;

//客户端发送的数据包
typedef struct stClientPackData
{
	stClientPackData()
	{
		dataSize = 0;
		data = NULL;
	}
	stClientPackData(byte id, const byte* buffer, uint size)
	{
		stClientPackData::stClientPackData();
		if (buffer == NULL || size == 0)
		{
			this->data = NULL;
			this->dataSize = size;
			return;
		}
		this->data = new byte[size];
		if (this->data != NULL)
		{
			memcpy(this->data, buffer, size);
			this->dataSize = size;
		}
	}
	stClientPackData(const stClientPackData &other)
	{
		*this = other;
	}
	stClientPackData& operator=(const stClientPackData &other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->head = other.head;
		this->dataSize = other.dataSize;
		safeDeleteArr(this->data);
		if (other.data != NULL&& other.dataSize > 0)
		{
			this->data = new byte[other.dataSize];
			if (this->data != NULL)
			{
				memcpy(this->data, other.data, other.dataSize);
			}
		}
	}
	~stClientPackData()
	{
		safeDeleteArr(this->data);
	}
	stPackHead head;
	ushort dataSize;//数据长度
	byte* data;//数据缓冲区
}ClientPackData;


//订阅消息
typedef struct stSubscibeData
{
	PackHead head;//数据头
	ushort count;//订阅的数据个数
	byte dataIds[255];//最多订阅255种数据
	stSubscibeData()
	{
		head.cmd = 0xaf;
		head.head1 = 0xaa;
		head.head2 = 0xff;
		head.id = 0;
		head.idCode = 0;
		memset(head.ip, 0, sizeof(head.ip));
		head.port = 0;
		count = 0;
		memset(dataIds, 0, 255);
	}
}SubscibeData;

enum EnClientState
{
	en_connected, //连接上服务器时的状态
	en_disconnected,//连接断开时状态
	en_reconnecting //正在重连
};

//udp心跳数据
typedef struct stBusHeartbeat
{
	PackHead head;//数据头
	ushort len;
	byte data[4];

	stBusHeartbeat()
	{
		len = 4;
	}
}BusHeartbeat;

//设置ID数据
typedef struct  stBusSetIdCode
{
	PackHead head;//数据头
	ushort len;
	uint idCode;
	stBusSetIdCode()
	{
		idCode = 0;
		len = sizeof(idCode);
		head.cmd = 0x04;
	}
}BusSetIdCode;


//udp通信数据
typedef struct stBusP2pData
{
	PackHead head;//数据头
	ushort len;
	uint idCode;

	stBusP2pData()
	{
		head.cmd = 0x01;
		len = sizeof(idCode);
	}
}BusP2pData;

typedef struct stBusControl
{
	PackHead head;//数据头
	ushort len;
	uint ctr[4];
	

	stBusControl()
	{
		head.cmd = 0x01;
		len = sizeof(uint)*4;
	}
}BusControl;


#pragma pack(pop)


#endif //__STCLIENTPACKDATA_H__