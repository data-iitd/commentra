# Optimize input/output operations
from sys import stdin, stdout

# Read the number of elements in the array
N = int(stdin.readline())

# Initialize a vector to store the elements
A = []

# Read the elements into the vector
for i in range(N):
  A.append(int(stdin.readline()))

# Initialize a variable to keep track of the maximum difference
answer = 0

# Iterate through all pairs of elements to find the maximum difference
for i in range(N - 1):
  for j in range(i + 1, N):
    # Calculate the absolute difference between the two elements
    diff = abs(A[i] - A[j])
    
    # Update the maximum difference found so far
    answer = max(answer, diff)

# Output the maximum difference
stdout.write(str(answer) + '\n')

# 