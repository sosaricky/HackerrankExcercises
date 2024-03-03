"""
// Level : Easy
// Exercise : Repeated string
// Topic  : Algorithms-Implementation
// Author : RaulSosa
// Status : Solved
"""
def get_matches_of_a(s):
    
    count = 0
    for c in s:
        if(c == "a"):
            count += 1
    
    return count    

def repeated_string(s,n):
    
    # Count matches of "a" in s.
    matches_per_string = get_matches_of_a(s)
   
    # Get number of times that "s" string fit a sequence of "n" characters.
    number_of_repeats = n//len(s)

    remaining_characters = n % len(s)
    
    if(remaining_characters == 0):
        total_repeats_of_a = matches_per_string * number_of_repeats
    else:
        total_repeats_of_a = get_matches_of_a(s[:remaining_characters]) + matches_per_string * number_of_repeats

    return total_repeats_of_a    


print(repeated_string("aba",10))