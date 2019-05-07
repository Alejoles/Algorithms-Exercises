#ifdef _BinHeap_hpp_
#include <vector>
#include <iostream>
#include "BinHeap.hpp"

template<typename dataType>
BinaryHeap<dataType>::BinaryHeap(int capacity){
	this->array.reserve(capacity);
}

template<typename dataType>
void BinaryHeap<dataType>::percolateDown(int hole){
	

}

template<typename dataType>
const dataType & BinaryHeap<dataType>::findMin()const{
	if(count > 0){
		return array[0];
	}
	else{
		throw std::underflow_error("Tried to find element in empty heap");
	}
}

template<typename dataType>
void BinaryHeap<dataType>::insert(const dataType &elem){
	if(this->count == this->array.capacity()){
		std::cout << "The array if full, can't insert key" << std::endl;
		return;
	}
	this->array.push_back(elem);
	unsigned i = count;
	this->count++;
	unsigned parent = std::floor(i/2);
	while(i!=0 && this->array[parent] > this->array[i]){
		dataType temp = array[i];
		array[i] = array[parent];
		array[parent] = temp;
		i = parent;
		parent = std::floor(i/2);
	}
}


template<typename dataType>
void BinaryHeap<dataType>::deleteMin(){
	// elimina el primer elemento y tiene que cambiar
	if(count == 0){
		std::cout << "Can't use delete in an empty array" << std::endl;
	}
	else{
		count--;
		
	}
}

template<typename dataType>
bool BinaryHeap<dataType>::isEmpty()const{
	return (this->count == 0);
}

template<typename dataType>
void BinaryHeap<dataType>::clear(){
	this->array.clear();
}

template<typename dataType>
void BinaryHeap<dataType>::display()const{
	std::cout << "[";
	for(auto it = this->array.cbegin(); it != this->array.cend(); it++){
		std::cout << *it << ",";
	}
	std::cout << "]";
}






#endif
