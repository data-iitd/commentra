import numpy as np

class Main:
    def __init__(self):
        self.vertex = 0  # Number of vertices in the graph
        self.path_count = 0  # Count of vertices in the current path
        self.cycle = []  # List to store the cycle path
        self.graph = []  # Adjacency matrix representation of the graph

    # Method to find the Hamiltonian cycle in the given graph
    def find_main(self, graph):
        # If the graph has only one vertex, return a trivial cycle
        if len(graph) == 1:
            return [0, 0]
        
        # Initialize the number of vertices and cycle array
        self.vertex = len(graph)
        self.cycle = [-1] * (self.vertex + 1)  # Fill cycle array with -1 to indicate unvisited
        self.graph = graph  # Set the graph
        self.cycle[0] = 0  # Start the cycle with the first vertex
        self.path_count = 1  # Initialize path count
        
        # Check if a Hamiltonian path can be found starting from vertex 0
        if not self.is_path_found(0):
            self.cycle = [-1] * (self.vertex + 1)  # Reset cycle if no path is found
        else:
            self.cycle[-1] = self.cycle[0]  # Close the cycle
        
        return self.cycle  # Return the found cycle

    # Recursive method to find the Hamiltonian path
    def is_path_found(self, vertex):
        # Check if we have returned to the starting vertex and visited all vertices
        if self.graph[vertex][0] == 1 and self.path_count == self.vertex:
            return True  # Hamiltonian cycle found
        
        # If all vertices are visited but not returning to start, return false
        if self.path_count == self.vertex:
            return False
        
        # Explore all adjacent vertices
        for v in range(self.vertex):
            # If there is an edge to the adjacent vertex
            if self.graph[vertex][v] == 1:
                self.cycle[self.path_count] = v  # Add vertex to cycle
                self.path_count += 1  # Increment path count
                self.graph[vertex][v] = 0  # Remove edge from graph
                self.graph[v][vertex] = 0  # Remove reverse edge
                
                # Check if the vertex is already in the cycle
                if not self.is_present(v):
                    # Recursively search for the next vertex
                    if self.is_path_found(v):
                        return True  # Path found
                
                # Backtrack: restore the edge and remove the vertex from the cycle
                self.graph[vertex][v] = 1  # Restore edge
                self.graph[v][vertex] = 1  # Restore reverse edge
                self.cycle[self.path_count - 1] = -1  # Remove vertex from cycle
                self.path_count -= 1  # Decrement path count
        
        return False  # No path found

    # Method to check if a vertex is already in the cycle
    def is_present(self, vertex):
        for i in range(self.path_count - 1):
            if self.cycle[i] == vertex:
                return True  # Vertex is present in the cycle
        return False  # Vertex is not present

# Main method to execute the program
if __name__ == "__main__":
    n = int(input("Enter the number of vertices: "))  # Read the number of vertices
    graph = np.zeros((n, n), dtype=int)  # Initialize the graph
    
    # Read the adjacency matrix from input
    for i in range(n):
        graph[i] = list(map(int, input().split()))
    
    # Create an instance of Main to find the Hamiltonian cycle
    hamiltonian_cycle = Main()
    result = hamiltonian_cycle.find_main(graph)  # Find the cycle
    
    # Output the result
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")  # No cycle found
    else:
        print(" ".join(map(str, result)))  # Print the cycle

# <END-OF-CODE>
