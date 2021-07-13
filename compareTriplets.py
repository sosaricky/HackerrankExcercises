#!/bin/python

import math
import os
import random
import re
import sys

#
# Complete the 'compareTriplets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def compareTriplets(a, b):
    final_score = [0,0]
    for i in range(0,len(a)):
        if(a[i] > b[i]):
            final_score[0] += 1
        elif(a[i] < b[i]):
            final_score[1] += 1
            
            
    return final_score        
                     
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = map(int, raw_input().rstrip().split())

    b = map(int, raw_input().rstrip().split())

    result = compareTriplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

