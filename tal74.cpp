//PALINDROMO

#include<iostream>
#include<string>

using namespace std;

bool isPalin(string pal){
	if(pal.size() == 0){
		return true;
	}
	else{
		if(pal.front() == pal.back()) return isPalin(pal.substr(1,pal.length()-2));
		else return false;
	}

}


int main(void){
	string pal = "abcdefghijklmnopqrsutv.vtusrqponmlkjihgfedcba";
	pal = "g";
	if(isPalin(pal) == true) {
	cout << "true"<< endl;
	}
	else{
	cout << "false" << endl;
	}
	return 0;
}
















