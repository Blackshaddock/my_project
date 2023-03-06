#include <iostream>
#include <chrono>
#include <numeric>
#include <io/base.h>
#include <io/pcap_parse.h>
#include <hesai/pandarGeneral_internal.h>
void FillPacket(boost::shared_ptr<PPointCloud> cld, double timestamp)
{
	cout << setprecision(14) << cld->points.size() << " " << timestamp << " " << time(0) << endl;
	//printf("%x,%x\n", buf[0], buf[1]);
}


int main(int argc, char* argv[]) {
	string pcap_file = argv[1];
	myslam::hesai::PandarGeneral_Internal process_pcap(pcap_file, boost::bind(FillPacket, _1, _2), 0, INT_MAX, "PandarXTM");
	process_pcap.Start();
	//testpcap.start(boost::bind(FillPacket, _1, _2, _3));
	
    return 0;
}
