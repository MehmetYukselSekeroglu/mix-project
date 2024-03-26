#include <stdio.h>
#include <iostream>
#include "console_tools.hpp"
#include "time_tools.hpp"


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


