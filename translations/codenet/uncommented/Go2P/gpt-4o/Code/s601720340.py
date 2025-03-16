import sys
import math
import argparse
from collections import defaultdict

magic = 1000000007

def find(n, p, N):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

def solve():
    io = Io()
    
    # PARSE HELPER SESSION
    X = io.next_int()
    N = io.next_int()
    p = [io.next_int() for _ in range(N)]
    
    for i in range(101):
        if find(X - i, p, N) == 1:
            print(X - i)
            sys.exit(0)
        if find(X + i, p, N) == 1:
            print(X + i)
            sys.exit(0)

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        return self.next_line().split()

    def next_int(self):
        return int(self.next()[0])

    def next_float(self):
        return float(self.next()[0])

    def print_ln(self, *args):
        print(*args, file=self.writer)

    def flush(self):
        self.writer.flush()

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
        res *= (combination(nreminder, mreminder) % p)
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

if __name__ == "__main__":
    solve()

# <END-OF-CODE>
