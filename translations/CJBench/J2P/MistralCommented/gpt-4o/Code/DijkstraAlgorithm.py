import sys

class Dijkstra:
    def __init__(self, vertex_count):
        # Constructor to initialize the number of vertices
        self.vertex_count = vertex_count

    def run(self, graph, source):
        # Check if the source vertex is valid
        if source < 0 or source >= self.vertex_count:
            raise ValueError("Incorrect source vertex")

        # Initialize arrays for distances and processed vertices
        distances = [sys.maxsize] * self.vertex_count
        processed = [False] * self.vertex_count

        # Set the initial distance of the source vertex to be zero
        distances[source] = 0

        # Iterate through all vertices except the source vertex
        for _ in range(self.vertex_count - 1):
            # Find the vertex with the minimum distance
            u = self.get_min_distance_vertex(distances, processed)
            # Mark the current vertex as processed
            processed[u] = True

            # Update the distances of neighboring vertices
            for v in range(self.vertex_count):
                # Check if the neighboring vertex is not processed, has an edge to the current vertex,
                # and the new distance is shorter than the current distance
                if (not processed[v] and graph[u][v] != 0 and
                        distances[u] != sys.maxsize and
                        distances[u] + graph[u][v] < distances[v]):
                    # Update the distance of the neighboring vertex
                    distances[v] = distances[u] + graph[u][v]

        # Return the shortest distances from the source vertex to all other vertices
        return distances

    def get_min_distance_vertex(self, distances, processed):
        # Initialize minimum value and index to -1 to represent no minimum found yet
        min_distance = sys.maxsize
        min_index = -1

        # Iterate through all vertices to find the one with the minimum distance
        for v in range(self.vertex_count):
            # Check if the vertex is not processed and its distance is less than or equal to the current minimum
            if not processed[v] and distances[v] <= min_distance:
                # Update the minimum value and index
                min_distance = distances[v]
                min_index = v

        # Return the index of the vertex with the minimum distance
        return min_index

# Main method to read input and run the algorithm
if __name__ == "__main__":
    # Read the number of vertices from the input
    vertex_count = int(input())

    # Initialize the adjacency matrix to represent the graph
    graph = []
    for _ in range(vertex_count):
        row = list(map(int, input().split()))
        graph.append(row)

    # Read the source vertex from the input
    source = int(input())

    # Create an instance of the Dijkstra class with the number of vertices
    dijkstra = Dijkstra(vertex_count)

    # Run the algorithm and print the results
    distances = dijkstra.run(graph, source)
    print(f"Shortest distances from source vertex {source}:")
    for i in range(len(distances)):
        print(f"Vertex {i} : {distances[i]}")

# <END-OF-CODE>
