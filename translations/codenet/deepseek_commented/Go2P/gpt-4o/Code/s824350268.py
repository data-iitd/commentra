import sys
import math

initial_buf_size = 10000
max_buf_size = 1000000
mod = int(1e9 + 7)

# Function to read an integer from standard input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to calculate the minimum sum of divisors of N
def main():
    N = get_int()  # Read the integer N from standard input
    sqrtN = int(math.sqrt(N))

    min_sum = N  # Initialize min_sum with N
    for i in range(1, sqrtN + 1):
        if N % i != 0:  # Check if i is a divisor of N
            continue

        num = i + (N // i) - 2  # Calculate the sum of the divisor and its complement
        if num < min_sum:  # Update min_sum if the current sum is smaller
            min_sum = num

    print(min_sum)  # Print the minimum sum found

# Graph class to represent a graph with n vertices and edges
class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

# Depth-first search function
def dfs(c, edges, visited):
    visited.add(c)  # Mark the current vertex as visited

    for v in edges[c]:
        if v in visited:
            continue
        dfs(v, edges, visited)  # Recursively visit unvisited neighbors

# Function to calculate the absolute value of a
def abs_val(a):
    return abs(a)

# Function to calculate p raised to the power of q
def pow_func(p, q):
    return p ** q

# Function to calculate n raised to the power of p modulo mod
def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

# Function to return the minimum value among the provided integers
def min_func(*nums):
    if len(nums) == 0:
        raise ValueError("function min_func() requires at least one argument.")
    return min(nums)

# Function to return the maximum value among the provided integers
def max_func(*nums):
    if len(nums) == 0:
        raise ValueError("function max_func() requires at least one argument.")
    return max(nums)

# Function to check if b is present in the list a
def str_search(a, b):
    return b in a

# Function to print the elements of an integer array
def print_int_array(array):
    print(array)

# Function to return x modulo mod
def calc_mod(x):
    return x % mod

# Function to reverse a given string
def reverse(s):
    return s[::-1]

# Function to check if n is a prime number
def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    sqrtN = int(math.sqrt(n))
    for i in range(3, sqrtN + 1, 2):
        if n % i == 0:
            return False

    return True

if __name__ == "__main__":
    main()

# <END-OF-CODE>
