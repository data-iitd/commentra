from collections import defaultdict

class Main:
    def __init__(self):
        self.stack = []  # Stack to hold nodes in the order of their finishing times
        self.scc = []  # List to hold the current strongly connected component
        self.sccs_list = []  # List to hold all strongly connected components

    # Main method to find strongly connected components using Kosaraju's algorithm
    def kosaraju(self, v, graph):
        # Step 1: Sort the edges by their finishing times
        self.sort_edges_by_lowest_finish_time(v, graph)
        # Step 2: Create the transpose of the graph
        transpose_graph = self.create_transpose_matrix(v, graph)
        # Step 3: Find strongly connected components in the transposed graph
        self.find_strongly_connected_components(v, transpose_graph)
        return self.sccs_list  # Return the list of strongly connected components

    # Method to perform DFS and fill the stack with nodes based on their finishing times
    def sort_edges_by_lowest_finish_time(self, v, graph):
        vis = [0] * v  # Array to track visited nodes
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, graph)  # Perform DFS if the node is not visited

    # Method to create the transpose of the given graph
    def create_transpose_matrix(self, v, graph):
        transpose_graph = defaultdict(list)  # Initialize the transpose graph
        # Fill the transpose graph with reversed edges
        for i in range(v):
            for neigh in graph[i]:
                transpose_graph[neigh].append(i)  # Reverse the direction of edges
        return transpose_graph  # Return the transposed graph

    # Method to find strongly connected components in the transposed graph
    def find_strongly_connected_components(self, v, transpose_graph):
        vis = [0] * v  # Array to track visited nodes
        # Process nodes in the order defined by the stack
        while self.stack:
            node = self.stack.pop()  # Get the top node from the stack
            if vis[node] == 0:
                self.dfs2(node, vis, transpose_graph)  # Perform DFS on the transposed graph
                self.sccs_list.append(self.scc)  # Add the found SCC to the list
                self.scc = []  # Reset the current SCC for the next component

    # Depth-first search method to fill the stack with nodes based on finishing times
    def dfs(self, node, vis, graph):
        vis[node] = 1  # Mark the node as visited
        for neighbour in graph[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, graph)  # Recursively visit unvisited neighbours
        self.stack.append(node)  # Push the node onto the stack after visiting all neighbours

    # Depth-first search method to collect nodes in the current strongly connected component
    def dfs2(self, node, vis, graph):
        vis[node] = 1  # Mark the node as visited
        for neighbour in graph[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, graph)  # Recursively visit unvisited neighbours
        self.scc.append(node)  # Add the node to the current SCC

# Main method to execute the program
if __name__ == "__main__":
    vertices = int(input("Enter number of vertices: "))  # Read number of vertices
    edges = int(input("Enter number of edges: "))  # Read number of edges
    graph = defaultdict(list)  # Initialize the adjacency list for the graph
    # Read edges and populate the adjacency list
    for _ in range(edges):
        u, v = map(int, input("Enter edge (u v): ").split())  # Read start and end vertex of the edge
        graph[u].append(v)  # Add the edge to the adjacency list
    # Create an instance of Main to use the kosaraju method
    kosaraju = Main()
    # Find strongly connected components
    sccs = kosaraju.kosaraju(vertices, graph)
    # Print the strongly connected components
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)  # Print each SCC
