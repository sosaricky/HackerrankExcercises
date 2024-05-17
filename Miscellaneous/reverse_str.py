## This is an academic way to reverse a string.
def reverse_str(str_orginal):
    list_aux = []
    for i in range(len(str_orginal)-1,-1,-1):
        list_aux.append(str_orginal[i])
    return "".join(list_aux)

