// Importing required packages
import sys

// Reading the first line from standard input and storing it in the string 's'
s = sys.stdin.readline().strip()

// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
d = ord('a') - ord('A')

// Iterating through each character 'r' in the string 's'
for r in s:
    # Declaring and initializing a variable 'rr' with the value of 'r'
    rr = r

    # Checking if the current character 'r' is an uppercase letter
    if 'A' <= r <= 'Z':
        # If yes, adding the value of 'd' to 'r' and storing it in 'rr'
        rr = chr(ord(r) + d)
    elif 'a' <= r <= 'z':
        # If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
        rr = chr(ord(r) - d)

    # Printing the transformed character 'rr' to the standard output
    print(rr, end='')

# Printing a newline character after the transformation is complete
print()

# End of the code


Translate the above Python code to C++ and end with comment "