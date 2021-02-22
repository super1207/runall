#include "StdAfx.h"
#include "runall.h"

#include <vector>
#include <string>

using namespace std;

#define CURL_STATICLIB

#include "libcurl/include/curl.h"

#pragma comment(lib, "libcurl/lib/libcurl.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "Crypt32.Lib")


#include "jsoncpp/include/json.h"
#pragma comment(lib, "jsoncpp/lib/jsoncpp.lib")

static std::vector<std::vector<std::string> > GetLanVec()
{
	std::vector<std::vector<std::string> > retVec;

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("assembly");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("asm");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("ats");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("sh");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("bash");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("dats");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("c");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("c");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("clojure");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("clj");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("cobol");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("cob");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("coffeescript");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("coffee");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("cpp");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("cpp");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("crystal");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("cr");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("csharp");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("cs");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("d");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("d");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("elixir");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("ex");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("elm");
	retVec.at(retVec.size() - 1).push_back("Main");
	retVec.at(retVec.size() - 1).push_back("elm");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("erlang");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("erl");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("fsharp");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("fs");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("go");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("go");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("groovy");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("groovy");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("haskell");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("hs");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("idris");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("idr");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("java");
	retVec.at(retVec.size() - 1).push_back("Main");
	retVec.at(retVec.size() - 1).push_back("java");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("javascript");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("js");


	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("julia");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("jl");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("kotlin");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("kt");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("lua");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("lua");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("mercury");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("m");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("nim");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("nim");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("ocaml");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("ml");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("perl");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("pl");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("perl6");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("pl6");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("php");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("php");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("plaintext");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("txt");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("python");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("py");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("ruby");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("rb");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("rust");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("rs");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("scala");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("scala");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("swift");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("swift");

	retVec.push_back(std::vector<std::string>());
	retVec.at(retVec.size() - 1).push_back("typescript");
	retVec.at(retVec.size() - 1).push_back("main");
	retVec.at(retVec.size() - 1).push_back("ts");

	return retVec;

}


static  std::vector<std::vector<std::string> > gs_retVec = GetLanVec();


//curl回调
static size_t DownloadCallback(void *buffer, size_t sz, size_t nmemb, void *writer)
{
    using namespace std;
    string *response = (string *) writer;
    size_t size = sz * nmemb;
    response->append((char *) buffer, size);
    return sz * nmemb;
}



std::string RunAll(const std::string & cmd,const std::string & data,const std::string & proxy)
{
	size_t pos;
	for(pos = 0;pos < gs_retVec.size();++pos)
	{
		if(gs_retVec.at(pos).at(2) == cmd)
		{
			break;
		}
	}
	if(pos ==  gs_retVec.size())
	{
		throw std::exception("no this language");
	}


	string postUrl = "https://glot.io/run/" + gs_retVec.at(pos).at(0) + "?version=latest";
	//printf("%s\n",postUrl.c_str());
	string resultStr;

	CURL * curl = curl_easy_init();
	if(!curl)
	{
		return "curl_easy_init error";
	}

	//设置代理，方便抓包
	if(proxy != "")
	{
		 curl_easy_setopt(curl, CURLOPT_PROXY, proxy.c_str());
	}
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_URL, postUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DownloadCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resultStr);
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	curl_easy_setopt( curl, CURLOPT_CONNECTTIMEOUT, 10); //连接超时


	curl_slist *headerList = NULL;
    headerList = curl_slist_append(headerList, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36");
	headerList = curl_slist_append(headerList, "Content-Type: application/json");
	headerList = curl_slist_append(headerList, "Accept: application/json, text/javascript, */*; q=0.01");
	headerList = curl_slist_append(headerList, "Cache-Control: no-cache");
	headerList = curl_slist_append(headerList, "Host: glot.io");
	headerList = curl_slist_append(headerList, "X-Requested-With: XMLHttpRequest");
	headerList = curl_slist_append(headerList, "Origin: https://glot.io");


	Json::Value root;
	root["files"][0]["name"] = gs_retVec.at(pos).at(1) + "." + gs_retVec.at(pos).at(2);
	root["files"][0]["content"] = data;
	root["files"][0]["stdin"] = "";
	root["files"][0]["command"] = "";
	string inputData = Json::FastWriter().write(root);
	//printf("%s\n",inputData.c_str());

	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, inputData.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, inputData.length());

	CURLcode curlRes = curl_easy_perform(curl);
	if (curlRes != CURLE_OK)
    {
		curl_slist_free_all(headerList);
		curl_easy_cleanup(curl);
		resultStr = string("curl error:") + curl_easy_strerror(curlRes);
		return resultStr;
    }
	Json::Reader reader;
	//printf("%s\n",resultStr.c_str());
	if(!reader.parse(resultStr, root))
	{
		curl_slist_free_all(headerList);
		curl_easy_cleanup(curl);
		resultStr = "json parse error";
		return resultStr;
	}
	if(root["message"].isString())
	{
		curl_slist_free_all(headerList);
		curl_easy_cleanup(curl);
		resultStr = root["message"].asString();
		return resultStr;
	}
	resultStr = root["stdout"].asString() + root["error"].asString() + root["stderr"].asString();
	curl_slist_free_all(headerList);
	curl_easy_cleanup(curl);
	return resultStr;
}

#include "pubtool.h"
int main()
{
	string inputData = "super py\nwhile True:\n\tpass";
	string fitstCmd;
	string secondCmd;
	string data;
	

	try{

		SpliteInput(inputData,fitstCmd,secondCmd,data);

		replace_all_distinct(data, "&amp;", "&");
		replace_all_distinct(data, "&#91;", "[");
		replace_all_distinct(data, "&#93;", "]");
		replace_all_distinct(data, "&#44;", ",");

		std::string ret = RunAll(secondCmd,data,"127.0.0.1:10809");

		replace_all_distinct(data, "&", "&amp;");
		replace_all_distinct(data, "[", "&#91;");
		replace_all_distinct(data, "]", "&#93;");
		replace_all_distinct(data, ",", "&#44;");

		printf("%s",ret.c_str());
	}catch(std::exception &)
	{
	}
	
	return 0;
}
