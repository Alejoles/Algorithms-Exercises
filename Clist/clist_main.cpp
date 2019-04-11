#include "clist.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void){

	Clist<int> playlist;

	int b = 2;
	int c = 1;
	int a = 3;
	playlist.insert(c);
	playlist.insert(b);
	playlist.insert(a);
	
	cout << "Now playing" << playlist.back() << endl;
	
	int d = 4;
	playlist.advance();
	playlist.advance();
	cout << "Size: " << playlist.size() << endl;
	playlist.remove();
	playlist.insert(d);
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	playlist.advance();
	cout << "Now playing" << playlist.back() << endl;
	cout << "Size: " << playlist.size() << endl;
	playlist.clear();
	cout << "Size: " << playlist.size() << endl;
	
	return 0;
}

