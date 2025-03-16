# Package main is the entry point of the program
import sys

# Importing required packages

# Initialize scanner, reader, and writer

# Helper function to read a single word from the standard input
def next():
	return sys.stdin.readline().strip()

# Helper function to read an integer from the standard input
def nextInt():
	return int(next())

# Helper function to read float64 from the standard input
def nextFloat64():
	return float(next())

# Helper function to read n integers from the standard input
def nextInts(n):
	return [int(x) for x in next().split()]

# Helper function to read n float64 from the standard input
def nextFloat64s(n):
	return [float(x) for x in next().split()]

# Helper function to read a megabyte-sized string from the standard input
def nextMega():
	return sys.stdin.read()

# Helper function to print a formatted string to the standard output
def putf(format, a):
	sys.stdout.write(format % a)

# Helper function to print a single line to the standard output
def puts(a):
	sys.stdout.write(str(a) + '\n')

# Initialize answer variable
ans = 0

# Initialize left and right indices
l, r = 0, 0

# Iterate through the array 'a'
for i in range(n):
	# Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
	while r+1 < n and (a[r]-a[l])*(a[r+1]-a[r]) >= 0:
		r += 1

	# Increment the answer variable
	ans += 1

	# Update the index 'i' to 'r' for the next iteration
	i = r

# Print the answer
puts(ans)

# 