#include <iostream>
#include <string>

using namespace std;

//La funcion retorna el string invertido recursivamente


string invertir_str(string str){
	if(str.length()==1) return str;
	else{
		return invertir_str(str.substr(1,str.length()-1)) + str.at(0);
		
	}

}


int main(void){
	cout << invertir_str("hola") << endl;
	return 0;
}
