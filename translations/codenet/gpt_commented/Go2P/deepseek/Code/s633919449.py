import sys
import math
from collections import deque

# Constants for buffer sizes and modulo value
initialBufSize = 10000
maxBufSize = 1000000
mod = 10**9 + 7

# Scanner for reading input
input = sys.stdin.readline

def main():
    # Read an integer input
    N = int(input().strip())

    # Determine the output based on the last digit of N
    match N % 10:
        case 2 | 4 | 5 | 7 | 9:
            print("hon")
        case 0 | 1 | 6 | 8:
            print("pon")
        case 3:
            print("bon")

# Graph structure to represent edges
class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

# Depth-first search (DFS) algorithm implementation
def dfs(c, edges, visited):
    visited.add(c)

    # Visit all adjacent nodes recursively
    for v in edges[c]:
        if v in visited:
            continue
        dfs(v, edges, visited)

# Breadth-first search (BFS) algorithm implementation
def bfs(c, graph):
    next_queue = deque([c])
    visited = set([c])

    # Continue until there are no more nodes to visit
    while next_queue:
        u = next_queue.popleft()
        visited.add(u)

        # Process each adjacent node
        for v in graph.edges[u]:
            if v in visited:
                continue

            # Placeholder for processing the node (e.g., marking, counting, etc.)

            next_queue.append(v)

# Function to read an integer from input
def get_int():
    return int(input().strip())

# Function to read an array of integers from input
def get_int_array(n):
    return [int(input().strip()) for _ in range(n)]

# Function to read a string from input
def get_string():
    return input().strip()

# Function to read an array of strings from input
def get_string_array(n):
    return [input().strip() for _ in range(n)]

# Function to calculate the absolute value of an integer
def abs(a):
    return abs(a)

# Function to calculate p raised to the power of q
def pow(p, q):
    return p**q

# Function to calculate n raised to the power of p modulo mod
def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return (t * t) % mod
    else:
        return (n * pow_mod(n, p - 1)) % mod

# Function to find the minimum value among a list of integers
def min(nums):
    return min(nums)

# Function to find the maximum value among a list of integers
def max(nums):
    return max(nums)

# Function to check if a string exists in an array of strings
def str_search(a, b):
    return b in a

# Function to print an array of integers
def print_int_array(array):
    print(array)

# Function to calculate x modulo mod
def calc_mod(x):
    return x % mod

# Function to reverse a string
def reverse(s):
    return s[::-1]

# Function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    return True

# Function to check if an integer exists in a slice
def contains(s, e):
    return e in s

# Function to create a range of integers from min to max
def make_range(min, max):
    return list(range(min, max + 1))

# Function to generate the powerset of a given slice of integers
def powerset(nums):
    length = 2**len(nums)
    result = [[]]

    for num in nums:
        new_subsets = [subset + [num] for subset in result]
        result.extend(new_subsets)

    return result

# Function to calculate the greatest common divisor (GCD) of two integers
def calc_gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

# Function to get all divisors of a number
def get_divisor(n):
    divisors = set([1, n])
    sqrt_n = int(math.sqrt(n))

    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)

    return list(divisors)

# Custom heap type for integers
class intHeap(list):
    def push(self, x):
        super().append(x)
        self.up(len(self) - 1)

    def pop(self):
        if len(self) > 1:
            self[0], self[-1] = self[-1], self[0]
        x = super().pop()
        self.down(0)
        return x

    def up(self, j):
        parent = (j - 1) // 2
        while j > 0 and self[j] < self[parent]:
            self[j], self[parent] = self[parent], self[j]
            j = parent
            parent = (j - 1) // 2

    def down(self, j):
        child = 2 * j + 1
        while child < len(self):
            if child + 1 < len(self) and self[child] > self[child + 1]:
                child += 1
            if self[j] <= self[child]:
                break
            self[j], self[child] = self[child], self[j]
            j = child
            child = 2 * j + 1

# Function to initialize a new integer heap
def init_heap():
    return intHeap()

# Push an integer onto the heap
def push_heap(h, n):
    h.push(n)

# Pop an integer from the heap
def pop_heap(h):
    return h.pop()

# Function to calculate factorial modulo mod
def fact_mod(n):
    value = 1
    for i in range(2, n + 1):
        value = (value * i) % mod
    return value

# Function to calculate combinations modulo mod
def combination_mod(n, k):
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_nk = fact_mod(n - k)
    fact_kr = pow_mod(fact_k, mod - 2)
    fact_nkr = pow_mod(fact_nk, mod - 2)
    return (fact_n * fact_kr * fact_nkr) % mod

# Function to find prime factors of a number
def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 1
    if n > 1:
        factors.append(n)
    return factors

