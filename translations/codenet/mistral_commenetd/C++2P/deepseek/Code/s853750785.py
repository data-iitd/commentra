import sys
from math import *
from collections import deque, defaultdict
from itertools import permutations, combinations
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right

# Define constants and helper functions
MOD = 10**9 + 7

class mint:
    def __init__(self, x=0):
        self.x = (x % MOD + MOD) % MOD

    def __neg__(self):
        return mint(-self.x)

    def __add__(self, other):
        return mint(self.x + other.x)

    def __sub__(self, other):
        return mint(self.x + MOD - other.x)

    def __mul__(self, other):
        return mint(self.x * other.x)

    def __pow__(self, other):
        return mint(pow(self.x, other, MOD))

    def __truediv__(self, other):
        return mint(self.x * pow(other.x, MOD - 2, MOD))

    def __repr__(self):
        return str(self.x)

class combination:
    def __init__(self, n):
        assert n < MOD
        self.fact = [1] * (n + 1)
        self.ifact = [1] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = self.fact[i - 1] * i % MOD
        self.ifact[n] = pow(self.fact[n], MOD - 2, MOD)
        for i in range(n, 0, -1):
            self.ifact[i - 1] = self.ifact[i] * i % MOD

    def __call__(self, n, k):
        if k < 0 or k > n:
            return 0
        return self.fact[n] * self.ifact[k] * self.ifact[n - k] % MOD

comb = combination(1000005)

def f(n, k):
    if n < 0:
        return 0
    res = comb(n, k)
    res *= comb.fact[k]
    return res

# Read input
N, M = map(int, sys.stdin.readline().split())
H = list(map(int, sys.stdin.readline().split()))
G = defaultdict(list)

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    u -= 1
    v -= 1
    G[u].append(v)
    G[v].append(u)

# Main logic
ans = 0
for u in range(N):
    flag = True
    for v in G[u]:
        if H[u] <= H[v]:
            flag = False
            break
    if flag:
        ans += 1

# Output the result
print(ans)
