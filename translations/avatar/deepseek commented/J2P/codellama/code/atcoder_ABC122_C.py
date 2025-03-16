
import sys

# Define a constant for modulo operations
mod = 1000000007

# Read the length of the string and the number of queries
n, q = map(int, input().split())

# Read the string as a character array
c = list(input())

# Read the ranges for the queries and store them in a 2D array
range = []
for i in range(q):
    range.append(list(map(int, input().split())))

# Initialize arrays to count "AC" fragments and store cumulative sums
frag = [0] * (n + 1)
rui = [0] * (n + 1)

# Process the string to find "AC" fragments
for i in range(2, n + 1):
    if c[i - 2] == 'A' and c[i - 1] == 'C':
        # Increment the count of "AC" fragments at position i
        frag[i] += 1
    # Update the cumulative sum array
    rui[i] = rui[i - 1] + frag[i]

# Process the queries
for i in range(q):
    left = range[i][0]
    right = range[i][1]
    # Calculate the number of "AC" fragments in the given range
    print(rui[right] - rui[left])

# END-OF-CODE
