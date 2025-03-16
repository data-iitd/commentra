
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

# Helper function to print output.
def out(x):
	print(x)

# Scanner to read input from standard input.
sc = bufio.Scanner(os.Stdin)

# Function to read an integer from input.
def getInt():
	sc.scan()
	i, e = strconv.Atoi(sc.text())
	if e != None:
		raise e
	return i

# Function to read a string from input.
def getString():
	sc.scan()
	return sc.text()

# Function to return the maximum of two integers.
def max(a, b):
	if a > b:
		return a
	return b

# Function to return the minimum of two integers.
def min(a, b):
	if a < b:
		return a
	return b

# Function to return the absolute difference between two integers.
def asub(a, b):
	if a > b:
		return a - b
	return b - a

# Function to return the absolute value of an integer.
def abs(a):
	if a >= 0:
		return a
	return -a

# Function to find the lower bound index of a value in a sorted array.
def lowerBound(a, x):
	idx = sort.Search(len(a), lambda i: a[i] >= x)
	return idx

# Function to find the upper bound index of a value in a sorted array.
def upperBound(a, x):
	idx = sort.Search(len(a), lambda i: a[i] > x)
	return idx

# Struct to represent a shop with its price and stock.
class shop:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Slice of shops to implement sorting.
class Datas(list):
	def __lt__(self, other):
		return self.a < other.a

# Main function to execute the program logic.
def main():
	sc.split(bufio.ScanWords)

	# Read the number of shops and the amount of items to buy.
	N, M = getInt(), getInt()

	# Create a slice of shops and read each shop's price and stock.
	s = Datas()
	for i in range(N):
		a, b = getInt(), getInt()
		s.append(shop(a, b))

	# Sort the shops by price.
	s.sort()

	# Calculate the total cost of buying the required number of items.
	total = 0
	for e in s:
		# Determine the number of items to buy from the current shop.
		n = min(e.b, M)
		# Update the total cost and the remaining items to buy.
		total += n * e.a
		M -= n
		# Break if all items are bought.
		if M == 0:
			break

	# Print the total cost.
	out(total)

# 