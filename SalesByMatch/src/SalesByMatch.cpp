// Level : Easy
// Exercise : SalesByMatch.cpp // Problema de encontrar los matcheos de pares de medias.
// Topic  : Algorithms
// Author : RaulSosa
// Status : Not Solved
#include<iostream>
#include<vector>
using namespace std;
int SockMerchant(int n, vector<int> arr);
int CountMatches(int number,vector<int> arr,int begin,int n);
bool IsProcessed(int number,vector<int> processedNumbers);

int main(void){
	
	vector<int> arr = {2,4,5,1,3,5,4,23,5,68,7,2,6,3};
	cout << "Hay " << SockMerchant(arr.size(),arr) << " pares de numeros";
//	cout << CountMatches(3,arr,5,arr.size());


	return 0;
}
int CountMatches(int number,vector<int> arr,int begin,int n){
    int counter = 0;
    for(int i=begin;i<n;i++){
        if(arr[i] == number){
            counter++;
        }
    }
    return counter;
}

// Precondition : array of int and int number
// Postcondition : inform about if number are in processedNumbers
bool IsProcessed(int number,vector<int> processedNumbers){
	unsigned int i = 0;
	while(i < processedNumbers.size() && processedNumbers[i] != number){
		i++;
	}
    return (i < processedNumbers.size()) ? true : false;
}
int SockMerchant(int n, vector<int> arr){

    int evenCounter = 0;
    vector<int> processedNumbers;

    for(int i =0;i<n;i++){
        if(!IsProcessed(arr[i],processedNumbers)){
            evenCounter += CountMatches(arr[i],arr,i, n)/2;
            processedNumbers.push_back(arr[i]);
        }

    }
    return evenCounter;
}
