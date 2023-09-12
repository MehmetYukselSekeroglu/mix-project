#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(){

    string YOUT_FILE;
    cout << "-> Enter target file path: ";
    cin >> YOUT_FILE;


    cout << "[ + ] Reading file: " << YOUT_FILE << endl << endl;


    // Dosya acıldı 

    ifstream TargetFile(YOUT_FILE);
    
    if (!TargetFile){
        cerr << "Error file open failed: " << strerror(errno) << endl;
        return 1;
    }
    


    string know_lines;


    // Satır satır okundu ve ekrana yazıldı 
    while (getline(TargetFile, know_lines)){
        cout << know_lines << endl;
    }
    

    cout << "[ + ] Reading finished.";

    // Dosya kapatıldı 
    TargetFile.close();

    return 0;
}