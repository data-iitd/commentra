#######
# Import necessary modules and set up some constants.
# sys is a standard Python library module for interacting with the interpreter.
# sys.stdin.readline() is a function that reads a line from standard input.
# MOD is a constant representing 10^9 + 7 for modular arithmetic.
# INF is a constant representing infinity for numerical computations.
# sys.setrecursionlimit() sets the maximum depth of the recursion limit.

import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


# Define the main function to handle the input and perform the computation.
def main():
    # Read the number of test cases from the standard input.
    N = int(readline())

    # Define a set containing some powers of 2.
    s = {1, 2, 4, 8, 16, 32, 64}

    # Initialize a variable to store the answer.
    ans = 0

    # Iterate through the range from 1 to N and check if each number is in the set.
    # If a number is found in the set, update the answer with that number.
    for i in range(1, N + 1):
        if i in s:
            ans = i

    # Print the answer to the standard output.
    print(ans)


# Call the main function if the script is run as the main program.
if __name__ == '__main__':
    main()
