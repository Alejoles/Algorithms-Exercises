#include <iostream>
#include <string>

using namespace std;

int n=0;
int x = 1;

void recur(int oe){
	string pp;
	string ll;
	string oo;
	if(oe==0){	
	}
	else{
	ll = to_string(oe);
	oo=ll.at(ll.length()-1);
	n++;
	recur(oe/(x*10));
	cout << oo.front();
	}
}

int main(void){
	int n;
	cout << ">";
	cin >> n;
	recur(n);
	return 0;
}




