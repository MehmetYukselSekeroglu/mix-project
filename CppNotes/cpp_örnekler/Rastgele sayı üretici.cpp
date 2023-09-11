#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // 1-90 arası 6 rastgele sayı
    cout << "sayılar: ";
    
    short i;
    while (i < 7){
        cout << rand() % 91 << " "; // 1 ile 90 arasu sayılar çıkartır 
        
        i++;
    }
}