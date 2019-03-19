#include <iostream>
#include <string>
#include <vector>

//PERMUTACIONES DE STRING

using namespace std;

vector<string> permu(string pal){
		vector<string> vec;
		vec.push_back(pal);
		if(pal.size() == 0){
			return vec;
		}
		else{
			return permu(pal.substr())
		}
}


int main(void){
	string len = "bus";
	vector<string> vec = permu(len);
	for(unsigned i = 0; i<vec.size(); i++){
		cout << vec[i] << endl;
	}
	return 0;
}
