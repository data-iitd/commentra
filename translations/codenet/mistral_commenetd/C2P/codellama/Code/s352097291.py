
#include <stdio.h>
#include <string.h>

# Declare variables
c = [] # An array to store the input string
ans = [] # An array to store the output string

def main():
    # Initialize variables
    c = input() # Read a string from the standard input and store it in the 'c' array

    # Process the string
    for i in range(len(c)): # Iterate through each character in the string 'c'
        if c[i] != 'B': # If the current character is not 'B'
            ans.append(c[i]) # Append the character to the output string 'ans'
        else: # If the current character is 'B'
            ans.pop() # Remove the last character from the output string 'ans'

    # Print the output
    print("".join(ans)) # Print the final output string

# The comments explain the purpose of each logical block and make the code more readable.

