
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants for buffer sizes and modulo value
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
	mod            = 1e9 + 7
)

// Scanner for reading input
var (
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords)
		return sc
	}()
)

// Main function
def main():
	# Read an integer N from input
	N = getInt()
	# Calculate the integer square root of N
	sqrtN = int(math.sqrt(float(N)))

	# Initialize min to N, which will hold the minimum value found
	min = N
	# Iterate through all possible divisors of N
	for i in range(1, sqrtN + 1):
		# If i is not a divisor of N, skip to the next iteration
		if N % i != 0:
			continue

		# Calculate the value based on the divisor and its complement
		num = i + (N // i) - 2
		# Update min if the new value is smaller
		if num < min:
			min = num

	# Print the minimum value found
	print(min)

# Helper function to read an integer from input
def getInt():
	sc.scan()
	i, e = strconv.atoi(sc.text())
	if e != None:
		raise e
	return i

# Helper function to read a string from input
def getString():
	sc.scan()
	return sc.text()

# Function to return the absolute value of an integer
def abs(a):
	return int(math.fabs(float(a)))

# Function to compute p raised to the power of q
def pow(p, q):
	return int(math.pow(float(p), float(q)))

# Function to compute (n^p) % mod using exponentiation by squaring
def powMod(n, p):
	if p == 0:
		return 1
	elif p % 2 == 0:
		t = powMod(n, p // 2)
		return calcMod(t * t)
	else:
		return calcMod(n * powMod(n, p - 1))

# Function to find the minimum value among a variable number of integers
def min(*nums):
	if len(nums) == 0:
		raise ValueError("function min() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = min(res, nums[i])
	return res

# Function to find the maximum value among a variable number of integers
def max(*nums):
	if len(nums) == 0:
		raise ValueError("function max() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = max(res, nums[i])
	return res

# Function to check if a string exists in a slice of strings
def strSearch(a, b):
	for i in range(len(a)):
		if a[i] == b:
			return True
	return False

# Function to print an integer array in a formatted way
def printIntArray(array):
	strArray = str(array)
	print(strArray[1 : len(strArray) - 1])

# Function to calculate x % mod
def calcMod(x):
	return x % mod

# Function to reverse a string
def reverse(s):
	runes = list(s)
	for i, j in zip(range(len(runes)), range(len(runes) - 1, -1, -1)):
		runes[i], runes[j] = runes[j], runes[i]
	return "".join(runes)

# Function to check if a number is prime
def isPrime(n):
	if n < 2:
		return False
	elif n == 2:
		return True
	elif n % 2 == 0:
		return False

	# Check for factors from 3 to the square root of n
	sqrtN = int(math.sqrt(float(n)))
	for i in range(3, sqrtN + 1, 2):
		if n % i == 0:
			return False

	return True

# END-OF-CODE
