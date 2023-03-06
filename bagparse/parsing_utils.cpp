// *****************************************************************************
//
// Copyright (c) 2017, Southwest Research Institute® (SwRI®)
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
// ARE DISCLAIMED. IN NO EVENT SHALL SOUTHWEST RESEARCH INSTITUTE BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

#include "parsing_utils.h"
#include <ros/ros.h>

namespace general_utils
{
  double ParseDouble(const uint8_t* buffer)
  {
    double x;
    std::copy(buffer, buffer + sizeof(double), reinterpret_cast<uint8_t*>(&x));
    return x;
  }

  bool ParseDouble(const std::string& string, double& value)
  {
	  return false;
    //return swri_string_util::ToDouble(string, value) || string.empty();
  }

  float ParseFloat(const uint8_t* buffer)
  {
    float x;
    std::copy(buffer, buffer + sizeof(float), reinterpret_cast<uint8_t*>(&x));
    return x;
  }

  bool ParseFloat(const std::string& string, float& value)
  {
	  return false;
    //return swri_string_util::ToFloat(string, value) || string.empty();
  }

  int16_t ParseInt16(const uint8_t* buffer)
  {
    int16_t number;
    std::copy(buffer, buffer+2, reinterpret_cast<uint8_t*>(&number));
    return number;
  }

  bool ParseInt16(const std::string& string, int16_t& value, int32_t base)
  {
    /*value = 0;
    if (string.empty())
    {
      return true;
    }

    int32_t tmp;
    if (swri_string_util::ToInt32(string, tmp, base) &&
        tmp <= std::numeric_limits<int16_t>::max() &&
        tmp >= std::numeric_limits<int16_t>::min())
    {
      value = static_cast<int16_t>(tmp);
      return true;
    }*/

    return false;
  }

  int32_t ParseInt32(const uint8_t* buffer)
  {
    int32_t number;
    std::copy(buffer, buffer+4, reinterpret_cast<uint8_t*>(&number));
    return number;
  }

  bool ParseInt32(const std::string& string, int32_t& value, int32_t base)
  {
	  return false;
    //return swri_string_util::ToInt32(string, value, base) || string.empty();
  }

  uint32_t ParseUInt32(const uint8_t* buffer)
  {
    uint32_t number;
    std::copy(buffer, buffer+4, reinterpret_cast<uint8_t*>(&number));
    return number;
  }

  bool ParseUInt32(const std::string& string, uint32_t& value, int32_t base)
  {
	  return false;
    //return swri_string_util::ToUInt32(string, value, base) || string.empty();
  }

  bool ParseUInt8(const std::string& string, uint8_t& value, int32_t base)
  {
    /*value = 0;
    if (string.empty())
    {
      return true;
    }

    uint32_t tmp;
    if (swri_string_util::ToUInt32(string, tmp, base) && tmp <= std::numeric_limits<uint8_t>::max())
    {
      value = static_cast<uint8_t>(tmp);
      return true;
    }*/

    return false;
  }

  uint16_t ParseUInt16(const uint8_t* buffer)
  {
    uint16_t number;
    std::copy(buffer, buffer+2, reinterpret_cast<uint8_t*>(&number));
    return number;
  }

  bool ParseUInt16(const std::string& string, uint16_t& value, int32_t base)
  {
    /*value = 0;
    if (string.empty())
    {
      return true;
    }

    uint32_t tmp;
    if (swri_string_util::ToUInt32(string, tmp, base) && tmp <= std::numeric_limits<uint16_t>::max())
    {
      value = static_cast<uint16_t>(tmp);
      return true;
    }

    return false;*/
	  return false;
  }

  double UtcFloatToSeconds(double utc_float)
  {
    uint32_t hours = static_cast<uint32_t>(utc_float) / 10000;
    uint32_t minutes = (static_cast<uint32_t>(utc_float) - hours * 10000) / 100;
    double seconds = utc_float -
                     static_cast<double>(hours * 10000 + minutes * 100);
    seconds += static_cast<double> (hours * 3600 + minutes * 60);
    return seconds;
  }

  double ConvertDmsToDegrees(double dms)
  {
    uint32_t whole_degrees = static_cast<uint32_t>(dms) / 100;
    double minutes = dms - static_cast<double>(whole_degrees * 100);
    // 60 minutes in a degree
    double degrees = static_cast<double>(whole_degrees) + minutes / 60.0;
    return degrees;
  }


}