
import sys

class Main:
    # Number of vertices and edges in the graph
    vertex = 0
    edge = 0
    # Array to store edges
    edges = []
    # Index to keep track of the current edge position
    index = 0

    # Constructor to initialize the graph with a given number of vertices and edges
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = [None] * e # Initialize the edges array

    # Inner class to represent an edge in the graph
    class Edge:
        # Start vertex of the edge
        u = 0
        # End vertex of the edge
        v = 0
        # Weight of the edge
        w = 0

        # Constructor to create an edge with specified vertices and weight
        def __init__(self, a, b, c):
            self.u = a
            self.v = b
            self.w = c

    # Method to add an edge to the graph
    def addEdge(self, x, y, z):
        self.edges[self.index] = Main.Edge(x, y, z) # Create a new edge and add it to the array
        self.index += 1 # Increment the index

    # Method to retrieve the array of edges
    def getEdgeArray(self):
        return self.edges # Return the edges array

    # Recursive method to print the path from the source to a given vertex
    def printPath(self, parent, vertex):
        if parent[vertex] == -1: # Base case: if there is no parent
            return
        self.printPath(parent, parent[vertex]) # Recursively print the parent path
        print(vertex, end=" ") # Print the current vertex

    # Method to execute the Bellman-Ford algorithm from a given source vertex
    def execute(self, source):
        # Arrays to store distances and parent vertices
        dist = [sys.maxsize] * self.vertex
        parent = [-1] * self.vertex

        # Initialize distances to infinity and parents to -1
        for i in range(self.vertex):
            dist[i] = sys.maxsize # Set initial distances to max value
            parent[i] = -1 # Set initial parents to -1 (no parent)
        dist[source] = 0 # Distance from source to itself is 0

        # Relax edges repeatedly
        for i in range(self.vertex - 1):
            for j in range(self.edge):
                e = self.edges[j] # Get the edge
                # Check if the edge can be relaxed
                if dist[e.u] != sys.maxsize and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w # Update distance
                    parent[e.v] = e.u # Update parent

        # Check for negative weight cycles
        for j in range(self.edge):
            e = self.edges[j]
            # If we can still relax an edge, a negative cycle exists
            if dist[e.u] != sys.maxsize and dist[e.v] > dist[e.u] + e.w:
                print("Negative cycle detected")
                return # Exit the method if a negative cycle is found

        # Print the distances from the source to each vertex
        print("Vertex distances from source:")
        for i in range(self.vertex):
            print("Vertex: " + str(i) + ", Distance: " + str(dist[i]))

        # Print the paths from the source to each vertex
        print("Paths:")
        for i in range(self.vertex):
            print("Path to " + str(i) + ": " + str(source) + " ", end="")
            self.printPath(parent, i) # Print the path using the parent array
            print()

# Main method to run the program
def main():
    sc = sys.stdin # Create a scanner for input
    v = int(sc.readline()) # Read number of vertices
    e = int(sc.readline()) # Read number of edges
    bf = Main(v, e) # Create a new graph instance

    # Read edges from input
    for i in range(e):
        u = int(sc.readline()) # Start vertex
        ve = int(sc.readline()) # End vertex
        w = int(sc.readline()) # Weight of the edge
        bf.addEdge(u, ve, w) # Add the edge to the graph

    source = int(sc.readline()) # Read the source vertex
    bf.execute(source) # Execute the Bellman-Ford algorithm

if __name__ == "__main__":
    main()
