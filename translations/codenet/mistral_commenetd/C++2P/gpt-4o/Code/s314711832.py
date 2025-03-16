import sys

INF = 1000000001

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def main():
    V, E, r = map(int, input().split())  # Read number of vertices, edges, and source vertex

    edges = []
    
    # Read edges
    for _ in range(E):
        source, target, distance = map(int, input().split())
        edges.append(Edge(source, target, distance))

    # Initialize distances array with maximum value
    distances = [INF] * V
    distances[r] = 0  # Set initial distance of source vertex to 0

    # Bellman-Ford algorithm
    for _ in range(1, V):
        prev_distances = distances.copy()  # Copy current distances

        # Update distances for all edges
        for edge in edges:
            if distances[edge.source] + edge.weight < distances[edge.target]:
                distances[edge.target] = distances[edge.source] + edge.weight

        # Check if all distances have been updated
        if distances == prev_distances:
            break

    # Print results
    for distance in distances:
        if distance == INF:
            print("INF")
        else:
            print(distance)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
