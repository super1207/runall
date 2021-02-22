#pragma once

#include <string>


void SpliteInput(const std::string & inputData,std::string & firstCmd,std::string & secondCmd,std::string & data);

std::string & replace_all_distinct(std::string & str, const std::string & old_value, const std::string & new_value);

BOOL FilePathExists(LPCSTR lpPath);

std::string UTF8ToGBK( const std::string & u8Str);

std::string GBKToUTF8( const std::string & gbkStr);