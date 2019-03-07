#include <iostream>
#include <vector>

using namespace std;

int FindMiss(vector<int> vec){
	int lh=0; int rh = vec.size();
	while(lh<=rh){
		int mid = (lh+rh)/2;
		if(vec[mid] != vec[mid+1]-1 ){
			return vec[mid]+1;
		}
		else if(vec[mid] != vec[mid-1]+1){
			return vec[mid]-1;
		}
		else if(vec[mid] != mid+1){
			rh = mid -1;
		}
		else
			lh = mid +1;

	}

	return -1;

}

int main(void){
	vector<int> vec= {1,3,4,5,6,7,8,9,10,11,12,13,14,15};
	cout << "El número que falta es: " << FindMiss(vec) << endl;

	return 0;
}
