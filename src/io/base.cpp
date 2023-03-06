

#include <iostream>

#include "base.h"

namespace myslam {
	namespace io {

		base::base( std::string& name,  std::string & file_name, setup_type_t setup_type,  model_type_t model_type,  color_order_t color_order)
			: name_(name),file_name_(file_name), setup_type_(setup_type), model_type_(model_type), color_order_(color_order) {}

		void base::get_rootpath()
		{
		   int pos1 = file_name_.find_last_of(".");
		   root_path_ = file_name_.substr(0, pos1);
		   if (boost::filesystem::exists(root_path_))
		   {
			   boost::filesystem::remove_all(root_path_);
			   boost::filesystem::create_directory(root_path_);
		   }
		   else {
			   boost::filesystem::create_directory(root_path_);
		   }
		   root_path_ = root_path_ + "\\";
		}



		base::~base() {

		}

		setup_type_t base::load_setup_type(const YAML::Node& yaml_node) {
			const auto setup_type_str = yaml_node["setup"].as<std::string>();
			if (setup_type_str == "BIN") {
				return io::setup_type_t::Bin;
			}
			else if (setup_type_str == "E57") {
				return io::setup_type_t::E57;
			}
			else if (setup_type_str == "PCAP") {
				return io::setup_type_t::PCAP;
			}
			else if (setup_type_str == "General") {
				return io::setup_type_t::General;
			}

			throw std::runtime_error("Invalid setup type: " + setup_type_str);
		}

		setup_type_t base::load_setup_type(const std::string& setup_type_str) {
			const auto itr = std::find(setup_type_to_string.begin(), setup_type_to_string.end(), setup_type_str);
			if (itr == setup_type_to_string.end()) {
				throw std::runtime_error("Invalid setup type: " + setup_type_str);
			}
			return static_cast<setup_type_t>(std::distance(setup_type_to_string.begin(), itr));
		}

		model_type_t base::load_model_type(const YAML::Node& yaml_node) {
			const auto model_type_str = yaml_node["model"].as<std::string>();
			if (model_type_str == "Laser") {
				return io::model_type_t::Laser;
			}
			else if (model_type_str == "Camera") {
				return io::model_type_t::Camera;
			}
			else if (model_type_str == "IMU") {
				return io::model_type_t::IMU;
			}
			else if (model_type_str == "GPS") {
				return io::model_type_t::GPS;
			}
			throw std::runtime_error("Invalid camera model: " + model_type_str);
		}

		model_type_t base::load_model_type(const std::string& model_type_str) {
			const auto itr = std::find(model_type_to_string.begin(), model_type_to_string.end(), model_type_str);
			if (itr == model_type_to_string.end()) {
				throw std::runtime_error("Invalid camera model: " + model_type_str);
			}
			return static_cast<model_type_t>(std::distance(model_type_to_string.begin(), itr));
		}

		color_order_t base::load_color_order(const YAML::Node& yaml_node) {
			if (!yaml_node["color_order"]) {
				return color_order_t::Gray;
			}

			const auto color_order_str = yaml_node["color_order"].as<std::string>();
			if (color_order_str == "Gray") {
				return color_order_t::Gray;
			}
			else if (color_order_str == "RGB" || color_order_str == "RGBA") {
				return color_order_t::RGB;
			}
			else if (color_order_str == "BGR" || color_order_str == "BGRA") {
				return color_order_t::BGR;
			}

			throw std::runtime_error("Invalid color order: " + color_order_str);
		}

		color_order_t base::load_color_order(const std::string& color_order_str) {
			const auto itr = std::find(color_order_to_string.begin(), color_order_to_string.end(), color_order_str);
			if (itr == color_order_to_string.end()) {
				throw std::runtime_error("Invalid color order: " + color_order_str);
			}
			return static_cast<color_order_t>(std::distance(color_order_to_string.begin(), itr));
		}

		void base::show_common_parameters() const {
			std::cout << "- name: " << name_ << std::endl;
			std::cout << "- setup: " << get_setup_type_string() << std::endl;
			std::cout << "- color: " << get_color_order_string() << std::endl;
			std::cout << "- model: " << get_model_type_string() << std::endl;
		}

		std::ostream& operator<<(std::ostream& os, const base& params) {
			os << "- name: " << params.name_ << std::endl;
			os << "- setup: " << params.get_setup_type_string() << std::endl;
			os << "- color: " << params.get_color_order_string() << std::endl;
			os << "- model: " << params.get_model_type_string() << std::endl;
			return os;
		}

	} // namespace io
} // namespace myslam
