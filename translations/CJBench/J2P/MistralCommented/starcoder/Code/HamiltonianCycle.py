
import sys

# Class to represent the Main class
class Main:
    # Number of vertices in the graph
    vertex = 0

    # Number of paths found in the graph
    pathCount = 0

    # Array to store the cycle of the Hamiltonian path or cycle
    cycle = []

    # 2D array to represent the graph
    graph = []

    # Function to find the main path or cycle in the graph
    def findMain(self, graph):
        # Base case: If the graph has only one vertex, return an empty cycle
        if len(graph) == 1:
            return []

        # Initialize the variables
        self.vertex = len(graph)
        self.cycle = [-1] * (self.vertex + 1)
        self.cycle[0] = 0
        self.pathCount = 1

        # If no path is found, initialize the cycle array with -1 and return it
        if not self.isPathFound(0):
            self.cycle = [-1] * (self.vertex + 1)
            return self.cycle

        # Set the last vertex of the cycle to the first vertex
        self.cycle[len(self.cycle) - 1] = self.cycle[0]

        return self.cycle

    # Function to check if a path is found from the given vertex
    def isPathFound(self, vertex):
        # Base case: If all vertices have been visited and the path count equals the number of vertices,
        # return true as a Hamiltonian path or cycle has been found
        if self.graph[vertex][0] == 1 and self.pathCount == self.vertex:
            return True

        # If all vertices have been visited, return false as no Hamiltonian path or cycle exists
        if self.pathCount == self.vertex:
            return False

        # Iterate through all the adjacent vertices and check if a path exists to them
        for v in range(self.vertex):
            if self.graph[vertex][v] == 1:
                # Add the current vertex to the path and recursively check if a path exists to the adjacent vertex
                self.cycle[self.pathCount] = v
                self.graph[vertex][v] = 0
                self.graph[v][vertex] = 0

                # If a path is found, return true
                if self.isPathFound(v):
                    return True

                # Backtrack and restore the graph to its original state
                self.graph[vertex][v] = 1
                self.graph[v][vertex] = 1
                self.cycle[self.pathCount] = -1

        # If no path is found, return false
        return False

    # Function to check if a vertex is already present in the cycle
    def isPresent(self, vertex):
        # Iterate through the cycle array and check if the given vertex is present
        for i in range(self.pathCount - 1):
            if self.cycle[i] == vertex:
                return True

        # If the vertex is not present, return false
        return False

    # Main function to read the input and call the findMain function
    def main(self):
        # Read the number of vertices from the input
        self.vertex = int(input())

        # Initialize the 2D array to represent the graph
        self.graph = [[0] * self.vertex for i in range(self.vertex)]

        # Read the edges of the graph from the input
        for i in range(self.vertex):
            for j in range(self.vertex):
                self.graph[i][j] = int(input())

        # Initialize the Main class and call the findMain function
        hamiltonianCycle = Main()
        result = hamiltonianCycle.findMain(self.graph)

        # Print the result
        print("Hamiltonian Cycle:")
        if result[0] == -1:
            print("No Hamiltonian Cycle exists.")
        else:
            # Print the vertices of the Hamiltonian cycle
            for vertex in result:
                print(vertex, end=" ")

        # End the program
        sys.exit(0)

# Create the Main class object and call the main function
if __name__ == "__main__":
    main = Main()
    main.main()

