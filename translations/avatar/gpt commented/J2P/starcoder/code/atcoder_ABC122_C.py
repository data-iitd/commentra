import sys

# Define a constant for the modulo value
mod = 1000000007

# Read the number of characters (n) and the number of queries (q)
n, q = map(int, input().split())

# Read the character array from input
c = list(input().strip())

# Initialize a 2D array to store the ranges for each query
range = [[0] * 2 for _ in range(q)]

# Read the ranges for each query
for i in range(q):
    range[i][0], range[i][1] = map(int, input().split())

# Initialize arrays to track fragments and cumulative sums
frag = [0] * (n + 1) # To count occurrences of "AC"
rui = [0] * (n + 1)  # To store cumulative sums of fragments

# Loop through the character array to count occurrences of "AC"
for i in range(2, n + 1):
    # Check if the current and previous characters form "AC"
    if c[i - 2] == 'A' and c[i - 1] == 'C':
        frag[i] += 1 # Increment the fragment count
    # Update the cumulative sum of fragments
    rui[i] = rui[i - 1] + frag[i]

# Process each query to find the number of "AC" in the specified range
for i in range(q):
    left = range[i][0]   # Get the left index of the query
    right = range[i][1]  # Get the right index of the query
    
    # Calculate and print the result for the current query
    print(rui[right] - rui[left])

# 