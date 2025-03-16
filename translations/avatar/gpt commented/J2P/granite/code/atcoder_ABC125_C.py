
import math

# Read the number of elements
N = int(input())

# Read N integers from input and store them in array A
A = [int(input()) for _ in range(N)]

# Arrays to hold the GCD values from the left and right
L = [0] * N  # GCD values from the left
R = [0] * N  # GCD values from the right

# Initialize the first element of L with the first element of A
L[0] = A[0]

# Calculate GCD from the left side
for i in range(1, N):
    L[i] = math.gcd(L[i - 1], A[i])

# Initialize the last element of R with the last element of A
R[N - 1] = A[N - 1]

# Calculate GCD from the right side
for i in range(N - 2, -1, -1):
    R[i] = math.gcd(R[i + 1], A[i])

# Calculate the maximum GCD excluding the last element
answer = max(L[N - 2], R[1])

# Iterate through the array to find the maximum GCD excluding the current element
for i in range(1, N - 1):
    answer = max(answer, math.gcd(L[i - 1], R[i + 1]))

# Print the final answer
print(answer)

