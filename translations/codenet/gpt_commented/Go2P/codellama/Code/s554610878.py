
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants for buffer sizes
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
)

// Global variables for scanner and modulus
var (
	// Initialize a buffered scanner for reading input
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords) // Split input by words
		return sc
	}()
	mod int = 1e9 + 7 // Modulus value for calculations
)

func main() {
	// Array representing the days of the week
	week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
	
	# Get the input day as a string
	s = getString()
	index = -1 # Initialize index to -1 to indicate not found

	# Search for the input day in the week array
	for i, day in enumerate(week):
		if s == day:
			index = i # Update index if the day is found
			break

	# Calculate and print the number of days until the next Sunday
	print(7 - index)
}

# Function to read an integer from input
def getInt():
	sc.scan() # Scan the next token
	i, e = strconv.atoi(sc.text()) # Convert the scanned text to an integer
	if e != None:
		raise e # Panic if there is an error in conversion
	return i # Return the integer value

# Function to read a string from input
def getString():
	sc.scan() # Scan the next token
	return sc.text() # Return the scanned text as a string

# Function to compute the absolute value of an integer
def abs(a):
	return int(math.fabs(a)) # Use math.fabs to get the absolute value

# Function to compute p raised to the power of q
def pow(p, q):
	return int(math.pow(p, q)) # Use math.pow for exponentiation

# Function to find the minimum value among given integers
def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.") # Panic if no arguments are provided
	res = nums[0] # Initialize result with the first number
	for i in range(len(nums)):
		res = int(min(res, nums[i])) # Update result with the minimum value
	return res # Return the minimum value

# Function to find the maximum value among given integers
def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.") # Panic if no arguments are provided
	res = nums[0] # Initialize result with the first number
	for i in range(len(nums)):
		res = int(max(res, nums[i])) # Update result with the maximum value
	return res # Return the maximum value

# Function to check if a string exists in a slice of strings
def strSearch(a, b):
	for i in range(len(a)):
		if a[i] == b:
			return True # Return true if the string is found
	return False # Return false if the string is not found

# Function to print an array of integers
def printIntArray(array):
	strArray = str(array) # Convert the array to a string
	print(strArray[1 : len(strArray)-1]) # Print the string representation without brackets

# Function to calculate the modulus of x with respect to the defined mod
def calcMod(x):
	return x % mod # Return the result of x modulo mod


