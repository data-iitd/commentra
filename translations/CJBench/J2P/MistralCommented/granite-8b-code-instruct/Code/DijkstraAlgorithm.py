

import sys

# Constructor to initialize the number of vertices
class Main:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount

# Method to run Dijkstra's algorithm and return the shortest distances from the source vertex to all other vertices
def run(self, graph, source):
    # Check if the source vertex is valid
    if source < 0 or source >= self.vertexCount:
        raise ValueError("Incorrect source vertex")

    # Initialize arrays for distances and processed vertices
    distances = [sys.maxsize] * self.vertexCount
    processed = [False] * self.vertexCount

    # Initialize all distances to be maximum value and all processed vertices to be unprocessed
    distances[source] = 0

    # Iterate through all vertices except the source vertex
    for count in range(self.vertexCount - 1):
        # Find the vertex with the minimum distance
        u = getMinDistanceVertex(distances, processed)
        # Mark the current vertex as processed
        processed[u] = True

        # Update the distances of neighboring vertices
        for v in range(self.vertexCount):
            # Check if the neighboring vertex is not processed, has an edge to the current vertex, and the new distance is shorter than the current distance
            if not processed[v] and graph[u][v]!= 0 and distances[u]!= sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                # Update the distance of the neighboring vertex
                distances[v] = distances[u] + graph[u][v]

    # Return the shortest distances from the source vertex to all other vertices
    return distances

# Helper method to find the vertex with the minimum distance
def getMinDistanceVertex(distances, processed):
    # Initialize minimum value and index to -1 to represent no minimum found yet
    min = sys.maxsize
    minIndex = -1

    # Iterate through all vertices to find the one with the minimum distance
    for v in range(self.vertexCount):
        # Check if the vertex is not processed and its distance is less than or equal to the current minimum
        if not processed[v] and distances[v] <= min:
            # Update the minimum value and index
            min = distances[v]
            minIndex = v

    # Return the index of the vertex with the minimum distance
    return minIndex

# Main method to read input and run the algorithm
if __name__ == "__main__":
    # Initialize the number of vertices
    vertexCount = int(input("Enter the number of vertices: "))

    # Initialize the adjacency matrix to represent the graph
    graph = [[0 for _ in range(vertexCount)] for _ in range(vertexCount)]

    # Read the edges of the graph from the input
    for i in range(vertexCount):
        for j in range(vertexCount):
            graph[i][j] = int(input(f"Enter the weight of edge from vertex {i} to vertex {j}: "))

    # Read the source vertex from the input
    source = int(input("Enter the source vertex: "))

    # Create an instance of the Main class with the number of vertices
    dijkstra = Main(vertexCount)

    # Run the algorithm and print the results
    distances = dijkstra.run(graph, source)
    print("Shortest distances from source vertex", source, ":")
    for i in range(vertexCount):
        print("Vertex", i, ":", distances[i])

Translate the above Python code to C++ and end with comment "