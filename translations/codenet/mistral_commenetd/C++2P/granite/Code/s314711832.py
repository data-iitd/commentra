

# Python code

# Define the edge class
class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

# Read input
V, E, r = map(int, input().split())
edges = []
for i in range(E):
    source, target, weight = map(int, input().split())
    edges.append(Edge(source, target, weight))

# Initialize distances array with maximum value
distances = [float('inf')] * V

# Set initial distance of source vertex to 0
distances[r] = 0

# Bellman-Ford algorithm
for i in range(1, V):
    # Initialize previous distances array with current distances
    prev_distances = distances.copy()

    # Update distances for all vertices
    for edge in edges:
        distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

    # Check if all distances have been updated
    if distances == prev_distances:
        break

# Print results
for distance in distances:
    if distance == float('inf'):
        print("INF")
    else:
        print(distance)

