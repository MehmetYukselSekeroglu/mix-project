#include <iostream> 
#include <string>
using namespace std;

int main(){
	// karakter dizisi saklamak için 
	string DogName; 
	cout << "Lütfen köpek ismini giriniz: " << endl;
	cin >> DogName;
	cout << "Lütfen köpek yaşını giriniz" << endl;
	
	// hafızada gereksiz yer kaplamasın diye 
	short DogAge;
	cin >> DogAge;

	if (DogAge <= 0){
		cout << "yaş negatif veya 0 değeri alamaz" << endl;
		return 0;
	}
	
	

	cout << DogName << "'in insan yaşı: " << DogAge * 7 << endl;
	return 0;

}
