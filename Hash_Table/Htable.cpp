#ifdef _Htable_hpp_
#include <iostream>
#include <vector>
#include <cstdlib>


template<typename dataType>
void hash_table<dataType>::checkrep() const{
	if(this->array.size() != this->n_buckets){
		std::cout << "the size of the table is diferent than the capacity of buckets." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::vector<bucket> a = this->array;
	for(unsigned i = 0; i<a.size(); i++){
		if(a.at(i).info != Empty || a.at(i).info != Deleted || a.at(i).info != Active);
		else{
			std::cout << "Info error" << std::endl;
			exit(EXIT_FAILURE);
		}
		
	}
}

template<typename dataType>
unsigned hash_table<dataType>::hashing(const dataType &x) const{
	hashFunction<dataType> hashFunctor;
	return hashFunctor(x)%this->n_buckets;
}

template<typename dataType>
void hash_table<dataType>::rehash(){
	checkrep();
	std::vector<bucket> oldarr = this->array;
	this->n_buckets *= 2;
	dataType trash;
	this->array.clear();
	for(unsigned i = 0; i<this->n_buckets; i++){
		this->array.push_back(bucket(trash, Empty));
	}

	for(unsigned i = 0; i<oldarr.size(); i++){
		if(oldarr[i].info == Active){
				unsigned t = hashing(oldarr.at(i).elem);
				this->array.at(t).elem = oldarr.at(i).elem;
				this->array.at(t).info = Active;
		}
	}
	checkrep();
}

template<typename dataType>
hash_table<dataType>::hash_table(){
	this-> n_buckets = 101;
	dataType trash;
	for(unsigned i = 0; i < this->n_buckets; ++i) {
		this->array.push_back(bucket(trash, Empty));
	}
}

template<typename dataType>
hash_table<dataType>::~hash_table(){
	this->array.clear();
}


template<typename dataType>
void hash_table<dataType>::empty(){
	checkrep();
	for(unsigned i = 0; i < this->array.size(); ++i){
		this->array.at(i).info = Empty;
	}
	checkrep();
}

template<typename dataType>
int hash_table<dataType>::insert(const dataType &x){
	checkrep();
	unsigned a = hashing(x);
	unsigned b = a;
	while(a < this->array.size()) {
		if(this->array[a].info == Empty || this->array[a].info == Deleted){
			this->array[a].elem = x;
			this->array[a].info = Active;
			return a;
		}
		else a++;
	}
	a = 0;
	while(a != b){
		if(this->array[a].info == Empty || this->array[a].info == Deleted){
			this->array[a].elem = x;
			this->array[a].info = Active;
			return a;
		}
		else a++;
	}
	rehash();
	insert(x);
	checkrep();
	return -1;
}

template<typename dataType>
int hash_table<dataType>::search(const dataType &x) const{
	checkrep();
	unsigned num = hashing(x);
	unsigned b = num;
	while(num < this->array.size()){
		if(this->array[num].elem == x && this->array[num].info == Active){
			return num;
		}
		else num++;
	}
	num = 0;
	while(num != b){
		if(this->array[num].elem == x && this->array[num].info == Active){
			return num;
		}
		else num++;
	}
	checkrep();
	return -1;
}


template<typename dataType>
int hash_table<dataType>::remove(const dataType &x){
	checkrep();
	int a = search(x);
	if(a != -1) {
		this->array.at(a).info = Deleted;
		checkrep();
		return a;
	}
	checkrep();
	return -1;
}

#endif //
