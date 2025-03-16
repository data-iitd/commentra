
#include<stdio.h>
# Declare variables
m, n = 0, 0
i, j = 0, 0
A = [[0 for x in range(100)] for y in range(100)]
B = [0 for x in range(100)]
S = [0 for x in range(100)]

# Read the dimensions of the matrices from user
scanf("%d %d",&m,&n);
# Comments for the for loop: Read the elements of matrix A row-wise
for i in range(m):
  for j in range(n-1):
    scanf("%d ",&A[i][j]);
  # Read the last element of the row
  scanf("%d\n",&A[i][n-1]);

# Comments for the for loop: Read the elements of vector B
for i in range(n):
  scanf("%d\n",&B[i]);

# Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
for i in range(m):
  for j in range(n):
    S[i] += A[i][j] * B[j];

# Comments for the for loop: Print the elements of vector S
for i in range(m):
  printf("%d\n",S[i]);

# The program ends with a return statement with value 0
return 0;

