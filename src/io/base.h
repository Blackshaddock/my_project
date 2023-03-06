#ifndef IO_BASE_H
#define IO_BASE_H



#include <string>
#include <limits>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <yaml-cpp/yaml.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
namespace myslam {
namespace io {

enum class setup_type_t {
    Bin = 0,
    E57 = 1,
    PCAP = 2,
	General = 3
};

const std::array<std::string, 4> setup_type_to_string = {{"Bin", "E57", "PCAP", "General"}};

enum class model_type_t {
    Laser = 0,
    Camera = 1,
    IMU = 2,
    GPS = 3,
	General = 4
};

const std::array<std::string, 5> model_type_to_string = {{"Laser", "Camera", "IMU", "GPS", "General"}};

enum class color_order_t {
    Gray = 0,
    RGB = 1,
    BGR = 2
};

const std::array<std::string, 3> color_order_to_string = {{"Gray", "RGB", "BGR"}};

struct image_bounds {
    //! Default constructor
    image_bounds() = default;

    //! Constructor with initialization
    template<typename T, typename U>
    image_bounds(const T min_x, const U max_x, const T min_y, const U max_y)
        : min_x_(min_x), max_x_(max_x), min_y_(min_y), max_y_(max_y) {}

    float min_x_ = 0.0;
    float max_x_ = 0.0;
    float min_y_ = 0.0;
    float max_y_ = 0.0;
};

class base {
public:
    //! Constructor
    base( std::string& name,  std::string & file_name, setup_type_t setup_type,  model_type_t model_type,  color_order_t color_order);

	void get_rootpath();
    //! Destructor
    virtual ~base();

    //! device name
    const std::string name_;
	//! file name
	const std::string file_name_;
	//! root path
	std::string root_path_;
    //! setup type
    const setup_type_t setup_type_;
    //! Get setup type as string
    std::string get_setup_type_string() const { return setup_type_to_string.at(static_cast<unsigned int>(setup_type_)); }
    //! Load setup type from YAML
	static setup_type_t load_setup_type(const YAML::Node& yaml_node);
    //! Load setup type from string
    static setup_type_t load_setup_type(const std::string& setup_type_str);

    //! model type
    const model_type_t model_type_;
    //! Get model type as string
    std::string get_model_type_string() const { return model_type_to_string.at(static_cast<unsigned int>(model_type_)); }
    //! Load model type from YAML
    static model_type_t load_model_type(const YAML::Node& yaml_node);
    //! Load model type from string
    static model_type_t load_model_type(const std::string& model_type_str);

    //! color order
    const color_order_t color_order_;
    //! Get color order as string
    std::string get_color_order_string() const { return color_order_to_string.at(static_cast<unsigned int>(color_order_)); }
    //! Load color order from YAML
    static color_order_t load_color_order(const YAML::Node& yaml_node);
    //! Load color order from string
    static color_order_t load_color_order(const std::string& color_order_str);

    //! Show common parameters along camera models
    void show_common_parameters() const;

    //---------------------------
    // To be set in the base class


    //---------------------------
    // To be set in derived classes

    //! information of image boundary
    image_bounds img_bounds_;


    //-------------------------
    // To be implemented in derived classes

    //! Show camera parameters
    virtual void show_parameters() const = 0;
	//! parse bin
	virtual void parse_bin()  = 0;
	//! parse e57
	virtual void parse_e57()  = 0;
	//! parse general
	virtual void parse_general()  = 0;
	//! parse pcap
	virtual void parse_pcap()  = 0;

};

std::ostream& operator<<(std::ostream& os, const base& params);

} // namespace io
} // namespace myslam

#endif // IO_BASE_H
