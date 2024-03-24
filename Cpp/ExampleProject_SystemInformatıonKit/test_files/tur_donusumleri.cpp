#include <iostream>
#include <stdint.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Turkish");
    int exampleInt = 12;
    std::string exampleString = "12";
    std::string exampleString_2 = "12a";
    std::string exampleString_3 = "a";
    std::cout << "Örnek değerler: " << std::endl;
    std::cout << "Example int: " << exampleInt << std::endl;
    std::cout << "Example string1: " << exampleString << std::endl;
    std::cout << "Example string2: " << exampleString_2 << std::endl;
    std::cout << "Example string3: " << exampleString_3 << std::endl;
    std::cout << std::endl;
    std::cout << "Dönüşüm sonrası veriler: " << std::endl;
    std::cout << "Example String 1 den int: " << atoi(exampleString.c_str()) << std::endl;
    std::cout << "Example String 2 den int: " << atoi(exampleString_2.c_str()) << std::endl;
    std::cout << "Example String 3 den int: " << atoi(exampleString_3.c_str()) << std::endl;
    std::cout << "Example int den str ye: " << std::to_string(exampleInt) + " String birleştirme alanı " << std::endl;
    std::cout << std::endl;
    return 0;
}
