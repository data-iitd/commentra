import sys
from collections import defaultdict

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Bit Matching Algorithm
class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = defaultdict(list)
        self.match = [-1] * (2 * V)
        self.used = [False] * (2 * V)

    # Initialize the graph
    def init(self):
        for i in range(2 * self.V):
            self.G[i].clear()

    # Add an edge between node a and node b in the bipartite graph
    def add(self, a, b):
        self.G[a].append(b + self.V)
        self.G[b + self.V].append(a)

    # Depth-First Search to find augmenting paths
    def dfs(self, v):
        self.used[v] = True
        for u in self.G[v]:
            w = self.match[u]
            if w < 0 or (not self.used[w] and self.dfs(w)):
                self.match[v] = u
                self.match[u] = v
                return True
        return False

    # Execute the bipartite matching algorithm
    def exec(self):
        res = 0
        for v in range(self.V):
            if self.match[v] < 0:
                self.used = [False] * (2 * self.V)
                if self.dfs(v):
                    res += 1
        return res

# Read input from stdin
for line in sys.stdin:
    n, m = map(int, line.split())
    if n == 0:
        break
    bm = BitMatching(520)
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    bm.init()
    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j]) != 1:
                bm.add(i, j)
    print(bm.exec())
