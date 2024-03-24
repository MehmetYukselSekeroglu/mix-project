#include <opencv4/opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <filesystem>



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

// ********** otomatik alan bitti **********


int main(int argc, char const *argv[]){
    
    // 0 demek ilk web kamerayı aç demektir
    unsigned short int deviceID = 0; 
    
    // kamerayı açalım
    cv::VideoCapture webCam(deviceID);
    
    // kareleri atamak için değişken belirledik 
    cv::Mat currentFrame ;
    
    // kamera açıldımı kontrol edilir
    if (! webCam.isOpened()){
        p_error("Failed to open device, proccess topped...");
        return -1;
    }

    // videoyu verebilmek için sürekli döngü başlatılır 
    while (true){

        // videodan veya yayından kare alınır ve belirlenen değişkene verilir 
        webCam.read(currentFrame);

        // video veya yayından gelen veri boş mu kontrol edilir 
        if (currentFrame.empty()){
            p_info("End of the stream, exiting...");
            return 0;
        }

        // ekrana verilir 
        cv::imshow("Live Stream",currentFrame);
        
        // 1 milisaniye beklemeye alınır
        cv::waitKey(1);

    }
    

    return 0;
}
