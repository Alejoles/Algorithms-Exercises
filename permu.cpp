#include <iostream>
#include <string>
#include <set>

using namespace std;


set<string> permu(const string & str){
	set<string> final;
	if(str.length() == 0){
	final.insert("");
	return final;
	}else{
	char first = str[str.size()-1];
	string tmp = str.substr(0,str.size()-1);
		for(set<string>::iterator it = s_tmp.begin(); it != s_tmp.end(); it++){
	cout << (*it)<< endl;
	set<string> s_tmp = permu(tmp);

	} 
//	final = putCharInGrooves(s_tmp, first);
	return final;
	
	}


}


int main(void){
	string str = "hola";
	permu(str);


	
	return 0;
}
