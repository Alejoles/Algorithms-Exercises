#include <iostream>
#include <string>

using namespace std;


string invertido(string str){

	if(str.length()==1) return str;
	else{
		return invertido(str.substr(1,str.length()-1)) + str.at(0);
		
	}

}

int main(void){
	string str = "hola";
	//getline(cin,str);
	cout << invertido(str)<< endl;
	return 0;
}


