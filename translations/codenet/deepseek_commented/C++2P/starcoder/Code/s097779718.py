# Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
def Euclid(x, y):
	# Ensure x is greater than y
	if x < y:
		tmp = x
		x = y
		y = tmp

	# Base case: if x is divisible by y, return y
	if not(x % y): return y

	# Recursive case: apply the Euclidean algorithm
	return Euclid(y, x % y)

# Read two long long integers from standard input
A, B = map(int, raw_input().split())

# Calculate and output the least common multiple (LCM) of A and B
print (A * B) / Euclid(A, B)

