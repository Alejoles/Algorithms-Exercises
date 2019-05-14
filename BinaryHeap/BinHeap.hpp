#ifndef _BinHeap_hpp_
#define _BinHeap_hpp_

#include <vector>
#include <iostream>

template <typename dataType>
class BinaryHeap {
public:
	BinaryHeap(int capacity = 100); //?
	BinaryHeap(const std::vector<dataType> &vec);
	
	const dataType & findMin() const;
	void insert(const dataType &elem);
	void deleteMin();
	
	bool isEmpty() const;
	void clear();
	void display() const;
private:
	unsigned int count;		// Numero de elementos
	std::vector<dataType> array;	// vector de elementos
	void percolateDown(int hole);
	
};

#include "BinHeap.cpp"

#endif //BinHeap.hpp
