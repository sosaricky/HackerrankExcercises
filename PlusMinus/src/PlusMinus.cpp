// Level : Easy
// Exercise : PlusMinus.cpp
// Topic  : Algorithms
// Author : RaulSosa

#include <iostream>
#include <vector>
using namespace std;

void plusMinus(vector<int>);

int main(void){
	int n = 6;
	vector<int> lista{6,10,-11,100,0,-1};
	plusMinus(lista);


	return 0;
}


void plusMinus(vector<int> arr) {

	int quantityOfPositives = 0,quantityOfNegatives = 0 , quantityOfZeros =0;

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] > 0){
            quantityOfPositives++;
        }
        else if(arr[i] < 0){
            quantityOfNegatives++;
        }
        else{
            quantityOfZeros++;
        }
    }
    cout << quantityOfPositives/double(arr.size()) <<endl ;
    cout << quantityOfNegatives/double(arr.size()) << endl;
    cout << quantityOfZeros/double(arr.size()) << endl;


}
