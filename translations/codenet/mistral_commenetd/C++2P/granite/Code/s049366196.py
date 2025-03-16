

import math

# Function to check if a number is prime
def is_prime(x):
	# Check for edge cases
	if x <= 1: return False
	if x == 2: return True

	# Check for composite numbers up to the square root of x
	for i in range(2, int(math.sqrt(x))+1):
		# If x is divisible by i, it's not prime
		if x % i == 0: return False

	# If we've made it this far, x is prime
	return True

# Read the input number N
N = int(input())

# Initialize answer to 1
ans = 1

# Iterate through all numbers from 2 to N
for i in range(2, N+1):
	# If the number is prime, calculate its contribution to the answer
	if is_prime(i):
		# Initialize variables for counting prime factors and total count
		NN = N
		cnt = 0

		# Count the number of occurrences of i as a factor in N
		while NN:
			# Increment the count
			cnt += NN//i

			# Update NN to the next number without the current factor
			NN //= i

		# Multiply the answer by the count and update it modulo mod
		ans *= (cnt+1)
		ans %= mod

# Print the final answer
print(ans)

