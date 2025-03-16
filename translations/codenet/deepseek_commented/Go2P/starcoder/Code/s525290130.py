import sys

# Reads the number of elements
n = int(sys.stdin.readline())

# Initializes a slice of integers with size n
a = [0] * n

# Reads each element and assigns it to the slice
for i in range(n):
	a[i] = int(sys.stdin.readline())

# Reads the number of queries
q = int(sys.stdin.readline())

# Reads the start index of the segment to reverse
for i in range(q):
	b = int(sys.stdin.readline())
	e = int(sys.stdin.readline())
	a[b:e] = a[b:e][::-1]

# Writes the elements to the output
for i in range(n):
	if i > 0:
		sys.stdout.write(" ")
	sys.stdout.write(str(a[i]))

# Adds a newline after all elements
sys.stdout.write("\n")

# 