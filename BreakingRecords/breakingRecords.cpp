#include "breakingRecords.h"
std::vector<int> BreakingRecords::breakingRecords(std::vector<int> scores) {
    
    int min = scores[0];
    int max = scores[0];
    int breakMinCounter = 0;
    int breakMaxCounter = 0;
    std::vector<int> breaksCounter;
    
    for(int i = 0; i<scores.size();i++){
        if(scores[i] < min){
            breakMinCounter++;
            min = scores[i];
        }
        else if(scores[i] > max){
            breakMaxCounter++;
            max = scores[i];
        }
    }
    breaksCounter.push_back(breakMaxCounter);
    breaksCounter.push_back(breakMinCounter);
    
    return breaksCounter;
}
