# coding: utf-8
# Import required libraries
import re
import math
from collections import defaultdict
import itertools
from copy import deepcopy
import random
from heapq import heappop,heappush
import time
import os
import queue
import sys
import datetime
from functools import lru_cache

# Decorator for function caching (optional)
#@lru_cache(maxsize=None)

# Function to read a line from standard input
readline = sys.stdin.readline

# Set recursion limit (optional)
sys.setrecursionlimit(2000000)

# Define alphabet and modulus constants
alphabet = "abcdefghijklmnopqrstuvwxyz"
mod = int(10**9 + 7)
inf = int(10**20)

# Define helper functions
def yn(b):
    """Print 'yes' if b is True, otherwise print 'no'."""
    if b:
        print("yes")
    else:
        print("no")

def Yn(b):
    """Print 'Yes' if b is True, otherwise print 'No'."""
    if b:
        print("Yes")
    else:
        print("No")

def YN(b):
    """Print 'YES' if b is True, otherwise print 'NO'."""
    if b:
        print("YES")
    else:
        print("NO")

class union_find():
    """Union-Find data structure."""

    def __init__(self, n):
        """Initialize Union-Find data structure with n elements."""
        self.n = n
        self.P = [a for a in range(n)]  # Parent pointers
        self.rank = [0] * n           # Rank of each element

    def find(self, x):
        """Find the root of the tree containing x."""
        if x != self.P[x]:
            self.P[x] = self.find(self.P[x])  # Path compression
        return self.P[x]

    def same(self, x, y):
        """Check if x and y belong to the same tree."""
        return self.find(x) == self.find(y)

    def link(self, x, y):
        """Link x and y together."""
        self.P[x] = y
        self.rank[y] += 1

    def unite(self, x, y):
        """Unite the trees containing x and y."""
        self.link(self.find(x), self.find(y))

    def size(self):
        """Return the number of elements in the Union-Find data structure."""
        return len(set(self.P))

def is_power(a, b):
    """Check if a is a power of b."""
    now = b
    while now < a:
        now *= b
    return now == a

def bin_(num, size):
    """Convert a decimal number to a binary string of size."""
    A = [0] * size
    for i in range(size):
        if (num >> (size - i - 1)) & 1:
            A[i] = 1
    return A

def get_facs(n, mod_=0):
    """Compute factorials up to n."""
    A = [1] * (n + 1)
    for i in range(2, len(A)):
        A[i] = A[i - 1] * i
        if mod_:
            A[i] %= mod_
    return A

def comb(n, r, mod, fac):
    """Compute the binomial coefficient nCr modulo mod."""
    if n - r < 0:
        return 0
    return (fac[n] * pow(fac[n - r], mod - 2, mod) * pow(fac[r], mod - 2, mod)) % mod

def next_comb(num, size):
    """Compute the next combination number."""
    x = num & (-num)
    y = num + x
    z = num & (~y)
    z //= x
    z >>= 1
    num = y | z
    if num > (1 << size):
        return False
    else:
        return num

def get_primes(n, type="int"):
    """Generate prime numbers up to n."""
    A = [True] * (n + 1)
    A[0] = False
    A[1] = False
    for p in range(2, n + 1):
        if A[p]:
            for q in range(p * 2, n + 1, p):
                A[q] = False
    if type == "bool":
        return A
    else:
        primes = []
        for p in range(n + 1):
            if A[p]:
                primes.append(p)
        return primes

def is_prime(num):
    """Check if a number is prime."""
    if num <= 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def ifelse(a, b, c):
    """Conditional expression: if a then b else c."""
    if a:
        return b
    else:
        return c

def join(A, c=" "):
    """Join a list of strings with a separator."""
    n = len(A)
    return "".join(A)

def main():
    """Read input, perform calculations, and print output."""
    n, l = map(int, input().split())
    S = []
    for _ in range(n):
        S.append(input())
    S.sort()
    print(join(S))

# Call the main function
main()
