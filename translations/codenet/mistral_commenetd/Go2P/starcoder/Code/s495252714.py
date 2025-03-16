
#=====I/O=====

# Initialize scanner and writer
import sys

# Function to read an integer from standard input
def scanInt():
	return int(input())

# Function to read an integer64 from standard input
def scanInt64():
	return int(input())

# Function to read n integers from standard input
def scanInts(n):
	return [int(input()) for i in range(n)]

# Function to print integers to standard output
def printInts(a):
	for i in range(len(a)):
		print(a[i], end=' ')
	print()

#=====main=====

# Set scanner to scan words
import sys

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
print(ans*pow(4,n-1,mod)%mod)

#=====END-OF-CODE=====

