import sys

# Define constants for modulo operation and factorial limit
mod = 998244353
facNum = 300001

# Define a function for reading input
def read_int():
	return int(sys.stdin.readline())

# Define a function for reading input
def read_ints():
	return map(int, sys.stdin.readline().split())

# Define a function for reading input
def read_floats():
	return map(float, sys.stdin.readline().split())

# Define a function for reading input
def read_str():
	return sys.stdin.readline().strip()

# Define a function for reading input
def read_strs():
	return sys.stdin.readline().strip().split()

# Define a function for reading input
def read_lines():
	return sys.stdin.readlines()

# Define a function for printing output
def print_int(x):
	sys.stdout.write(str(x) + '\n')

# Define a function for printing output
def print_float(x):
	sys.stdout.write(str(x) + '\n')

# Define a function for printing output
def print_str(x):
	sys.stdout.write(str(x) + '\n')

# Define a function for printing output
def print_strs(x):
	sys.stdout.write(" ".join(x) + '\n')

# Define a function for printing output
def print_floats(x):
	sys.stdout.write(" ".join(map(str, x)) + '\n')

# Define a function for printing output
def print_ints(x):
	sys.stdout.write(" ".join(map(str, x)) + '\n')

# Define a function for printing output
def print_lines(x):
	sys.stdout.writelines(x)

# Define a function for calculating the greatest common divisor of a and b
def gcd(a, b):
	if a < b:
		return gcd(b, a) # Ensure a is greater than b
	if b == 0:
		return a # Return a if b is 0
	return gcd(b, a%b) # Apply Euclidean algorithm

# Define a function for calculating the least common multiple of a and b
def lcm(a, b):
	return a * b / gcd(a, b) # Return the LCM

# Define a function for calculating a^n under modulo
def pow(a, n):
	ans = 1
	for n > 0:
		if (n & 1) == 1:
			ans = ans * a % mod # Multiply by a if n is odd
		a = a * a % mod # Square a
		n = n >> 1 # Right shift n
	return ans # Return the result

# Define a function for calculating n choose k using precomputed factorials
def combination(n, k, fac, ifac):
	if n < k or n < 0:
		return 0 # Return 0 if invalid
	if k == 0:
		return 1 # Return 1 if k is 0
	# Calculate combination using factorials
	ans = ifac[k] * ifac[n-k] % mod
	return ans * fac[n] % mod

# Define a function for precomputing factorials and their modular inverses
def factorial():
	fac = [1] * facNum # Create a slice for factorials
	ifac = [1] * facNum # Create a slice for inverse factorials
	fac[0] = 1
	ifac[0] = 1
	for i in range(1, facNum):
		fac[i] = fac[i-1] * i % mod # Compute factorial
		ifac[i] = ifac[i-1] * pow(i, mod-2) % mod # Compute inverse factorial using Fermat's little theorem
	return fac, ifac

# Define a function for finding the index of the first element in a sorted slice that is not less than v
def lower_bound(vs, v):
	n = len(vs) / 2 # Initialize mid index
	m = len(vs) # Length of the slice
	for m!= n:
		if vs[n] < v:
			n = (m-n+1)/2 + n # Move to the right half
		else:
			m = n # Move to the left half
			n = n / 2 # Update mid index
	return n # Return the found index

# Define a function for creating a slice of integers initialized to a specific value
def int_slice(n, init):
	r = [init] * n # Create a slice of length n
	return r # Return the initialized slice

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divisible by 3 or 5
def solve():
	# Read an integer N from input
	N = read_int()
	sum = 0
	
	# Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue # Skip numbers divisible by 3 or 5
		sum += i # Add the number to the sum
	
	# Output the final sum
	print_int(sum)

# Define a function for calculating the sum of all integers from 1 to N that are not divi