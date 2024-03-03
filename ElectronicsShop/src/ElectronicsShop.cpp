// Level : Easy
// Exercise : ElectronicsShop.cpp
// Topic  : Algorithms
// Author : RaulSosa
// Status : Complete
#include<iostream>
#include<vector>
using namespace std;

void Swap(int *a, int *b);
void OrdenarPorSeleccionAdaptativo(vector<int> &v);
int GetMoneySpent(vector<int> keyboards, vector<int> drives, int b);

int main(void){

	vector<int> keyboards = {3,1};
	vector<int> drives = {5,2,8};
	GetMoneySpent(keyboards,drives,10);
	
	return 0;
}
void Swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void OrdenarPorSeleccionAdaptativo(vector<int> &v){

    int i = 0,swaps = 0;
    int n  = v.size();

    do{
        for(int j=0;j<n-1;j++){
            if(v[j]<v[j+1]){
                Swap(&v[j],&v[j+1]);
                swaps++;
            }
        }
        i++;
    }while(swaps != 0 && i<n-1);
}

int GetMoneySpent(vector<int> keyboards, vector<int> drives, int b) {

    int maxPurchase = -1;
    for(int j = 0;j<drives.size();j++){
        for(int i = 0;i< keyboards.size() ;i++){
            int currentPurchase = keyboards[i] + drives[j];
            if((currentPurchase > maxPurchase) && (currentPurchase <= b)){
                maxPurchase = currentPurchase;
            }
        }
    }
    return maxPurchase;
}
