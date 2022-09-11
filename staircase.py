def staircase(n):
    # A loop that takes control over the number of lines written.
    for i in range(n):
        # This Control number of spaces . spaces_quantity per line =  n-(i+1)
        for j in range(n-(i+1)):
            print('x',end = '')
        # Control number of # . #_quantity per line = i+1    
        for k in range(i+1):
            print('#',end = '')
        print(end='\n')    

staircase(4)        