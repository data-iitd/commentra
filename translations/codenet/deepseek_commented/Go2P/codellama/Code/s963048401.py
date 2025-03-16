
# Go:
package main

import (
	"bufio" # For efficient I/O operations
	"fmt"   # For formatted I/O operations
	"os"    # For file operations
	"sort"  # For sorting operations
	"strconv" # For string conversion operations
)

# Scanner reads a single line of input
def Scanner():
	sc.Scan()
	return sc.Text()

# intScanner reads an integer from input
def intScanner():
	n, _ = strconv.Atoi(Scanner())
	return n

# floatScanner reads a float64 from input
def floatScanner():
	n, _ = strconv.ParseFloat(Scanner(), 64)
	return n

# stringToInt converts a string to an integer
def stringToInt(s):
	n, _ = strconv.Atoi(s)
	return n

# mod is a global variable for storing a modulus value
mod = 1000000007

# main function initializes the modulus value, sets up the bufio.Scanner, and reads the number of elements
def main():
	buf = make([]byte, 0)
	sc.Buffer(buf, mod)
	sc.Split(bufio.ScanWords)
	n = intScanner()
	as = make([]int, n)
	for i in range(n):
		as[i] = intScanner()
	
	# Initialize xs with the first element of as
	xs = [as[0]]
	for j in range(1, n):
		# Use sort.Search to find the position to insert the current element
		idx = sort.Search(len(xs), lambda i: xs[i] < as[j])
		if idx == len(xs):
			# If the element is larger than all elements in xs, append it
			xs.append(as[j])
		else:
			# Otherwise, replace the existing element at the found position
			xs[idx] = as[j]
	
	# Print the length of the longest increasing subsequence found
	print(len(xs))

# 