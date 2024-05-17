/*
Reverse a vector in an academic way
*/

#include <iostream>
#include<vector>
using namespace std;


void reverseVector(vector<int> &v){
    int aux;
    for(int i=0;i<=v.size()/2;i++){
        aux = v[v.size()-i];
        v[v.size()-i] = v[i-1];
        v[i-1] = aux;
    }
}
void show(vector<int> v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {10,20,30};
    reverseVector(v);
    show(v);
    return 0;
}