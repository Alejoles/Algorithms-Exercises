#include <iostream>

using namespace std;


void to_binary(int n){
	if(n/2 == 0){
		cout << n%2;
	}
	else{
		to_binary(n/2);
		cout << n%2;
	}
}

string binary(int n){
	if(n/2 == 0) return to_string(n%2);
	else{
		return binary(n/2) + to_string(n%2);
	}

}


int main(void){
	cout << binary(-256) << endl;
	return 0;
}
