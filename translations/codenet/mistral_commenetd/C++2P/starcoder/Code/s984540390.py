
# Define long long integer as ll for better readability

ans, mx, sum, mn = 1e8, 1, 1, 1e8 # Initialize variables

# Read input integer h from standard input
h = int(input())

# Loop until h becomes 1
while h!= 1:
	# If h is odd, decrement it by 1
	if h % 2!= 0: h -= 1

	# Divide h by 2 and multiply cnt by 2
	h //= 2
	cnt *= 2

	# Add the new value of cnt to the answer
	ans += cnt

# Output the final answer plus 1
print(ans + 1)

