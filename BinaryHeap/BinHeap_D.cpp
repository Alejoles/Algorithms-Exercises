#include <random>
#include <iostream>
#include "BinHeap.hpp"

int main(void){
	const short min = 1;
	const short max = 20;
	std::random_device rd;
	std::default_random_engine generator{rd()};
	std::uniform_int_distribution<short> distribution(min,max);
	
	BinaryHeap<short> bh;
	
	for(int i = min; i<=max-5; i++){
		short number= distribution(generator);
		bh.insert(number);
		std::cout << "Inserted: " << number << std::endl;
	}
	
	std::cout << "Heap: " << std::endl;
	bh.display();
	std::cout << std::endl;
	
	std::cout << "Min heap:" << bh.findMin() << std::endl;
	
	return 0;
}
