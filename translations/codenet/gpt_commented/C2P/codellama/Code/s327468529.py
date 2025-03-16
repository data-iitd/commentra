#if 0
cat <<EOF >mistaken-paste
#endif
#!/usr/bin/env python3

# Suppress warnings for incompatible pointer types
# pylint: disable=invalid-name,ungrouped-imports,unused-import,unused-variable,unused-wildcard-import

# Include necessary headers
import math
import sys

# Define constants for large numbers and modular arithmetic
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353

# Define types for unsigned and signed long long integers
ull = int
sll = int

# Define maximum size for arrays
N_MAX = 1048576

# Define structures for various data types
class hwll:
	def __init__(self, a, b):
		self.a = a
		self.b = b

class hwllc:
	def __init__(self, a, b, c):
		self.a = a
		self.b = b
		self.c = c

class linell:
	def __init__(self, a, b):
		self.a = a
		self.b = b

class hwreal:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Global variables for various parameters
n = 4
m = 0
h = 0
w = 0
k = 0
q = 0
va = 0
vb = 0
vc = 0
vd = 0
ve = 0
vf = 0
ua = 0
ub = 0
uc = 0
ud = 0
ue = 0
uf = 0
vra = 0
vrb = 0
vrc = 0
vda = 0
vdb = 0
vdc = 0
ch = 0
dh = 0

# Function to return the minimum of two unsigned long long integers
def umin(x, y):
	return x if x < y else y

# Function to return the maximum of two unsigned long long integers
def umax(x, y):
	return x if x > y else y

# Function to return the minimum of two signed long long integers
def smin(x, y):
	return x if x < y else y

# Function to return the maximum of two signed long long integers
def smax(x, y):
	return x if x > y else y

# Function to compute the greatest common divisor (GCD) of two unsigned long long integers
def gcd(x, y):
	if y == 0:
		return x
	else:
		return gcd(y, x % y)

# Function to compute a^x mod modulo using binary exponentiation
def bitpow(a, x, modulo):
	result = 1
	while x:
		if x & 1:
			result *= a
			result %= modulo
		x //= 2
		a = (a * a) % modulo
	return result

# Function to perform modular division a / b mod modulo
def divide(a, b, modulo):
	return (a * bitpow(b, modulo - 2, modulo)) % modulo

# Function to return the absolute difference between two unsigned long long integers
def udiff(a, b):
	if a >= b:
		return a - b
	else:
		return b - a

# Function to return the absolute difference between two signed long long integers
def sdiff(a, b):
	if a >= b:
		return a - b
	else:
		return b - a

# Function to count the number of set bits in an unsigned long long integer
def bitcount(n):
	result = 0
	while n:
		if n & 1:
			result += 1
		n //= 2
	return result

# Macros for comparison functions
def pullcomp(left, right):
	l = left
	r = right
	if l < r:
		return -1
	if l > r:
		return 1
	return 0

def prevcomp(left, right):
	l = left
	r = right
	if r < l:
		return -1
	if r > l:
		return 1
	return 0

def psllcomp(left, right):
	l = left
	r = right
	if l < r:
		return -1
	if l > r:
		return 1
	return 0

def pcharcomp(left, right):
	l = left
	r = right
	if l < r:
		return -1
	if l > r:
		return 1
	return 0

def pdoublecomp(left, right):
	l = left
	r = right
	if l < r:
		return -1
	if l > r:
		return 1
	return 0

def pstrcomp(left, right):
	l = left
	r = right
	return strcmp(l, r)

def phwllABcomp(left, right):
	l = left
	r = right
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	return 0

def phwllREVcomp(left, right):
	l = left
	r = right
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	return 0

def ptriplecomp(left, right):
	l = left
	r = right
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	if l.c < r.c:
		return -1
	if l.c > r.c:
		return 1
	return 0

def ptripleREVcomp(left, right):
	l = left
	r = right
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	if l.c < r.c:
		return -1
	if l.c > r.c:
		return 1
	return 0

def ptripleCABcomp(left, right):
	l = left
	r = right
	if l.c < r.c:
		return -1
	if l.c > r.c:
		return 1
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	return 0

def phwrealcomp(left, right):
	l = left
	r = right
	if l.a < r.a:
		return -1
	if l.a > r.a:
		return 1
	if l.b < r.b:
		return -1
	if l.b > r.b:
		return 1
	return 0

def pquadcomp(left, right):
	l = left
	r = right
	if phwllABcomp(l.a, r.a) != 0:
		return phwllABcomp(l.a, r.a)
	if phwllABcomp(l.b, r.b) != 0:
		return phwllABcomp(l.b, r.b)
	return 0

def pfracomp(left, right):
	l = left
	r = right
	if l.a * r.b < l.b * r.a:
		return -1
	if l.a * r.b > l.b * r.a:
		return 1
	return 0

# Function to check if a value x is within a range [left, right]
def isinrange(left, x, right):
	return left <= x and x <= right

# Function to check if a value x is within a range [left, right] or vice versa
def isinrange_soft(left, x, right):
	return left <= x and x <= right or left >= x and x >= right

# Function to swap two signed long long integers
def sw(l, r):
	if l == r:
		return
	t = l
	l = r
	r = t

# Arrays for factorials and their inverses
frac = [0] * (N_MAX * 3)
invf = [0] * (N_MAX * 3)

# Function to compute n choose r modulo m
def ncr(n, r, m):
	if n < 0 or r < 0 or n < r:
		return 0
	return frac[n] * (invf[r] * invf[n - r] % m) % m

# Arrays for various data types
a = [0] * (N_MAX + 5)
b = [0] * (N_MAX + 5)
c = [0] * (N_MAX + 5)
d = [0] * (N_MAX + 5)
e = [0] * (N_MAX * 4)
s = [0] * (N_MAX + 1)
t = [0] * (N_MAX + 1)
u = [0] * (N_MAX + 1)
xy = [0] * (N_MAX + 5)
tup = [0] * (N_MAX + 5)
table = [[0] * 3005 for _ in range(3005)]
gin = [0] * (N_MAX + 1)

# Initialize counters and arrays for computations
cnt = [0] * 3
pcnt = 0
x = [[0] * 3005 for _ in range(3005)]

# Main solving function
def solve():
	i = 0
	j = 0
	ki = 0
	li = 0
	result = 1 # Variable to store the result
	maybe = 0 # Variable for potential calculations
	sum = 0 # Variable for summation
	item = 0 # Temporary variable
	dpcell = 0 # Pointer for dynamic cell references

	# Initialize result
	result = 1

	# Process the input string and calculate the result based on color counts
	for i in range(n * 3):
		v = 0
		if s[i] == 'R':
			v = 0 # Red
		elif s[i] == 'G':
			v = 1 # Green
		elif s[i] == 'B':
			v = 2 # Blue

		# Check if there are available colors to form combinations
		if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
			result *= pcnt # Multiply by the count of available combinations
			pcnt -= 1 # Decrease the count of available combinations
			result %= FOD # Apply modulo
			cnt[(v + 1) % 3] -= 1 # Decrease count of the first color
			cnt[(v + 2) % 3] -= 1 # Decrease count of the second color
		else:
			# If there are more of the other two colors than the current color
			if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
				result %= FOD # Apply modulo
				pcnt += 1 # Increase the count of available combinations
			cnt[v] += 1 # Increase count of the current color

	# Calculate the factorial of n for final result
	for i in range(1, n + 1):
		result *= i
		result %= FOD

	# Output the result
	print(result)
	return 0

# Main function to execute the program
def main(argc, argv):
	global n
	global m

	n = 4 # Set initial value for n
	m = 0 # Set initial value for m

	# Read input values
	n, m = map(int, input().split())
	s = input() # Read the string input

	# Call the solve function to compute the result
	solve()

	return 0 # Exit the program

if __name__ == "__main__":
	main(len(sys.argv), sys.argv)

