#include <stdio.h> // Standard Input/Output Library
#include <string.h> // String Library

str = input("Enter a string: ") # Read a string from the standard input and store it in the 'str' variable

len = len(str) # Calculate the length of the string stored in the 'str' variable and assign it to the 'len' variable

print("Reversed string: ", end="") # Print a message to indicate that the reversed string will be printed

for i in range(len-1, -1, -1): # Use a for loop to print each character of the string in reverse order
    print(str[i], end="") # Print the character at the index 'i' of the 'str' variable

print() # Print a newline character

