// *****************************************************************************
//
// Copyright (c) 2014, Southwest Research Institute® (SwRI®)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Southwest Research Institute® (SwRI®) nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

#include "string_util.h"
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <vector>
namespace swri_string_util
{
  bool ToDouble(const std::string& string, double& value)
  {
    if (string.empty())
    {
      return false;
    }

    char* end;
    errno = 0;
    double number = strtod(string.c_str(), &end);

    // Check if an error occured or if there are junk characters at the end.
    if (errno != 0 || end != string.c_str() + string.length())
    {
      return false;
    }

    value = number;
    return true;
  }

  bool ToFloat(const std::string& string, float& value)
  {
    if (string.empty())
    {
      return false;
    }

    char* end;
    errno = 0;
    float number = strtof(string.c_str(), &end);

    // Check if an error occured or if there are junk characters at the end.
    if (errno != 0 || end != string.c_str() + string.length())
    {
      return false;
    }

    value = number;
    return true;
  }

  bool ToInt32(const std::string& string, int32_t& value, int32_t base)
  {
    if (string.empty())
    {
      return false;
    }

    char* end;
    errno = 0;
    int64_t number = strtol(string.c_str(), &end, base);

    // Check if an error occured or if there are junk characters at the end.
    if (errno != 0 || end != string.c_str() + string.length())
    {
      return false;
    }

    if (number > std::numeric_limits<int32_t>::max() ||
        number < std::numeric_limits<int32_t>::min())
    {
      return false;
    }

    value = number;
    return true;
  }

  bool ToUInt32(const std::string& string, uint32_t& value, int32_t base)
  {
    if (string.empty())
    {
      return false;
    }

    char* end;
    errno = 0;
    int64_t number = strtol(string.c_str(), &end, base);

    // Check if an error occured or if there are junk characters at the end.
    if (errno != 0 || end != string.c_str() + string.length())
    {
      return false;
    }

    if (number > std::numeric_limits<uint32_t>::max() || number < 0)
    {
      return false;
    }

    value = number;
    return true;
  }


  /**
  * @brief 字符串分割
  * @param input_str    参数1 待分割的字符
  * @param separators   参数2 分割符
  *
  * @return 返回分割后的字符用vector存储
  *    
  */

  std::vector<std::string> explode(const std::string &input_str, const std::string& separators)
  {
	  std::vector<std::string> words;
	  size_t n = input_str.length();
	  size_t start = 0;
	  size_t stop = input_str.find_first_of(separators);
	  if (stop > n) stop = n;
	  while (start <= n)
	  {
		  words.push_back(input_str.substr(start, stop - start));
		  start = stop + 1;
		  stop = input_str.find_first_of(separators, start);
		  if (stop > n) stop = n;

	  }
	  return words;
  }

 
  double GetUTC2GPSSkipSecond(double gpssecond)
  {
	  double t1 = (boost::posix_time::time_from_string("2017-1-1 00:00:00") - boost::posix_time::time_from_string("1970-1-1 00:00:00")).total_seconds();

	  if (gpssecond >= t1)
		  return 18;
	  else
		  return -1;
  }
  std::string timestampToString(const std::string& timestamp)
  {
	  time_t t = std::stoll(timestamp);
	  tm local_time;
	  localtime_s(&local_time, &t);
	  char buffer[20];
	  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
	  return buffer;
  }

  
  double gpsweeksecond2utc(double gps_week, double gps_second)
  {
	  double gpssecond = gps_week * 7 * 86400 + gps_second;
	  double utcsecond = gps_week * 7 * 86400 + gps_second + 315964800;
	  double secondskip = GetUTC2GPSSkipSecond(utcsecond);
	  if (secondskip > 0)
		  utcsecond -= secondskip;
	  else
		  std::cout << "time skip error------------" << std::endl;
	  return utcsecond;
  }
  std::string utc2datatime(double utc_time)
  {
	  time_t now = std::stoll(std::to_string(utc_time));

	  struct tm utc_tm1 = *gmtime(&now);
	  char buf[64];
	  sprintf_s(buf, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d", utc_tm1.tm_year + 1900,
		  utc_tm1.tm_mon + 1, utc_tm1.tm_mday, utc_tm1.tm_hour, utc_tm1.tm_min,
		  utc_tm1.tm_sec);
	  return buf;
  }
}
