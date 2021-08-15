def splitter_by_parity(msj):
    
    msj_odd = ''
    msj_even = ''
    
    for i in range(0,len(msj)):
        if i%2 == 0 :
            
            msj_even += msj[i]
        else:
            msj_odd += msj[i]
            
    print(msj_even+' '+msj_odd)   


def main():

    msjs = []
    n = int(input('Please, enter amount of words: ' ))
    
    for i in range(0,n):
        msjs.append(input(f'Enter word number {i+1}: '))

    for i in range(0,n):
        splitter_by_parity(msjs[i])
    

        
        
main()    