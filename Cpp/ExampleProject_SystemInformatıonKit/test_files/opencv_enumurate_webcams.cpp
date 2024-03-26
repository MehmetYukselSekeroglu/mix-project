#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/utils/logger.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>

// Bu alan ekrana standart bilgileri daha temiz yazdırmak içindir direk alt kısma geçilebilir
// ********** OTOMATIK ALAN - GECINIZ **********
std::string getCurrentTime(void){
    auto now = std::chrono::system_clock::now();
    std::time_t  currentTime = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[100];
    std::strftime(timeBuffer, 100, "%d/%m/%Y %H:%M:%S", std::localtime(&currentTime));
    std::string time_a = timeBuffer;
    return time_a;    
}
// ********** otomatik alan bitti **********

/*
    * DERLEME *
g++ -fdiagnostics-color=always -g enumurate_webcams.cpp -o opencv_test.run `pkg-config opencv4 --libs --cflags` && export OPENCV_LOG_LEVEL=OFF

*/

int main(int argc, char const *argv[]){
    const unsigned short int enumSize = 10;
    unsigned short int currentIndex = 0;
    
    setlocale(LC_ALL, "Turkish");

    
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

    while (currentIndex <= enumSize){
        try{
            cv::VideoCapture currentCamera(currentIndex);
            if (!currentCamera.isOpened()){
                std::cout << getCurrentTime() << " No camera for index: " << currentIndex << std::endl;
            }else {
                std::cout << getCurrentTime() << " Camera Detected index: " << currentIndex << std::endl;       
            }
            currentCamera.release();
            currentIndex+=1;
        }catch(const std::exception& e){
            std::cout << getCurrentTime() << " Error in: " << currentIndex << std::endl;
            std::cerr << e.what() << '\n';
            currentIndex+=1;
        }        
    }
    return 0;
}
