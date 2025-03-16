import sys

# Reading the number of elements and a threshold value
N, T = map(int, sys.stdin.readline().split())
# Reading the elements into a list
A = list(map(int, sys.stdin.readline().split()))

# Initializing the minimum value with the first element of A
m = A[0]
# Initializing a list to store the differences
B = [0] * N
# Calculating the difference between the second element and the initial minimum, and storing it in B[1]
B[1] = A[1] - m
# Updating the minimum value to be the minimum of its current value and the second element of A
m = min(m, A[1])
# For each subsequent element in A, calculate the difference, update the minimum, and store the difference in B
for i in range(2, N):
    B[i] = A[i] - m
    m = min(m, A[i])

# Finding the maximum value in B
max_value = max(B)
# Counting how many times the maximum value appears in B
count = B.count(max_value)
print(count)
