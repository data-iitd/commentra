from collections import defaultdict

class Main:
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
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, i)

        adj_rev_list = defaultdict(list)
        for i in range(n):
            neighbors = adj_list.get(i, [])
            for neighbor in neighbors:
                adj_rev_list[neighbor].append(i)

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
    input = sys.stdin.read
    data = input().splitlines()
    
    try:
        n, e = map(int, data[0].split())
        adj_list = defaultdict(list)
        for i in range(1, e + 1):
            src, dest = map(int, data[i].split())
            adj_list[src].append(dest)

        scc_finder = Main()
        result = scc_finder.get_output(adj_list, n)
        print("Number of strongly connected components:", result)
    except ValueError:
        print("Invalid input. Please provide integers as input.")
        
# <END-OF-CODE>
