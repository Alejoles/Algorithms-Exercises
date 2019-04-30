#include <random>
#include <iostream>
#include "Htable.hpp"

using namespace std;
				//???????????????????????????????
template<>
class hashFunction<int>{
public:
	unsigned operator()(const int &key){
		return static_cast<unsigned>(key);
	}
};

int main(void){

	/*const int min = -15, max = +15;
	random_device rd;
	default_random_engine generator{rd()};
	uniform_int_distribution<int> distribution(min, max);

	hash_table<int> ht;

	//insert keys

	for(int i = 0; i<max ; i++){
		int key = distribution(generator);
		ht.insert(key);
		cout << "insert: " << key << endl;
	}

	//find keys
	for(int key = min; key < max ; ++key){
		cout << "Find: " << key << " " << ht.search(key) << endl;
	}
	//remove pairs
	for(int i = min; i<max; i++){
		int key = distribution(generator);
		cout << "Remove: " << key << " " << ht.remove(key) << endl;
	}
	//find keys again
	for(int key = min; key < max ; ++key){
		cout << "Find: " << key << " " << ht.search(key) << endl;
	}
	*/
	hash_table<int> a = hash_table<int>();
	a.insert(4);
	cout << a.search(4) << endl;
	a.insert(8);
	cout << a.search(8) << endl;
	a.insert(12);
	cout << a.search(12) << endl;
	a.insert(16);
	cout << a.search(16) << endl;
	a.insert(20);
	cout << a.search(20) << endl;
	//cout << "/////" << endl;
	//cout << a.remove(100) << endl;
	//cout << a.search(100) << endl;



	return 0;

}
