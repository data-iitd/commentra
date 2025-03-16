
import sys

class Main:
    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0 for _ in range(numberofvertices + 1)] for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices

    def floydwarshall(self, adjacencyMatrix):
        # Initialize the distance matrix with the adjacency matrix.
        for source in range(1, self.numberofvertices + 1):
            self.distanceMatrix[source] = adjacencyMatrix[source][:]

        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    # Update distance if a shorter path through the intermediate vertex exists.
                    if self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination] < self.distanceMatrix[source][destination]:
                        self.distanceMatrix[source][destination] = self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination]

    def printDistanceMatrix(self):
        # Print the distance matrix
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                if self.distanceMatrix[source][destination] == sys.maxsize:
                    print("INF", end="\t")
                else:
                    print(self.distanceMatrix[source][destination], end="\t")
            print()

if __name__ == "__main__":
    numberofvertices = int(input())

    adjacencyMatrix = []
    for _ in range(numberofvertices):
        row = list(map(int, input().split()))
        adjacencyMatrix.append(row)

    floydWarshall = Main(numberofvertices)
    floydWarshall.floydwarshall(adjacencyMatrix)

    print("Shortest path matrix:")
    floydWarshall.printDistanceMatrix()

