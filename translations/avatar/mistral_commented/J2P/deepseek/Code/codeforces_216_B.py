import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    
    def dfs(self, v, parent):
        self.visited[v] = True
        for i in self.graph[v]:
            if not self.visited[i]:
                if self.dfs(i, v):
                    return True
            elif i != parent:
                return True
        return False
    
    def count_edges(self):
        edge_count = 0
        for i in range(self.V):
            edge_count += len(self.graph[i])
        return edge_count // 2

def main():
    sc = sys.stdin
    m = int(sc.readline().strip())
    n = int(sc.readline().strip())
    g = Graph(m + 1)
    visited = [False] * (m + 1)
    
    for _ in range(n):
        x, y = map(int, sc.readline().strip().split())
        g.add_edge(x, y)
    
    toremove = 0
    for i in range(1, m + 1):
        if not visited[i]:
            if g.dfs(i, -1):
                edge_count = g.count_edges()
                if edge_count % 2 == 1:
                    toremove += 1
    
    if (m - toremove) % 2 == 1:
        toremove += 1
    
    print(toremove)

if __name__ == "__main__":
    main()
