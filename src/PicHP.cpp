// PicHP.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#include "pubtool.h"
#include "runall.h"

#pragma comment(lib, "CQP.lib")

static __int32 sg_authCode = 0;

#define cq_bool_t __int32

extern "C" __int32 __stdcall CQ_sendPrivateMsg(__int32 auth_code, __int64 qq, const char *msg);
extern "C" __int32 __stdcall CQ_sendGroupMsg(__int32 auth_code, __int64 group_id, const char *msg);
extern "C" const char * __stdcall CQ_getAppDirectory(__int32 auth_code);
extern "C" __int32 __stdcall CQ_addLog(__int32 auth_code, __int32 log_level, const char *category, const char *log_msg);


/* 接收authCode */
extern "C" __int32 __stdcall Initialize(__int32 authCode)
{
	sg_authCode = authCode;
	return 0;
}


/* 插件启用事件 type = 1003 */
extern "C" __int32 __stdcall event_enable()
{
	if(FilePathExists((CQ_getAppDirectory(sg_authCode) + std::string("config.ini")).c_str()) != TRUE)
	{
		WritePrivateProfileStringA("Setting","Proxy","",(CQ_getAppDirectory(sg_authCode) + std::string("config.ini")).c_str());
	}
	return 0;
}


/* 私聊事件 type = 21 */
extern "C" __int32 __stdcall event_private_message(__int32 sub_type, __int32 msg_id, __int64 from_qq, const char *msg, __int32 font)
{
	std::string inputData = msg;
	std::string fitstCmd;
	std::string secondCmd;
	std::string data;
	

	try{

		SpliteInput(inputData,fitstCmd,secondCmd,data);
		if(fitstCmd == "super")
		{
			replace_all_distinct(data, "&amp;", "&");
			replace_all_distinct(data, "&#91;", "[");
			replace_all_distinct(data, "&#93;", "]");
			replace_all_distinct(data, "&#44;", ",");

			char proxy[1024] = {0};
			GetPrivateProfileStringA("Setting","Proxy","",proxy,sizeof(proxy),(CQ_getAppDirectory(sg_authCode) + std::string("config.ini")).c_str());
			std::string ret = UTF8ToGBK(RunAll(secondCmd,GBKToUTF8(data),proxy));
			//std::string ret = RunAll(secondCmd,data,"127.0.0.1:10809");

			replace_all_distinct(data, "&", "&amp;");
			replace_all_distinct(data, "[", "&#91;");
			replace_all_distinct(data, "]", "&#93;");
			replace_all_distinct(data, ",", "&#44;");
	
			char sendMsg[100] = {0}; 
			sprintf_s(sendMsg,"[CQ:at,qq=%ld]\n",from_qq);

			CQ_sendPrivateMsg(sg_authCode,from_qq,(sendMsg + ret).c_str());
		}
		
	}catch(std::exception & e)
	{
		CQ_addLog(sg_authCode,1,"error",e.what());
	}
	return 0;
}

/* 群聊事件 type = 2 */
extern "C" __int32 __stdcall event_group_message(__int32 sub_type, __int32 msg_id, __int64 from_group, __int64 from_qq, const char *from_anonymous_base64,const char *msg, __int32 font)
{

	std::string inputData = msg;
	std::string fitstCmd;
	std::string secondCmd;
	std::string data;
	

	try{

		SpliteInput(inputData,fitstCmd,secondCmd,data);
		if(fitstCmd == "super")
		{
			replace_all_distinct(data, "&amp;", "&");
			replace_all_distinct(data, "&#91;", "[");
			replace_all_distinct(data, "&#93;", "]");
			replace_all_distinct(data, "&#44;", ",");

			char proxy[1024] = {0};
			GetPrivateProfileStringA("Setting","Proxy","",proxy,sizeof(proxy),(CQ_getAppDirectory(sg_authCode) + std::string("config.ini")).c_str());
			std::string ret = UTF8ToGBK(RunAll(secondCmd,GBKToUTF8(data),proxy));
			//std::string ret = RunAll(secondCmd,data,"127.0.0.1:10809");

			replace_all_distinct(data, "&", "&amp;");
			replace_all_distinct(data, "[", "&#91;");
			replace_all_distinct(data, "]", "&#93;");
			replace_all_distinct(data, ",", "&#44;");
	
			char sendMsg[100] = {0}; 
			sprintf_s(sendMsg,"[CQ:at,qq=%ld]\n",from_qq);

			CQ_sendGroupMsg(sg_authCode,from_group,(sendMsg + ret).c_str());
		}
		
	}catch(std::exception & e)
	{
		CQ_addLog(sg_authCode,1,"error",e.what());
	}
	return 0;
}






