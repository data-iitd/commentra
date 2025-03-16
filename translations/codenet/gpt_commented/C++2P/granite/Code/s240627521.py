
# Read the number of elements
N = int(input())

# Initialize a list to store the elements
A = list(map(int, input().split()))

# Sort the list in descending order
A.sort(reverse=True)

# Initialize variables to track the minimum difference and the corresponding index
index = 0
max_diff = float('inf')

# Find the element in the list that minimizes the difference with twice the second largest element
for i in range(1, N):
    # Calculate the absolute difference and update if it's smaller than the current max
    diff = abs(A[0] - 2 * A[i])
    if diff < max_diff:
        max_diff = diff
        index = i  # Store the index of the element that gives the minimum difference

# Output the largest element and the element that minimizes the difference
print(A[0], A[index])

