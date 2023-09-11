#include <iostream>

using namespace std;

int main(){
        long long int sayi1, sayi2;
        char secim, devam;
        string sonuc_ver = "Sonuç: ";
        
        while (true){
            cout << "lütfen işleminizi giriniz: ";
            cin >> sayi1 >> secim >> sayi2;
            
            switch(secim){
                case '+':
                    cout << sonuc_ver << sayi1 + sayi2 << endl;
                    break;
                case '-':
                    cout << sonuc_ver << sayi1 - sayi2 << endl;
                    break;
                    
                case 'x':
                    cout << sonuc_ver << sayi1 * sayi2 << endl;
                    break;
                    
                case '/':
                    cout << sonuc_ver << sayi1 / sayi2 << endl;
                    break;
                default:
                    cout << "Tanımlanmamış işlem!" << endl;
                    break;
            }
            cout << "Devam etmek istermisiniz? (Devam -> y): ";
            cin >> devam;
        
            if (devam != 'y' && devam != 'Y' )
            break; // burası tek satırlık if kısmıdır 
                
        }
}
