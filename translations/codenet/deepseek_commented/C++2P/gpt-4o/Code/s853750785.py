# AtCoder.py : This file contains the main function where the program execution starts and ends.

import sys
from collections import defaultdict
from math import gcd

# Define constants
MOD = 10**9 + 7

# Function to calculate the least common multiple (LCM)
def lcd(a, b):
    if b == 0:
        return a
    return (a // gcd(a, b)) * b

# Function to return the digits of a number as a list
def divnum(num):
    p = []
    while num:
        p.append(num % 10)
        num //= 10
    return p

# Function to count the number of digits in a number
def digiter(num):
    return len(divnum(num))

# Function to convert a string to a list of integers
def convertstring(s):
    return [int(char) for char in s]

# Function to perform prime factorization of a number
def prime_factor(n):
    ret = {}
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            if i in ret:
                ret[i] += 1
            else:
                ret[i] = 1
            n //= i
    if n != 1:
        ret[n] = 1
    return ret

# Function to find all divisors of a number
def divisor(n):
    res = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            res.append(i)
            if i * i != n:
                res.append(n // i)
    return res

# Function to compute x raised to the power n modulo m
def myPow(x, n, m):
    if n == 0:
        return 1
    if n % 2 == 0:
        return myPow(x * x % m, n // 2, m)
    else:
        return x * myPow(x, n - 1, m) % m

# Function to generate a list of prime numbers using the Sieve of Eratosthenes
def Eratosthenes(N):
    is_prime = [True] * (N + 1)
    P = []
    for i in range(2, N + 1):
        if is_prime[i]:
            for j in range(2 * i, N + 1, i):
                is_prime[j] = False
            P.append(i)
    return P

# Structure for modular arithmetic
class mint:
    def __init__(self, x=0):
        self.x = (x % MOD + MOD) % MOD

    def __neg__(self):
        return mint(-self.x)

    def __add__(self, a):
        return mint(self.x + a.x)

    def __sub__(self, a):
        return mint(self.x + MOD - a.x)

    def __mul__(self, a):
        return mint(self.x * a.x)

    def pow(self, t):
        if t == 0:
            return mint(1)
        a = self.pow(t // 2)
        a *= a
        if t % 2:
            a *= self
        return a

    def inv(self):
        return self.pow(MOD - 2)

    def __truediv__(self, a):
        return self * a.inv()

# Structure for combinations (n choose k)
class combination:
    def __init__(self, n):
        self.fact = [mint(1)] * (n + 1)
        self.ifact = [mint(1)] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = self.fact[i - 1] * mint(i)
        self.ifact[n] = self.fact[n].inv()
        for i in range(n, 0, -1):
            self.ifact[i - 1] = self.ifact[i] * mint(i)

    def __call__(self, n, k):
        if k < 0 or k > n:
            return mint(0)
        return self.fact[n] * self.ifact[k] * self.ifact[n - k]

comb = combination(1000005)  # Precompute combinations up to 1,000,005

# Main function
N, M = map(int, input().split())  # Read number of nodes (N) and edges (M)
H = list(map(int, input().split()))  # Read heights of each node
G = defaultdict(list)  # Adjacency list for the graph

# Read edges and build the graph
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1  # Convert to 0-based indexing
    v -= 1  # Convert to 0-based indexing
    G[u].append(v)
    G[v].append(u)

ans = 0  # Variable to count the number of nodes that are taller than all their neighbors

# Iterate through each node to check if it is taller than all its neighbors
for u in range(N):
    flag = True  # Flag to check if the current node is taller
    for v in G[u]:
        if H[u] <= H[v]:
            flag = False  # If any neighbor is taller or equal, set flag to false
    if flag:
        ans += 1  # If the flag is still true, increment the answer

# Output the result
print(ans)

# <END-OF-CODE>
