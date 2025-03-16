
import sys

# Function to run Dijkstra's algorithm and find shortest paths from the source vertex
def dijkstra(graph, source):
    # Validate the source vertex index
    if source < 0 or source >= len(graph):
        raise ValueError("Incorrect source vertex")

    # Array to hold the shortest distances from the source vertex
    distances = [sys.maxsize] * len(graph)
    # Array to track processed vertices
    processed = [False] * len(graph)

    # Initialize distances to infinity and processed array to false
    distances[source] = 0

    # Main loop to find shortest paths for all vertices
    for count in range(len(graph) - 1):
        # Get the vertex with the minimum distance that hasn't been processed yet
        u = get_min_distance_vertex(distances, processed)
        # Mark the vertex as processed
        processed[u] = True

        # Update distances for adjacent vertices of the processed vertex
        for v in range(len(graph)):
            # Check if the vertex is not processed, there is an edge, and the distance can be updated
            if not processed[v] and graph[u][v]!= 0 and distances[u]!= sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                distances[v] = distances[u] + graph[u][v] # Update the distance

    # Return the array of shortest distances
    return distances

# Helper function to find the vertex with the minimum distance value that has not been processed
def get_min_distance_vertex(distances, processed):
    min_distance = sys.maxsize # Initialize minimum distance
    min_index = -1 # Initialize index of the vertex with minimum distance

    # Loop through all vertices to find the minimum distance vertex
    for v in range(len(graph)):
        if not processed[v] and distances[v] <= min_distance:
            min_distance = distances[v] # Update minimum distance
            min_index = v # Update index of the vertex

    # Return the index of the vertex with the minimum distance
    return min_index

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of vertices from input
    vertex_count = int(input("Enter the number of vertices: "))
    # Initialize the graph as a 2D array
    graph = [[0 for _ in range(vertex_count)] for _ in range(vertex_count)]

    # Read the graph's adjacency matrix from input
    for i in range(vertex_count):
        for j in range(vertex_count):
            graph[i][j] = int(input(f"Enter the weight of edge between vertex {i} and vertex {j}: "))

    # Read the source vertex from input
    source = int(input("Enter the source vertex: "))
    
    # Run Dijkstra's algorithm and output the shortest distances from the source vertex
    distances = dijkstra(graph, source)
    print("Shortest distances from source vertex", source, ":")
    for i in range(len(distances)):
        print(f"Vertex {i} : {distances[i]}")