
#=====I/O=====

# Initialize buffered reader and writer for efficient I/O operations.
sc = bufio.Scanner(sys.stdin)
wr = bufio.Writer(sys.stdout)

# Function to scan an integer from input.
def scanInt():
	sc.scan()
	return int(sc.text())

# Function to scan a 64-bit integer from input.
def scanInt64():
	sc.scan()
	return int(sc.text())

# Function to scan a list of integers from input.
def scanInts(n):
	res = []
	for i in range(n):
		res.append(scanInt())
	return res

# Function to scan a single line of text from input.
def scanText():
	sc.scan()
	return sc.text()

# Function to print a list of integers, separated by spaces.
def printInts(a):
	for i, e in enumerate(a):
		wr.write(str(e))
		if i != len(a)-1: wr.write(" ")
	wr.write("\n")
	wr.flush()

#=====main=====

# The main function of the program.
def main():
	# Set the split function for the scanner to scan words.
	sc.split(bufio.ScanWords)

	# Read the number of elements.
	n = scanInt()

	# Read n integers into a slice.
	c = scanInts(n)

	# Initialize the answer variable.
	ans = 0

	# Sort the slice of integers.
	c.sort()

	# Calculate the answer based on the sorted slice.
	for i in range(n):
		ans = (ans+(n+1-i)*c[i]%mod)%mod

	# Print the final answer, multiplied by 4^(n-1) modulo mod.
	print(ans*modpow(4,n-1)%mod)

# Define the constant for modular arithmetic.
mod = 1000000007

# Function to perform modular exponentiation.
def modpow(a,n):
	res = 1
	while n>0:
		if n&1 == 1:
			res = res*a%mod
		a = a*a%mod
		n= n>>1
	return res

# END-OF-CODE
