#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/utils/logger.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>

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
    
    unsigned short int cameraID = 0;
    char keyInput;

    cv::Size VideoResulation(1240,480);

    setlocale(LC_ALL, "Turkish");

    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
    cv::VideoCapture videoSource(cameraID);
    cv::Mat currentFrame;


    p_info("Starting live stream...");
    while (true){
        videoSource.read(currentFrame);
 
        if (currentFrame.empty()){
            p_info("End of the stream, exiting...");
            return 0;
        }
        cv::putText(currentFrame, getCurrentTime(),
                cv::Point(VideoResulation.width - VideoResulation.width * 0.999,
                VideoResulation.height - VideoResulation.height * 0.01 ),
                cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 255, 0), 2.2);
        cv::resize(currentFrame, currentFrame,VideoResulation);
        cv::imshow("Live Stream",currentFrame);
        keyInput = (char)cv::waitKey(1);

        if (keyInput == 'q'){
            p_info("Q keyword detected, exiting...");
            break;
        }


    }
    return 0;
}













