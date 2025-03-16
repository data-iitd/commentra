import sys
from collections import defaultdict
from math import gcd

# Define constants
MOD = int(1e9 + 7)
INF = int(1e9)
LINF = 1000000000000000000

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
    ret = defaultdict(int)
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            ret[i] += 1
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
class Mint:
    def __init__(self, x=0):
        self.x = (x % MOD + MOD) % MOD

    def __neg__(self):
        return Mint(-self.x)

    def __add__(self, a):
        return Mint(self.x + a.x)

    def __sub__(self, a):
        return Mint(self.x - a.x)

    def __mul__(self, a):
        return Mint(self.x * a.x)

    def pow(self, t):
        if t == 0:
            return Mint(1)
        a = self.pow(t // 2)
        a *= a
        if t % 2 == 1:
            a *= self
        return a

    def inv(self):
        return self.pow(MOD - 2)

    def __truediv__(self, a):
        return self * a.inv()

# Structure for combinations (n choose k)
class Combination:
    def __init__(self, n):
        self.fact = [Mint(1)] * (n + 1)
        self.ifact = [Mint(1)] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = self.fact[i - 1] * Mint(i)
        self.ifact[n] = self.fact[n].inv()
        for i in range(n, 0, -1):
            self.ifact[i - 1] = self.ifact[i] * Mint(i)

    def __call__(self, n, k):
        if k < 0 or k > n:
            return Mint(0)
        return self.fact[n] * self.ifact[k] * self.ifact[n - k]

comb = Combination(1000005)  # Precompute combinations up to 1,000,005

# Function to calculate permutations with repetition
def f(n, k):
    if n < 0:
        return Mint(0)
    res = comb(n, k)
    res *= comb.fact[k]
    return res

# Main function
N, M = map(int, sys.stdin.readline().split())
H = list(map(int, sys.stdin.readline().split()))
G = defaultdict(list)

# Read edges and build the graph
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
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
