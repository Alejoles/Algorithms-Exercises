#include <iostream>
#include <vector>

using namespace std;


void ordenar(vector<int> vec1, vector<int> vec2, vector<int> & ordenado){

	if(vec1.size() == 0 && vec2.size() == 0){
		return;
	}
	else{
		if(vec1.size() != 0 && vec2.size() != 0){
			if(vec1[0] >= vec2[0]){
			ordenado.push_back(vec2[0]);
			vec2.erase(vec2.begin());
			}
			else{
			ordenado.push_back(vec1[0]);
			vec1.erase(vec1.begin());
			}
		}
		else if(vec2.size() == 0 && vec1.size() != 0){
			ordenado.push_back(vec1[0]);
			vec1.erase(vec1.begin());
		}
		else if(vec2.size() != 0 && vec1.size() == 0){
			ordenado.push_back(vec2[0]);
			vec2.erase(vec2.begin());
		}	
		/*for(unsigned i = 0; i< ordenado.size(); i++){
			cout << ordenado[i] << " * ";
		}*/
		ordenar(vec1,vec2,ordenado);
		
	}
	
}



int main(void){
	vector<int> vec1 = {2,4,6,7,8,9,10};
	vector<int> vec2 = {0,1,3,5,7,9,11};
	vector<int> r;
	ordenar(vec1,vec2,r);
	
	for(unsigned i = 0; i<r.size();i++){
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}
