# Include necessary libraries
import sys

# Define a function to read input
def read_input():
    return sys.stdin.readline().strip()

# Read the number of strings (N) and the length of strings (L)
N, L = map(int, read_input().split())

# Read N strings from the user and store them in a list
v = []
for _ in range(N):
    s = read_input()
    v.append(s)  # Add the string to the list

# Sort the list of strings in lexicographical order
v.sort()

# Output the sorted strings
for s in v:
    print(s, end='')  # Print each string in the sorted order without newline
print()  # Print a newline at the end

