
# Python code to modify a string

# Get a string input from the user using input() function and store it in a variable str
str = input("Enter a string: ")

# Assign a space character to the 6th index and 14th index of the string str
str = str[:5] +'' + str[6:13] +'' + str[14:]

# Print the modified string
print(str)

# End of Python code
