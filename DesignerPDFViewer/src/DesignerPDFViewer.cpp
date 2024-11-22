// Level : Easy
// Topic  : Algorithms
// Author : RaulSosa


#include <iostream>
#include <vector>
using namespace std;


int designerPdfViewer(vector<int>,string);

int main(void){
	// Test Example
	vector<int> heights {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
	string word = "zaba";
	cout << designerPdfViewer(heights,word);

	return 0;
}

int designerPdfViewer(vector<int> heights,string word){

	int maxHeight = heights[int(word[0])-97];

	for(long unsigned int i = 0; i < word.length();i++){
		if(heights[int(word[i])-97] > maxHeight){
			maxHeight = heights[int(word[i])-97];
		}
	}
	return maxHeight*word.length();
}
