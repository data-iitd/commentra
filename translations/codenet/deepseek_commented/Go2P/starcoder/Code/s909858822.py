# Declare two integer variables A and B
A, B = 0, 0

# Read two integers from the standard input and assign them to A and B
A, B = map(int, input().split())

# Declare a variable to store the result
ans = 0

# Check if A is between 6 and 12 inclusive
if 6 <= A and A <= 12:
	# Calculate the half of B and assign it to ans
	ans = B // 2
elif 12 < A:
	# Assign B to ans if A is greater than 12
	ans = B

# Print the value of ans
print(ans)

