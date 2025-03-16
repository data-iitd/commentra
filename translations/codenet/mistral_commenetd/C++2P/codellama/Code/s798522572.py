#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

# Initialize variables
N = 0
T = 0

# Read input values from the standard input
N, T = map(int, input().split())

# Allocate memory for an integer array A of size N
A = [0] * N

# Allocate memory for a vector B of size N
B = [0] * N

# Read integer values from the standard input and store them in array A
for i in range(N):
    A[i] = int(input())

# Initialize variable m with the minimum value among the first two elements of array A
m = A[0]
if A[1] < m:
    m = A[1]

# Set the first element of vector B with the difference between the second element of array A and the initialized value of m
B[1] = A[1] - m

# Iterate through the remaining elements of array A starting from the third one
for i in range(2, N):
    # Update the value of m with the minimum value between it and the current element of array A
    m = min(m, A[i])

    # Set the current element of vector B with the difference between the current element of array A and the updated value of m
    B[i] = A[i] - m

# Print the output value to the standard output
print(count(B, max(B)))

# End of main function

