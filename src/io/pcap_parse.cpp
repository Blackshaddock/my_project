#include "pcap_parse.h"
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <map>
#include <thread>
//
#define PKT_HEADER_SIZE (42)


namespace myslam {
	namespace io {
		PcapReader::PcapReader(std::string path, std::string frame_id, int start_id, int end_id) {
			initTimeIndexMap();
			pcapPath = path;
			m_sFrameId = frame_id;
			pcap_startid_ = start_id;
			pcap_endid_ = end_id;
			pcap_id_ = -1;
			loop = true;
			parse_thr_ = NULL;
			std::map<std::string, std::pair<int, int>>::iterator iter = m_timeIndexMap.find(m_sFrameId);
			if (iter != m_timeIndexMap.end()) {
				m_iTsIndex = iter->second.first;
				m_iUTCIndex = iter->second.second;

			}
			else {
				m_iTsIndex = 0;
				m_iUTCIndex = 0;
			}
		}
		//
		PcapReader::~PcapReader() {
			stop();
		}

		void PcapReader::initTimeIndexMap() {
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("Pandar40P", std::pair<int, int>(1250, 1256)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("Pandar40M", std::pair<int, int>(1250, 1256)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("Pandar64", std::pair<int, int>(1182, 1188)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("PandarQT", std::pair<int, int>(1056, 1062)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("Pandar20A", std::pair<int, int>(1258, 1264)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("Pandar20B", std::pair<int, int>(1258, 1264)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("PandarXT-32", std::pair<int, int>(1071, 1065)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("PandarXT-16", std::pair<int, int>(559, 553)));
			m_timeIndexMap.insert(std::pair<string, std::pair<int, int>>("PandarXTM", std::pair<int, int>(811, 805)));
		}

		int PcapReader::mygettimeofday(timeval * tp, void * tzp)
		{
			time_t clock;
			struct tm tm;
			SYSTEMTIME wtm;

			GetLocalTime(&wtm);
			tm.tm_year = wtm.wYear - 1900;
			tm.tm_mon = wtm.wMonth - 1;
			tm.tm_mday = wtm.wDay;
			tm.tm_hour = wtm.wHour;
			tm.tm_min = wtm.wMinute;
			tm.tm_sec = wtm.wSecond;
			tm.tm_isdst = -1;

			clock = mktime(&tm);
			tp->tv_sec = clock;
			tp->tv_usec = wtm.wMilliseconds * 1000;
			return (0);
		}

		void PcapReader::start(boost::function<void(const uint8_t*, const int, double timestamp)> callback) {
			// LOG_FUNC();
			stop();

			this->callback = callback;

			

			parse_thr_ = new boost::thread(boost::bind(&PcapReader::parsePcap, this));
			//parse_thr_->detach();
		}

		void PcapReader::stop() {
			loop = false;

			if (parse_thr_) {
				parse_thr_->join();
				delete parse_thr_;
				parse_thr_ = NULL;
			}
		}

		void PcapReader::parsePcap() {
			// LOG_FUNC();
			pcap_t *pcapFile = NULL;
			char pcapBuf[PCAP_ERRBUF_SIZE];
			struct bpf_program filter;
			pcap_pkthdr *pktHeader;
			const unsigned char *packetBuf;
			struct tm t = { 0 };
			static int gap = 100;
			double last_pkt_ts = 0;
			int count;
			double last_time = 0;
			double current_time = 0;
			double pkt_ts = 0;
			loop = true;
			if (pcapPath.empty()) { return; }

			pcapFile = pcap_open_offline(pcapPath.c_str(), pcapBuf);

			if (NULL == pcapFile) {
				printf("open pcap file %s fail\n", pcapPath.c_str());
				return;
			}

			if (pcap_compile(pcapFile, &filter, "udp", 0, 0xffffffff) == -1) {
				printf("compile pcap file fail\n");
				return;
			}

			if (pcap_setfilter(pcapFile, &filter) == -1) {
				printf("pcap set filter fail\n");
				return;
			}

			if (NULL == callback) {
				printf("pcap read callback is null\n");
				return;
			}
			while (pcap_next_ex(pcapFile, &pktHeader, &packetBuf) >= 0 && loop) {
				//把头部数据不要
				/*if (pcap_id_ % 100 == 0)
				{
					cout << "id: " << pcap_id_ << endl;
				}*/
				pcap_id_++;
				if ((pcap_id_ < pcap_startid_))
				{
					continue;
				}
				/*if (pcap_id_ > pcap_endid_)
				{
					break;
				}*/
				//cout << setprecision(14) << time(0) << endl;
				//cout << "id: " << pcap_id_ << endl;
				const uint8_t *packet = packetBuf + PKT_HEADER_SIZE;
				int pktSize = pktHeader->len - PKT_HEADER_SIZE;
				double curtime = time(0);	
				//std::this_thread::sleep_for(std::chrono::microseconds(1));
				callback(packet, pktSize, curtime);
				count++;
				if (count >= 100 && m_iUTCIndex != 0) {
					//cout << "id: " << pcap_id_ << endl;
					//cout << time(0) << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
					//cout << time(0) << endl;
					count = 0;
				}
				//	count = 0;

				//	t.tm_year = packet[m_iUTCIndex];
				//	t.tm_mon = packet[m_iUTCIndex + 1] - 1;
				//	t.tm_mday = packet[m_iUTCIndex + 2];
				//	t.tm_hour = packet[m_iUTCIndex + 3];
				//	t.tm_min = packet[m_iUTCIndex + 4];
				//	t.tm_sec = packet[m_iUTCIndex + 5];
				//	// LOG_D("[%d][%d][%d][%d][%d][%d]",t.tm_year,t.tm_mon,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
				//	t.tm_isdst = 0;


				//	pkt_ts = (mktime(&t) * 1000000 + ((packet[m_iTsIndex] & 0xff) | \
				//		(packet[m_iTsIndex + 1] & 0xff) << 8 | \
				//		((packet[m_iTsIndex + 2] & 0xff) << 16) | \
				//		((packet[m_iTsIndex + 3] & 0xff) << 24)))/1000000.;
				//	struct timeval sys_time;
				//	mygettimeofday(&sys_time, NULL);
				//	current_time = sys_time.tv_sec  + sys_time.tv_usec/1000000.;
				//	
				//	//current_time = time(0);

				//	if (0 == last_pkt_ts) {
				//		last_pkt_ts = pkt_ts;
				//		last_time = current_time;
				//	}
				//	else {
				//		int64_t sleep_time = ((pkt_ts - last_pkt_ts) - (current_time - last_time))*1000;

				//		// LOG_D("[%lld],[%lld],[%lld],[%lld]",pkt_ts,last_pkt_ts,current_time,last_time);
				//		// LOG_D("sleep time is: [%lld]", sleep_time);

				//		if (sleep_time > 0) {
				//			struct timeval waitTime;
				//			waitTime.tv_sec = sleep_time / 1000000;
				//			waitTime.tv_usec = sleep_time % 1000000;
				//			
				//			int err;

				//			do {
				//				err = select(0, NULL, NULL, NULL, &waitTime);
				//			} while (err < 0 && errno != EINTR);

				//		}
				//		last_pkt_ts = pkt_ts;
				//		last_time = current_time;
				//		last_time += sleep_time;
				//	}
				//}
			}
			// LOG_D("read pcap file done");
			cout << "read pcap file done" << endl;
			if (pcapFile != NULL) {
				pcap_close(pcapFile);
				pcapFile = NULL;
			}
		}
	}
}
