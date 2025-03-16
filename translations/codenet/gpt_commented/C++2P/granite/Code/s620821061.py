
import sys
from math import gcd

class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = [[] for _ in range(2 * V)]
        self.match = [-1] * (2 * V)
        self.used = [False] * (2 * V)

    def init(self):
        self.G = [[] for _ in range(2 * self.V)]

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
        self.match = [-1] * (2 * self.V)
        for v in range(self.V):
            if self.match[v] < 0:
                self.used = [False] * (2 * self.V)
                if self.dfs(v):
                    res += 1
        return res

def main():
    while True:
        n, m = map(int, input().split())
        if n == 0:
            break

        bm = BitMatching(n)
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        for i in range(n):
            for j in range(m):
                if gcd(a[i], b[j])!= 1:
                    bm.add(i, j)

        print(bm.exec())

if __name__ == "__main__":
    main()

