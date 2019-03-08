#include <iostream>
#include <map>
#include <string>
#include <fstream>


using namespace std;

int main(void){
	map<string, string> mapa;
	string cadena;
	ifstream lec;
	lec.open("error.txt");
	while(!lec.eof()){
	string line;
	string linea;
	string linear;
		getline(lec,cadena);
		for(unsigned i = 0; i<cadena.size();i++){
			if(cadena[i] != '\t') line += cadena[i];
			else break;
		}
		for(unsigned j = cadena.size(); j!=0; j--){
			if(cadena[j] != '\t') linea += cadena[j];
			else break;	
		}
		for(unsigned k = linea.size(); k!=0; k--){
			linear += linea[k];
		}
		mapa.insert(pair<string,string>(line,linear));
	}
	lec.close();
	for(map<string,string>::iterator it=mapa.begin(); it!=mapa.end(); it++){
		cout << it->first << " => " << it->second << endl;
	}
	return 0;
}
