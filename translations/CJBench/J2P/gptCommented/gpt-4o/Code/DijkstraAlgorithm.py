import sys

class Dijkstra:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count

    def run(self, graph, source):
        # Validate the source vertex index
        if source < 0 or source >= self.vertex_count:
            raise ValueError("Incorrect source vertex")

        # Array to hold the shortest distances from the source vertex
        distances = [sys.maxsize] * self.vertex_count
        # Array to track processed vertices
        processed = [False] * self.vertex_count

        # Distance from source to itself is always 0
        distances[source] = 0

        # Main loop to find shortest paths for all vertices
        for _ in range(self.vertex_count - 1):
            # Get the vertex with the minimum distance that hasn't been processed yet
            u = self.get_min_distance_vertex(distances, processed)
            # Mark the vertex as processed
            processed[u] = True

            # Update distances for adjacent vertices of the processed vertex
            for v in range(self.vertex_count):
                # Check if the vertex is not processed, there is an edge, and the distance can be updated
                if (not processed[v] and graph[u][v] != 0 and
                        distances[u] != sys.maxsize and
                        distances[u] + graph[u][v] < distances[v]):
                    distances[v] = distances[u] + graph[u][v]  # Update the distance

        # Return the array of shortest distances
        return distances

    def get_min_distance_vertex(self, distances, processed):
        min_distance = sys.maxsize  # Initialize minimum distance
        min_index = -1  # Initialize index of the vertex with minimum distance

        # Loop through all vertices to find the minimum distance vertex
        for v in range(self.vertex_count):
            if not processed[v] and distances[v] <= min_distance:
                min_distance = distances[v]  # Update minimum distance
                min_index = v  # Update index of the vertex

        # Return the index of the vertex with the minimum distance
        return min_index

# Main execution
if __name__ == "__main__":
    vertex_count = int(input("Enter the number of vertices: "))
    # Initialize the graph as a 2D list
    graph = []

    # Read the graph's adjacency matrix from input
    for _ in range(vertex_count):
        row = list(map(int, input().split()))
        graph.append(row)

    # Read the source vertex from input
    source = int(input("Enter the source vertex: "))

    # Create an instance of the Dijkstra class and run Dijkstra's algorithm
    dijkstra = Dijkstra(vertex_count)
    distances = dijkstra.run(graph, source)

    # Output the shortest distances from the source vertex
    print(f"Shortest distances from source vertex {source}:")
    for i in range(len(distances)):
        print(f"Vertex {i} : {distances[i]}")

# <END-OF-CODE>
