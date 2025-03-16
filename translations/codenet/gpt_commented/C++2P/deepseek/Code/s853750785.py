import sys
from math import *
from collections import deque, defaultdict, Counter
from itertools import accumulate, permutations, combinations
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop
from functools import lru_cache

# Define type aliases for convenience
typedef long long ll;

# Define mathematical constants and macros
rad_to_deg = lambda rad: ((rad)/2/pi)*360
EPS = 1e-7
INF = 1e9
PI = acos(-1)

# Define a pair type for convenience
P = tuple[ll, ll]

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to calculate the least common multiple (LCM)
def lcd(a, b):
    if b == 0:
        return a
    return (a // gcd(a, b)) * b

# Function to return the digits of a number as a list
def divnum(num):
    dig = []
    while num:
        dig.append(num % 10)
        num //= 10
    return dig

# Function to count the number of digits in a number
def digiter(num):
    dig = []
    while num:
        dig.append(num % 10)
        num //= 10
    return len(dig)

# Function to convert a string to a list of integers
def convertstring(s):
    return [int(c) for c in s]

# Function to perform prime factorization of a number
def prime_factor(n):
    ret = {}
    for i in range(2, int(sqrt(n)) + 1):
        while n % i == 0:
            ret[i] = ret.get(i, 0) + 1
            n //= i
    if n != 1:
        ret[n] = 1
    return ret

# Function to find all divisors of a number
def divisor(n):
    res = []
    for i in range(1, int(sqrt(n)) + 1):
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

# Define a structure for modular arithmetic
mod = 10**9 + 7
class mint:
    def __init__(self, x=0):
        self.x = (x % mod + mod) % mod

    def __neg__(self):
        return mint(-self.x)

    def __add__(self, other):
        return mint(self.x + other.x)

    def __sub__(self, other):
        return mint(self.x + mod - other.x)

    def __mul__(self, other):
        return mint(self.x * other.x)

    def pow(self, t):
        if t == 0:
            return mint(1)
        a = self.pow(t // 2)
        a *= a
        if t % 2 == 1:
            a *= self
        return a

    def inv(self):
        return self.pow(mod - 2)

    def __truediv__(self, other):
        return self * other.inv()

    def __str__(self):
        return str(self.x)

# Structure for combinations (n choose k)
class combination:
    def __init__(self, n):
        self.fact = [1] * (n + 1)
        self.ifact = [1] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = self.fact[i - 1] * i % mod
        self.ifact[n] = pow(self.fact[n], mod - 2, mod)
        for i in range(n, 0, -1):
            self.ifact[i - 1] = self.ifact[i] * i % mod

    def __call__(self, n, k):
        if k < 0 or k > n:
            return mint(0)
        return mint(self.fact[n]) * mint(self.ifact[k]) * mint(self.ifact[n - k])

# Function to calculate permutations with repetition
def f(n, k):
    if n < 0:
        return mint(0)
    res = comb(n, k)
    res *= comb.fact[k]
    return res

# Main function
N, M = map(int, input().split())
H = list(map(int, input().split()))
G = [[] for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append(v)
    G[v].append(u)

ans = 0

for u in range(N):
    flag = True
    for v in G[u]:
        if H[u] <= H[v]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)
