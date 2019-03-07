#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;


void Sistema(){
	int random;
	int x;
	int agen;
	int lib;
	int cuad;
	int paq;
	int cajas;
	stack<int> agendas;
	stack<int> libros;
	stack<int> cuadernos;
	stack<int> paquetes;
	stack<stack<int>> pilapaquetes;
	clock_t timer = clock();
	while(((double)(clock()-timer)/CLOCKS_PER_SEC) < 5){// ejecuto todo por un tiempo determinado
		random = rand() % 300;
		if(random < 100) {
			for(unsigned i = 0; i < 2e4 ; i++);//sleep
			agendas.push(random);
			agen++;
		}
		else if(random > 100 && random < 200){
			for(unsigned i = 0; i < 2e4 ; i++);
			libros.push(random);
			lib++;
		}
		else if(random > 200 && random < 300){
			for(unsigned i = 0; i < 2e4 ; i++);
			cuadernos.push(random);
			cuad++;
		}
		if(agendas.size() >= 5 && cuadernos.size() >= 5 && libros.size() >= 5){
			for(unsigned i = 0; i<3; i++){
				x = cuadernos.top();
				paquetes.push(x);
				x = libros.top();
				paquetes.push(x);
				x = agendas.top();
				paquetes.push(x);
				cuadernos.pop();
				libros.pop();
				agendas.pop();
			}
			pilapaquetes.push(paquetes);
			paq++;
		}
		if(pilapaquetes.size() == 12){
			while(!(pilapaquetes.empty())){
				pilapaquetes.pop();
			}
			cajas++;
		}
	
	}
	
	cout << "El total de libros fue: " << lib << '\n' << "El total de agendas fue: " << agen << '\n' << "El total de cuadernos fue: " << 		cuad << '\n' << "El total de paquetes despachados fue: " << paq << '\n' << "El total de cajas despachadas fue: " << cajas << endl;

}

int main(void){

	Sistema();
	return 0;
}

