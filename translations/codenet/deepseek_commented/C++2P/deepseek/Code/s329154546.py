import sys

# Read the number of strings and the length of each string
N, L = map(int, input().split())

# Read each string and store it in a list
S = [input() for _ in range(N)]

# Sort the list of strings alphabetically
S.sort()

# Output each sorted string
for s in S:
    print(s, end='')
print()  # Output a newline character

# <END-OF-CODE>