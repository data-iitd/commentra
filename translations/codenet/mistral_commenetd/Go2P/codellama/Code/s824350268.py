
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants definition
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
	mod            = 1e9 + 7
)

// Variables definition and initialization
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
    # Read the first integer from the standard input
    N = getInt()

    # Calculate the square root of N
    sqrtN = int(math.sqrt(float(N)))

    # Initialize the minimum number with N
    min = N

    # Iterate through all numbers from 1 to the square root of N
    for i in range(1, sqrtN + 1):
        # Check if N is divisible by i
        if N % i != 0:
            continue

        # Calculate the number of divisors of i and N
        num = i + (N // i) - 2

        # Update the minimum number if the current number is smaller
        if num < min:
            min = num

    # Print the minimum number
    print(min)

# Define a Graph data structure
class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def addEdge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

# Depth First Search function
def dfs(c, edges, visited):
    # Mark the current vertex as visited
    visited[c] = 1

    # Iterate through all neighbors of the current vertex
    for v in edges[c]:
        # If the neighbor is already visited, skip it
        if visited[v]:
            continue

        # Recursively call DFS for the neighbor
        dfs(v, edges, visited)

# Helper functions for reading integers and strings from the standard input
def getInt():
    sc.scan()
    i, e = strconv.Atoi(sc.text())
    if e != nil:
        panic(e)
    return i

def getString():
    sc.scan()
    return sc.text()

# Helper functions for basic arithmetic operations
def abs(a):
    return int(math.Abs(float(a)))

def pow(p, q):
    return int(math.Pow(float(p), float(q)))

def powMod(n, p):
    # Base case: if p is 0, return 1
    if p == 0:
        return 1
    elif p % 2 == 0:
        # Recursive case: if p is even, square the base and recursively call powMod
        t = powMod(n, p // 2)
        return calcMod(t * t)
    else:
        # Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
        return calcMod(n * powMod(n, p - 1))

# Helper functions for finding the minimum and maximum values
def min(*nums):
    # Base case: if there are no numbers, panic
    if len(nums) == 0:
        panic("funciton min() requires at least one argument.")

    # Initialize the minimum value with the first number
    res = nums[0]

    # Iterate through all numbers and update the minimum value if necessary
    for i in range(len(nums)):
        res = min(res, nums[i])

    # Return the minimum value
    return res

def max(*nums):
    # Base case: if there are no numbers, panic
    if len(nums) == 0:
        panic("funciton max() requires at least one argument.")

    # Initialize the maximum value with the first number
    res = nums[0]

    # Iterate through all numbers and update the maximum value if necessary
    for i in range(len(nums)):
        res = max(res, nums[i])

    # Return the maximum value
    return res

# Helper function for searching a string in an array of strings
def strSearch(a, b):
    # Iterate through all strings in the array and return true if the target string is found
    for i in range(len(a)):
        if a[i] == b:
            return True

    # If the target string is not found, return false
    return False

# Helper function for printing an integer array
def printIntArray(array):
    # Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
    strArray = str(array)
    print(strArray[1 : len(strArray) - 1])

# Helper function for calculating the modulo operation
def calcMod(x):
    # Calculate the modulo of x with the modulus constant
    return x % mod

# Helper function for reversing a string
def reverse(s):
    # Create a slice of runes from the input string, reverse it in-place, and convert it back to a string
    runes = list(s)
    for i, j in enumerate(range(len(runes))):
        runes[i], runes[j] = runes[j], runes[i]
    return "".join(runes)

# Helper function for checking if a number is prime
def isPrime(n):
    # Base case: if n is less than 2, it is not prime
    if n < 2:
        return False

    # Base case: if n is 2, it is prime
    if n == 2:
        return True

    # Base case: if n is even, it is not prime
    if n % 2 == 0:
        return False

    # Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
    sqrtN = int(math.sqrt(float(n)))
    for i in range(3, sqrtN + 1, 2):
        # If n is divisible by i, it is not prime
        if n % i == 0:
            return False

    # If we have reached here, n is prime
    return True

# Translate the above Go code to Python and end with comment "