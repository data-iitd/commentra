import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.graph = defaultdict(list)
        self.visited = []
        self.color = []
        self.one = 0
        self.bipartite = 0
        self.count = 0
        self.mujun = False

    def run(self):
        n, m = map(int, sys.stdin.readline().split())
        for _ in range(m):
            u, v = map(int, sys.stdin.readline().split())
            self.graph[u].append(v)
            self.graph[v].append(u)
        self.visited = [False] * (n + 1)
        self.color = [-1] * (n + 1)
        for i in range(1, n + 1):
            if not self.visited[i]:
                self.count += 1
                self.mujun = False
                kind = self.dfs(i, 0)
                if kind == 1:
                    self.one += 1
                elif not self.mujun:
                    self.bipartite += 1
        total = self.one * (2 * n - self.one)
        total += (self.count - self.one) * (self.count - self.one)
        total += self.bipartite * self.bipartite
        print(total)

    def dfs(self, a, c):
        if self.visited[a]:
            if self.color[a] >= 0 and self.color[a] != c:
                self.mujun = True
            return 0
        self.visited[a] = True
        self.color[a] = c
        total = 1
        for b in self.graph[a]:
            total += self.dfs(b, 1 - c)
        return total

if __name__ == "__main__":
    main = Main()
    main.run()
