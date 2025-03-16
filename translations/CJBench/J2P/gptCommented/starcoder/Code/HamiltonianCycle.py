import sys

class Main:
    def __init__(self):
        self.vertex = 0
        self.pathCount = 0
        self.cycle = []
        self.graph = []

    # Method to find the Hamiltonian cycle in the given graph
    def findMain(self, graph):
        # If the graph has only one vertex, return a trivial cycle
        if len(graph) == 1:
            return [-1]
        
        # Initialize the number of vertices and cycle array
        self.vertex = len(graph)
        self.cycle = [-1] * (self.vertex + 1)
        self.cycle[0] = 0
        self.pathCount = 1
        
        # Check if a Hamiltonian path can be found starting from vertex 0
        if not self.isPathFound(0, graph):
            self.cycle = [-1] * (self.vertex + 1) # Reset cycle if no path is found
        else:
            self.cycle[self.vertex] = self.cycle[0] # Close the cycle
        return self.cycle

    # Recursive method to find the Hamiltonian path
    def isPathFound(self, vertex, graph):
        # Check if we have returned to the starting vertex and visited all vertices
        if graph[vertex][0] == 1 and self.pathCount == self.vertex:
            return True # Hamiltonian cycle found
        
        # If all vertices are visited but not returning to start, return false
        if self.pathCount == self.vertex:
            return False
        
        # Explore all adjacent vertices
        for v in range(self.vertex):
            # If there is an edge to the adjacent vertex
            if graph[vertex][v] == 1:
                self.cycle[self.pathCount] = v # Add vertex to cycle
                graph[vertex][v] = 0 # Remove edge from graph
                graph[v][vertex] = 0 # Remove reverse edge
                
                # Check if the vertex is already in the cycle
                if not self.isPresent(v):
                    # Recursively search for the next vertex
                    if self.isPathFound(v, graph):
                        return True # Path found
                # Backtrack: restore the edge and remove the vertex from the cycle
                graph[vertex][v] = 1 # Restore edge
                graph[v][vertex] = 1 # Restore reverse edge
                self.cycle[self.pathCount] = -1 # Remove vertex from cycle
        return False # No path found

    # Method to check if a vertex is already in the cycle
    def isPresent(self, vertex):
        for i in range(self.pathCount - 1):
            if self.cycle[i] == vertex:
                return True # Vertex is present in the cycle
        return False # Vertex is not present

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of vertices
    n = int(input())
    graph = [[0] * n for i in range(n)] # Initialize the graph
    
    # Read the adjacency matrix from input
    for i in range(n):
        for j in range(n):
            graph[i][j] = int(input())
    
    # Create an instance of Main to find the Hamiltonian cycle
    hamiltonianCycle = Main()
    result = hamiltonianCycle.findMain(graph) # Find the cycle
    
    # Output the result
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.") # No cycle found
    else:
        for vertex in result:
            print(vertex, end=" ") # Print the cycle

