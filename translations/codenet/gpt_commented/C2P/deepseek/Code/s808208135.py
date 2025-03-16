import sys

# Define a constant for the maximum number of nodes
N = 100000
# Define a constant for representing infinity
INF = 1000000

# Structure to represent a directed edge with a cost
class Edge:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

# Function to compute shortest paths using the Bellman-Ford algorithm
def root(b):
    # Initialize distances to all nodes as infinity
    d = [INF] * n
    d[0] = 0  # Set the distance to the source node (node 0) as 0

    # Repeat the process until no changes occur
    flag = 1
    while flag != 0:
        flag = 0  # Reset flag for this iteration
        # Relax all edges
        for i in range(b):
            # Check if the current edge can provide a shorter path
            if d[a[i].back] + a[i].cost < d[a[i].go]:
                d[a[i].go] = d[a[i].back] + a[i].cost  # Update the shortest distance
                flag = 1  # Set flag to indicate a change occurred

    return d

# Read input
n = int(sys.stdin.readline().strip())  # Read the number of nodes
edges = []  # List to store edges

# Read edges for each node
for i in range(n):
    u, k = map(int, sys.stdin.readline().strip().split())  # Read the current node and number of edges
    for j in range(k):
        go, cost = map(int, sys.stdin.readline().strip().split())  # Read destination and cost
        edges.append(Edge(go, u, cost))  # Create an edge and add it to the list

# Compute shortest paths
distances = root(len(edges))

# Print the shortest distances from the source node to each node
for i in range(n):
    print(f"{i} {distances[i]}")  # Output the node index and its distance

# End-of-code
