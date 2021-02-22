#include "StdAfx.h"
#include "pubtool.h"

#include <string>

using namespace std;

void SpliteInput(const std::string & inputData,std::string & firstCmd,std::string & secondCmd,std::string & data)
{
	string firstLine = "";
	string &  otherData = data;
	otherData = "";
	firstCmd = "";
	secondCmd = "";
	size_t i;
	for(i = 0; i < inputData.length();++i)
	{
		if(inputData.at(i) != '\r' && inputData.at(i) != '\n')
		{
			firstLine += (inputData.at(i));
		}
		else
		{
			++i;
			break;
		}
	}
	for(; i < inputData.length();++i)
	{
		otherData += (inputData.at(i));
	}
	size_t pos = 0;
	for(i = 0; i < firstLine.length();++i)
	{
		if((firstLine.at(i) == ' ' || firstLine.at(i) == '\t') && pos == 0)
		{
			continue;
		}
		if(firstLine.at(i) != ' ' && firstLine.at(i) != '\t' && pos == 0)
		{
			pos = 1;
		}
		if((firstLine.at(i) == ' ' || firstLine.at(i) == '\t') && pos == 1)
		{
			pos = 2;
			continue;
		}
		if(firstLine.at(i) != ' ' && firstLine.at(i) != '\t' && pos == 2)
		{
			pos = 3;
		}
		if(pos == 1)
		{
			firstCmd += (firstLine.at(i));
		}
		if(pos == 3)
		{
			secondCmd += (firstLine.at(i));
		}
	}
}


/*  ÓÃÓÚ×Ö·û´®µÄÌæ»» */
std::string & replace_all_distinct(std::string & str, const std::string & old_value, const std::string & new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}


static BOOL FindFirstFileExists(LPCSTR lpPath, DWORD dwFilter)
{
    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(lpPath, &fd);
    BOOL bFilter = (FALSE == dwFilter) ? TRUE : fd.dwFileAttributes & dwFilter;
    BOOL RetValue = ((hFind != INVALID_HANDLE_VALUE) && bFilter) ? TRUE : FALSE;
    FindClose(hFind);
    return RetValue;
}

BOOL FilePathExists(LPCSTR lpPath)
{
    return FindFirstFileExists(lpPath, FALSE);
}




std::string UTF8ToGBK( const std::string & u8Str)
{
    INT32 len = MultiByteToWideChar(CP_UTF8, 0, u8Str.c_str(), -1, NULL, 0);  
    wchar_t * strUnicode = (wchar_t*)malloc(len*sizeof(wchar_t));
    if(strUnicode == NULL)
    {
        return "";
    }
    wmemset(strUnicode, 0, len);  
    MultiByteToWideChar(CP_UTF8, 0, u8Str.c_str(), -1, strUnicode, len);  
    len = WideCharToMultiByte(CP_ACP, 0, strUnicode, -1, NULL, 0, NULL, NULL);  
    char *strGbk = (char*)malloc(len);
    memset(strGbk, 0, len);  
    WideCharToMultiByte(CP_ACP,0, strUnicode, -1, strGbk, len, NULL, NULL);  
    free(strUnicode);  
    std::string retStr(strGbk);
    free(strGbk);  
    return retStr;
}

std::string GBKToUTF8( const std::string & gbkStr)
{
    INT32 len = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, NULL, 0);  
    wchar_t * strUnicode = (wchar_t*)malloc(len*sizeof(wchar_t));
    if(strUnicode ==NULL)
    {
        return "";
    }
    wmemset(strUnicode, 0, len);  
    MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, strUnicode, len);
    len = WideCharToMultiByte(CP_UTF8, 0, strUnicode, -1, NULL, 0, NULL, NULL);  
    char *strUtf8 = (char*)malloc(len);
    memset(strUtf8, 0, len);  
    WideCharToMultiByte(CP_UTF8,0, strUnicode, -1, strUtf8, len, NULL, NULL);  
    free(strUnicode); 
    std::string retStr(strUtf8);
    free(strUtf8);  
    return retStr;
}