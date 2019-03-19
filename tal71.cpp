#include <iostream>

using namespace std;

//n-ésima potencia de un número

int potencia(int n, int k){
/*
	n es el numero que se introduce
	k es la potencia a la que se eleva el numero n
	
*/
	if(k == 0) return 1;
	else{
		return n * potencia(n,k-1);
	}

}

int main(void){
	cout << potencia(5,3) << endl;
	return 0;
}
