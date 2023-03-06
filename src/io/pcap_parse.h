#include <iostream>
#include <pcap/pcap.h>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <thread>
#include <chrono>
#include "pcap.h"
#include <string>

#include "atltime.h"
#include <ctime>
#pragma comment(lib, "WS2_32")
#pragma once
using namespace std;

namespace myslam
{
	namespace io {
		class PcapReader {
		public:
			PcapReader(std::string path, std::string frame_id, int start_id, int end_id);

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
			int pcap_startid_;
			int pcap_endid_;
			int pcap_id_;


		};
	}
}
