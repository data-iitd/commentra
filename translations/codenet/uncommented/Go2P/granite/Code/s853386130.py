

import sys
from collections import deque

MOD = 1000000007
INF = 10000000007

def main():
    R = int(input())
    rs = list(map(int, input().split()))
    costs = [[INF] * R for _ in range(R)]
    for i in range(R):
        costs[i][i] = 0

    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        costs[a-1][b-1] = c
        costs[b-1][a-1] = c

    for k in range(R):
        for i in range(R):
            for j in range(R):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j-1] - 1
            to = perm[j] - 1
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

def permutations(arr):
    res = []
    def helper(arr, n):
        if n == 1:
            res.append(arr[:])
        else:
            for i in range(n):
                helper(arr, n-1)
                if n % 2 == 1:
                    arr[i], arr[n-1] = arr[n-1], arr[i]
                else:
                    arr[0], arr[n-1] = arr[n-1], arr[0]
    helper(arr, len(arr))
    return res

# Union-Find
class UnionFind:
    def __init__(self, n):
        self.d = [-1] * n

    def find(self, x):
        if self.d[x] < 0:
            return x
        self.d[x] = self.find(self.d[x])
        return self.d[x]

    def unite(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False
        if self.d[root_x] < self.d[root_y]:
            self.d[root_x] += self.d[root_y]
            self.d[root_y] = root_x
        else:
            self.d[root_y] += self.d[root_x]
            self.d[root_x] = root_y
        return True

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.d[self.find(x)]

# mod
def modpow(a, n, mod):
    res = 1
    for _ in range(n):
        if n % 2!= 0:
            res = res * a % mod
        a = a * a % mod
        n //= 2
    return res

def modinv(n, mod):
    return modpow(n, mod-2, mod)

def modcomb(n, a, mod):
    x = 1
    y = 1
    for i in range(a):
        x = x * (n - i) % mod
        y = y * (i + 1) % mod
    return x * modpow(y, mod-2, mod) % mod

def modfactorial(n, mod):
    res = 1
    for i in range(1, n+1):
        res = (res * i) % mod
    return res

# Combination...
class Combination:
    def __init__(self, n, mod):
        self.facts = [1] * (n+1)
        self.invs = [1] * (n+1)
        self.mod = mod

    def calc(self, n, k):
        res = self.facts[n] * self.invs[k] % self.mod
        res = res * self.invs[n-k] % self.mod
        return res

    def init(self, n):
        self.facts[0] = 1
        for i in range(1, n+1):
            self.facts[i] = self.facts[i-1] * i % self.mod
        self.invs[n] = modinv(self.facts[n], self.mod)
        for i in range(n-1, -1, -1):
            self.invs[i] = self.invs[i+1] * (i + 1) % self.mod

# Utility
def min(x, y):
    return x if x < y else y

def max(x, y):
    return x if x > y else y

def abs(x):
    return x if x >= 0 else -x

def primeFactor(x):
    res = {}
    for i in range(2, int(x**0.5)+1):
        while x % i == 0:
            res[i] = res.get(i, 0) + 1
            x //= i
    if x!= 1:
        res[x] = 1
    return res

def divisor(x):
    res = []
    for i in range(1, int(x**0.5)+1):
        if x % i == 0:
            res.append(i)
            if i!= x//i:
                res.append(x//i)
    return res

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x%y)

def lcm(x, y):
    return x // gcd(x, y) * y

def reverseString(s):
    return s[::-1]

def pow(a, n):
    res = 1
    for _ in range(n):
        res *= a
    return res

# Queue...
class Queue:
    def __init__(self):
        self.items = []

    def empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.empty():
            return None
        return self.items.pop(0)

# Stack...
class Stack:
    def __init__(self):
        self.items = []

    def empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.empty():
            return None
        return self.items.pop()

# priority_queue
class IntHeap:
    def __init__(self):
        self.h = []

    def len(self):
        return len(self.h)

    def less(self, i, j):
        return self.h[i] > self.h[j]

    def swap(self, i, j):
        self.h[i], self.h[j] = self.h[j], self.h[i]

    def push(self, x):
        self.h.append(x)

    def pop(self):
        if self.empty():
            return None
        x = self.h[0]
        self.h = self.h[1:]
        return x

# sortable points
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Points(list):
    def __lt__(self, other):
        return self[0].x < other[0].x

# main
if __name__ == "__main__":
    R = int(input())
    rs = list(map(int, input().split()))
    costs = [[INF] * R for _ in range(R)]
    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        costs[a-1][b-1] = c
        costs[b-1][a-1] = c

    for k in range(R):
        for i in range(R):
            for j in range(R):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j-1]
            to = perm[j]
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

