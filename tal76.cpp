#include <iostream>
//PRINT_NUM(INT N);

using namespace std;


void print_num(int n){
	if(n/10==0) {
	cout << n%10;
	}
	else{
		print_num(n/10);
		cout << n%10;
	}
}


int main(void){
	print_num(8125958);
	cout << endl;
	return 0;
}
