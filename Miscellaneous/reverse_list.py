# This is an academic way to reduce a string
def reverse_list(my_list):
    for i in range(1,(len(my_list)//2)+1):
        temp = my_list[len(my_list)-i]
        my_list[len(my_list)-i] = my_list[i-1]
        my_list[i-1] = temp

