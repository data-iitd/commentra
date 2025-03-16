str_input = input()
str_list = list(str_input)  # Convert the string to a list to modify it
str_list[5] = ' '
str_list[13] = ' '
result = ''.join(str_list)  # Join the list back into a string
print(result)
# <END-OF-CODE>
