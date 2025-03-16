
# <START-OF-CODE>

MN = 520

class BitMatching:
    def __init__(self):
        self.G = [[] for _ in range(2*MN)]
        self.match = [-1] * 2*MN
        self.used = [False] * 2*MN

    def init(self):
        for i in range(2*MN):
            self.G[i].clear()

    def add(self, a, b):
        self.G[a].append(b+MN)
        self.G[b+MN].append(a)

    def dfs(self, v):
        self.used[v] = True

        for i in range(len(self.G[v])):
            u = self.G[v][i]
            w = self.match[u]

            if w < 0 or not self.used[w] and self.dfs(w):
                self.match[v] = u
                self.match[u] = v
                return True
        return False

    def exec(self):
        res = 0
        self.match = [-1] * 2*MN

        for v in range(MN):
            if self.match[v] < 0:
                self.used = [False] * 2*MN
                if self.dfs(v):
                    res += 1
        return res

bm = BitMatching()

while True:
    n, m = map(int, input().split())

    if not n:
        break

    bm.init()

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j])!= 1:
                bm.add(i, j)

    print(bm.exec())

# 