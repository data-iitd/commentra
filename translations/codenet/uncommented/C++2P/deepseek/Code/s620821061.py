import sys
from collections import defaultdict

class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = defaultdict(list)
        self.match = [-1] * (2 * V)
        self.used = [False] * (2 * V)

    def init(self):
        for i in range(2 * self.V):
            self.G[i].clear()

    def add(self, a, b):
        self.G[a].append(b + self.V)
        self.G[b + self.V].append(a)

    def dfs(self, v):
        self.used[v] = True
        for u in self.G[v]:
            w = self.match[u]
            if w < 0 or (not self.used[w] and self.dfs(w)):
                self.match[v] = u
                self.match[u] = v
                return True
        return False

    def exec(self):
        res = 0
        for v in range(self.V):
            if self.match[v] < 0:
                self.used = [False] * (2 * self.V)
                if self.dfs(v):
                    res += 1
        return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

while True:
    n, m = map(int, sys.stdin.readline().split())
    if n == 0:
        break
    bm = BitMatching(n)
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))

    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j]) != 1:
                bm.add(i, j)

    print(bm.exec())
