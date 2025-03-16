from collections import defaultdict

class SCCFinder:
    def btrack(self, adj_list, visited, dfs_calls_nodes, current_node):
        visited[current_node] = 1
        neighbors = adj_list.get(current_node, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, neighbor)
        dfs_calls_nodes.append(current_node)

    def btrack2(self, adj_rev_list, visited, current_node, new_scc):
        visited[current_node] = 1
        new_scc.append(current_node)
        neighbors = adj_rev_list.get(current_node, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack2(adj_rev_list, visited, neighbor, new_scc)

    def get_output(self, adj_list, n):
        visited = [-1] * n
        dfs_calls_nodes = []

        # Perform DFS and populate the stack
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, i)

        # Create the reversed graph
        adj_rev_list = defaultdict(list)
        for i in range(n):
            for neighbor in adj_list.get(i, []):
                adj_rev_list[neighbor].append(i)

        # Find strongly connected components
        visited = [-1] * n
        strongly_connected_components = 0

        while dfs_calls_nodes:
            node = dfs_calls_nodes.pop()
            if visited[node] == -1:
                new_scc = []
                self.btrack2(adj_rev_list, visited, node, new_scc)
                strongly_connected_components += 1

        return strongly_connected_components

if __name__ == "__main__":
    import sys

    try:
        n = int(input())
        e = int(input())

        adj_list = defaultdict(list)
        for _ in range(e):
            src, dest = map(int, input().split())
            adj_list[src].append(dest)

        scc_finder = SCCFinder()
        result = scc_finder.get_output(adj_list, n)

        print("Number of strongly connected components:", result)
    except ValueError:
        print("Invalid input. Please provide integers as input.")
