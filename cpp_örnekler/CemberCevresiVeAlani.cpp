#include <iostream>
#include <string>

using namespace std;

int main(){
    unsigned long long int Yaricap_1; // yarıçap negatif değer alamica için nsignet seçildi ve buyuk değerleri alabilsin diye long 
    const short PI = 3.14; // PI yazma sebebimiz geleneksel yazım kurlı olarak const değerlerin buyuk yzılmasıdır  
    cout << "Lütfen yarıçap değerini giriniz: ";
    cin >> Yaricap_1;

    cout << "Çember çevresi: " << (2 * PI * Yaricap_1) << endl;
    cout << "Çember alanı: " << (PI * Yaricap_1 * Yaricap_1) << endl;
}