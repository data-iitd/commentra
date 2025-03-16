import sys

# Class to represent a graph
class Graph:
    # Constructor to initialize the graph
    def __init__(self, numberofvertices):
        # Number of vertices in the graph
        self.numberofvertices = numberofvertices
        # Adjacency matrix to represent the graph
        self.adjacencymatrix = [[0 for column in range(numberofvertices + 1)] for row in range(numberofvertices + 1)]

    # Method to add an edge to the graph
    def addedge(self, source, destination, weight):
        self.adjacencymatrix[source][destination] = weight

    # Method to perform the Floyd-Warshall algorithm
    def floydwarshall(self):
        # Initialize the distance matrix with the adjacency matrix values
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                self.adjacencymatrix[source][destination] = self.adjacencymatrix[source][destination]

        # Update the distance matrix with the shortest paths
        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    # Check if a shorter path exists through the intermediate vertex
                    if self.adjacencymatrix[source][intermediate] + self.adjacencymatrix[intermediate][destination] < self.adjacencymatrix[source][destination]:
                        self.adjacencymatrix[source][destination] = self.adjacencymatrix[source][intermediate] + self.adjacencymatrix[intermediate][destination]

    # Method to print the distance matrix
    def printdistancematrix(self):
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                # Print "INF" for unreachable paths
                if self.adjacencymatrix[source][destination] == sys.maxsize:
                    print("INF\t", end="")
                else:
                    # Print the distance for reachable paths
                    print(self.adjacencymatrix[source][destination] + "\t", end="")
            # Move to the next line after printing each row
            print()

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of vertices from user input
    numberofvertices = int(input())
    # Initialize the adjacency matrix
    adjacencymatrix = [[0 for column in range(numberofvertices + 1)] for row in range(numberofvertices + 1)]

    # Read the adjacency matrix values from user input
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            adjacencymatrix[i][j] = int(input())

    # Create an instance of Graph and execute the Floyd-Warshall algorithm
    graph = Graph(numberofvertices)
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            graph.addedge(i, j, adjacencymatrix[i][j])
    graph.floydwarshall()

    # Print the resulting shortest path matrix
    print("Shortest path matrix:")
    graph.printdistancematrix()

# 