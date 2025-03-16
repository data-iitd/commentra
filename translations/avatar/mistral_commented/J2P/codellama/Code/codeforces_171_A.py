# Importing necessary libraries
import sys

# Defining a function for reading input
def read_input():
    # Reading input for number of test cases
    n = int(sys.stdin.readline())

    # Reading input for number of operations
    m = int(sys.stdin.readline())

    # Calling reverse function for m and adding it to n
    t = reverse(m)
    print(t + n)

# Function for reversing a number
def reverse(n):
    # Base case for numbers less than 10
    if n < 10:
        return n * 10

    # Initializing variables
    t = n
    r = 0

    # Reversing the number
    while t > 0:
        # Adding the digit to the reversed number
        r = (r * 10) + t % 10

        # Moving to the next digit
        t = t // 10

    # Returning the reversed number
    return r

# Calling the function for reading input
read_input()

# END-OF-CODE
