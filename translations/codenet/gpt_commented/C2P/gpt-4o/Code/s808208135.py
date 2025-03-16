import sys

N = 100000  # Define a constant for the maximum number of nodes
INF = 1000000  # Define a constant for representing infinity

# Class to represent a directed edge with a cost
class Edge:
    def __init__(self, go, back, cost):
        self.go = go  # Destination node
        self.back = back  # Source node
        self.cost = cost  # Cost of the edge

n = int(sys.stdin.readline().strip())  # Read the number of nodes
d = [INF] * n  # Array to store the shortest distances
edges = []  # List to store edges

# Read edges for each node
for _ in range(n):
    u, k = map(int, sys.stdin.readline().strip().split())  # Read the current node and number of edges
    for _ in range(k):
        go, cost = map(int, sys.stdin.readline().strip().split())  # Read destination and cost
        edges.append(Edge(go, u, cost))  # Create an edge and add it to the list

# Function to compute shortest paths using the Bellman-Ford algorithm
def root(b):
    global d
    d[0] = 0  # Set the distance to the source node (node 0) as 0
    flag = True  # Flag to indicate changes

    # Repeat the process until no changes occur
    while flag:
        flag = False  # Reset flag for this iteration
        # Relax all edges
        for edge in edges:
            # Check if the current edge can provide a shorter path
            if edge.cost + d[edge.back] < d[edge.go]:
                d[edge.go] = edge.cost + d[edge.back]  # Update the shortest distance
                flag = True  # Set flag to indicate a change occurred

# Call the root function to compute shortest paths
root(len(edges))

# Print the shortest distances from the source node to each node
for i in range(n):
    print(i, d[i])  # Output the node index and its distance

# End of the code
# <END-OF-CODE>
