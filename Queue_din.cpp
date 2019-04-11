#include <iostream>
#include <cassert>

using namespace std;

template <typename dataType>
class Queue{
private:
	static const int INITIAL_CAPACITY = 10;
	dataType *array = new dataType[INITIAL_CAPACITY];
	int capacity = 0;
	int head = 0;
	int tail = 0;
	void expandCapacity();
	void deepCopy(const Queue<dataType> &rhs);
	void checkRep(); //--
	
public:

	Queue() = default;
	Queue(const Queue &rhs);
	~Queue();
	unsigned size()const;
	bool empty();
	void clear();
	void enqueue(dataType & ch);
	dataType dequeue();
	dataType peek();

};
template <typename dataType>
void Queue<dataType>::checkRep(){
	if(tail == head){
		tail = 0;
		head = 0;
	}
	if(tail > head){
		assert(tail>head);
	}
}

template <typename dataType>
void Queue<dataType>::expandCapacity(){
	dataType *oldarr = array;
	capacity*=2;
	array = new dataType[capacity];
	for(int i = 0; i<head; i++){
		array[i] = oldarr[i];
	}
	delete[] oldarr;
}
template <typename dataType>
void Queue<dataType>::deepCopy(const Queue<dataType> &rhs){
	array = new dataType[rhs.capacity+10];
	for(int i = 0; i<head ;i++){
		array = rhs.array[i];
	}
	head = rhs.head;
	capacity = rhs.capacity+10;
}

//constructor copia
/*
template <typename dataType>
Queue<dataType>::Queue(){
	this->capacity = INITIAL_CAPACITY;
	this->array = new dataType[INITIAL_CAPACITY];
	
}
*/
template <typename dataType>
Queue<dataType>::~Queue(){
	delete[] array;
}

template <typename dataType>
unsigned Queue<dataType>::size()const{
	return this->head;
}

template <typename dataType>
bool Queue<dataType>::empty(){
	return (head == tail);
}

template <typename dataType>
dataType Queue<dataType>::dequeue(){
	dataType lol = array[tail];
	tail++;
	/*
	for(int i = 1; i<=head ; i++){
		array[i-1] = array[i];
	}*/
	return lol;
}

template <typename dataType>
void Queue<dataType>::enqueue(dataType & ch){
	if(head == capacity) expandCapacity();
	head++;
	array[head] = ch;
}

template <typename dataType>
void Queue<dataType>::clear(){
	head = 0;
	tail = 0;
}
template <typename dataType>
dataType Queue<dataType>::peek(){
	return array[tail];
}


int main(void){
	Queue<int> que;
	if(que.empty()){
		cout << "siks" << endl;
	}
	for(int i = 0; i < 10 ;i++){
		que.enqueue(i);
		que.dequeue();
		cout << que.peek() << endl;
	}
	int x = 5;
	que.enqueue(x);
	if(que.empty()){
		cout << "siks" << endl;
	}
	else{
		cout << "noks" << endl;
	}
	for(int i = 0; i < 10 ;i++){
		que.enqueue(i);
	}
	que.clear();
	if(que.empty()){
		cout << "siks" << endl;
	}
	return 0;
}



