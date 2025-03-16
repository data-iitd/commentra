from collections import defaultdict

class Main:
    def __init__(self):
        self.stack = []  # Stack to hold the vertices
        self.scc = []  # List to hold the current strongly connected component
        self.sccs_list = []  # List to hold all strongly connected components

    def kosaraju(self, v, graph):
        # Sort edges by their finish time (LTS)
        self.sort_edges_by_lowest_finish_time(v, graph)

        # Create the transpose graph
        transpose_graph = self.create_transpose_matrix(v, graph)

        # Find strongly connected components in the transpose graph
        self.find_strongly_connected_components(v, transpose_graph)

        return self.sccs_list

    def sort_edges_by_lowest_finish_time(self, v, graph):
        vis = [0] * v  # Initialize a visited array

        # DFS traversal to compute LTS for all vertices
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, graph)

    def dfs(self, node, vis, graph):
        # Mark the current node as visited
        vis[node] = 1

        # Recur for all neighbors
        for neighbor in graph[node]:
            if vis[neighbor] == 0:
                self.dfs(neighbor, vis, graph)

        # Push the current node to the stack
        self.stack.append(node)

    def create_transpose_matrix(self, v, graph):
        transpose_graph = defaultdict(list)  # Initialize the transpose graph

        # Add edges from the transpose graph
        for i in range(v):
            for neighbor in graph[i]:
                transpose_graph[neighbor].append(i)

        return transpose_graph

    def find_strongly_connected_components(self, v, transpose_graph):
        vis = [0] * v  # Initialize a visited array

        # DFS traversal to find SCCs
        while self.stack:
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transpose_graph)
                self.sccs_list.append(self.scc)  # Add the SCC to the list
                self.scc = []  # Initialize a new SCC

    def dfs2(self, node, vis, graph):
        # Mark the current node as visited
        vis[node] = 1

        # Add the current node to the SCC
        self.scc.append(node)

        # Recur for all neighbors
        for neighbor in graph[node]:
            if vis[neighbor] == 0:
                self.dfs2(neighbor, vis, graph)

# Main method to read input and call the kosaraju method
if __name__ == "__main__":
    vertices = int(input("Enter number of vertices: "))  # Read the number of vertices
    edges = int(input("Enter number of edges: "))  # Read the number of edges

    graph = defaultdict(list)  # Initialize an empty adjacency list

    # Create the adjacency list based on input
    for _ in range(edges):
        u, v = map(int, input("Enter edge (u v): ").split())  # Read the source and destination vertices
        graph[u].append(v)  # Add the edge from u to v

    kosaraju = Main()  # Initialize an instance of the Main class
    sccs = kosaraju.kosaraju(vertices, graph)  # Call the kosaraju method

    print("Strongly Connected Components:")  # Print the header for SCCs
    for scc in sccs:
        print(scc)  # Print each SCC

# <END-OF-CODE>
