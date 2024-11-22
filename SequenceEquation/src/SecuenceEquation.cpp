// Level : Easy
// Author : RaulSosa
// Status : Solved
// Comment : Este ejercicio es una boludes,tarde bastante en entender que quería el enunciado.
#include<iostream>
#include<vector>
using namespace std;
int LinearSearch(vector<int> arr,int value);
vector<int> PermutationEquation(vector<int> p);



int main(void){
	
	return 0;
}
int LinearSearch(vector<int> arr,int value){
    unsigned int index = 0;
    while(index < arr.size() && arr[index] != value){
        index++;
    }
    if(index == arr.size()){
        return -1;
    }else{
        return index;
    }
}
vector<int> PermutationEquation(vector<int> p){
    vector<int> result;
    int n = p.size();
    for(int i=1;i<n+1;i++){
        // Obtengo el indice donde esta el elemento x
        int indexFounded = LinearSearch(p,i);
        // Agrego al vector de resultados el indice donde encontre el indexFounded en arr.
        result.push_back(LinearSearch(p,indexFounded+1)+1);
    }
    return result;
}
