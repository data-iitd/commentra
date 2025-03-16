
#=====I/O=====

# Initialize scanner and writer
sc = input
wr = print

# Function to read an integer from standard input
def scanInt():
	return int(sc())

# Function to read an integer64 from standard input
def scanInt64():
	return int(sc())

# Function to read n integers from standard input
def scanInts(n):
	return [int(sc()) for i in range(n)]

# Function to print integers to standard output
def printInts(*a):
	# Iterate through slice a and print each integer followed by a space
	for i, e in enumerate(a):
		wr(e)
		if i != len(a)-1: wr(" ")
	# Print newline character and flush writer buffer
	wr("\n")
	wr.flush()

#=====main=====

# Set scanner to scan words
def main():
	# Read an integer n from standard input
	n = scanInt()

	# Read n integers c from standard input and store them in a slice
	c = scanInts(n)

	# Initialize answer variable to 0
	ans = 0

	# Sort slice c in ascending order
	c.sort()

	# Iterate through slice c and calculate answer
	for i in range(n):
		# Calculate contribution of current integer to answer
		ans = (ans + (n+1-i)*c[i]%mod)%mod

	# Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
	print(ans*modpow(4,n-1)%mod)

# Constants
mod = 1000000007

# Function to calculate modular exponentiation
def modpow(a,n):
	# Initialize result to 1
	res = 1

	# If n is 0, return result
	if n == 0: return res

	# If n is 1, return a
	if n == 1: return a

	# If n is odd, multiply result with a multiplied by itself recursively
	if n&1 == 1:
		res = res*a%mod
		a = a*a%mod
		n = n>>1
		res = res*modpow(a,n)%mod

	# If n is even, square result and recursively call function for n/2
	else:
		a = a*a%mod
		n = n>>1
		res = modpow(a,n)%mod

	# Return result
	return res

#=====END-OF-CODE=====
