// Level : Easy
// Exercise : MigratoryBirds.cpp
// Topic  : 
// Author : RaulSosa

// Two tasks :
// 1 - Count every occurrence for each type of id
// 2 - Get maximum from him . Don't forget the case when exists more than one maximum.

#include<iostream>
#include<vector>
using namespace std;

int getMaximumRepeat(vector<int>);
int migratoryBirds(vector<int>);
void TestSuiteMigratoryBirds(void);
void TestA(void);
void TestB(void);
void TestC(void);

int main(void){
	
	TestSuiteMigratoryBirds();

	return 0;
}
int getMaximumRepeat(vector<int> repeats){

    int max = repeats[0];
    int idMax = 0;

    for(unsigned int id = 0;id<repeats.size();id++){
        if(repeats[id] > max){
            max = repeats[id];
            idMax = id+1;
        }
    }
    return idMax;
}
int migratoryBirds(vector<int> arr){

    vector<int> repeatsById = {0,0,0,0,0};

    for(unsigned int id = 0;id<repeatsById.size();id++){
        for(unsigned int j = 0 ; j<arr.size();j++){
            if(arr[j] == id+1){
                repeatsById[id]++;
            }
        }
    }
    return getMaximumRepeat(repeatsById);
}
void TestA(void){

	vector<int> arr = {1,2,2,2,3,4,5,1,5,2};
	int idExpected = 2;
	bool result = (idExpected == migratoryBirds(arr));
	cout << (result == true ? "TestA OK" : "TestA FAIL") << endl;
}
void TestB(void){

	vector<int> arr = {1,2,2,3,5,5,1,5,2};
	int idExpected = 2;
	bool result = (idExpected == migratoryBirds(arr));
	cout << (result == true ? "TestB OK" : "TestB FAIL") << endl;
}
void TestSuiteMigratoryBirds(void){
	TestA();
	TestB();
}
