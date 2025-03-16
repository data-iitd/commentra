import sys
from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    
    def dfs(self, v, parent):
        self.visited[v] = True
        self.count += 1
        
        for neighbour in self.graph[v]:
            if neighbour != parent:
                if self.visited[neighbour]:
                    return True
                if self.dfs(neighbour, v):
                    return True
        return False
    
    def find_min_remove(self):
        toremove = 0
        for i in range(1, self.V + 1):
            if not self.visited[i]:
                self.count = 0
                if self.dfs(i, -1) and self.count % 2 == 1:
                    toremove += 1
        
        if (self.V - toremove) % 2 == 1:
            toremove += 1
        
        return toremove

def main():
    # Read the number of nodes (m) and edges (n)
    m, n = map(int, sys.stdin.readline().split())
    
    # Create a graph instance
    g = Graph(m)
    
    # Read the edges and populate the graph
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        g.add_edge(x, y)
    
    # Initialize the visited array
    g.visited = [False] * (m + 1)
    
    # Find and print the minimum number of nodes to remove
    result = g.find_min_remove()
    print(result)

if __name__ == "__main__":
    main()
