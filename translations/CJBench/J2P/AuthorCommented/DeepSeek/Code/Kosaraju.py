import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.transpose_graph = defaultdict(list)
        self.stack = []
        self.scc = []
        self.sccs_list = []

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, node, vis):
        vis[node] = True
        for neighbour in self.graph[node]:
            if not vis[neighbour]:
                self.dfs(neighbour, vis)
        self.stack.append(node)

    def fill_order(self, node, vis):
        vis[node] = True
        self.scc.append(node)
        for neighbour in self.transpose_graph[node]:
            if not vis[neighbour]:
                self.fill_order(neighbour, vis)

    def get_transpose(self):
        for i in range(self.V):
            for j in self.graph[i]:
                self.transpose_graph[j].append(i)

    def get_sccs(self):
        vis = [False] * self.V
        for i in range(self.V):
            if not vis[i]:
                self.dfs(i, vis)

        self.get_transpose()
        vis = [False] * self.V
        while self.stack:
            node = self.stack.pop()
            if not vis[node]:
                self.scc = []
                self.fill_order(node, vis)
                self.sccs_list.append(self.scc)

    def print_sccs(self):
        print("Strongly Connected Components:")
        for scc in self.sccs_list:
            print(scc)

def main():
    vertices, edges = map(int, sys.stdin.readline().split())
    g = Graph(vertices)

    for _ in range(edges):
        u, v = map(int, sys.stdin.readline().split())
        g.add_edge(u, v)

    g.get_sccs()
    g.print_sccs()

if __name__ == "__main__":
    main()

