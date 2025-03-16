
# =====I/O=====

# Declare scanner and writer for input and output
import sys

sc = sys.stdin.readline
wr = sys.stdout.write

# Function to scan an integer from input
def scanInt():
	return int(sc())

# Function to scan a 64-bit integer from input
def scanInt64():
	return int(sc())

# Function to scan multiple integers from input
def scanInts(n):
	res = []
	for i in range(n):
		res.append(scanInt())
	return res

# Function to scan a single line of text from input
def scanText():
	return sc()

# Function to print integers to output
def printInts(a):
	wr(" ".join(map(str, a)))
	wr("\n")
	wr.flush()

# =====main=====

# Main function where execution starts
if __name__ == "__main__":
	n = scanInt() # Read the number of integers

	c = scanInts(n) # Read n integers into slice c

	ans = 0 # Initialize answer variable
	c.sort() # Sort the slice of integers

	# Calculate the answer based on the sorted integers
	for i in range(n):
		ans = (ans + (n+1-i)*c[i]%mod) % mod # Update the answer using the formula

	# Print the final result after applying modular exponentiation
	print(ans * pow(4, n-1, mod) % mod)

# 