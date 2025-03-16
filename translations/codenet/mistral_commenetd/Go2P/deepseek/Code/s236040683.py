import sys
from collections import defaultdict

# Custom function for printing output.
def out(x):
    print(x)

# Read an integer from the input.
def get_int():
    return int(sys.stdin.readline().strip())

# Read a string from the input.
def get_string():
    return sys.stdin.readline().strip()

# Main function to read the input and process the graph.
def main():
    # Read the number of nodes N and edges M from the input.
    N, M = map(int, sys.stdin.readline().strip().split())

    # Create a dictionary to store the graph as an adjacency list.
    graph = defaultdict(list)

    # Process each edge by adding it to the adjacency list.
    for _ in range(M):
        # Read the from and to nodes from the input.
        from_node, to_node = map(int, sys.stdin.readline().strip().split())

        # Add the edge to the adjacency list.
        graph[from_node].append(to_node)
        graph[to_node].append(from_node)

    # Print the number of neighbors for each node.
    for node in range(1, N + 1):
        # Print the number of neighbors of the current node.
        out(len(graph[node]))

# Call the main function.
if __name__ == "__main__":
    main()
