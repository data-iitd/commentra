
import math
import sys

# Constants for buffer sizes and modulo value
initial_buf_size = 10000
max_buf_size = 1000000
mod = 100000007

# Scanner for reading input
sc = None

# Main function
def main():
    global sc
    sc = bufio.Scanner(sys.stdin)
    sc.buffer(bytearray(initial_buf_size), max_buf_size)
    sc.token_compress(True)

    # Read an integer N from input
    N = getInt()
    # Calculate the integer square root of N
    sqrtN = int(math.sqrt(N))

    # Initialize min to N, which will hold the minimum value found
    min = N
    # Iterate through all possible divisors of N
    for i in range(1, sqrtN + 1):
        # If i is not a divisor of N, skip to the next iteration
        if N % i!= 0:
            continue

        # Calculate the value based on the divisor and its complement
        num = i + (N // i) - 2
        # Update min if the new value is smaller
        if num < min:
            min = num

    # Print the minimum value found
    print(min)

# Graph structure to represent a graph with n nodes
class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

# Depth-first search (DFS) algorithm to traverse the graph
def dfs(c, edges, visited):
    # Mark the current node as visited
    visited[c] = True

    # Recursively visit all adjacent nodes
    for v in edges[c]:
        if not visited[v]:
            dfs(v, edges, visited)

# Helper function to read an integer from input
def getInt():
    sc.scan()
    return int(sc.token())

# Helper function to read a string from input
def getString():
    sc.scan()
    return sc.token().decode()

# Function to return the absolute value of an integer
def abs(a):
    return int(math.fabs(a))

# Function to compute p raised to the power of q
def pow(p, q):
    return int(math.pow(p, q))

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
    for num in nums:
        res = min(res, num)
    return res

# Function to find the maximum value among a variable number of integers
def max(*nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")
    res = nums[0]
    for num in nums:
        res = max(res, num)
    return res

# Function to check if a string exists in a slice of strings
def strSearch(a, b):
    return b in a

# Function to print an integer array in a formatted way
def printIntArray(array):
    print("[{}]".format(", ".join(map(str, array))))

# Function to calculate x % mod
def calcMod(x):
    return x % mod

# Function to reverse a string
def reverse(s):
    return s[::-1]

# Function to check if a number is prime
def isPrime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    # Check for factors from 3 to the square root of n
    sqrtN = int(math.sqrt(n))
    for i in range(3, sqrtN + 1, 2):
        if n % i == 0:
            return False

    return True

# Translate the above Go code to Python and end with comment "