# Declare a string to hold user input
str_input = input()

# Convert the string to a list of characters to allow modification
str_list = list(str_input)

# Replace the character at index 5 with a space
str_list[5] = ' '

# Replace the character at index 13 with a space
str_list[13] = ' '

# Join the list back into a string and print the modified string to the console
print(''.join(str_list))

# Return 0 to indicate successful execution of the program
# (Not necessary in Python, but included for clarity)
# return 0

# <END-OF-CODE>
