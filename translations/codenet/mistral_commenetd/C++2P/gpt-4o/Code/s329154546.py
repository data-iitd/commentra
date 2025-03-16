# Import necessary libraries
import sys

# Function to read input
def main():
    # Read the number of strings and their length
    N, L = map(int, sys.stdin.readline().split())
    S = []  # Initialize an empty list to store strings

    # Read each string from the user and store it in the list
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    # Sort the strings in ascending order
    S.sort()

    # Print each sorted string to the console
    for string in S:
        print(string, end='')  # Print without newline
    print()  # Print an empty line at the end

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
