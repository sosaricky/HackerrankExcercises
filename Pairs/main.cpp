#include "pairs.h"
#include <iostream>

int main(){

    std::vector<int> arr = {2,4,5,9};
    std::cout << Pairs::pairsNotEfficient(1,arr) << std::endl;
    std::cout << Pairs::pairsEfficient(1,arr) << std::endl;
    return 0;
}