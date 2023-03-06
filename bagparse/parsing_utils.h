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

#ifndef NOVATEL_GPS_DRIVER_BASE_PARSER_H
#define NOVATEL_GPS_DRIVER_BASE_PARSER_H

#include <iostream>
#include <stdint.h>

/**
 * Utility functions, structures, and constants used when parsing messages.
 */

namespace general_utils
{
  

  
  double ParseDouble(const uint8_t* buffer);

  bool ParseDouble(const std::string& string, double& value);

 
  float ParseFloat(const uint8_t* buffer);

  bool ParseFloat(const std::string& string, float& value);

  
  int16_t ParseInt16(const uint8_t* buffer);

  
  bool ParseInt16(const std::string& string, int16_t& value, int32_t base = 10);

 
  int32_t ParseInt32(const uint8_t* buffer);

 
  bool ParseInt32(const std::string& string, int32_t& value, int32_t base = 10);

  
  bool ParseUInt8(const std::string& string, uint8_t& value, int32_t base = 10);

 
  uint16_t ParseUInt16(const uint8_t* buffer);

  
  bool ParseUInt16(const std::string& string, uint16_t& value, int32_t base = 10);

  
  uint32_t ParseUInt32(const uint8_t* buffer);

  
  bool ParseUInt32(const std::string& string, uint32_t& value, int32_t base = 10);

  double UtcFloatToSeconds(double utc_float);
}

#endif //NOVATEL_GPS_DRIVER_BASE_PARSER_H
