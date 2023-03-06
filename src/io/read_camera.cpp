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


#include <cerrno>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include "read_camera.h"
using namespace std;
namespace myslam {
	namespace io {
		read_camera::read_camera(std::string & name, std::string& file_name, setup_type_t setup_type, color_order_t  color_order) :base(name,file_name, setup_type, model_type_t::Laser, color_order) {
			read_img_file_.open(file_name_, std::ios::binary | std::ios::in);
			base::get_rootpath();
			std::cout << base::root_path_ << std::endl;
			write_img_file_.open(base::root_path_ + "result.txt", std::ios::out);
		}
		read_camera::read_camera(YAML::Node & yaml_node) : read_camera(yaml_node["laser.name"].as<std::string>(), yaml_node["file_name"].as<std::string>(), load_setup_type(yaml_node), load_color_order(yaml_node)) {}
		
		void read_camera::parse_camera()
		{
			switch (setup_type_)
			{
			case setup_type_t::Bin:
				parse_bin();
			case setup_type_t::E57:
				parse_e57();
			case setup_type_t::General:
				parse_general();
			case setup_type_t::PCAP:
				parse_pcap();
			default:
				break;
			}

		}
		read_camera::~read_camera()
		{}
		void read_camera::show_parameters() const
		{
		}
		void read_camera::parse_bin() 
		{
			CameraFrame str;
			if (!read_img_file_)
			{
				cout << "error read the binary file..." << endl;
			}
			while (read_img_file_.read((char *)&str, sizeof(str)))
			{
				if (int(str.image_respond) == 2)
				{
					continue;
				}
				else if (int(str.image_respond) == 1)
				{
					write_img_file_ << setprecision(14) << (int)str.image_id << "," << (double)str.trigger_tm / 1000.0 << "," <<
						(double)str.triggerA_tm / 1000.0 << "," << (double)str.triggerB_tm / 1000.0 << "," << (double)str.triggerC_tm / 1000.0 << endl;
				}
			}
		}
		void read_camera::parse_e57() 
		{
		}
		void read_camera::parse_general() 
		{
		}
		void read_camera::parse_pcap() 
		{
		}
	}
}

