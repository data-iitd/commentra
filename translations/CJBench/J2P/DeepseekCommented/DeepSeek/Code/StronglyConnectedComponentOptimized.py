import sys
from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.rev_graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.rev_graph[v].append(u)

    def dfs(self, v, visited, stack):
        visited[v] = True
        for i in self.graph[v]:
            if not visited[i]:
                self.dfs(i, visited, stack)
        stack.append(v)

    def dfs_util(self, v, visited, component):
        visited[v] = True
        component.append(v)
        for i in self.rev_graph[v]:
            if not visited[i]:
                self.dfs_util(i, visited, component)

    def get_scc_count(self):
        stack = []
        visited = [False] * self.V
        for i in range(self.V):
            if not visited[i]:
                self.dfs(i, visited, stack)

        visited = [False] * self.V
        scc_count = 0
        while stack:
            v = stack.pop()
            if not visited[v]:
                component = []
                self.dfs_util(v, visited, component)
                scc_count += 1
                print("SCC:", component)
        return scc_count

def main():
    try:
        n, e = map(int, sys.stdin.readline().split())
        g = Graph(n)
        for _ in range(e):
            u, v = map(int, sys.stdin.readline().split())
            g.add_edge(u, v)
        result = g.get_scc_count()
        print("Number of strongly connected components:", result)
    except ValueError:
        print("Invalid input. Please provide integers as input.")

if __name__ == "__main__":
    main()
