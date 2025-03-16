
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

# out is a utility function to print output to the console.
def out(x):
	print(x)

# sc is a scanner for reading input from standard input.
sc = bufio.Scanner(os.Stdin)

# getInt reads an integer from input and returns it.
def getInt():
	sc.scan() # Read the next token from input
	i, e = strconv.Atoi(sc.text()) # Convert the token to an integer
	if e != None:
		raise e # Panic if conversion fails
	return i # Return the integer

# getString reads a string from input and returns it.
def getString():
	sc.scan() # Read the next token from input
	return sc.text() # Return the string

# max returns the maximum of two integers.
def max(a, b):
	if a > b:
		return a
	return b

# min returns the minimum of two integers.
def min(a, b):
	if a < b:
		return a
	return b

# asub returns the absolute difference between two integers.
def asub(a, b):
	if a > b:
		return a - b
	return b - a

# abs returns the absolute value of an integer.
def abs(a):
	if a >= 0:
		return a
	return -a

# lowerBound returns the index of the first element in a that is not less than x.
def lowerBound(a, x):
	idx = sort.search(len(a), lambda i: a[i] >= x)
	return idx

# upperBound returns the index of the first element in a that is greater than x.
def upperBound(a, x):
	idx = sort.search(len(a), lambda i: a[i] > x)
	return idx

# shop represents a shop with a price (a) and available quantity (b).
class shop:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Datas is a slice of shop, implementing sort.Interface.
class Datas(list):
	def __lt__(self, other):
		return self.a < other.a

# main is the entry point of the program.
def main():
	sc.split(bufio.ScanWords) # Split input by whitespace

	# Read the number of shops (N) and the total quantity needed (M)
	N, M = getInt(), getInt()
	s = Datas() # Create a slice to hold the shops

	# Read the price and quantity for each shop
	for i in range(N):
		a, b = getInt(), getInt() # Read price (a) and quantity (b)
		s.append(shop(a, b)) # Store the shop information
	s.sort() # Sort the shops by price

	total = 0 # Initialize total cost
	# Calculate the total cost based on available quantities and prices
	for e in s:
		n = min(e.b, M) # Determine how much can be bought from this shop
		total += n * e.a # Add to total cost
		M -= n # Decrease the remaining quantity needed
		if M == 0:
			break # Stop if the required quantity is met
	out(total) # Output the total cost

