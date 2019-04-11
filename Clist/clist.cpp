#ifdef clist_hpp
//#define clist_cpp
#include <iostream>
#include <cstdlib>
//#include "clist.hpp"


template<typename dataType>
void Clist<dataType>::checkrep()const{
	if(count < 0){
		std::cout << "Size undervaluated" << std::endl;
		exit(EXIT_FAILURE);
	}
	if(count > 0 && cursor == nullptr){
		std::cout << "Fpermissive memory violated" << std::endl;
		exit(EXIT_FAILURE);
	}
	
}


template<typename dataType>
Clist<dataType>::~Clist(){
	checkrep();
	clear();
	checkrep();
}

template<typename dataType>
dataType & Clist<dataType>::back()const{
	return cursor->data;
}
template<typename dataType>
dataType & Clist<dataType>::front()const{
	return (cursor->next)->data;
}

template<typename dataType>
void Clist<dataType>::insert(dataType item){
	checkrep();
	if(cursor == nullptr){
		cursor = new Node{item};
		cursor->next = cursor;
	}
	else{
		Node *dir = cursor->next;
		Node *tmp = cursor;
		cursor = new Node{item};
		cursor->next = dir;
		tmp->next = cursor;
	}
	count++;
	checkrep();
}

template<typename dataType>
void Clist<dataType>::remove(){
	checkrep();
	if(count>1){
		Node *tmp = cursor->next;
		Node *dir = tmp->next;
		cursor->next = dir;
		delete tmp;
	}
	else cursor = nullptr;
	count--;
	checkrep();
}

template<typename dataType>
void Clist<dataType>::advance(){
	checkrep();
	cursor = cursor->next;
	checkrep();
}

template<typename dataType>
void Clist<dataType>::clear(){
	checkrep();
	while(!empty()){
		remove();
	}
	checkrep();
}

template<typename dataType>
unsigned Clist<dataType>::size()const{
	return count;
}
template<typename dataType>
bool Clist<dataType>::empty()const{
	return (count==0);
}
#endif //_clist_hpp_
