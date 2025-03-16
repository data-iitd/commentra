def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Initialize the array A and read its elements from the standard input
N = int(input())  # Read the number of elements in the array A
A = list(map(int, input().split()))  # Read the elements of the array A from the standard input

# Initialize arrays M, L, and R
M = [0] * N
L = [0] * N
R = [0] * N

# Initialize the first elements of L and R arrays
L[0] = A[0]
R[N - 1] = A[N - 1]

# Calculate the gcd of consecutive pairs of elements in the array A,
# starting from the second element, and store the results in the L array
for i in range(1, N):
    L[i] = gcd(L[i - 1], A[i])

# Calculate the gcd of consecutive pairs of elements in the array A,
# starting from the last element, and store the results in the R array
for i in range(N - 2, -1, -1):
    R[i] = gcd(R[i + 1], A[i])

# Find the maximum value among the gcd of consecutive pairs of elements
# in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
answer = max(L[N - 2], R[1])
for i in range(1, N - 1):
    answer = max(answer, gcd(L[i - 1], R[i + 1]))

# Print the result
print(answer)
