import sys

# Use readline for faster input
input = sys.stdin.readline

# Read the number of elements
n = int(input())

# Read the list of integers
w = list(map(int, input().split()))

# Calculate the sum of the list
x = sum(w)

# Initialize an empty list to store indices
d = []

# Iterate through each element in the list
for i in range(n):
    # Check if removing the current element results in an average equal to the current element
    if (x - w[i]) / (n - 1) == w[i]:
        # If the condition is met, append the 1-based index to the list
        d.append(i + 1)

# Print the number of valid indices found
print(len(d))

# Print the valid indices as a space-separated string
print(' '.join(map(str, d)))
