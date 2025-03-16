
# Read the number of elements in the array A
N = int(input())
# Read the elements of the array A
A = [int(x) for x in input().split()]
# Sort the array A in descending order
A.sort(reverse=True)
# Initialize max with a large value
max = 10**18
# Iterate through the array to find the optimal pair
for i in range(1, N):
    # Check if the current difference is smaller than the previous minimum
    if max > abs(A[0] - 2 * A[i]):
        # Update the minimum difference
        max = abs(A[0] - 2 * A[i])
        # Store the index of the current element
        index = i
# Output the first and the found optimal pair
print(A[0], A[index])

