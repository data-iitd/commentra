#include <stdio.h>  // Include headers for input/output operations
#include <string.h> // Include headers for string manipulation

def main():
    str = input() # Read a string from the user
    len = len(str) # Calculate the length of the input string

    # Reverse the string and print it
    for i in range(len - 1, -1, -1):
        print(str[i], end = '') # Print each character in reverse order
    print() # Print a newline character at the end

if __name__ == '__main__':
    main()

