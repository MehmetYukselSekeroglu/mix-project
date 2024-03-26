#include <ctime>
#include <chrono>

#include "time_tools.hpp"

std::string getCurrentTime(void){
    auto now = std::chrono::system_clock::now();
    std::time_t  currentTime = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[100];
    std::strftime(timeBuffer, 100, "%d/%m/%Y %H:%M:%S", std::localtime(&currentTime));
    std::string time_a = timeBuffer;
    return time_a;    
}



