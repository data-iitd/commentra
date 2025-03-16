from typing import List

class BitMatching:
    def __init__(self, V: int):
        self.V = V
        self.G = [[] for _ in range(2 * V)]
        self.match = [-1] * (2 * V)
        self.used = [False] * (2 * V)

    def init(self):
        for i in range(2 * self.V):
            self.G[i].clear()

    def add(self, a: int, b: int):
        self.G[a].append(b + self.V)
        self.G[b + self.V].append(a)

    def dfs(self, v: int) -> bool:
        self.used[v] = True
        for u in self.G[v]:
            w = self.match[u]
            if w < 0 or (not self.used[w] and self.dfs(w)):
                self.match[v] = u
                self.match[u] = v
                return True
        return False

    def exec(self) -> int:
        res = 0
        for v in range(self.V):
            if self.match[v] < 0:
                self.used = [False] * (2 * self.V)
                if self.dfs(v):
                    res += 1
        return res

def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a % b)

if __name__ == "__main__":
    while True:
        n, m = map(int, input().split())
        if n == 0:
            break

        bm = BitMatching(520)
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        bm.init()
        for i in range(n):
            for j in range(m):
                if gcd(a[i], b[j]) != 1:
                    bm.add(i, j)

        print(bm.exec())
