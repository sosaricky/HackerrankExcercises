// Level : Medium
// Author : RaulSosa
// Status : Solved
// Obs : I'm not sure about the limits in the first while. I'm talking about maxRepeats.
//		 It's works , but I need a better explanation for that.
#include<iostream>
#include<vector>
using namespace std;

// Pre: Array de int cuyos elementos son consecutivos.
// Post: Devuelve true si está ordenado , false caso contrario.
bool IsSorted(vector<int> arr);

string LarysArrays(vector<int> arr);
vector<int> GetBestGroup(vector<int> arr);
int Min(vector<int> arr);
void ShowVector(vector<int> arr);
int main(void){
	
	vector<int> v1= {1,4,12,43,10,1,3,4};
	vector<int> v2 = { 1,3,4,2};
	cout << "size of input : "<<v2.size() << endl;
	cout << LarysArrays(v2);
	//ShowVector(v2);
	//cout << IsSorted(v2);
	cout << endl;

 	return 0;
}

bool IsSorted(vector<int> arr){

	bool sorted = true;
	unsigned int i = 0;

	while(i < arr.size()-1 && sorted != false){
		if(arr[i]>arr[i+1]){
			sorted = false;
		}
		i++;
	}
	return sorted;
}

string LarysArrays(vector<int> arr){

	unsigned int i = 0,repeats = 0;
	unsigned int maxRepeats;
	// maxRepeats of iterate over the array while we're selecting groups of three.
	maxRepeats = (arr.size()%2 == 0) ? arr.size()/2 : (arr.size()-1)/2;

	while(IsSorted(arr) == false && repeats < maxRepeats){
		while(i<arr.size()-2){
			// Select group of three
				vector<int> currentGroup;
				for(unsigned int j = i;j<i+3;j++){
					currentGroup.push_back(arr[j]);
				}
				// Get a better group of 3 sorted.
				vector <int> bestGroup = GetBestGroup(currentGroup);

				arr[i] = bestGroup[0];
				arr[i+1] = bestGroup[1];
				arr[i+2] = bestGroup[2];
				i++;

		}
	repeats++;
	i = 0;

	}
	ShowVector(arr);
	if(IsSorted(arr)){
		return "YES";
	}else{
		return "NO";
	}

}

vector<int> GetBestGroup(vector<int> arr){
	// Encuentro quien es el menor del grupo.
	unsigned int i = 0;
	while(i<arr.size() && arr[i] != Min(arr)){
		i++;
	}
	// El menor está en la posición i.
	char option = i + 'A';

	switch(option){

	case 'B':{
		vector<int> rotationBCA;
		rotationBCA.push_back(arr[i]);
		rotationBCA.push_back(arr[2]);
		rotationBCA.push_back(arr[0]);
		return rotationBCA;
		break;
	}
	case 'C':{
		vector<int> rotationCAB;
		rotationCAB.push_back(arr[i]);
		rotationCAB.push_back(arr[0]);
		rotationCAB.push_back(arr[1]);
		return rotationCAB;
		break;
	}
	default:{
		return arr;
		break;
	}

	}
}

int Min(vector<int> arr){
	int min = arr[0];
	for(unsigned int i = 0;i<arr.size();i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}
void ShowVector(vector<int> arr){
	for(unsigned int i = 0;i<arr.size();i++){
		cout << arr[i] << " ";
	}
}
