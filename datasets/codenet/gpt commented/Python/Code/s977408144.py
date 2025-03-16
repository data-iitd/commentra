# coding: utf-8
import re
import math
from collections import defaultdict
import itertools
from copy import deepcopy
import random
from heapq import heappop, heappush
import time
import os
import queue
import sys
import datetime
from functools import lru_cache

# Set up input reading and recursion limit
readline = sys.stdin.readline
sys.setrecursionlimit(2000000)

# Define constants
alphabet = "abcdefghijklmnopqrstuvwxyz"
mod = int(10**9 + 7)
inf = int(10**20)

# Utility functions to print "yes" or "no" in different formats
def yn(b):
    if b:
        print("yes")
    else:
        print("no")

def Yn(b):
    if b:
        print("Yes")
    else:
        print("No")

def YN(b):
    if b:
        print("YES")
    else:
        print("NO")

# Union-Find (Disjoint Set Union) class for efficient union and find operations
class union_find():
    def __init__(self, n):
        self.n = n
        self.P = [a for a in range(N)]  # Parent array
        self.rank = [0] * n  # Rank array for union by rank

    # Find the root of the set containing x
    def find(self, x):
        if (x != self.P[x]):
            self.P[x] = self.find(self.P[x])  # Path compression
        return self.P[x]

    # Check if x and y are in the same set
    def same(self, x, y):
        return self.find(x) == self.find(y)

    # Link two sets
    def link(self, x, y):
        if self.rank[x] < self.rank[y]:
            self.P[x] = y
        elif self.rank[y] < self.rank[x]:
            self.P[y] = x
        else:
            self.P[x] = y
            self.rank[y] += 1

    # Unite two sets
    def unite(self, x, y):
        self.link(self.find(x), self.find(y))

    # Return the number of unique sets
    def size(self):
        S = set()
        for a in range(self.n):
            S.add(self.find(a))
        return len(S)

# Check if a is a power of b
def is_power(a, b):
    now = b
    while now < a:
        now *= b
    return now == a

# Convert a number to binary representation of a given size
def bin_(num, size):
    A = [0] * size
    for a in range(size):
        if (num >> (size - a - 1)) & 1 == 1:
            A[a] = 1
        else:
            A[a] = 0
    return A

# Get factorials up to n, optionally modulo mod_
def get_facs(n, mod_=0):
    A = [1] * (n + 1)
    for a in range(2, len(A)):
        A[a] = A[a - 1] * a
        if mod > 0:
            A[a] %= mod_
    return A

# Calculate combinations n choose r modulo mod using precomputed factorials
def comb(n, r, mod, fac):
    if (n - r < 0):
        return 0
    return (fac[n] * pow(fac[n - r], mod - 2, mod) * pow(fac[r], mod - 2, mod)) % mod

# Get the next combination in binary representation
def next_comb(num, size):
    x = num & (-num)
    y = num + x
    z = num & (~y)
    z //= x
    z = z >> 1
    num = (y | z)
    if num >= (1 << size):
        return False
    else:
        return num

# Get all prime numbers up to n, return as boolean array or list
def get_primes(n, type="int"):
    A = [True] * (n + 1)
    A[0] = False
    A[1] = False
    for a in range(2, n + 1):
        if A[a]:
            for b in range(a * 2, n + 1, a):
                A[b] = False
    if type == "bool":
        return A
    B = []
    for a in range(n + 1):
        if A[a]:
            B.append(a)
    return B

# Check if a number is prime
def is_prime(num):
    if num <= 2:
        return False
    i = 2
    while i * i <= num:
        if num % i == 0:
            return False
        i += 1
    return True

# Ternary conditional function
def ifelse(a, b, c):
    if a:
        return b
    else:
        return c

# Join elements of a list into a string with a specified separator
def join(A, c=" "):
    n = len(A)
    A = list(map(str, A))
    s = ""
    for a in range(n):
        s += A[a]
        if a < n - 1:
            s += c
    return s

# Factorize a number into its prime factors, return as a dictionary or list
def factorize(n, type_="dict"):
    b = 2
    list_ = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            list_.append(b)
        b += 1
    if n > 1:
        list_.append(n)
    if type_ == "dict":
        dic = {}
        for a in list_:
            if a in dic:
                dic[a] += 1
            else:
                dic[a] = 1
        return dic
    elif type_ == "list":
        return list_
    else:
        return None

# Floor function to round down to the nearest multiple of x
def floor_(n, x=1):
    return x * (n // x)

# Ceiling function to round up to the nearest multiple of x
def ceil_(n, x=1):
    return x * ((n + x - 1) // x)

# Clamp a value x to be within the range [min_, max_]
def hani(x, min_, max_):
    ret = x
    if x < min_:
        ret = min_
    if x > max_:
        ret = max_
    return ret

# Return the sign of x
def seifu(x):
    return x // abs(x)

###################################################

# Main function to read input, process it, and output the result
def main():
    n, l = map(int, input().split())  # Read n and l from input
    S = []
    for a in range(n):
        S.append(input())  # Read n strings from input
    S.sort()  # Sort the list of strings
    print("".join(S))  # Print the concatenated sorted strings

# Execute the main function
main()
