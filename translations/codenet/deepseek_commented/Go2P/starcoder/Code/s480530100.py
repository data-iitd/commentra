import sys

# out is a helper function to print output.
def out(x):
	print(x)

# getInt reads a single word from the input and converts it to an integer.
def getInt():
	return int(sys.stdin.readline())

# getString reads a single word from the input and returns it as a string.
def getString():
	return sys.stdin.readline().strip()

# main function is the entry point of the program.
def main():
	# Set the buffer size for the scanner to a large value.
	sys.stdin = open("input.txt", "r")
	sys.stdout = open("output.txt", "w")

	# Read the number of elements (n) and the number of queries (q).
	n, q = getInt(), getInt()

	# Initialize a Fenwick Tree with n elements.
	fw = FenwickTree(n)

	# Read n elements and add them to the Fenwick Tree.
	for i in range(n):
		a = getInt()
		fw.Add(i, a)

	# Process q queries.
	for i in range(q):
		t = getInt()
		if t == 0:
			# Update the value at position p by adding x to it.
			p, x = getInt(), getInt()
			fw.Add(p, x)
		else:
			# Query the sum of elements between indices l and r.
			l, r = getInt(), getInt()
			out(fw.Sum(l, r))

# Fenwick Tree implementation

# BIT represents the Fenwick Tree data structure.
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n

	# Add updates the value at position p by adding x to it.
	def Add(self, p, x):
		p += 1 # Convert to 1-based index
		while p <= self.n:
			self.data[p-1] += x
			p += p & -p # Move to the next node

	# Sum calculates the sum of elements between indices l and r.
	def Sum(self, l, r):
		return self.sum(r) - self.sum(l)

	# sum calculates the prefix sum up to index r.
	def sum(self, r):
		s = 0
		while r > 0:
			s += self.data[r-1]
			r -= r & -r # Move to the parent node
		return s

if __name__ == "__main__":
	main()

