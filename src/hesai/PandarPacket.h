// Generated by gencpp from file hesai_lidar/PandarPacket.msg
// DO NOT EDIT!


#ifndef HESAI_LIDAR_MESSAGE_PANDARPACKET_H
#define HESAI_LIDAR_MESSAGE_PANDARPACKET_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hesai_lidar
{
template <class ContainerAllocator>
struct PandarPacket_
{
  typedef PandarPacket_<ContainerAllocator> Type;

  PandarPacket_()
    : stamp()
    , data()
    , size(0)  {
    }
  PandarPacket_(const ContainerAllocator& _alloc)
    : stamp()
    , data(_alloc)
    , size(0)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _data_type;
  _data_type data;

   typedef uint32_t _size_type;
  _size_type size;




  typedef boost::shared_ptr< ::hesai_lidar::PandarPacket_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hesai_lidar::PandarPacket_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct PandarPacket_

typedef ::hesai_lidar::PandarPacket_<std::allocator<void> > PandarPacket;

typedef boost::shared_ptr< ::hesai_lidar::PandarPacket > PandarPacketPtr;
typedef boost::shared_ptr< ::hesai_lidar::PandarPacket const> PandarPacketConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hesai_lidar::PandarPacket_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hesai_lidar::PandarPacket_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hesai_lidar

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'hesai_lidar': ['/home/yuyuyu00/catkin_hesai/src/HesaiLidar_General_ROS/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hesai_lidar::PandarPacket_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hesai_lidar::PandarPacket_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hesai_lidar::PandarPacket_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c29f0f7365a75504f5f0008b5913cb94";
  }

  static const char* value(const ::hesai_lidar::PandarPacket_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc29f0f7365a75504ULL;
  static const uint64_t static_value2 = 0xf5f0008b5913cb94ULL;
};

template<class ContainerAllocator>
struct DataType< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hesai_lidar/PandarPacket";
  }

  static const char* value(const ::hesai_lidar::PandarPacket_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# field		size(byte)\n\
# SOB 		2\n\
# angle		2\n\
# measure	5\n\
# block		SOB + angle + measure * 40\n\
# timestamp	4\n\
# factory	2\n\
# reserve	8\n\
# rpm		2\n\
# tail		timestamp + factory + reserve + rpm\n\
# packet	block * 6 + tail\n\
\n\
time stamp\n\
uint8[] data\n\
uint32 size\n\
";
  }

  static const char* value(const ::hesai_lidar::PandarPacket_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.data);
      stream.next(m.size);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PandarPacket_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hesai_lidar::PandarPacket_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hesai_lidar::PandarPacket_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
    s << indent << "size: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.size);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HESAI_LIDAR_MESSAGE_PANDARPACKET_H
