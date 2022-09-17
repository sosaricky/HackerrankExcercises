// Level : Easy
// Exercise : AppleAndOrange.cpp
// Topic  : 
// Author : ricky

#include<iostream>
#include<vector>
using namespace std;

int getFruitsFallenInHouse(int s,int t,int locationTree,vector<int> fruits){
    int qtyOfFruitsFallenInHouse = 0;
    for(unsigned int i = 0; i<fruits.size();i++){
        if((fruits[i] + locationTree) <= t  && (fruits[i] + locationTree)>=s){
            qtyOfFruitsFallenInHouse++;
        }
    }
    return qtyOfFruitsFallenInHouse;
}



void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

    int qtyOfApplesFallenInHouse =getFruitsFallenInHouse(s,t,a,apples);
    int qtyOfOrangesFallenInHouse = getFruitsFallenInHouse(s,t,b,oranges);
    cout << qtyOfApplesFallenInHouse << endl;
    cout << qtyOfOrangesFallenInHouse;
}


int main(void){
	
	return 0;
}
