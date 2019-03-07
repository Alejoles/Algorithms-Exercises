#include <iostream>
#include <queue>
#include <string>

//-------------------------------FLAVIO JOSEFO-------------------------------

using namespace std;

void Flavio(queue<string> que){
	

}

int main(void){
	string line;
	queue<string> que;
	cout << "ingrese los nombres de las personas, y escriba end al terminar" << endl;
	while(cin >> line){
	if(line != "end"){
	que.push(line);
	}else break;
	}
	cout << que.back() << endl;
	return 0;
}
