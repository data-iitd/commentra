class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]
        self.transpose_graph = [[] for _ in range(vertices)]
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

    def fill_stack(self):
        vis = [False] * self.V
        for i in range(self.V):
            if not vis[i]:
                self.dfs(i, vis)

    def transpose(self):
        for i in range(self.V):
            for neighbour in self.graph[i]:
                self.transpose_graph[neighbour].append(i)

    def dfs2(self, node, vis):
        vis[node] = True
        self.scc.append(node)
        for neighbour in self.transpose_graph[node]:
            if not vis[neighbour]:
                self.dfs2(neighbour, vis)

    def find_scc(self):
        vis = [False] * self.V
        while self.stack:
            node = self.stack.pop()
            if not vis[node]:
                self.dfs2(node, vis)
                self.sccs_list.append(self.scc)
                self.scc = []

    def kosaraju(self):
        self.fill_stack()
        self.transpose()
        self.find_scc()
        return self.sccs_list


def main():
    vertices = int(input())
    edges = int(input())
    g = Graph(vertices)
    for _ in range(edges):
        u, v = map(int, input().split())
        g.add_edge(u, v)
    sccs = g.kosaraju()
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)


main()
