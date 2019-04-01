#include <iostream>
#include <string>

using namespace std;

class Domino{
	int izq, der;
public:
	Domino(): izq(0), der(0) {}
	Domino(int izquierda, int derecha): izq(izquierda), der(derecha) {}
	void set_left_dots(int ldots);
	void set_right_dots(int rdots);
	int get_left_dots();
	int get_right_dots();
	string t_string(); //crea una representacion del domino en string	
	//operadores booleanos
	friend bool operator==(Domino d1, Domino d2);
	friend bool operator!=(Domino d1, Domino d2);//
	friend bool operator<(Domino d1, Domino d2);//
	friend bool operator<=(Domino d1, Domino d2);//
	friend bool operator>(Domino d1, Domino d2);//
	friend bool operator>=(Domino d1, Domino d2);//
	//--------------------
	friend ostream & operator<<(ostream os, Domino d);
	void flip_them(); //Voltea los valores iz a der y viceversa 
	
};
bool operator!=(Domino &d1, Domino &d2){
	if(d1.get_left_dots()!=d2.get_left_dots())
}

void Domino::flip_them(){
	int chan;
	chan = this->izq;
	this->izq = this->der;
	this->der = chan;
}

bool operator==(Domino &d1, Domino &d2){
	return (d1.get_left_dots() == d2.get_left_dots() && d1.get_right_dots() == d2.get_right_dots()) or (d1.get_left_dots() == d2.get_right_dots() && d1.get_right_dots() == d2.get_left_dots());
}

ostream & operator<<(ostream os, Domino d){
	return os << "[" << d.get_left_dots() << "|" << d.get_right_dots() << "]";
}

int Domino::get_left_dots(){
	return this->izq;
}
int Domino::get_right_dots(){
	return this->der;
}

string Domino::t_string(){
	std::string str = "";
	std::string left = to_string(this->izq);
	std::string right = to_string(this->der);
	str = "[" + left + "|" + right + "]";
	return str;
}

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

int main(void){
	Domino d = {2,4};
	cout << d.get_left_dots() << endl;
	cout << d.t_string() << endl;
	d.flip_them();
	cout << d.get_left_dots() << endl;
	return 0;
}









