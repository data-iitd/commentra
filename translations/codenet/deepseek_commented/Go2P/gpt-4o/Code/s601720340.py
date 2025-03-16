import sys
import math
import argparse
from collections import defaultdict

# Constants
magic = 1000000007

# Argument parser for profiling
parser = argparse.ArgumentParser()
parser.add_argument('--cpuprofile', type=str, help='write cpu profile to file')
parser.add_argument('--memprofile', type=str, help='write mem profile to file')
args = parser.parse_args()

# Variables
N = 0
p = []

# Function to check if a number exists in the array p
def find(n):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

# Main function that handles the program logic
def solve():
    global N, p
    io = Io()
    
    # Read input
    X = io.next_int()
    N = io.next_int()
    p = [io.next_int() for _ in range(N)]

    # Search for the closest number to X in the array p
    for i in range(101):
        if find(X - i) == 1:
            print(X - i)
            sys.exit(0)
        if find(X + i) == 1:
            print(X + i)
            sys.exit(0)

# Input/output helper class
class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.next_token = 0

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        while self.next_token >= len(self.tokens):
            line = self.next_line()
            self.tokens = line.split()
            self.next_token = 0
        r = self.tokens[self.next_token]
        self.next_token += 1
        return r

    def next_int(self):
        return int(self.next())

    def next_float(self):
        return float(self.next())

    def flush(self):
        self.writer.flush()

# Main entry point of the program
if __name__ == "__main__":
    if args.cpuprofile:
        import cProfile
        cProfile.run('solve()', args.cpuprofile)

    solve()

    if args.memprofile:
        import tracemalloc
        tracemalloc.start()
        snapshot = tracemalloc.take_snapshot()
        snapshot.dump(args.memprofile)

# Utility functions
def int_min(a, b):
    return a if a < b else b

def int_max(a, b):
    return a if a > b else b

def combination(n, m):
    if m > n:
        return 0
    elif m == n or m == 0:
        return 1
    else:
        res = 1
        for i in range(m):
            res *= (n - i)
        for i in range(1, m + 1):
            res //= i
        return res

def lucas(n, m, p):
    ntemp = n
    mtemp = m
    res = 1
    for _ in range(100):
        nreminder = ntemp % p
        ntemp //= p
        mreminder = mtemp % p
        mtemp //= p
        res *= combination(nreminder, mreminder) % p
        if ntemp == 0:
            break
    return res % p

def comb_mod(n, m, p):
    return lucas(n, m, p)

def bfs(start, nodes, fn):
    frontier = [start]
    visited = {}

    while frontier:
        next_frontier = []
        for node in frontier:
            visited[node] = True
            fn(node)
            for n in bfs_frontier(node, nodes, visited):
                next_frontier.append(n)
        frontier = next_frontier

def bfs_frontier(node, nodes, visited):
    next_nodes = []
    for n in nodes[node]:
        if n not in visited:
            next_nodes.append(n)
    return next_nodes

def dfs(node, nodes, fn):
    dfs_recur(node, nodes, {}, fn)

def dfs_recur(node, nodes, visited, fn):
    visited[node] = True
    fn(node)
    for n in nodes[node]:
        if n not in visited:
            dfs_recur(n, nodes, visited, fn)

def dfs2(node, nodes, fn1, fn2):
    dfs2_recur(node, -1, nodes, {}, fn1, fn2)

def dfs2_recur(node, parent, nodes, visited, fn1, fn2):
    visited[node] = True
    if fn1:
        fn1(node, parent)
    for n in nodes[node]:
        if n not in visited:
            dfs2_recur(n, node, nodes, visited, fn1, fn2)
    if fn2:
        fn2(node, parent)

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def len(self):
        return self.size

    def push(self, value):
        self.top = Element(value, self.top)
        self.size += 1

    def pop(self):
        if self.size > 0:
            value = self.top.value
            self.top = self.top.next
            self.size -= 1
            return value
        return None

class Element:
    def __init__(self, value, next):
        self.value = value
        self.next = next

def power_int(n, p):
    return p ** n

def find_divisors(n):
    divisors = []
    if n == 1:
        return divisors

    sqrt = int(math.sqrt(n))
    for i in range(2, sqrt + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
    divisors.append(n)
    return divisors

def remove_duplicate(a):
    return list(set(a))

def abs_value(a):
    return a if a > 0 else -a

def gcd(a, b):
    while a != 0:
        a, b = b % a, a
    return b

def power2mod(n, mod):
    res, x = 1, 2
    while n > 0:
        if n & 1 == 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res

def power2(n):
    return power2mod(n, magic)

# End of code
# <END-OF-CODE>
