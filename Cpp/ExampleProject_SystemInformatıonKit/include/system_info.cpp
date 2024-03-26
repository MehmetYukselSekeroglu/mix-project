#include <sys/sysinfo.h>
#include <unistd.h>
#include <iostream>

#include "system_info.hpp"
#include "time_tools.hpp"
#include "conversions.hpp"

void printSystemInformation(void){
    struct sysinfo a_sysinfo;
    const char* loggedUsernmae = getlogin();
    char hwHostname[250];
    char currentWorkdir[1000];
    
    getcwd(currentWorkdir, sizeof(currentWorkdir));
    gethostname(hwHostname, sizeof(hwHostname));

    if ( sysinfo(&a_sysinfo) != 0 ) {
        std::cerr << "[ " << getCurrentTime() << " ] [ ERROR ] Sistem Bilgiis Alınamadı." << std::endl;
        return;        
        }


    std::cout << "SYSTEM BASED INFORMATION:" << std::endl;
    std::cout << "-> TIME           : " << getCurrentTime() << std::endl;
    std::cout << "-> TOTAL RAM      : " << byte2gbyte(a_sysinfo.totalram) << " GB" << std::endl;
    std::cout << "-> FREE RAM       : " << byte2gbyte(a_sysinfo.freeram) << " GB" << std::endl;
    std::cout << "-> USED RAM       : " << byte2gbyte((a_sysinfo.totalram-a_sysinfo.freeram)) << " GB" << std::endl;
    std::cout << "-> UPTIME         : " << (a_sysinfo.uptime / 60) / 60 << " HOURS" << std::endl;
    std::cout << "-> TOTAL PROCCESS : " << a_sysinfo.procs << std::endl;
    std::cout << std::endl;
    std::cout << "USER BASED INFORMATION:" << std::endl;
    std::cout << "-> USER           : " << loggedUsernmae << std::endl; 
    std::cout << "-> HOSTNAME       : " << hwHostname << std::endl;
    std::cout << "-> USER ID        : " << getuid() << std::endl;
    std::cout << "-> GROUP ID       : " << getgid() << std::endl;
    std::cout << "-> CURRENT DIR    : " << currentWorkdir << std::endl;
    return;

}