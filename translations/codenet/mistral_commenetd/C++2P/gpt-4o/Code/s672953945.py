# Import necessary libraries
from typing import List

# The main function begins here
def main():
    # Read the number of strings 'N' and their lengths 'L' from the standard input
    N, L = map(int, input().split())

    # Initialize an empty list 'v' to store the strings
    v = []

    # Read 'N' strings from the standard input and append them to the list 'v'
    for _ in range(N):
        s = input().strip()  # Read a string and remove any surrounding whitespace
        v.append(s)

    # Sort the strings in the list 'v' in ascending order
    v.sort()

    # Iterate through the sorted strings in the list 'v' and print each string
    for string in v:
        print(string, end='')  # Print the current string without a newline

    # Print a newline character at the end of the output
    print()

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
