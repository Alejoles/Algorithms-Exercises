#include <random>
#include <iostream>
#include "BinHeap.hpp"

int main(void){
	const short min = 65, max = 90;
	std::random_device rd;
	std::default_random_engine generator{rd()};
	std::uniform_int_distribution<int> distribution(min,max);
	
	BinaryHeap<short> bh;
	
	for(int i = min; i<=max-5; i++){
		short number= distribution(generator);
		bh.insert(number);
		std::cout << "Inserted: " << number << std::endl;
	}
	
	std::cout << "Heap: " << std::endl;
	bh.display();
	bh.deleteMin();
	bh.display();
	std::cout << std::endl;
	
	std::cout << "Min heap:" << bh.findMin() << std::endl;
	
	return 0;
}
