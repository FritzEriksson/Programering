#include <iostream>

using namespace std;

class Arbetare{
	public:
		void setArbetare();
		void getArbetare();
		void berakning();
	private:
		string Namn;
		int lon;
		int timlon;
		int arbetstimmar;
};

void Arbetare::berakning(){
	lon = arbetstimmar * timlon;
}

void Arbetare::setArbetare(){
	cout << "\nFörnamn på den anställda: ";
	cin >> Namn;
	cout << "\nAnställdes timlön: ";
	cin >> timlon;
	cout << "\nAnställdes arbetstimmar: ";
	cin >> arbetstimmar;	
}

void Arbetare::getArbetare(){
	cout << "====================================" << endl;
	cout << "Namn:         | " << Namn << endl;
	cout << "arbetstimmar: | " << arbetstimmar << " h" << endl;
	cout << "Lön:          | " << timlon << " kr/h" << endl;
	cout << "Månadslön:    | " << lon << " kr" << endl;	
}

int main(){
	int x;
	cout << "Hur många anställda vill du lista?: ";
	cin >> x;
	Arbetare lista[x];
	for(int i=0; i<x; i++){
		lista[i].setArbetare();
	}
	for(int i=0; i<x; i++){
		lista[i].berakning();
	}
	cout << "\nLista över andställda och dess löner" << endl;
	for(int i=0; i<x; i++){
		lista[i].getArbetare();
	}
}
