#ifndef __IBUSCLIENT__H__
#define __IBUSCLIENT__H__

#ifdef BUSCLIENTV3_EXPORTS
#define BUSCLIENT_API __declspec(dllexport)
#else
#define BUSCLIENT_API __declspec(dllimport)
#pragma comment(lib,"BusClientv3.lib")
#endif

#include "PackData.h"
class IBusClient;
/*enum EnClientState
{
	en_connected, //连接上服务器时的状态
	en_disconnected,//连接断开时状态
	en_reconnecting //正在重连
};*/

//数据处理函数指针类型
typedef void (*BusDataCallback) (ClientPackData* pData,void* arg);

//状态改变时函数指针定义
typedef void(*BusStateChangeCallback) (IBusClient* pClient,EnClientState state, void* arg);


class IBusClient
{
public:
	virtual ~IBusClient(){}
	//************************************
	// Method:    SetDataCallback
	// FullName:  IBusClient::SetDataCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier: 设置数据接收到以后的回调函数
	// Parameter: BusDataCallback dataCb 函数指针
	// Parameter: void* arg 调用回调函数时附带的arg参数
	//************************************
	virtual void SetDataCallback(BusDataCallback cb, void* arg) = 0;

	//************************************
	// Method:    SetStateChangeCallback
	// FullName:  IBusClient::SetStateChangeCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:设置client状态改变时回调函数
	// Parameter: BusStateChangeCallback cb 回调函数指针
	// Parameter: void * arg 调用回调函数时的附加参数指针
	//************************************
	virtual void SetStateChangeCallback(BusStateChangeCallback cb, void* arg) = 0;

	//************************************
	// Method:    Start
	// FullName:  IBusClient::Start
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: 启动客户端连接，必须先启动才能发送数据与接收数据
	//************************************
	virtual bool Start() = 0;

	//************************************
	// Method:    Stop
	// FullName:  IBusClient::Stop
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:调用Stop后断开与服务端的连接，不能再发送数据
	//************************************
	virtual bool Stop() = 0;

	//************************************
	// Method:    SendData
	// FullName:  IBusClient::SendData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: 调用该接口发送数据
	// Parameter: byte id 发送数据的ID
	// Parameter: const byte * data 要发送的数据
	// Parameter: ushort size 发送的数据长度
	//************************************
	virtual bool SendData(byte id,const byte* data,ushort size) = 0;

	//************************************
	// Method:    GetClientId
	// FullName:  IBusClient::GetIdCode
	// Access:    virtual public 
	// Returns:   uint
	// Qualifier:获取客户端ID v3
	//************************************
	virtual uint GetIdCode() = 0;


	//************************************
	// Method:    GetSubscribeData
	// FullName:  IBusClient::GetSubscribeData
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:获取订阅的数据id
	// Parameter: byte subsData[255]
	// Parameter: int outCount
	//************************************
	virtual void GetSubscribeData(byte subIds[255], int *outCount) = 0;

	//************************************
	// Method:    SetSubscribeData
	// FullName:  IBusClient::SetSubscribeData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:动态设置订阅数据id
	// Parameter: byte * subsData
	// Parameter: int count
	//************************************
	virtual bool SetSubscribeData(byte* subIds,int inCount) = 0;
};
#ifdef __cplusplus
extern "C" {
#endif
	//************************************
	// Method:    CreateIBusClient
	// FullName:  CreateIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API IBusClient*
	// Qualifier: 创建一个客户端
	// Parameter: const char * clientId 配置文件中的客户端配置ID
	// Parameter: char * err 如果创建失败，返回错误信息
	//************************************
	BUSCLIENT_API IBusClient* CreateIBusClient(const char* clientId, char* err);

	//************************************
	// Method:    ReleaseIBusClient
	// FullName:  ReleaseIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API void
	// Qualifier:释放已经创建的客户端
	// Parameter: IBusClient * pClient 已经创建的客户端指针
	//************************************
	BUSCLIENT_API void ReleaseIBusClient(IBusClient *pClient);


	/***********************************************************/
	/***********************************************************/
	/*************************以下为c接口************************/
	/***********************************************************/
	/***********************************************************/
	typedef  void* HBusClient;

	typedef void(*HBusStateChangeCallback) (HBusClient pClient, EnClientState state, void* arg);

	//************************************
	// Method:    CreateHBusClient
	// FullName:  CreateHBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API HBusClient
	// Qualifier:创建客户端句柄
	// Parameter: const char * clientId
	// Parameter: char * err
	//************************************
	BUSCLIENT_API HBusClient CreateHBusClient(const char* clientId, char* err);

	//************************************
	// Method:    ReleaseIBusClient
	// FullName:  ReleaseIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API void
	// Qualifier:释放客户端句柄
	// Parameter: HBusClient hClient
	//************************************
	BUSCLIENT_API void ReleaseHBusClient(HBusClient hClient);

	//************************************
	// Method:    SetDataCallback
	// FullName:  IBusClient::SetDataCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier: 设置数据接收到以后的回调函数
	// Parameter: BusDataCallback dataCb 函数指针
	// Parameter: void* arg 调用回调函数时附带的arg参数
	//************************************
	BUSCLIENT_API void SetDataCallback(HBusClient hClient,BusDataCallback cb, void* arg);

	//************************************
	// Method:    SetStateChangeCallback
	// FullName:  IBusClient::SetStateChangeCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:设置client状态改变时回调函数
	// Parameter: BusStateChangeCallback cb 回调函数指针
	// Parameter: void * arg 调用回调函数时的附加参数指针
	//************************************
	BUSCLIENT_API void SetStateChangeCallback(HBusClient hClient, HBusStateChangeCallback cb, void* arg);

	//************************************
	// Method:    Start
	// FullName:  IBusClient::Start
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: 启动客户端连接，必须先启动才能发送数据与接收数据
	//************************************
	BUSCLIENT_API bool Start(HBusClient hClient);

	//************************************
	// Method:    Stop
	// FullName:  IBusClient::Stop
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:调用Stop后断开与服务端的连接，不能再发送数据
	//************************************
	BUSCLIENT_API bool Stop(HBusClient hClient);

	//************************************
	// Method:    SendData
	// FullName:  IBusClient::SendData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: 调用该接口发送数据
	// Parameter: byte id 发送数据的ID
	// Parameter: const byte * data 要发送的数据
	// Parameter: ushort size 发送的数据长度
	//************************************
	BUSCLIENT_API bool SendData(HBusClient hClient, byte id, const byte* data, ushort size);


	//获取客户端ID v3
	BUSCLIENT_API uint GetIdCode(HBusClient hClient);


	//************************************
	// Method:    GetSubscribeData
	// FullName:  IBusClient::GetSubscribeData
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:获取订阅的数据id
	// Parameter: byte subsData[255]
	// Parameter: int outCount
	//************************************
	BUSCLIENT_API void GetSubscribeData(HBusClient hClient,byte subIds[255], int *outCount);

	//************************************
	// Method:    SetSubscribeData
	// FullName:  IBusClient::SetSubscribeData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:动态设置订阅数据id
	// Parameter: byte * subsData
	// Parameter: int count
	//************************************
	BUSCLIENT_API bool SetSubscribeData(HBusClient hClient,byte* subIds, int inCount);

#ifdef __cplusplus
}
#endif
#endif //__IBUSCLIENT__H__