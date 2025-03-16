# Import the string library for string manipulation functions
import string

# Read a string input from the user and store it in'mes'
mes = input()

# Calculate the length of the string excluding the first and last character
length = len(mes) - 2

# Print the first character, the calculated length, and the last character of the string
print(mes[0], length, mes[len(mes) - 1])

