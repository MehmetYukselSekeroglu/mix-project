#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    /*
    vize_1 = %20 
    vize_2 = %20
    final_1 = %60 

    yüzdelik etkileridir  
    */

    int vize_1, vize_2, final_1;
    cout << "Vize 1'in notunu giriniz: ";
    cin >> vize_1;

    if (vize_1 > 100 or vize_1 < 0 ){
        cout << "Vize notu 100 den büyük 0 dan küçük olamaz!" << endl;
        return 0;
    }


    cout << "Vize 2'nin notunu giriniz: ";
    cin >> vize_2;

    if (vize_2 > 100 or vize_2 < 0 ){
        cout << "Vize notu 100 den büyük 0 dan küçük olamaz!" << endl;
        return 0;
    }


    cout << "Final notunu giriniz: ";
    cin >> final_1;

    if (final_1 > 100 or final_1 < 0 ){
        cout << "Vize notu 100 den büyük 0 dan küçük olamaz!" << endl;
        return 0;
    }

    int not_ortalmasi = (vize_1 * 0.2) + (vize_2 * 0.2) + (final_1 * 0.6);
    cout << "------------------------------" << endl;
    cout << "Ders sonu not ortalaması: " << not_ortalmasi << endl;
    return 0;
}
