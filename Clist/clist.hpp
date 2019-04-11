#ifndef clist_hpp
#define clist_hpp

template <typename dataType>
class Clist{
public:
	Clist() = default;	// Crea una lista vacia
	~Clist();		// Destruye una lista
	
	dataType &back() const;	// elemento en el cursor
	dataType &front() const;// elemento siguiente al cursor
	
// inserta nodo con un tipo de dato despues del cursor
	void insert(dataType item); 
	void remove(); 	// mata nodo despues del cursor
	void advance();	// mueve el cursor al nodo siguiente
	
	unsigned size() const;	// # elementos
	bool empty() const;	// mira si está vacía la lista
	void clear(); 		// elimina todo el contenido de lista
private:
	struct Node{
		dataType data;
		Node *next;
		Node(dataType &d, Node *n = nullptr): data{d}, next{n} {}	//in-function
		
	};
	
	Node *cursor = nullptr;	// Puntero cursor
	unsigned count = 0;	// Numero de elementos
	void checkrep()const;

};

#include "clist.cpp"

#endif // _clist_hpp_

