mod = 1000000007
INF = 1000000007

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    m = int(data[1])
    R = int(data[2])

    rs = list(map(lambda x: int(x) - 1, data[3:3 + R]))

    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    idx = 3 + R
    for _ in range(m):
        a = int(data[idx]) - 1
        b = int(data[idx + 1]) - 1
        c = int(data[idx + 2])
        costs[a][b] = c
        costs[b][a] = c
        idx += 3

    # ワーシャルフロイド法で最短経路を算出
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # 順列で訪問先の順序をすべて試す
    # これでは重複して訪問する町がでてしまうか。。
    import itertools
    perms = list(itertools.permutations(rs))
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j - 1]
            to = perm[j]
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

# permutations
def permutations(arr):
    def helper(arr, n):
        if n == 1:
            return [arr[:]]
        res = []
        for i in range(n):
            for perm in helper(arr, n - 1):
                if n % 2 == 1:
                    perm[0], perm[n - 1] = perm[n - 1], perm[0]
                else:
                    perm[i], perm[n - 1] = perm[n - 1], perm[i]
                res.append(perm)
        return res
    return helper(arr, len(arr))

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
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return False
        if self.d[rootX] < self.d[rootY]:
            self.d[rootX] += self.d[rootY]
            self.d[rootY] = rootX
        else:
            self.d[rootY] += self.d[rootX]
            self.d[rootX] = rootY
        return True

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.d[self.find(x)]

# mod
def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n % 2 != 0:
            res = res * a % mod
        a = a * a % mod
        n = n // 2
    return res

def modinv(n, mod):
    return modpow(n, mod - 2, mod)

def modcomb(n, a, mod):
    x = 1
    y = 1
    for i in range(a):
        x = x * (n - i) % mod
        y = y * (i + 1) % mod
    return x * modpow(y, mod - 2, mod) % mod

def modfactorial(n, mod):
    result = 1
    for i in range(1, n + 1):
        result = (result * i) % mod
    return result

# Combination ...
class Combination:
    def __init__(self, n, mod):
        self.facts = [1] * (n + 1)
        self.invs = [1] * (n + 1)
        self.mod = mod
        self.init(n)

    def calc(self, n, k):
        ret = self.facts[n] * self.invs[k]
        ret %= self.mod
        ret = ret * self.invs[n - k]
        ret %= self.mod
        return ret

    def init(self, n):
        for i in range(1, n + 1):
            self.facts[i] = self.facts[i - 1] * i % self.mod
        self.invs[n] = modinv(self.facts[n], self.mod)
        for i in range(n - 1, 0, -1):
            self.invs[i] = self.invs[i + 1] * (i + 1) % self.mod

# Utility
def min(x, y):
    if x < y:
        return x
    return y

def max(x, y):
    if x > y:
        return x
    return y

def abs(x):
    if x < 0:
        return -x
    return x

def primeFactor(x):
    res = {}
    i = 2
    while i * i <= x:
        while x % i == 0:
            res[i] = res.get(i, 0) + 1
            x = x // i
        i += 1
    if x != 1:
        res[x] = 1
    return res

def divisor(x):
    res = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            res.append(i)
            if i != x // i:
                res.append(x // i)
        i += 1
    return res

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

def lcm(x, y):
    return x // gcd(x, y) * y

def reverseString(s):
    return s[::-1]

def pow(a, n):
    ret = 1
    for _ in range(n):
        ret *= a
    return ret

# Queue ...
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

# Stack ...
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
import heapq

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def push(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def pop(self):
        if self.empty():
            return None
        return heapq.heappop(self.elements)[1]

# sortable points
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Points(list):
    def __init__(self, points):
        super().__init__(points)

    def __getitem__(self, index):
        return super().__getitem__(index)

    def __len__(self):
        return super().__len__()

    def sort(self):
        super().sort(key=lambda p: p.x)

    def reverse(self):
        super().reverse()

