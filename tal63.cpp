#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(stack<char> stk){
	char x = stk.top();
	int parentesis = 0;
	int corchetes = 0;
	int llaves = 0;
	if(x == '{' ||x == '(' ||x == '[') return false;
	if(x == '}') llaves++;
	else if(x == ']') corchetes++;
	else if(x == ')') parentesis++;
	stk.pop();
	while(!(stk.empty())){
		x = stk.top();
		if(x == '{') llaves++;
		else if(x == '[') corchetes++;
		else if(x == '(') parentesis++;
		else if(x == ')') parentesis++;
		else if(x == ']') corchetes++;
		else if(x == '}') llaves++;
		stk.pop();
	}
	if((parentesis != 0 && llaves != 0 && corchetes != 0)&& parentesis %2 == 0 && llaves %2 == 0 && corchetes %2 == 0) return true;
	else if(parentesis <= 0 && llaves %2 == 0 && corchetes %2 == 0) return true;
	else if(parentesis <= 0 && corchetes %2 == 0 && llaves %2 == 0) return true;
	else if(llaves <= 0 && parentesis %2 == 0 && corchetes %2 == 0) return true;
	else if(llaves <= 0 && corchetes %2 == 0 && parentesis %2 == 0) return true;
	else if(corchetes <= 0 && llaves %2 == 0 && parentesis %2 == 0) return true;
	else if(corchetes <= 0 && parentesis %2 == 0 && llaves %2 == 0) return true;
	else return false;
}

int main(void){
	stack<char> stk;
	string line;
	cout << "ingrese la cadena de caracteres: ";
	cin >> line;
	for(unsigned i = 0; i<line.size();i++) stk.push(line[i]);
	if (isBalanced(stk)) cout << "El arreglo está ordendado." << endl;
	else cout << "el arreglo no está ordenado." << endl;
	
	return 0;
}
