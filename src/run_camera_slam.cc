#include <iostream>
#include <chrono>
#include <numeric>
#include <io/base.h>
#include <io/read_laser.h>
int main(int argc, char* argv[]) {
	std::string a1 = "laser";
	std::string b = "D:\\code\\123.txt";
	myslam::io::read_laser a(a1,b , myslam::io::setup_type_t::Bin,  myslam::io::color_order_t::BGR);
	a.get_rootpath();
    return 0;
}
