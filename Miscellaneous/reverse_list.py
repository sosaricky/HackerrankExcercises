def reverse_list(my_list):
    for i in range(1,(len(my_list)//2)+1):
        temp = my_list[len(my_list)-i]
        my_list[len(my_list)-i] = my_list[i-1]
        my_list[i-1] = temp


list_test = [10,20,30,50]
reverse_list(list_test)
print(list_test)