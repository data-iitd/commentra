
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

# out is a utility function for printing output, currently commented out.
def out(x):
	#	print(x)

# sc is a scanner for reading input from standard input.
sc = bufio.Scanner(os.Stdin)

# nextInt reads the next integer from input and returns it.
def nextInt():
	sc.scan() # Scan the next token from input
	i, e = strconv.Atoi(sc.text()) # Convert the scanned text to an integer
	if e != None:
		raise e # Panic if there is an error in conversion
	return i # Return the integer value

# nextString reads the next string from input and returns it.
def nextString():
	sc.scan() # Scan the next token from input
	return sc.text() # Return the scanned text

# Data represents a single data entry with a string field.
class Data:
	def __init__(self, x):
		self.x = x

# Datas is a slice of Data, implementing sort.Interface.
class Datas(list):
	def __init__(self, x):
		self.x = x

	def Len(self):
		return len(self.x)

	def Swap(self, i, j):
		self.x[i], self.x[j] = self.x[j], self.x[i]

	def Less(self, i, j):
		return self.x[i].x < self.x[j].x # Sort based on the string field X

def main():
	sc.split(bufio.ScanWords) # Set the scanner to split input by words
	N = nextInt() # Read the number of data entries
	L = nextInt() # Read an additional integer (not used further in the code)
	s = Datas([Data(nextString()) for i in range(N)]) # Create a slice of Datas with length N

	# Read N strings into the slice s
	for i in range(N):
		s[i].x = nextString() # Populate each Data entry with a string

	out(N, L, s) # Output the initial values (commented out)
	s.sort() # Sort the slice of Data entries
	out(s) # Output the sorted slice (commented out)

	# Concatenate all strings in the sorted slice into a single result
	ans = ""
	for i in range(N):
		ans = ans + s[i].x # Append each string to ans
	print(ans) # Print the concatenated result

