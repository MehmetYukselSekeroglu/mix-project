#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "include/console_tools.hpp"
#include "include/variables.hpp"
#include "include/time_tools.hpp"
#include "include/system_info.hpp"

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "Turkish");
    if ((argc - 1) == 0){
        p_error("Invalid Args, Use --help");
        return -1;
        }

    const static std::string mainArg = argv[1];
    if (mainArg == "--help"){
        std::cout << HELP_MENU << std::endl;
        return 0;
    }else if (mainArg == "--get-time"){
        std::cout << "[ + ] Your System Time: " << getCurrentTime() << std::endl;
        return 0;    
    }else if ( mainArg == "--system-info" ){ 
        std::cout << std::endl;
        std::cout << "SOFTWARE BASED INFORMATION:" << std::endl;
        std::cout << "-> APPLICATION_VENDOR    : " << APPLICATION_VENDOR << std::endl;
        std::cout << "-> APPLICATION_VERSION   : " << APPLICATION_VERSION << std::endl;
        std::cout << std::endl;    
        printSystemInformation();
        return 0;  

    }else if (mainArg == "--rand"){
        p_info("Generating random data...");
        srand(time(0));
        std::cout << std::endl << "-> YOUR DATA: ";
        for (int c_i=0;c_i < 4;){
            unsigned int randData = rand() ;
            if (randData > 1000) {
                std::cout << randData << " "; 
                c_i++;
            }else continue;
        } 
        std::cout << std::endl << std::endl;
        p_info("Successfuly...");
        
    }else if (mainArg == "--read") {
        if (argc != 4){
            p_error("Invalid Arg Usage, Visit --help.");
            return -1;
            }

        const std::filesystem::path TargetFilePath = argv[2];
        const std::string buffer_ReadLineCount = argv[3];
        unsigned int ReadLineCount = atoi(buffer_ReadLineCount.c_str()); 

        if (ReadLineCount < 1 && buffer_ReadLineCount != "00"){
            p_error("Invalid Line Size, Proccess stopped");
            return -1;
        }
        if (buffer_ReadLineCount == "00" ){
            ReadLineCount = UINT16_MAX;;
        }
        if ( ! std::filesystem::is_regular_file(TargetFilePath) ){
            p_error("The file not a text file, proccess stopped");
            return -1;
        }

        std::string buffer_userFeedBack = "Reading Your File: " + TargetFilePath.generic_string();
        p_info(buffer_userFeedBack);
        buffer_userFeedBack.clear();
        std::ifstream readableFile; readableFile.open(TargetFilePath);
        if (! readableFile.is_open()){
            p_error("Failed to read file, proccess stopped.");
            return -1;
        }

        std::cout << std::endl;
        std::string buffer_readedLine;
        int buffer_lineCounter=1;
        while (readableFile && buffer_lineCounter <= ReadLineCount)
        {
            std::getline(readableFile, buffer_readedLine);
            std::cout << "[ " << buffer_lineCounter << " ]: "  << buffer_readedLine << std::endl;
            buffer_lineCounter+=1;
        }

        std::cout << std::endl;
        
        // close the file
        readableFile.close();
        p_info("Read proccess successfuly.");
        return 0;       
    }else{
        p_error("Invalid Args, Visit --help");
        return -1;
        }
    return 0;

}