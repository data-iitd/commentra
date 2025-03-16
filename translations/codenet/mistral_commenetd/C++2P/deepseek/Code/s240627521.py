import sys

# Read the number of elements in the vector
N = int(input())

# Read the elements into the vector
A = list(map(int, sys.stdin.readline().split()))

# Sort the vector in descending order
A.sort(reverse=True)

# Initialize the maximum difference to an infinite value
max_diff = float('inf')
# Initialize the index of the second smallest element
index = -1

# Iterate through the range [1, N)
for i in range(1, N):
    # Calculate the absolute difference
    diff = abs(A[0] - 2 * A[i])
    # Check if the current difference is greater than the maximum difference
    if diff < max_diff:
        # Update the maximum difference and the index of the second smallest element
        max_diff = diff
        index = i

# Output the smallest and second smallest elements
print(A[0], A[index])
