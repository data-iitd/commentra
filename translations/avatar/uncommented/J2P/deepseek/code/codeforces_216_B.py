import sys
from collections import defaultdict, deque

class Graph:
    def __init__(self, m):
        self.m = m
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def bfs(self, start):
        visited = [False] * (self.m + 1)
        queue = deque([start])
        visited[start] = True
        count = 0

        while queue:
            node = queue.popleft()
            count += 1
            for neighbor in self.graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

        return count

def main():
    input_line = sys.stdin.readline
    m, n = map(int, input_line().split())
    g = Graph(m)

    for _ in range(n):
        x, y = map(int, input_line().split())
        g.add_edge(x, y)

    toremove = 0
    for i in range(1, m + 1):
        if not g.graph[i]:
            toremove += 1

    if (m - toremove) % 2 == 1:
        toremove += 1

    print(toremove)

if __name__ == "__main__":
    main()
