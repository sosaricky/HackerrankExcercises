## Algorithm to determine if a word is palindrome.
## Only ascii [a-z]

from HackerrankExcercises.Miscellaneous.reverse_str import reverse_str

## Slow using an auxiliar function to reverse a string
def is_palindrome(string_objective):
    
    ## Delete spaces, convert to lowercase
    string_objective_cleaned = ("".join(string_objective.split())).lower()
    ## length odd or even?
    if(len(string_objective_cleaned)%2 == 0):
        second_half_str = string_objective_cleaned[len(string_objective_cleaned)//2:]
    else:
        second_half_str = string_objective_cleaned[1+len(string_objective_cleaned)//2:]
    first_half_str = string_objective_cleaned[0:len(string_objective_cleaned)//2]
    
    return(first_half_str == reverse_str(second_half_str))

## Fast version, classic
def is_palindrome(string_test):
    # Comparo cada caracter , si alguno es distinto no es palindromo
    len_of_half = len(string_test)//2
    counter = 0
    for i in range(0,len_of_half):
        if(string_test[i] != string_test[-1-i]):
            break
        else:
            counter = counter +1
            continue
    return counter == len_of_half