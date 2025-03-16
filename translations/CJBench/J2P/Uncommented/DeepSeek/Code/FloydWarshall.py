import sys

class Main:
    INFINITY = 999

    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices

    def floydwarshall(self, adjacencyMatrix):
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                self.distanceMatrix[source][destination] = adjacencyMatrix[source][destination]

        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    if self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination] < self.distanceMatrix[source][destination]:
                        self.distanceMatrix[source][destination] = self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination]

    def printDistanceMatrix(self):
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                if self.distanceMatrix[source][destination] == self.INFINITY:
                    print("INF", end="\t")
                else:
                    print(self.distanceMatrix[source][destination], end="\t")
            print()

if __name__ == "__main__":
    numberofvertices = int(input())
    adjacencyMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            adjacencyMatrix[i][j] = int(input())

    floydWarshall = Main(numberofvertices)
    floydWarshall.floydwarshall(adjacencyMatrix)
    print("Shortest path matrix:")
    floydWarshall.printDistanceMatrix()
