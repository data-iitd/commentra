# Declare a global variable for the adjacency list representation of the graph
e = []
# Declare variables for the number of nodes (n) and edges (m)
n, m = 0, 0

# Function to print the edges of the graph
def print_edge(e):
    # Iterate through each node in the graph
    for i in range(1, n + 1):
        print(f"{i}: ", end="")  # Print the node number
        # Print all adjacent nodes (edges) for the current node
        for v in e[i]:
            print(f"{v} ", end="")
        print()  # Move to the next line after printing all edges for the current node

# Depth-first search (DFS) function to explore the graph
def dfs(v, visited):
    # Check if all nodes have been visited
    comp = all(visited[1:n + 1])  # Check if all nodes from 1 to n are visited

    # If all nodes have been visited, return 1 (indicating a complete component)
    if comp:
        return 1

    count = 0  # Initialize count of connected nodes
    # Explore all neighbors of the current node
    for ne in e[v]:
        # Skip already visited nodes
        if visited[ne]:
            continue
        visited[ne] = True  # Mark the neighbor as visited
        # Recursively call DFS for the neighbor and accumulate the count
        rst = dfs(ne, visited)
        count += rst  # Increment the count with the result from the DFS call
        visited[ne] = False  # Backtrack: unmark the neighbor as visited
    return count  # Return the total count of connected nodes

def main():
    global n, m, e
    # Read the number of nodes and edges from input
    n, m = map(int, input().split())

    # Initialize the adjacency list for the graph
    e = [[] for _ in range(n + 1)]
    # Read the edges and populate the adjacency list
    for _ in range(m):
        a, b = map(int, input().split())  # Read each edge
        e[a].append(b)  # Add the edge to the adjacency list
        e[b].append(a)  # Since the graph is undirected, add both directions

    # Uncomment to print the edges of the graph
    # print_edge(e)

    # Initialize the visited array to keep track of visited nodes
    visited = [False] * (n + 1)
    visited[1] = True  # Mark the starting node (node 1) as visited
    count = dfs(1, visited)  # Perform DFS starting from node 1
    print(count)  # Print the count of connected nodes

if __name__ == "__main__":
    main()

# <END-OF-CODE>
