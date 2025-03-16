// Package declaration
import sys

// Importing the 'sys' package for input/output operations

def main():
    # Variable declaration and initialization
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()

    # Variable declaration and initialization for maximum count and current count
    max = 0
    cnt = 0

    # Iterating through each character in the string 's'
    for r in s:
        # Checking if the character is 'I'
        if r == 'I':
            # Incrementing the current count
            cnt += 1
        else:
            # Decrementing the current count
            cnt -= 1

        # Updating the maximum count if the current count is greater
        if cnt > max:
            max = cnt

    # Printing the maximum count
    print(max)

# End of the code

