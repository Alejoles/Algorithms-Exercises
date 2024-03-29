#ifndef _Htable_hpp_
#define _Htable_hpp_
#include <vector>

template<typename data_type> class hashFunction;

template<typename dataType>
class hash_table {
	enum bucket_type {Active, Empty , Deleted };

	struct bucket {
		dataType elem;		// llave actual
		bucket_type info;	// estado del bucket
		bucket(const dataType &e, bucket_type i = Empty): elem{e}, info{i} {} //in-class inicialization
	};

	unsigned n_buckets;		// tamaño de la tabla
	std::vector<bucket> array;	// size: n_buckets

	void rehash();
	unsigned hashing(const dataType &x) const;
	
	void checkrep() const;	// recorrer la tabla y ver que hay en la tabla por elem e info(acti,del,empt), chequear el tamaño size = n_buckets etc...

public:
	hash_table();
	~hash_table();
	void empty();

	int insert(const dataType &x);
	int search(const dataType &x) const;
	int remove(const dataType &x);

};

#include "Htable.cpp"


#endif // _Htable_hpp_
