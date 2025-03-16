// Read the values of n (number of nodes) and m (number of edges) from input
n, m := [int(x) for x in input().split()]

// Create a list of nodes from 1 to n
p := [x for x in range(1, n + 1)]

// Read the health points for each node from input
h := [int(x) for x in input().split()]

// Create a dictionary to map each node to its corresponding health points
hp := dict(zip(p, h))

// Initialize a dictionary to represent the graph as an adjacency list
// Each node will map to a list of its connected nodes (edges)
path := {i: [] for i in range(1, n + 1)}

// Read m edges from input and populate the adjacency list
for i in range(m):
    (a, b) := [int(x) for x in input().split()]
    path[a].append(b)  // Add edge from a to b
    path[b].append(a)  // Add edge from b to a (undirected graph)

// Initialize a counter for nodes that have no neighbors with equal or higher health points
c := 0

// Iterate through each node and its connected nodes
for i, v in path.items():
    f := 0  // Flag to check if any neighbor has equal or higher health points
    for j in v:
        // Check if the current node's health is less than or equal to any of its neighbors
        if hp[i] <= hp[j]:
            f = 1  // Set flag if a neighbor with equal or higher health is found
            break  // No need to check further neighbors
    // If no neighbors have equal or higher health points, increment the counter
    if f == 0:
        c += 1

// Print the count of nodes that have no neighbors with equal or higher health points
print(c)

