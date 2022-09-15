// Level : Easy
// Exercise : DiagonalDifference.cpp
// Topic  : Algorithms
// Author : RaulSosa

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int DiagonalDifference(vector<vector<int>>);
void PrintMatrix(vector<vector<int>> arr);

int main(void){

	vector<vector <int>> myMatrix{

	   {-10,  3,   0,  5,  -4},

		{2,  -1,   0,  2,  -8},

		{9,  -2,  -5,  6,   0},

		{9,  -7,   4,  8,  -2},

		{3,   7,   8, -5,   0}};

	PrintMatrix(myMatrix);
	cout << endl << "Diagonal difference = " <<  DiagonalDifference(myMatrix) << endl;
	return 0;
}

int DiagonalDifference(vector<vector<int>> arr){
	// Quantity of rows, same that columns because is a square matrix.
	int n = arr.size();
	int sumDiagonalRight = 0,sumDiagonalLeft = 0;

	for(int row = 0;row < n;row++){
		for(int column = 0;column < n;column++){
			if(row == column){
				sumDiagonalRight += arr[row][column];
			}
			if(row + column == n-1){
				sumDiagonalLeft += arr[row][column];
			}
		}
	}
	return abs(sumDiagonalRight - sumDiagonalLeft);

}

void PrintMatrix(vector<vector<int>> arr){
	for(long unsigned int row = 0;row < arr.size();row++){
		for(long unsigned int column = 0;column < arr[0].size();column++){
			cout << "  " << arr[row][column] << "  ";
		}
		cout << endl;
	}
}
