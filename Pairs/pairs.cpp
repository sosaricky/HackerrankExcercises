// Level :  Medium
// Author : RickySosa
// Status : Solved

#include "pairs.h"

int Pairs::pairsNotEfficient(int k, std::vector<int> arr) {
    
    int count = 0;

    for(int i = 0 ;i<arr.size()-1;i++){
        for(int j = i+1;j < arr.size();j++){
            if(std::abs(arr[i] - arr[j]) == k){
                count++;
            }
        }
    }
    return count;
}
int Pairs::pairsEfficient(int k,std::vector<int> arr){
   
    int count = 0;
    std::sort(arr.begin(),arr.end());

    for(int i = 0 ;i<arr.size()-1;i++){
        for(int j = i+1;j < arr.size();j++){
            if(std::abs(arr[i] - arr[j]) > k){
                break;
            }
            else if(std::abs(arr[i] - arr[j])){
                count++;
            }
        }
    }
    return count; 
}