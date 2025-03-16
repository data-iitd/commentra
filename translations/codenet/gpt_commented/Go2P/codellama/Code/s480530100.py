
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// out is a utility function to print output to the console.
def out(x):
	print(x)

# Initialize a new scanner to read input from standard input.
sc = bufio.Scanner(sys.stdin)

# getInt reads an integer from input and returns it.
# It panics if the input cannot be converted to an integer.
def getInt():
	sc.scan()
	i, e = strconv.Atoi(sc.text())
	if e != None:
		panic(e)
	return i

# getString reads a string from input and returns it.
def getString():
	sc.scan()
	return sc.text()

def main():
	# Set the scanner to split input by whitespace and allocate a large buffer.
	sc.split(bufio.ScanWords)
	sc.buffer(bytearray(), 1000000)

	# Read the number of elements (n) and the number of queries (q).
	n, q = getInt(), getInt()

	# Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	fw = FenwickTree(n)

	# Read n integers and add them to the Fenwick Tree.
	for i in range(n):
		a = getInt()
		fw.add(i, a)

	# Process q queries.
	for i in range(q):
		t = getInt() # Read the type of query.
		if t == 0:
			# For update queries, read position (p) and value (x) and update the Fenwick Tree.
			p, x = getInt(), getInt()
			fw.add(p, x)
		else:
			# For sum queries, read the range (l, r) and output the sum from l to r.
			l, r = getInt(), getInt()
			out(fw.sum(l, r))

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s += b.data[r-1] # Add the value at index r-1
		r -= r & -r      # Move to the parent index
	return s # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0] * n # Create a slice to hold the tree data

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
	return BIT(n)

# Add updates the Fenwick Tree by adding x to the element at position p.
def (b *BIT) Add(p, x):
	p++ # Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n:
		b.data[p-1] += x # Update the tree data
		p += p & -p      # Move to the next index

# Sum calculates the sum of elements in the range [l, r).
def (b *BIT) Sum(l, r):
	return b.sum(r) - b.sum(l) # Return the difference of sums

# sum calculates the prefix sum from the start to index r.
def (b *BIT) sum(r):
	s = 0 # Initialize sum
	for r > 0:
		s +=