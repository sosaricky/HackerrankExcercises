// Level : Easy
// Exercise : DivisibleSumPairs.cpp
// Topic  : Algorithms
// Author : ricky
#include<iostream>
#include<vector>
using namespace std;

int DivisibleSumPairs(int,int,vector<int>);

int main(void){
	
	int k = 2;
	vector<int> arr = {10,5,3,1};
	cout << " Para el vector " << "hay " << DivisibleSumPairs(arr.size(),k,arr) << " pares divsibles por " << k << endl;

	return 0;
}
int DivisibleSumPairs(int n, int k, vector<int> arr) {

    int contador = 0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i] + arr[j])%k == 0){
                contador++;
            }
        }
    }
    return contador;
}
