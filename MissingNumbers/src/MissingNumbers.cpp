// Level : Easy
// Exercise : MissingNumbers.cpp
// Topic  : Sorting
// Author : RaulSosa
// Status : (Solved)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr);

int binarySearch(vector <int> arr, int value);
int countMatches(vector <int> arr,int value);
void bubbleSort(vector <int> &arr);
void ShowVector(vector<int> arr);

int main(){
    vector<int> arr = {203 ,204 ,205, 206, 207, 208, 203, 204, 205, 206};
    vector<int> brr = { 203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204};
    ShowVector(missingNumbers(arr,brr));

    return 0;
}

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    vector<int> missing;
    vector<int> processed;
    int matchesInFirst,matchesInSecnd;

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    for(unsigned int i = 0;i<brr.size();i++){
        // If not processed yet,count matches in first array (arr)
        if(binarySearch(processed,brr[i]) == -1){
            matchesInFirst = countMatches(arr,brr[i]);
            matchesInSecnd = countMatches(brr,brr[i]);
            // Add current element to processed
            processed.push_back(brr[i]);
            if(matchesInFirst != matchesInSecnd && binarySearch(missing,brr[i]) == -1){
                missing.push_back(brr[i]);
            }
        }
    }

    return missing;

}


int binarySearch(vector <int> arr, int value){
    int firstIndex = 0 , lastIndex = arr.size()-1;
    int  centralIndex = (firstIndex+lastIndex)/2;
    while(firstIndex<=lastIndex && arr[centralIndex] != value){
        // Tengo que buscar a la derecha.
        if(value > arr[centralIndex]){
            // inicio = central+1, final no cambia.
            firstIndex = centralIndex+1 ;
        // Tengo que buscar a la izquierda.
        }else{
            // final = central-1
            lastIndex = centralIndex-1;
        }
        centralIndex = (firstIndex+lastIndex)/2;
    }
    return firstIndex > lastIndex ? -1 : centralIndex;
}

int countMatches(vector <int> arr,int value){
	// Counts the coincidences of @value in @arr and returns that
	int coincidences = 0;
	for(unsigned int i = 0;i < arr.size();i++){
		arr[i] == value ? coincidences++ : coincidences;
	}
	return coincidences;
}
void ShowVector(vector<int> arr){
    for(unsigned int i = 0;i<arr.size();i++){
        cout << arr[i] << " " ;
    }
}
