#ifndef MYSLAM_CONFIG_H
#define MYSLAM_CONFIG_H



namespace myslam {

class config {
public:
    //! Constructor
    

    //! Destructor
    ~config();

    

    //! path to config YAML file
    const std::string config_file_path_;

};

} // namespace myslam

#endif // MYSLAM_CONFIG_H
