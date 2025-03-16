import sys

# Main Function
# The main function reads two integers, n and k, and calculates the sum of combinations from k to n+1.
# It uses a modulo operation to prevent overflow and prints the final result.
def main():
	n = int(sys.stdin.readline()) # Read the first integer, n.
	k = int(sys.stdin.readline()) # Read the second integer, k.

	total = 0 # Initialize the total sum of combinations.
	for i in range(k, n+1):
		total += combi(n, i) # Calculate the combination and add it to the total.
		total = total % (1000000007) # Apply modulo operation to prevent overflow.
	print(total) # Print the final result.

# Combination Function
# The combi function calculates the number of combinations of choosing k items from n items.
# It uses a simplified formula to find the range of the binomial coefficient.
def combi(n, k):
	min = (k-1) * (k) // 2 # Calculate the minimum value of the binomial coefficient.
	max = (2*n-k+1) * (k) // 2 # Calculate the maximum value of the binomial coefficient.
	return max - min + 1 # Return the number of combinations.

# Utility Functions
# These functions provide basic mathematical operations and input reading capabilities.

# Abs returns the absolute value of an integer.
def Abs(x):
	if x >= 0:
		return x
	return -x

# Min returns the smallest value among the given integers.
def Min(values):
	if len(values) == 0:
		raise Exception("no values")
	min = values[0]
	for _, v in enumerate(values):
		if v < min:
			min = v
	return min

# Max returns the largest value among the given integers.
def Max(values):
	if len(values) == 0:
		raise Exception("no values")
	max = values[0]
	for _, v in enumerate(values):
		if v > max:
			max = v
	return max

# Pow returns the base raised to the power of exponent.
def Pow(base, exponent):
	answer = 1
	for i in range(0, exponent):
		answer *= base
	return answer

# Abs64 returns the absolute value of a 64-bit integer.
def Abs64(x):
	if x >= 0:
		return x
	return -x

# Min64 returns the smallest value among the given 64-bit integers.
def Min64(values):
	if len(values) == 0:
		raise Exception("no values")
	min = values[0]
	for _, v in enumerate(values):
		if v < min:
			min = v
	return min

# Max64 returns the largest value among the given 64-bit integers.
def Max64(values):
	if len(values) == 0:
		raise Exception("no values")
	max = values[0]
	for _, v in enumerate(values):
		if v > max:
			max = v
	return max

# Pow64 returns the base raised to the power of exponent for 64-bit integers.
def Pow64(base, exponent):
	answer = 1
	for i in range(0, exponent):
		answer *= base
	return answer

if __name__ == "__main__":
	main()

# 