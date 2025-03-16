import sys
import re

# Read input from stdin
def input():
    return sys.stdin.readline().strip()

# Initialize a scanner to read input from standard input
sc = input

# Read the number of elements (n) and the number of comparisons (m)
n, m = map(int, sc().split())

# Create a list to hold the heights and a list to track which elements are "good"
h = list(map(int, sc().split()))
good = [True] * n

# Process each comparison
for _ in range(m):
    ai, bi = map(int, sc().split())
    ai -= 1  # Convert to 0-based index
    bi -= 1  # Convert to 0-based index

    # Compare the heights and update the good list accordingly
    if h[ai] > h[bi]:
        good[bi] = False  # If ai is taller, bi is not "good"
    elif h[ai] < h[bi]:
        good[ai] = False  # If bi is taller, ai is not "good"
    else:
        # If heights are equal, mark both as not "good"
        good[ai] = False
        good[bi] = False

# Count the number of "good" elements
ans = sum(good)

# Print the result: the number of "good" elements
print(ans)

