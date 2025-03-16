# Import the necessary libraries
import sys

# Read the number of strings 'N' and their lengths 'L' from the standard input
N, L = map(int, sys.stdin.readline().split())

# Initialize an empty list 'v' to store the strings
v = []

# Read 'N' strings from the standard input and append them to the list 'v'
for _ in range(N):
    s = sys.stdin.readline().strip()
    v.append(s)

# Sort the strings in the list 'v' in ascending order using the 'sort' function
v.sort()

# Join the sorted strings in the list 'v' and print the result to the standard output
result = ''.join(v)
print(result)

# Print a newline character at the end of the output
print()
