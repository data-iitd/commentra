import sys

# Define a constant for infinity (a large value)
INF = 1000000001
# Define a constant for the maximum number of vertices
N = 100000

# Structure to represent an edge in the graph
class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

# Read the number of vertices, edges, and the source vertex from input
V, E, r = map(int, sys.stdin.readline().split())

# List to store all edges of the graph
edges = []

# Read all edges from input and store them in the edges list
for _ in range(E):
    source, target, weight = map(int, sys.stdin.readline().split())
    edges.append(Edge(source, target, weight))

# Array to store the shortest distances from the source vertex
distances = [INF] * V
distances[r] = 0

# Main loop to relax edges V-1 times
for _ in range(V - 1):
    prev_distances = distances.copy()

    # Relax all edges
    for edge in edges:
        # Update the distance to the target vertex if a shorter path is found
        distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

    # Check if any distance was updated in this iteration
    if all(distances[i] == prev_distances[i] for i in range(V)):
        break

# Output the shortest distances from the source vertex to all other vertices
for distance in distances:
    if distance == INF:
        print("INF")
    else:
        print(distance)

# End-of-code
