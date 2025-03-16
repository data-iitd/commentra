# Declare two integer variables A and B to hold input values
A, B = map(int, input().split())

# Declare a variable to hold the result
ans = 0

# Check if A is between 6 and 12 (inclusive)
if 6 <= A and A <= 12:
	# If A is in the range, set ans to half of B
	ans = B // 2
elif 12 < A:
	# If A is greater than 12, set ans to the value of B
	ans = B

# Print the result
print(ans)

