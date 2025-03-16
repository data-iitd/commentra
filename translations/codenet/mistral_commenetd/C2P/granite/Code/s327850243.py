

# Read the dimensions of the matrices from user
m, n = map(int, input().split())
# Comments for the for loop: Read the elements of matrix A row-wise
A = []
for i in range(m):
  row = list(map(int, input().split()))
  A.append(row)
# Read the elements of vector B
B = list(map(int, input().split()))
# Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
S = [0] * m
for i in range(m):
  for j in range(n):
    S[i] += A[i][j] * B[j]
# Comments for the for loop: Print the elements of vector S
for i in range(m):
  print(S[i])

# The program ends with a return statement with value 0
return 0

