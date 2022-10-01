// Level : Easy
// Exercise : CircularArrayRotation.cpp
// Topic  : 
// Author : RaulSosa

#include<iostream>
#include<vector>
using namespace std;

vector<int> CircularArrayRotationSlow(vector<int> a, int k, vector<int> queries);
vector<int> CircularArrayRotationFast(vector<int> a, int k, vector<int> queries);

void MostrarVector(vector<int> arr);

int main(void){
	
	vector<int> myArray = {12,4,5,6,10,23};
	//MostrarVector(myArray);
	int k = 5;
	vector<int> queries = {2,3,1};
	//cout << MinorModule(8,4);
	MostrarVector(CircularArrayRotationFast(myArray,k,queries));

	return 0;
}


// Esta solución no pasa los test con datos muy grandes.Tarda mucho.
vector<int> CircularArrayRotationSlow(vector<int> a, int k, vector<int> queries) {

    vector<int> valuesPostRotation;
    int rotations = 0;
    int n = a.size();
    int i,temp;

    while(rotations < k ){
        temp = a[n-1];
        i = 0;
        for(i = n-1;i > 0;i--){
            a[i] = a[i-1];
        }
        a[i] = temp;
        rotations++;
    }
    for(unsigned int j = 0;j < queries.size();j++){
       valuesPostRotation.push_back(a[queries[j]]);
    }
    return valuesPostRotation;
}
// Podría mejorar con rotations < k%n para no repetir al pepe
vector<int> CircularArrayRotationFast(vector<int> a, int k, vector<int> queries) {
    vector<int> valuesPostRotation;
    int rotations = 0;
    int n = a.size();
    int temp;

    while(rotations < k%n ){
        // Desarollo de una rotacion
        temp = a[n-1]; // Guardo el ultimo elemento.
        a.pop_back();  // Elimino el ultimo elemento.
        a.insert(a.begin(),temp); // Inserto el ultimo al ppio.
        rotations++;
    }
    for(unsigned int j = 0;j < queries.size();j++){
       valuesPostRotation.push_back(a[queries[j]]);
    }
    return valuesPostRotation;
}
void MostrarVector(vector<int> arr){
	for(unsigned int i = 0;i < arr.size();i++){
		cout << arr[i] << " " ;
	}
}
