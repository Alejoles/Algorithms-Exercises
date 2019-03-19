#include <iostream>
#include <set>

using namespace std;

bool subset(set<int>a, set<int>b){
	unsigned len = b.size();
	set<int>::iterator it;
	for(it = a.begin(); it!= a.end(); it++){
		b.insert(*it);
	}
	if(len == b.size()) return true;
	else return false;

}


int main(void){
	set<int> a = {1,2,3,4,5,6,7,8,9,10,20};
	set<int> b = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if(subset(a,b) == true){
	cout << "A es subcojunto de b." << endl;
	}else{
	cout << "A no es subconjunto de b." << endl;
	}
	return 0;
}
