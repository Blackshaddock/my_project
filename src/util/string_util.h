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

#ifndef STRING_UTIL_STRING_UTIL_H_
#define STRING_UTIL_STRING_UTIL_H_

#include <stdint.h>
#include <string>


#include <boost-1_60\boost\date_time\posix_time\posix_time.hpp>
namespace myslam {
	namespace swri_string_util
	{
		bool ToDouble(const std::string& string, double& value);

		bool ToFloat(const std::string& string, float& value);

		bool ToInt32(const std::string& string, int32_t& value, int32_t base = 10);

		bool ToUInt32(const std::string& string, uint32_t& value, int32_t base = 10);

		std::vector<std::string> explode(const std::string &text, const std::string& separators);

		

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
		/**
		* @brief 周秒转utc
		* @param gps_week    参数1 周数
		* @param gps_second  参数2 秒数
		*
		* @return 返回utc时间
		*
		*/
		void gpsweeksecond2utc(double gps_week, double gps_second);
		/**
		* @brief utc转年 月 日 时 分 秒
		* @param utc_time    参数1 utc时间
		* 
		*
		* @return 返回年月日 时分秒
		*
		*/
		std::string utc2datatime(double utc_time);
	}
}
#endif  // STRING_UTIL_STRING_UTIL_H_
