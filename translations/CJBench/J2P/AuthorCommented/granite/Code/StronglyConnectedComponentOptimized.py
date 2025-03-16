
import sys

class Main:
    def __init__(self):
        self.visited = []
        self.dfs_calls_nodes = []

    def btrack(self, adj_list, node):
        self.visited[node] = 1
        neighbors = adj_list.get(node, [])
        for neighbor in neighbors:
            if self.visited[neighbor] == -1:
                self.btrack(adj_list, neighbor)
        self.dfs_calls_nodes.append(node)

    def btrack2(self, adj_rev_list, node, new_scc):
        self.visited[node] = 1
        new_scc.append(node)
        neighbors = adj_rev_list.get(node, [])
        for neighbor in neighbors:
            if self.visited[neighbor] == -1:
                self.btrack2(adj_rev_list, neighbor, new_scc)

    def get_output(self, adj_list, n):
        self.visited = [-1] * n
        for i in range(n):
            if self.visited[i] == -1:
                self.btrack(adj_list, i)

        adj_rev_list = {}
        for i in range(n):
            neighbors = adj_list.get(i, [])
            for neighbor in neighbors:
                adj_rev_list.setdefault(neighbor, []).append(i)

        self.visited = [-1] * n
        strongly_connected_components = 0
        while self.dfs_calls_nodes:
            node = self.dfs_calls_nodes.pop()
            if self.visited[node] == -1:
                new_scc = []
                self.btrack2(adj_rev_list, node, new_scc)
                strongly_connected_components += 1

        return strongly_connected_components

if __name__ == "__main__":
    n = int(input())
    e = int(input())

    adj_list = {}
    for _ in range(e):
        src, dest = map(int, input().split())
        adj_list.setdefault(src, []).append(dest)

    scc_finder = Main()
    result = scc_finder.get_output(adj_list, n)

    print("Number of strongly connected components:", result)

