#include <iostream>
#include <chrono>
#include <numeric>
#include <io/base.h>
#include <io/read_camera.h>
int main(int argc, char* argv[]) {
	

	std::string a1 = "laser";
	std::string b = argv[1];
	myslam::io::read_camera a(a1,b , myslam::io::setup_type_t::Bin,  myslam::io::color_order_t::BGR);
	a.parse_camera();
    return 0;
}
