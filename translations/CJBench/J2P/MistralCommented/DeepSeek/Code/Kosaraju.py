import sys
from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.transpose = defaultdict(list)
        self.stack = deque()
        self.scc = []
        self.sccs_list = []

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def fill_order(self, v, visited, stack):
        visited[v] = True
        for i in self.graph[v]:
            if not visited[i]:
                self.fill_order(i, visited, stack)
        stack.append(v)

    def get_transpose(self):
        for i in range(self.V):
            for j in self.graph[i]:
                self.transpose[j].append(i)

    def dfs(self, v, visited):
        visited[v] = True
        self.scc.append(v)
        for i in self.transpose[v]:
            if not visited[i]:
                self.dfs(i, visited)

    def get_sccs(self):
        visited = [False] * self.V
        for i in range(self.V):
            if not visited[i]:
                self.fill_order(i, visited, self.stack)

        self.get_transpose()
        visited = [False] * self.V
        while self.stack:
            i = self.stack.pop()
            if not visited[i]:
                self.dfs(i, visited)
                self.sccs_list.append(self.scc)
                self.scc = []

        return self.sccs_list

def main():
    vertices, edges = map(int, sys.stdin.readline().split())
    g = Graph(vertices)
    for _ in range(edges):
        u, v = map(int, sys.stdin.readline().split())
        g.add_edge(u, v)

    sccs = g.get_sccs()
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

if __name__ == "__main__":
    main()
