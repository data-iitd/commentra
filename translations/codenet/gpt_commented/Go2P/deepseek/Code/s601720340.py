import sys
import math
from collections import deque

# Define a large prime number for modulo operations
magic = 1000000007

# Command-line flags for CPU and memory profiling
cpuprofile = ''
memprofile = ''

N = 0
p = [0] * 200000

# Function to check if a number exists in the array p
def find(n):
    for i in range(N):
        if n == p[i]:
            return 0  # Number found
    return 1  # Number not found

# Main solving function
def solve():
    io = Io()  # Create a new IO instance for input/output
    X = io.next_int()  # Read an integer
    N = io.next_int()  # Read the size of the array
    for i in range(N):
        p[i] = io.next_int()  # Read integers into the array p

    # Check for numbers around X that are not in the array p
    for i in range(101):
        if find(X - i) == 1:  # Check X - i
            print(X - i)  # Print the result
            sys.exit(0)  # Exit the program
        if find(X + i) == 1:  # Check X + i
            print(X + i)  # Print the result
            sys.exit(0)  # Exit the program

# Main function to execute the program
def main():
    global cpuprofile, memprofile
    if cpuprofile != '':
        f = open(cpuprofile, 'w')  # Create CPU profile file
        sys.stdout = f
        sys.stderr = f
        sys.stdout.flush()
        sys.stderr.flush()
        import cProfile
        cProfile.run('solve()', filename=cpuprofile)  # Start CPU profiling
        f.close()  # Close the file when done
    else:
        solve()  # Call the solve function

    if memprofile != '':
        import os
        import pstats
        from io import StringIO
        out = StringIO()
        prof = cProfile.Profile()
        prof.enable()
        solve()
        prof.disable()
        stats = pstats.Stats(prof, stream=out).sort_stats('cumulative')
        stats.dump_stats(memprofile)  # Write memory profile to file
        with open(memprofile, 'w') as f:
            f.write(out.getvalue())  # Write the output to the file

# Libraries

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.nextToken = 0

    def flush(self):
        self.writer.flush()  # Flush the writer buffer

    def next_line(self):
        buffer = []
        while not self.tokens:
            line = self.reader.readline()  # Read a line
            buffer.append(line)  # Append line to buffer
        return buffer[-1]  # Return the last line

    def next(self):
        while self.nextToken >= len(self.tokens):
            line = self.next_line()  # Read the next line
            self.tokens = line.split()  # Split line into tokens
        r = self.tokens[self.nextToken]  # Get the next token
        self.nextToken += 1  # Move to the next token
        return r  # Return the token

    def next_int(self):
        return int(self.next())  # Convert the next token to int

    def next_float(self):
        return float(self.next())  # Convert the next token to float

    def print_ln(self, a):
        print(*a, file=self.writer)  # Write to buffer with linefeed

    def print_f(self, format, a):
        print(format % a, file=self.writer)  # Write formatted output to buffer

    def print_int_ln(self, a):
        self.print_ln([str(x) for x in a])  # Print the integers in a single line

    def print_string_ln(self, a):
        self.print_ln(a)  # Print the strings in a single line

# Helper functions for mathematical operations

# Returns the minimum of two integers
def int_min(a, b):
    return a if a < b else b

# Returns the maximum of two integers
def int_max(a, b):
    return a if a > b else b

# Direct calculation of combination
# n, m should be "small"
def combination(n, m):
    if m > n:
        return 0  # Not possible to choose more than available
    elif m == n or m == 0:
        return 1  # Only one way to choose all or none
    else:
        res = 1
        for i in range(m):
            res *= (n - i)  # Calculate numerator
        for i in range(1, m + 1):
            res //= i  # Calculate denominator
        return res  # Return the combination result

# Calculate combination modulo based on Lucas theorem
def lucas(n, m, p):
    res = 1
    ntemp, mtemp = n, m
    while True:
        nreminder = ntemp % p  # Remainder of n
        ntemp //= p  # Update n
        mreminder = mtemp % p  # Remainder of m
        mtemp //= p  # Update m
        res *= combination(nreminder, mreminder) % p  # Combine results
        if ntemp == 0:
            break  # Break if n is exhausted
    return res % p  # Return the result modulo p

# Wrapper function for combination modulo
def comb_mod(n, m, p):
    return lucas(n, m, p)  # Call lucas function

# Breadth-First Search (BFS) implementation
def bfs(start, nodes, fn):
    frontier = deque([start])  # Initialize the frontier with the start node
    visited = set()  # Track visited nodes

    while frontier:
        node = frontier.popleft()  # Get the next node from the frontier
        if node not in visited:
            visited.add(node)  # Mark the node as visited
            fn(node)  # Execute the provided function on the node
            for n in bfs_frontier(node, nodes, visited):
                frontier.append(n)  # Add unvisited neighbors to the frontier

# Helper function to get unvisited neighbors for BFS
def bfs_frontier(node, nodes, visited):
    return [n for n in nodes[node] if n not in visited]  # Return unvisited neighbors

# Depth-First Search (DFS) implementation
def dfs(node, nodes, fn):
    visited = set()  # Track visited nodes
    dfs_recur(node, nodes, visited, fn)  # Start the recursive DFS

# Recursive DFS helper function
def dfs_recur(node, nodes, visited, fn):
    visited.add(node)  # Mark the node as visited
    fn(node)  # Execute the provided function on the node
    for n in nodes[node]:
        if n not in visited:
            dfs_recur(n, nodes, visited, fn)  # Recursively visit unvisited neighbors

# DFS with two functions: one before entering child tree, and another after
def dfs2(node, nodes, fn1, fn2):
    visited = set()  # Track visited nodes
    dfs2_recur(node, -1, nodes, visited, fn1, fn2)  # Start the recursive DFS with parent tracking

# Recursive DFS helper function with parent tracking
def dfs2_recur(node, parent, nodes, visited, fn1, fn2):
    visited.add(node)  # Mark the node as visited
    if fn1:
        fn1(node, parent)  # Execute the first function
    for n in nodes[node]:
        if n not in visited:
            dfs2_recur(n, node, nodes, visited, fn1, fn2)  # Recursively visit unvisited neighbors
    if fn2:
        fn2(node, parent)  # Execute the second function

# Stack data structure implementation
class Stack:
    def __init__(self):
        self.top = None  # Pointer to the top element
        self.size = 0  # Size of the stack

    def len(self):
        return self.size  # Return the size of the stack

    def push(self, value):
        self.top = Element(value, self.top)  # Create a new element and set it as the top
        self.size += 1  # Increment the size

    def pop(self):
        if self.size > 0:
            value, self.top = self.top.value, self.top.next  # Get the top value and update the top pointer
            self.size -= 1  # Decrement the size
            return value  # Return the value
        return None  # Return None if the stack is empty

# Element is a struct for stack element
class Element:
    def __init__(self, value, next):
        self.value = value  # Value of the element
        self.next = next  # Pointer to the next element

# Power function for integer parameters
def power_int(n, p):
    tmp = 1
    for _ in range(n):
        tmp *= p  # Calculate p^n
    return tmp  # Return the result

# Function to find divisors of a number
def find_divisors(n, a):
    if n == 1:
        return  # 1 has no divisors

    sqrt = int(math.sqrt(n))  # Calculate the square root of n
    for i in range(2, sqrt + 1):
        if n % i == 0:
            a.append(i)  # Append divisor i
            a.append(n // i)  # Append corresponding divisor n // i
    a.append(n)  # Append n itself as a divisor

# Function to remove duplicates from a list
def remove_duplicate(a):
    return list(set(a))  # Return a list of unique values

# Function to calculate the absolute value
def abs(a):
    return a if a > 0 else -a  # Return the absolute value

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    while a != 0:
        a, b = b % a, a  # Euclidean algorithm
    return b  # Return the GCD

# Function to calculate power of 2 modulo a given number
def power2mod(n, mod):
    res, x = 1, 2
    for _ in range(n):
        res = res * x % mod  # Update result
        x = x * x % mod  # Square the base
    return res  # Return the result

# Function to calculate power of 2 with modulo magic
def power2(n):
    return power2mod(n, magic)  # Call power2mod with magic

