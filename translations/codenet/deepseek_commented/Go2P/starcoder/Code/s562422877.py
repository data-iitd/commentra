
# Read the number of elements N
N = int(input())

# Create a slice A to store N integers
A = []
for i in range(N):
	# Read each integer and store it in slice A
	A.append(int(input()))

# Sort the slice A in ascending order
A.sort()

# Initialize the answer variable to store the result
ans = 0
for i in range(1, N):
	# Calculate the sum of differences between consecutive elements
	ans += A[i] - A[i-1]

# Print the result
print(ans)

