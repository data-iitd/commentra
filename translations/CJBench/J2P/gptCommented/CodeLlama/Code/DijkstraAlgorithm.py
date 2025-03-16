import sys

class Main:
    # Number of vertices in the graph
    vertexCount = 0

    # Constructor to initialize the vertex count
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount

    # Method to run Dijkstra's algorithm and find shortest paths from the source vertex
    def run(self, graph, source):
        # Validate the source vertex index
        if source < 0 or source >= self.vertexCount:
            raise ValueError("Incorrect source vertex")

        # Array to hold the shortest distances from the source vertex
        distances = [sys.maxsize] * self.vertexCount
        # Array to track processed vertices
        processed = [False] * self.vertexCount

        # Initialize distances to infinity and processed array to false
        for i in range(self.vertexCount):
            distances[i] = sys.maxsize
            processed[i] = False

        # Distance from source to itself is always 0
        distances[source] = 0

        # Main loop to find shortest paths for all vertices
        for count in range(self.vertexCount - 1):
            # Get the vertex with the minimum distance that hasn't been processed yet
            u = self.getMinDistanceVertex(distances, processed)
            # Mark the vertex as processed
            processed[u] = True

            # Update distances for adjacent vertices of the processed vertex
            for v in range(self.vertexCount):
                # Check if the vertex is not processed, there is an edge, and the distance can be updated
                if not processed[v] and graph[u][v] != 0 and distances[u] != sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                    distances[v] = distances[u] + graph[u][v] # Update the distance

        # Return the array of shortest distances
        return distances

    # Helper method to find the vertex with the minimum distance value that has not been processed
    def getMinDistanceVertex(self, distances, processed):
        min = sys.maxsize # Initialize minimum distance
        minIndex = -1 # Initialize index of the vertex with minimum distance

        # Loop through all vertices to find the minimum distance vertex
        for v in range(self.vertexCount):
            if not processed[v] and distances[v] <= min:
                min = distances[v] # Update minimum distance
                minIndex = v # Update index of the vertex

        # Return the index of the vertex with the minimum distance
        return minIndex

# Main method to execute the program
def main():
    # Read the number of vertices from input
    vertexCount = int(input())
    # Initialize the graph as a 2D array
    graph = [[0] * vertexCount for _ in range(vertexCount)]

    # Read the graph's adjacency matrix from input
    for i in range(vertexCount):
        for j in range(vertexCount):
            graph[i][j] = int(input())

    # Read the source vertex from input
    source = int(input())
    
    # Create an instance of the Main class and run Dijkstra's algorithm
    dijkstra = Main(vertexCount)
    distances = dijkstra.run(graph, source)
    
    # Output the shortest distances from the source vertex
    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(len(distances)):
        print("Vertex " + str(i) + " : " + str(distances[i]))

# Call the main method
main()

