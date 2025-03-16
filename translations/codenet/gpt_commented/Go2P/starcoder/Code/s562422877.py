# Read the number of elements N from input
N = int(input())

# Initialize a slice A to hold N integers
A = []

# Read N integers from input into the slice A
for i in range(N):
	A.append(int(input()))

# Sort the slice A in ascending order
A.sort()

# Initialize a variable to hold the total difference sum
ans = 0

# Calculate the sum of differences between consecutive elements in the sorted slice
for i in range(1, N):
	ans += A[i] - A[i-1]

# Output the total sum of differences
print(ans)

