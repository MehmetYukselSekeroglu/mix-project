#include <iostream>

using namespace std;

void ShowMenu(){
    cout << "********************" << endl;
    cout << "1- Hesap bilgisi göster " << endl;
    cout << "2- Para yatır " << endl;
    cout << "3- Para çek " << endl;
    cout << "4- Çıkış " << endl;
    cout << "********************" << endl;
    
}


int main(){
    
    short secim;
    long long int TotalBakiye = 0, Yatirim = 0, Cekim = 0;
    
    
    while (true){
        ShowMenu();
        cout << "-> ";
        cin >> secim;
        switch (secim){
        case 1:
            cout << "Hesabınızda " << TotalBakiye << " TL bulunuyor \n";
            break;
        case 2:
            cout << "Yatırılacak tutarı giriniz: ";
            cin >> Yatirim;
            TotalBakiye += Yatirim;
            
            break;
        case 3:
            cout << "Çekilecek miktarı giriniz: ";
            cin >> Cekim;
            
            if (Cekim > TotalBakiye){
                cout << "Yetersiz bakiye!" << endl;
            }else{
                TotalBakiye -= Cekim;
                cout << "Kalan bakiye: " << TotalBakiye << " TL dir " << endl;
            }
            break;
        case 4:
            cout << "Çıkış..." << endl;
            exit(EXIT_FAILURE);
            break;
            
        
        }
    }
    return 0;
}