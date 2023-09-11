#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    
    cout << "Doğduğunuz yılı giriniz: " << endl;
    
    // hafızada gereksiz yer kaplanmasın diye short tipli syı kullanıldı 
    short RawDogumYili,MevcutYil(2022);
    
    cin >> RawDogumYili;

    // negatif sayı veya benzer sorunlar yaşanmasın diye inpu kontrolü
    if (RawDogumYili <= 0){
        cout << "Yanlızca Millatdan sonrası!" << endl;
        return 0;
    }else if (RawDogumYili > MevcutYil){
        cout << "Gelcekte doğamazsın!" << endl;
        return 0;
    }

    // sonuç kullancıya döndürüldü 
    cout << "Yaşınız: " << MevcutYil - RawDogumYili << endl;

    
    return 0;
}
