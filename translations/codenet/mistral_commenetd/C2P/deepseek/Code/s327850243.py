# Declare variables
m, n = map(int, input().split())
A = [[0] * n for _ in range(m)]
B = [0] * n
S = [0] * m

# Read the elements of matrix A row-wise
for i in range(m):
    A[i] = list(map(int, input().split()))

# Read the elements of vector B
B = list(map(int, input().split()))

# Perform element-wise multiplication of matrices A and B, and store the result in vector S
for i in range(m):
    for j in range(n):
        S[i] += A[i][j] * B[j]

# Print the elements of vector S
for i in range(m):
    print(S[i])

# The program ends with a return statement with value 0
# <END-OF-CODE>