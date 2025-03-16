import sys

# Read the number of elements
N = int(input().strip())

# Input the elements into a list
A = list(map(int, sys.stdin.readline().strip().split()))

# Sort the list in descending order
A.sort(reverse=True)

# Initialize variables to track the minimum difference and the corresponding index
index = 0
min_diff = float('inf')

# Find the element in the list that minimizes the difference with twice the second largest element
for i in range(1, N):
    # Calculate the absolute difference and update if it's smaller than the current min_diff
    diff = abs(A[0] - 2 * A[i])
    if diff < min_diff:
        min_diff = diff
        index = i  # Store the index of the element that gives the minimum difference

# Output the largest element and the element that minimizes the difference
print(A[0], A[index])
