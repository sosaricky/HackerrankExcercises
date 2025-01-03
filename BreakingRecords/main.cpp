#include <iostream>
#include "breakingRecords.h"

int main(){
    std::vector<int> scores = { 10, 54, 6, 6 ,1, 100};
    std::vector<int> results;
    results = BreakingRecords::breakingRecords(scores);
    
    std::cout << results[0] << " ";
    std::cout << results[1] << "\n";

    return 0;
}