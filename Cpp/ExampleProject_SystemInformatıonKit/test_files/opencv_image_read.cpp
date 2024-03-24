#include <opencv4/opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <filesystem>

std::string getCurrentTime(void){
    auto now = std::chrono::system_clock::now();
    std::time_t  currentTime = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[100];
    std::strftime(timeBuffer, 100, "%d/%m/%Y %H:%M:%S", std::localtime(&currentTime));
    std::string time_a = timeBuffer;
    return time_a;    
}

void p_info(const std::string& targetText){
    std::string a_time = getCurrentTime();
    printf("[ %s ] [ INFO ]: %s \n", a_time.c_str(), targetText.c_str());
}
void p_warn(const std::string& targetText){
    std::string a_time = getCurrentTime();
    printf("[ %s ] [ WARNING ]: %s \n", a_time.c_str(), targetText.c_str());
}
void p_error(const std::string& targetText){
    std::string a_time = getCurrentTime();
    printf("[ %s ] [ ERROR ]: %s \n", a_time.c_str(), targetText.c_str());
}
void p_log(const std::string& targetText){
    std::string a_time = getCurrentTime();
    printf("[ %s ] [ LOG ]: %s \n", a_time.c_str(), targetText.c_str());
}



int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Turkish"); 
    if ((argc - 1) == 0){
        p_error("Invalid Args, Use --help");
        return -1;
        }

    const static std::filesystem::path TargetImagePath = argv[1];
    if (! std::filesystem::is_regular_file(TargetImagePath)){
        p_error("Invalid image path, app.run /path/to/my_image.png");
        return -1;
    }


    p_info("Reading your image via opencv...");
    cv::Mat readedImageData = cv::imread(TargetImagePath.string());
    p_info("Read successfuly, showing image...");
    cv::imshow("The Target Image", readedImageData);
    cv::waitKey(0);

    


    return 0;
}
