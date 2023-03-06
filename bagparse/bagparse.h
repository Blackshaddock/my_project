#include <iostream>
#include <pcap/pcap.h>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include "pcap.h"
#include <string>

#include "atltime.h"
#include <ctime>
#pragma comment(lib, "WS2_32")
using namespace std;

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








class PcapReader {
public:
	PcapReader(std::string path, std::string frame_id);
	
	~PcapReader();

	void start(boost::function<void(const uint8_t*, const int, double timestamp)> callback);
	void stop();
	void parsePcap();
	void initTimeIndexMap();
	int mygettimeofday(struct timeval *tp, void *tzp);

public:
	bool          loop;
	boost::thread *parse_thr_;
	std::string   pcapPath;
	std::string   m_sFrameId;
	boost::function<void(const uint8_t*, const int, double timestamp)> callback;
	std::map<std::string, std::pair<int, int>> m_timeIndexMap;
	int m_iTsIndex;
	int m_iUTCIndex;

	
};
