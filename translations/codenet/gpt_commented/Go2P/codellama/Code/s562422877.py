
import sys

# Read the number of elements N from input
N = int(sys.stdin.readline())

# Initialize a list A to hold N integers
A = []

# Read N integers from input into the list A
for i in range(N):
    A.append(int(sys.stdin.readline()))

# Sort the list A in ascending order
A.sort()

# Initialize a variable to hold the total difference sum
ans = 0

# Calculate the sum of differences between consecutive elements in the sorted list
for i in range(1, N):
    ans += A[i] - A[i-1]

# Output the total sum of differences
print(ans)

