
import sys

class Main:
    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0 for _ in range(numberofvertices + 1)] for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices
        self.INFINITY = 999

    def floydwarshall(self, adjacencyMatrix):
        # Copy the adjacency matrix to the distance matrix
        for source in range(1, self.numberofvertices + 1):
            self.distanceMatrix[source] = adjacencyMatrix[source][:]
        # Compute the shortest paths
        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    if self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination] < self.distanceMatrix[source][destination]:
                        self.distanceMatrix[source][destination] = self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination]

    def printDistanceMatrix(self):
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                if self.distanceMatrix[source][destination] == self.INFINITY:
                    sys.stdout.write("INF\t")
                else:
                    sys.stdout.write(str(self.distanceMatrix[source][destination]) + "\t")
            sys.stdout.write("\n")

# Read the number of vertices and adjacency matrix
numberofvertices = int(input())
adjacencyMatrix = [[0 for _ in range(numberofvertices + 1)] for _ in range(numberofvertices + 1)]
# Read the adjacency matrix
for i in range(1, numberofvertices + 1):
    for j in range(1, numberofvertices + 1):
        adjacencyMatrix[i][j] = int(input())

floydWarshall = Main(numberofvertices)
floydWarshall.floydwarshall(adjacencyMatrix)
print("Shortest path matrix:")
floydWarshall.printDistanceMatrix()

