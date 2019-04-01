#include <iostream>

using namespace std;

int main(void){
	int ival = 1024;
	int &rval = ival;
	int *pval2 = &rval;
	int *pval4 = &ival;
	int *p1, p2;
	cout << pval4 << endl;
	return 0;
}
