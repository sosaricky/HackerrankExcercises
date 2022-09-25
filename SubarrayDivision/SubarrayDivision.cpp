// Level : Easy
// Exercise : SubarrayDivision.cpp
// Topic  : Algorithms
// Author : RaulSosa
#include<iostream>
#include<vector>
using namespace std;

int FormasEnQueDividirArray(vector<int> arr,int d,int m);

int main(void){
	
	vector<int> arr = {5,2,3,2,5,10,3};
	cout << FormasEnQueDividirArray(arr,10,3);


	return 0;
}

int FormasEnQueDividirArray(vector<int> arr,int d,int m){
	// Obtengo la cantidad de subarrays posibles de longitud m
	int subArraysPosibles = arr.size()-m+1;
	int contador = 0,suma = 0;
	// De todos los subarrays me interesan los que la suma de sus elementos es "d";
	// Tengo que calcular la suma tantas veces como subarrays posibles.
	// Analizo al terminar cada subarray si su suma dio 40.Si lo hizo lo cuento.
	for(int i = 0;i<subArraysPosibles;i++){
		for(int j = 0;j<m;j++){
			suma += arr[i+j];
		}
		if(suma == d){
			contador++;
		}
		suma = 0;
	}
	return contador;

}
