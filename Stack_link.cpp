#include <iostream>

using namespace std;

template <typename dataType>
class Stack{
private:
	struct Cell{// linked list cell
		dataType data;
		Cell *link;
	};
	
	Cell *stack = nullptr; // in-class initialization
	size_t count = 0;
	void deepCopy(const Stack <dataType> & src);

public:

	Stack() = default;
	Stack(const Stack &rhs);
	~Stack();
	size_t size();
	bool empty();
	void clear();
	void push(dataType & ch);
	dataType pop();
	dataType peek();

};


template <typename dataType>
Stack<dataType>::~Stack(){
	clear();
}
template <typename dataType>
size_t Stack<dataType>::size(){
	return count;
}
template <typename dataType>
bool Stack<dataType>::empty(){
	return count==0;
}
template <typename dataType>
void Stack<dataType>::clear(){
	while(!empty()){
		pop();
	}
}
template <typename dataType>
void Stack<dataType>::push(dataType &ch){
	Cell *cell = new Cell;
	cell->data = ch;
	cell->link = stack;
	stack = cell;
	count++;
}
template <typename dataType>
dataType Stack<dataType>::pop(){
	if(empty()) cout << "error: Your stack is empty" << endl;
	Cell *cell = stack;
	dataType result = cell->data;
	stack = stack->link;
	count--;
	delete cell;
	return result;
}
template <typename dataType>
dataType Stack<dataType>::peek(){
	if(empty()) cout << "error: Your stack is empty" << endl;
	return stack->data;
}




int main(void){
	int x = 10;
	Stack<int> stk;
	stk.push(x);
	cout << "peek:" << stk.peek() << endl;
	
	
}









