import sys

class Main:
    def __init__(self):
        self.vertex = 0
        self.pathCount = 0
        self.cycle = []
        self.graph = []

    # Method to find a Hamiltonian cycle in the graph
    def findMain(self, graph):
        if len(graph) == 1: # If the graph has only one vertex, return the single vertex as the cycle
            return [0, 0]
        self.vertex = len(graph) # Set the number of vertices
        self.cycle = [-1] * (self.vertex + 1) # Initialize the cycle array with size vertex + 1
        self.cycle[0] = 0 # Start the cycle from vertex 0
        self.pathCount = 1 # Initialize the path count to 1 (starting vertex is already included)
        if not self.isPathFound(0): # Try to find a path starting from vertex 0
            self.cycle = [-1] * (self.vertex + 1) # If no path is found, reset the cycle
        else:
            self.cycle[self.vertex] = self.cycle[0] # Complete the cycle by connecting the last vertex to the first
        return self.cycle # Return the found cycle

    # Recursive method to find a Hamiltonian path
    def isPathFound(self, vertex):
        if self.graph[vertex][0] == 1 and self.pathCount == self.vertex: # If the path includes the first vertex and all vertices are visited, a cycle is found
            return True
        if self.pathCount == self.vertex: # If all vertices are visited but the first vertex is not included, no cycle is found
            return False
        for v in range(self.vertex): # Iterate through all vertices
            if self.graph[vertex][v] == 1: # If there is an edge between the current vertex and v
                self.cycle[self.pathCount] = v # Add v to the path
                self.graph[vertex][v] = 0 # Mark the edge as used
                self.graph[v][vertex] = 0 # Mark the reverse edge as used
                if not self.isPresent(v): # Check if v is already in the path
                    return self.isPathFound(v) # Recursively find the path
                self.graph[vertex][v] = 1 # Unmark the edge as used
                self.graph[v][vertex] = 1 # Unmark the reverse edge as used
                self.cycle[self.pathCount] = -1 # Remove v from the path
        return False # If no path is found, return false

    # Method to check if a vertex is already in the current path
    def isPresent(self, vertex):
        for i in range(self.pathCount - 1): # Iterate through the current path
            if self.cycle[i] == vertex: # If the vertex is found in the path
                return True # Return true
        return False # If the vertex is not found, return false

if __name__ == "__main__":
    main = Main()
    n = int(sys.stdin.readline()) # Read the number of vertices
    graph = [[0] * n for i in range(n)] # Create an adjacency matrix for the graph
    for i in range(n): # Read the graph adjacency matrix
        graph[i] = list(map(int, sys.stdin.readline().split()))
    result = main.findMain(graph) # Find the Hamiltonian cycle
    print("Hamiltonian Cycle:")
    if result[0] == -1: # If no Hamiltonian cycle exists
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result: # Print the Hamiltonian cycle
            print(vertex, end=" ")

