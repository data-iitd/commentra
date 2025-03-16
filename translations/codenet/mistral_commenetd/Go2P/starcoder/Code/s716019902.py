# Constants
mod = 998244353
facNum = 300001

# Main function
def main():
	# Initialize a new scanner
	sc = newScanner(sys.stdin)

	# Read an integer N from the standard input
	N = sc.i()

	# Initialize a variable sum to 0
	sum = 0

	# Loop through numbers from 1 to N
	for i in range(1, N+1):
		# If the number is not divisible by 3 or 5, add it to the sum
		if i%3!= 0 and i%5!= 0:
			sum += i

	# Print the result to the standard output
	print(sum)

# I/O
class scanner:
	def __init__(self, stream):
		# Initialize a new bufio.Scanner with the given input
		self.sc = bufio.Scanner(stream)

		# Set the scanner to split input on words
		self.sc.split(bufio.ScanWords)

		# Set the scanner buffer size
		self.sc.buffer(make([]byte, 1024), int(1e+9))

	def s(self):
		# Scan the next token and return it as a string
		self.sc.scan()
		return self.sc.text()

	def i(self):
		# Convert the next token to an integer and return it
		i, _ = int(self.s()), None
		return i

	def f(self):
		# Convert the next token to a float64 and return it
		f, _ = float(self.s()), None
		return f

	def bs(self):
		# Return the next token as a byte slice
		return self.s().encode()

	def is(self, n):
		# Read n integers from the standard input and return them as a slice
		res = [None] * n
		for i in range(n):
			res[i], _ = int(self.s()), None
		return res

	def fs(self, n):
		# Read n floating-point numbers from the standard input and return them as a slice
		res = [None] * n
		for i in range(n):
			res[i], _ = float(self.s()), None
		return res

# Math functions
def Pow(a, n):
	# Calculate a^n modulo mod
	ans = 1
	for n > 0:
		if (n & 1) == 1:
			ans = ans * a % mod
		a = a * a % mod
		n = n >> 1
	return ans

def Gcd(a, b):
	# Calculate the greatest common divisor of a and b
	if a < b:
		return Gcd(b, a)
	for b!= 0:
		a, b = b, a%b
	return a

def min(a, b):
	# Return the minimum of a and b
	if a < b:
		return a
	return b

# Combination function
def combination(n, k, fac, ifac):
	# Calculate the binomial coefficient (n choose k) modulo mod
	if n < k or n < 0:
		return 0
	if k == 0:
		return 1
	# While n is not 0
	ans = ifac[k] * ifac[n-k] % mod
	return ans * fac[n] % mod

# Factorial function
def factorial():
	# Calculate and return the factorial of all numbers from 0 to facNum-1
	fac = [None] * facNum
	fac[0] = 1
	ifac = [None] * facNum
	ifac[0] = 1
	for i in range(1, facNum):
		fac[i] = fac[i-1] * i % mod
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod
	return fac, ifac

# Lower bound function
def lowerBound(vs, v):
	# Calculate the index of the first element in vs that is greater than or equal to v
	n = len(vs) / 2
	m = len(vs)
	for m!= n:
		if vs[n] < v:
			n = (m-n+1)/2 + n
			#m = m
		else:
			m = n
			n = n / 2
	return n

# IntSlice function
def IntSlice(n, init):
	# Create and initialize a slice of length n with the given initial value
	r = [None] * n
	for i in range(n):
		r[i] = init
	return r

# 
