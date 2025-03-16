# Import necessary libraries
import sys

# Read the number of strings and the length of each string
N, L = map(int, sys.stdin.readline().split())
S = []  # Declare a list to store the strings

# Read each string and store it in the list
for _ in range(N):
    S.append(sys.stdin.readline().strip())

# Sort the list of strings alphabetically
S.sort()

# Output each sorted string
for string in S:
    print(string, end='')

print()  # Output a newline character
# <END-OF-CODE>
