
# The solve function reads an integer n and a slice of integers as.
# It then creates a new slice xs where each element is calculated as a - i + 1.
# The slice xs is sorted.
# The median of the sorted xs is chosen as b.
# The function calculates the sum of absolute differences between each element in xs and b.
# The result is printed.
def solve():
	n = getInt()
	as = getIntSlice(n)

	xs = []
	for i, a in enumerate(as):
		xs.append(a - i + 1)
	xs.sort() # Sort the slice xs

	b = xs[n//2] # Choose the median as b
	ans = 0
	for x in xs:
		ans += abs(x - b)
	print(ans)

# The abs function returns the absolute value of an integer n.
def abs(n):
	if n < 0:
		return -n
	return n

# -----------------------------------------

import sys

# The main function initializes the scanner and writer, sets the buffer size, and splits the input by words.
# It then calls the solve function to execute the program logic.
def main():
	maxBufSize = 100000000
	sys.stdin = open('input.txt', 'r')
	sys.stdout = open('output.txt', 'w')
	sys.stdin = sys.stdin.detach()
	sys.stdout = sys.stdout.detach()
	sc = sys.stdin.buffer.readline
	wr = sys.stdout.buffer.write
	solve()
	wr(b'\n')
	wr.flush()

# The getInt function reads a single integer from the standard input.
def getInt():
	return int(sc().rstrip())

# The getIntSlice function reads n integers from the standard input and returns them as a slice.
def getIntSlice(n):
	return [int(x) for x in sc().split()]

# The getString function reads a single string from the standard input.
def getString():
	return sc().rstrip().decode()

# The getRunes function reads a single string from the standard input and returns it as a slice of runes.
def getRunes():
	return list(getString())

