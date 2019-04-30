#ifdef _Htable_hpp_
#include <iostream>
#include <vector>
#include <cstdlib>

template<typename dataType>
unsigned hash_table<dataType>::hashing(const dataType &x) const{
	hashFunction<dataType> hashFunctor;
	return hashFunctor(x)%this->n_buckets;
}

template<typename dataType>
void hash_table<dataType>::rehash(){
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
}

template<typename dataType>
hash_table<dataType>::hash_table(){
	this-> n_buckets = 4;
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
	for(unsigned i = 0; i < this->array.size(); ++i){
		this->array.at(i).info = Empty;
	}
}

template<typename dataType>
int hash_table<dataType>::insert(const dataType &x){
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

	return -1;
}

template<typename dataType>
int hash_table<dataType>::search(const dataType &x) const{
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
	return -1;
}


template<typename dataType>
int hash_table<dataType>::remove(const dataType &x){
	int a = search(x);
	if(a != -1) {
		this->array.at(a).info = Deleted;
		return a;
	}
	return -1;
}

#endif //
