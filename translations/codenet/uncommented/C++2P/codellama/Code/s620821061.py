#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

class BitMatching:
    def __init__(self, V):
        self.G = [[] for _ in range(2*V)]
        self.match = [-1 for _ in range(2*V)]
        self.used = [False for _ in range(2*V)]

    def init(self):
        for i in range(2*V):
            self.G[i].clear()

    def add(self, a, b):
        self.G[a].append(b+V)
        self.G[b+V].append(a)

    def dfs(self, v):
        self.used[v] = True
        for i in range(len(self.G[v])):
            u = self.G[v][i]
            w = self.match[u]
            if w < 0 or (not self.used[w] and self.dfs(w)):
                self.match[v] = u
                self.match[u] = v
                return True
        return False

    def exec(self):
        res = 0
        memset(self.match, -1, sizeof(self.match))
        for v in range(V):
            if self.match[v] < 0:
                memset(self.used, 0, sizeof(self.used))
                if self.dfs(v):
                    res += 1
        return res

bm = BitMatching(MN)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    bm.init()
    a = [0] * n
    b = [0] * m
    for i in range(n):
        a[i] = int(input())
    for i in range(m):
        b[i] = int(input())

    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j]) != 1:
                bm.add(i, j)

    print(bm.exec())

