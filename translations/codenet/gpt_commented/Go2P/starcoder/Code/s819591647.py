// problem_b.py

import sys

# Define a constant for modulus operation
constMod = 1000000007

# Initialize scanner and writer for input and output
sc = sys.stdin
wr = sys.stdout

# -----------------------------------------

# getInt reads a single integer from input
def getInt():
	return int(sc.readline())

# getIntSlice reads n integers from input and returns them as a slice
def getIntSlice(n):
	return [int(x) for x in sc.readline().split()]

# getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D slice
def getIntDoubleSlice(m, n):
	return [getIntSlice(n) for i in range(m)]

# getString reads a single string from input
def getString():
	return sc.readline().strip()

# getStringSlice reads n strings from input and returns them as a slice
def getStringSlice(n):
	return [x.strip() for x in sc.readline().split()]

# getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D slice
def getStringDoubleSlice(m, n):
	return [getStringSlice(n) for i in range(m)]

# -----------------------------------------

# Sort Functions

# sortIntSlice sorts a slice of integers in ascending order
def sortIntSlice(ns):
	return sorted(ns)

# sortIntReverseSlice sorts a slice of integers in descending order
def sortIntReverseSlice(ns):
	return sorted(ns, reverse=True)

# -----------------------------------------

# Number Functions

# numAbs returns the absolute value of an integer x
def numAbs(x):
	return abs(x)

# numModPow computes a^n % m using modular exponentiation
def numModPow(a, n, m):
	result = 1

	while n > 0:
		if n & 1 == 1:
			result = (result * a) % m
		a = (a * a) % m
		n >>= 1

	return result

# numGcd computes the greatest common divisor of a and b
def numGcd(a, b):
	if b == 0:
		return a
	return numGcd(b, a % b)

# numLcm computes the least common multiple of a and b
def numLcm(a, b):
	return a * b / numGcd(a, b)

# numModInv computes the modular inverse of a under modulo p
def numModInv(a, p):
	if a == 1:
		return 1
	return p - numModInv(p % a, p) * (p / a) % p

# numModFrac computes factorials modulo constMod up to n
def numModFrac(n):
	frac = [1]

	for i in range(1, n + 1):
		frac.append(i * frac[i - 1] % constMod)

	return frac

# numModConb computes nCr % constMod using precomputed factorials
def numModConb(n, r):
	frac = numModFrac(n)
	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

# solve function implements the main logic of the problem
def solve():
	# Read n and m from input
	n, m = getInt(), getInt()
	# Read n integers into slice a
	a = getIntSlice(n)

	# Calculate the sum of all elements in a
	sum = 0
	for v in a:
		sum += v

	# Count how many elements in a meet the required rate
	count = 0
	for v in a:
		rate = float(sum) / float(4 * m)
		if float(v) >= rate:
			count += 1

	# Output "Yes" if count is greater than or equal to m, otherwise "No"
	if count >= m:
		print("Yes")
	else:
		print("No")

# -----------------------------------------

# main function initializes the program and calls solve
def main():
	# Set a maximum buffer size for input
	maxBufSize = 100000000
	sc.buffer = [None] * maxBufSize
	sc.bufsize = maxBufSize
	# Call the solve function to execute the main logic
	solve()

# -----------------------------------------

# Entry Point
if __name__ == "__main__":
	main()

