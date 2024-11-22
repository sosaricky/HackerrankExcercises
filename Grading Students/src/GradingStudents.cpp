// Level : Easy
// Author : RaulSosa
// Status : Solved
#include<iostream>
#include<vector>

using namespace std;

vector<int> gradingStudents(vector<int>);
void PrintArray(vector<int>);
int main(void){

	vector<int> grades {10,45,78,90,51};
	cout << "Grades before rounding : ";
    PrintArray(grades);
	cout << "\nGrades after rounding  : ";
    PrintArray(gradingStudents(grades));
	return 0;

}
vector<int> gradingStudents(vector<int> grades){

    for(long unsigned int grade = 0;grade < grades.size();grade ++){
        if(grades[grade] >= 38){
            int nextMultiple = (grades[grade]/5 +1)*5;
            if((-grades[grade] + nextMultiple)<3){
                grades[grade] = nextMultiple;
            }
        }
    }
    return grades;
}
void PrintArray(vector<int> arr){
	for(long unsigned int index = 0;index < arr.size();index++){
		cout << arr[index] << " ";
	}
}
