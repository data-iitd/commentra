import sys

INF = 1000000001
N = 100000

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

edges = []

distances = [INF] * N
prev_distances = [0] * N

# Main function
def main():
    # Read input
    V, E, r = map(int, sys.stdin.readline().split())

    # Initialize edges list
    for _ in range(E):
        source, target, distance = map(int, sys.stdin.readline().split())
        new_edge = Edge(source, target, distance)
        edges.append(new_edge)

    # Set initial distance of source vertex to 0
    distances[r] = 0

    # Bellman-Ford algorithm
    for _ in range(V - 1):
        # Initialize previous distances array with current distances
        for j in range(V):
            prev_distances[j] = distances[j]

        # Update distances for all vertices
        for edge in edges:
            distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

        # Check if all distances have been updated
        same = True
        for j in range(V):
            if distances[j] != prev_distances[j]:
                same = False
                break

        # If all distances have been updated, break the loop
        if same:
            break

    # Print results
    for i in range(V):
        if distances[i] == INF:
            print("INF")
        else:
            print(distances[i])

if __name__ == "__main__":
    main()
