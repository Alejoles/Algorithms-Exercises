#include <iostream>
#include <string>

using namespace std;

class Domino{
	int izq, der;
public:
	Domino(): izq(0), der(0) {}
	Domino(int izquierda, int derecha): izq(izquierda), der(derecha) {}
	string puntosIz();
	void set_left_dots(int ldots);
	void set_right_dots(int rdots);
	int get_left_dots();
	int get_right_dots();
	string to_string(); //crea una representacion del domino en string
	//operadores booleanos
	
	//--------------------
	friend ostream & operator<<(ostream os, Domino d);
	void flip_them(); //Voltea los valores iz a der y viceversa 
	
};

void Domino::set_left_dots(int ldots){
	if(ldots <= 6 && ldots >= 0){
		this->izq = ldots;
	}
	else{
		cout << "El domino va de [0,6] ingrese otro valor" << endl;
	}
	
}
void Domino::set_right_dots(int rdots){
	if(rdots <= 6 && rdots >= 0){
		this->der = rdots;
	}
	else{
		cout << "El domino va de [0,6] ingrese otro valor" << endl;
	}
}
int Domino::get_left_dots(){
	return this->izq;
}
int Domino::get_right_dots(){
	return this->der;
}
string Domino::to_string(){
	
}

int main(void){
	Domino d = {2,4};
	cout << d.get_left_dots() << endl;
	return 0;
}









