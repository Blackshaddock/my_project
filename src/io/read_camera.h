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

#ifndef READ_CAMERA_H_
#define READ_CAMERA_H_

#include "base.h"
#include "pcap_parse.h"
namespace myslam {
	namespace io
	{
		#pragma pack(push,1)
		struct CameraFrame
		{
			unsigned char image_head[3];
			unsigned char image_respond;
			unsigned int image_id;
			long long trigger_tm;
			long long triggerA_tm;
			long long triggerB_tm;
			long long triggerC_tm;
			unsigned char image_style[24];
			unsigned char image_end[4];
		};
		#pragma pack(pop)

		class read_camera final :public base
		{
		public:
			read_camera(std::string & name, std::string &file_name, setup_type_t setup_type, color_order_t  color_order);
			read_camera(YAML::Node& yaml_node);
			void parse_camera();
			~read_camera();
			void show_parameters() const override final;
			void parse_bin() ;
			void parse_e57() ;
			void parse_general();
			void parse_pcap();
		private:
			std::ifstream read_bin_file_;
			std::ifstream read_img_file_;
			std::ofstream write_bin_file_;
			std::ofstream write_img_file_;
		};



	}
}
#endif  // STRING_UTIL_STRING_UTIL_H_
