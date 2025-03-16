
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function out is used to print the output to the console
def out(x):
	#	fmt.Println(x...)

# Initialize scanner for reading input from stdin
sc = bufio.Scanner(os.Stdin)

# Function nextInt reads an integer from the input
def nextInt():
	sc.Scan()
	i, e = strconv.Atoi(sc.Text())
	if e != nil:
		panic(e)
	return i

# Function nextString reads a string from the input
def nextString():
	sc.Scan()
	return sc.Text()

# Define a type Data to represent a single data point
class Data:
	def __init__(self, x):
		self.x = x

# Define a type Datas as a slice of Data
class Datas(list):
	def __init__(self, x):
		self.x = x

# Implement Len method for Datas type to get the length of the slice
def (p Datas) Len():
	return len(p)

# Implement Swap method for Datas type to swap elements in the slice
def (p Datas) Swap(i, j):
	p[i], p[j] = p[j], p[i]

# Implement Less method for Datas type to sort the slice based on X field
def (p Datas) Less(i, j):
	return p[i].X < p[j].X

# Main function starts here
def main():
	# Initialize scanner for reading input from stdin
	sc.Split(bufio.ScanWords)

	# Read number of data points N from the input
	N = nextInt()

	# Read number of queries L from the input
	L = nextInt()

	# Initialize a slice of Data type named s with capacity N
	s = Datas(N)

	# Read data points X from the input and store them in the slice s
	for i in range(N):
		s[i].X = nextString()

	# Print the number of data points N, number of queries L, and the slice s
	out(N, L, s)

	# Sort the slice s in ascending order based on X field
	sort.Sort(s)

	# Initialize an empty string ans to store the concatenated X values
	ans = ""

	# Iterate through the slice s and concatenate X values to the string ans
	for i in range(N):
		ans = ans + s[i].X

	# Print the concatenated string ans to the console
	print(ans)

# 