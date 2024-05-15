## Algorithm to determine if a word is palindrome.
## Constraints : only English words

def invertir_str(str_orginal):
    lista_aux = []
    for i in range(len(str_orginal)-1,-1,-1):
        lista_aux.append(str_orginal[i])
    return "".join(lista_aux)

def es_palindromo(str_objetivo):
    ## Tratamiento previo , elimino espacios y unifico a minusculas.
    str_objetivo_limpio = ("".join(str_objetivo.split())).lower()
    print(str_objetivo_limpio)
    ## Determino si tiene cantidad par o impar de letras
    if(len(str_objetivo_limpio)%2 == 0):
        segunda_mitad_str = str_objetivo_limpio[len(str_objetivo_limpio)//2:]
    else:
        ## Cantidad impar , cambia la division de las mitades.
        segunda_mitad_str = str_objetivo_limpio[1+len(str_objetivo_limpio)//2:]
    ## La primera mitad siempre va en el mismo rango
    primera_mitad_str = str_objetivo_limpio[0:len(str_objetivo_limpio)//2]
    return(primera_mitad_str == invertir_str(segunda_mitad_str))