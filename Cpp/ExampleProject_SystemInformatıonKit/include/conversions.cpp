#include "conversions.hpp"
#include <iostream>


double byte2gbyte(const uint64_t& byteSize){
    double convertSize = byteSize;
    convertSize = ((convertSize / 1024) / 1024) / 1024;
    return convertSize;
}


