import sys
from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.transpose_graph = defaultdict(list)
        self.stack = deque()
        self.scc = []
        self.sccs_list = []

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list)
        self.stack.appendleft(node)

    def fill_order(self, node, vis):
        vis[node] = 1
        self.scc.append(node)
        for neighbour in self.transpose_graph[node]:
            if vis[neighbour] == 0:
                self.fill_order(neighbour, vis)

    def get_transpose(self):
        for i in range(self.V):
            for neighbour in self.graph[i]:
                self.transpose_graph[neighbour].append(i)

    def kosaraju(self):
        vis = [0] * self.V
        for i in range(self.V):
            if vis[i] == 0:
                self.dfs(i, vis, self.graph)

        self.get_transpose()
        vis = [0] * self.V
        while self.stack:
            node = self.stack.popleft()
            if vis[node] == 0:
                self.scc = []
                self.fill_order(node, vis)
                self.sccs_list.append(self.scc)

        return self.sccs_list

if __name__ == "__main__":
    vertices, edges = map(int, sys.stdin.readline().split())
    g = Graph(vertices)
    for _ in range(edges):
        u, v = map(int, sys.stdin.readline().split())
        g.add_edge(u, v)

    sccs = g.kosaraju()
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)
