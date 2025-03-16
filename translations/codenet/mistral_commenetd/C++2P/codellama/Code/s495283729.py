#include <stdio.h>
#include <string.h>

# Declare necessary header files for standard input/output and string manipulation

def main():
    s = input() # Read a string from the standard input and store it in the array 's'

    i, flag = 0, 0 # Initialize variables: 'i' as a loop counter and 'flag' as a boolean flag

    for i in range(len(s)): # Iterate through each character in the string 's'
        if i % 2 == 0: # Check if the current index 'i' is even
            if s[i] == 'R' or s[i] == 'U' or s[i] == 'D': # If the character is 'R', 'U', or 'D', do nothing and move to the next character
                pass
            else: # If the character is not 'R', 'U', or 'D', set the flag to 1
                flag = 1
                break
        else: # If the current index 'i' is odd
            if s[i] == 'L' or s[i] == 'U' or s[i] == 'D': # If the character is 'L', 'U', or 'D', do nothing and move to the next character
                pass
            else: # If the character is not 'L', 'U', or 'D', set the flag to 1
                flag = 1
                break

    if flag == 0: # If no invalid character was found during the iteration
        print("Yes") # Output "Yes" to the standard output
    else: # If an invalid character was found during the iteration
        print("No") # Output "No" to the standard output


