#include <iostream>
#include <string>

using namespace std;


bool isPal(string pal){
	int n = pal.length();
	if(n < 2) return true;
	else return (pal[0] == pal[n-1]) and (isPal(pal.substr(1,n-2)));

}

int main(void){
	string str = "";
	getline(cin, str);
	if(isPal(str) == true)cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}


