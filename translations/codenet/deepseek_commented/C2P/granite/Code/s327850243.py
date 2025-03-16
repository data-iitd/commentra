
# Read the dimensions of matrix A and vector B
m, n = map(int, input().split())

# Read the elements of matrix A row by row
A = []
for i in range(m):
  row = list(map(int, input().split()))
  A.append(row)

# Read the elements of vector B
B = list(map(int, input().split()))

# Perform matrix multiplication of A and B and store the result in array S
S = [0] * m
for i in range(m):
  for j in range(n):
    S[i] += A[i][j] * B[j]

# Print the elements of array S
for s in S:
  print(s)

