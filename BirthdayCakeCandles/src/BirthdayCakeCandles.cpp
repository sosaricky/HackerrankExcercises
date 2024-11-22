// Level : Easy
// Author : RaulSosa
// Status : Solved

#include <iostream>
using namespace std;

int birthdayCakeCandles(int *,int);

int main(void){

	 int lista[] = {1,1,1,1,1,1,1};
	 int n = 7;

	 cout << "Cantidad de apariciones del mayor: " << birthdayCakeCandles(lista,n)<< endl;


	return 0;
}

int birthdayCakeCandles(int *candles,int n){

	int max = *(candles);
	int contadorMaximos = 1;
	for(int i = 1 ; i<n ; i++){
		if(candles[i] > max){
			max = candles[i];
			contadorMaximos = 1;
		}
		else if(candles[i] == max){
			contadorMaximos++;
		}
	}
	return contadorMaximos;
}
