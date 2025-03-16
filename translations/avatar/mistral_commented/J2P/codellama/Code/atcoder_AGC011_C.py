
import sys
import threading
import time

class Main(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.graph = []
        self.visited = []
        self.color = []
        self.one = 0
        self.bipartite = 0
        self.count = 0
        self.mujun = False

    def run(self):
        scan = sys.stdin
        n = int(scan.readline())
        m = int(scan.readline())
        self.graph = [[] for i in range(n)]
        for i in range(m):
            u, v = map(int, scan.readline().split())
            self.graph[u - 1].append(v - 1)
            self.graph[v - 1].append(u - 1)
        self.visited = [False] * n
        self.color = [-1] * n
        for i in range(n):
            if self.visited[i]:
                continue
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
    Main().start()

