// Level : Easy
// Exercise : Staircase.cpp
// Topic  : Algorithms
// Author : RaulSosa


#include <iostream>

using namespace std;


void staircase(int);

int main(void){

	staircase(4);

	return 0;
}


void staircase(int n) {

	int i = 0;

	// Este bucle while controla que se escriban 4 lineas de algo.
	while(i<n){
		// Este bucle controla la cantidad de espacios por línea.Hay n-(i+1) espacios por línea
		for(int j = 0;j<n-(i+1);j++){
			cout << "x";
		}
		// Este bucle controla la cantidad de # por línea. Hay i+1 # por línea.
		for(int k = 0 ; k<i+1;k++){
			cout << "#";
		}
		cout << endl;
		i++;
	}

}
