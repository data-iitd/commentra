
import sys

# Main method to find strongly connected components using Main's algorithm
def kosaraju(v, list):
    # Step 1: Sort the edges by their finishing times
    sort_edges_by_lowest_finish_time(v, list)
    # Step 2: Create the transpose of the graph
    transpose_graph = create_transpose_matrix(v, list)
    # Step 3: Find strongly connected components in the transposed graph
    find_strongly_connected_components(v, transpose_graph)
    return sccsList # Return the list of strongly connected components

# Method to perform DFS and fill the stack with nodes based on their finishing times
def sort_edges_by_lowest_finish_time(v, list):
    vis = [0] * v # Array to track visited nodes
    for i in range(v):
        if vis[i] == 0:
            dfs(i, vis, list) # Perform DFS if the node is not visited

# Method to create the transpose of the given graph
def create_transpose_matrix(v, list):
    transpose_graph = [[] for i in range(v)] # Initialize the transpose graph
    # Fill the transpose graph with reversed edges
    for i in range(v):
        for neigh in list[i]:
            transpose_graph[neigh].append(i) # Reverse the direction of edges
    return transpose_graph # Return the transposed graph

# Method to find strongly connected components in the transposed graph
def find_strongly_connected_components(v, transpose_graph):
    vis = [0] * v # Array to track visited nodes
    # Process nodes in the order defined by the stack
    while stack:
        node = stack.pop() # Get the top node from the stack
        if vis[node] == 0:
            dfs2(node, vis, transpose_graph) # Perform DFS on the transposed graph
            sccsList.append(scc) # Add the found SCC to the list
            scc = [] # Reset the current SCC for the next component

# Depth-first search method to fill the stack with nodes based on finishing times
def dfs(node, vis, list):
    vis[node] = 1 # Mark the node as visited
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs(neighbour, vis, list) # Recursively visit unvisited neighbours
    stack.append(node) # Push the node onto the stack after visiting all neighbours

# Depth-first search method to collect nodes in the current strongly connected component
def dfs2(node, vis, list):
    vis[node] = 1 # Mark the node as visited
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs2(neighbour, vis, list) # Recursively visit unvisited neighbours
    scc.append(node) # Add the node to the current SCC

# Main method to execute the program
def main():
    v = int(sys.stdin.readline()) # Read number of vertices
    e = int(sys.stdin.readline()) # Read number of edges
    adjacencyList = [[] for i in range(v)] # Initialize the adjacency list for the graph
    # Read edges and populate the adjacency list
    for i in range(e):
        u = int(sys.stdin.readline()) # Read start vertex of the edge
        v = int(sys.stdin.readline()) # Read end vertex of the edge
        adjacencyList[u].append(v) # Add the edge to the adjacency list
    # Create an instance of Main to use the kosaraju method
    kosaraju = Main()
    # Find strongly connected components
    sccs = kosaraju.kosaraju(v, adjacencyList)
    # Print the strongly connected components
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc) # Print each SCC

# Main method to execute the program
if __name__ == "__main__":
    main()

