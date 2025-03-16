import sys

# Read input values from the standard input
N, T = map(int, sys.stdin.readline().split())

# Read integer values from the standard input and store them in a list A
A = list(map(int, sys.stdin.readline().split()))

# Initialize variable m with the minimum value among the first two elements of the list A
m = min(A[0], A[1])

# Initialize a list B with the same size as A
B = [0] * N

# Set the first element of list B with the difference between the second element of A and the initialized value of m
B[1] = A[1] - m

# Iterate through the remaining elements of A starting from the third one
for i in range(2, N):
    # Update the value of m with the minimum value between it and the current element of A
    m = min(m, A[i])

    # Set the current element of list B with the difference between the current element of A and the updated value of m
    B[i] = A[i] - m

# Print the output value to the standard output
print(B.count(max(B)))

# End of main function
