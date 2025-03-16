from collections import defaultdict

class Main:
    def __init__(self):
        self.stack = []
        self.scc = []
        self.sccs_list = []

    def kosaraju(self, v, adjacency_list):
        self.sort_edges_by_lowest_finish_time(v, adjacency_list)
        transpose_graph = self.create_transpose_matrix(v, adjacency_list)
        self.find_strongly_connected_components(v, transpose_graph)
        return self.sccs_list

    def sort_edges_by_lowest_finish_time(self, v, adjacency_list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, adjacency_list)

    def create_transpose_matrix(self, v, adjacency_list):
        transpose_graph = defaultdict(list)
        for i in range(v):
            for neighbour in adjacency_list[i]:
                transpose_graph[neighbour].append(i)
        return transpose_graph

    def find_strongly_connected_components(self, v, transpose_graph):
        vis = [0] * v
        while self.stack:
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transpose_graph)
                self.sccs_list.append(self.scc)
                self.scc = []

    def dfs(self, node, vis, adjacency_list):
        vis[node] = 1
        for neighbour in adjacency_list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, adjacency_list)
        self.stack.append(node)

    def dfs2(self, node, vis, transpose_graph):
        vis[node] = 1
        for neighbour in transpose_graph[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, transpose_graph)
        self.scc.append(node)

if __name__ == "__main__":
    vertices = int(input())
    edges = int(input())

    adjacency_list = [[] for _ in range(vertices)]
    for _ in range(edges):
        u, v = map(int, input().split())
        adjacency_list[u].append(v)

    kosaraju = Main()
    sccs = kosaraju.kosaraju(vertices, adjacency_list)

    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

# <END-OF-CODE>
