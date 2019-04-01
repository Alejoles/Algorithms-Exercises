#include "simple_vector.hpp"
#include <cmath>

using namespace std;

simple_vector::simple_vector(){
	this->capacity = Inicial;
	array = new double[capacity];
	this->length = 0;
}
simple_vector::simple_vector(const simple_vector &rhs){ // Constructor copia
	deepCopy(rhs);
}
simple_vector::~simple_vector(){
	delete[] array;
}
simple_vector::simple_vector(int n){
	delete[] array;
}

ostream & operator<<(ostream &os, const simple_vector &rhs) {
    os << "(  ";
    for (int i = 0; i < rhs.length; i++) cout << rhs.array[i] << "  ";
    os << "), len = " << rhs.length << ", cap = " << rhs.capacity;
    
    return os;
}


void simple_vector::deepCopy(const simple_vector &rhs){
	array = new double[rhs.capacity+10];
	for(int i = 0; i < rhs.length; i++){
		array[i] = rhs.array[i];
	}
	length = rhs.length;
	capacity = rhs.capacity +10;
}
void simple_vector::expandCapacity(){
	double *oldarr = array;
	capacity *= 2;
	array = new double[capacity];
	for(int i = 0; i <= length; i++){
		array[i] = oldarr[i];
	}
	delete[] oldarr;
}


simple_vector & simple_vector::operator=(const simple_vector &rhs){
	if(this != &rhs){
		delete[] array;
		deepCopy(rhs);
	}
	return *this;
}


void simple_vector::push(double value){
	if(length >= 0){
		if(length == capacity) expandCapacity();
		array[length++] = value;
	}
	else{
		cout << "Error length push" << endl;
	}
}
void simple_vector::erase(int index){ // Borra el elemento y todos los elementos posteriores se tienen que correr a la izquierda
	if(length >= 0){
		if(index <= length){
			for(int i = index; i < length; i++){
				if(i < length-1){
					array[i] = array[i+1];
				}
			}
			this->length--;
		}
		else{
			cout << "Out of range in erase" << endl;
		}
	}
	else{
		cout << "Error length erase" << endl;
	}
}
void simple_vector::insert(int index, double value){
	if(length >= 0){
		try{
			if(length == capacity) expandCapacity();
			length++;
			for(int i = length; i>=index; i--){
				array[i] = array[i-1];
				if(i == index){
					array[i] = value;
				}
			}
			if(index > capacity){
				throw 125;
			}
		}
		catch(int){
			cout << "Excepcion de tipo indexado"<< endl;
		}
	}
	else{
		cout << "Error length insert" << endl;
	}
}
void simple_vector::modify(int index, double value){
	if(index > length){
		cout << "Out of range in modify" << endl;
	}
	else{
		array[index] = value;
	}
}
double simple_vector::retrieve(int index){// get
	if(index <= length){
		return array[index];
	}
	else{
		cout << "Out of range error in retrieve" << endl;
		return -1.0;
	}
	
}


void simple_vector::clear(){
	this->length = 0;
}
bool simple_vector::empty() const{
	return (length == 0);
}
int simple_vector::size() const{
	return length;
}









