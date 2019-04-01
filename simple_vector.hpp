#ifndef _simple_vector_hpp_
#define _simple_vector_hpp_

#include <iostream>

using namespace std;

// Invariante más representativa del vector

class simple_vector{
private:
	static const int Inicial = 10;
	double *array = nullptr;
	int capacity = 10;
	int length = 0; // Diferencias entre el tamaño del arreglo y el numero de elementos
	void expandCapacity();
	void deepCopy(const simple_vector &rhs);
	
public:
	simple_vector(); // Default constructor
	simple_vector(int n);
	simple_vector(const simple_vector &rhs); // constructor copia
	~simple_vector();  // Destructor
	//~simple_vector(int);
	
	simple_vector & operator=(const simple_vector &rhs);
	
	friend ostream & operator<<(ostream &os, const simple_vector &rhs);
	
	void push(double value);
	void erase(int index);
	void insert(int index, double value);
	void modify(int index, double value);
	double retrieve(int index);
	
	void clear();		// borra el contenido del array
	bool empty() const;	// chequea si el array está vacio
	int size() const;	// retorna el numero de elementos

};

#endif // _simple_vector_hpp_
