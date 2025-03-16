import sys

INF = 1000000001  # Define a constant for infinity (a large value)

# Class to represent an edge in the graph
class Edge:
    def __init__(self, source, target, weight):
        self.source = source  # Source vertex of the edge
        self.target = target  # Target vertex of the edge
        self.weight = weight  # Weight of the edge

edges = []  # List to store all edges of the graph

def main():
    V, E, r = map(int, input().split())  # Read the number of vertices, edges, and the source vertex

    # Read all edges from input and store them in the edges list
    for _ in range(E):
        source, target, distance = map(int, input().split())  # Read edge data
        new_edge = Edge(source, target, distance)  # Create a new edge
        edges.append(new_edge)  # Add the new edge to the edges list

    distances = [INF] * V  # Initialize distances array to infinity for all vertices
    distances[r] = 0  # Set the distance to the source vertex to 0

    # Main loop to relax edges V-1 times
    for _ in range(1, V):
        prev_distances = distances.copy()  # Copy current distances for comparison
        
        # Relax all edges
        for edge in edges:
            # Update the distance to the target vertex if a shorter path is found
            distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

        # Check if any distance was updated in this iteration
        if distances == prev_distances:  # If no distances were updated, break out of the loop early
            break

    # Output the shortest distances from the source vertex to all other vertices
    for distance in distances:
        if distance == INF:
            print("INF")  # Print "INF" if the vertex is unreachable
        else:
            print(distance)  # Print the shortest distance

if __name__ == "__main__":
    main()

# <END-OF-CODE>
