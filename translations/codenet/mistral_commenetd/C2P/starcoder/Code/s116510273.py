
# Include necessary libraries for standard input/output and string manipulation

# Declare a character array'mes' of size 101 to store the input string
mes = [None] * 101

# Read a string from the standard input and store it in'mes' array
mes = input()

# Logic starts here

# Print the first character, length - 2 and last character of the input string
print(mes[0], len(mes)-2, mes[len(mes)-1])

# 