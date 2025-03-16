import sys

class Main:
    INFINITY = 999

    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices
        for i in range(1, numberofvertices + 1):
            for j in range(1, numberofvertices + 1):
                if i == j:
                    self.distanceMatrix[i][j] = 0
                else:
                    self.distanceMatrix[i][j] = Main.INFINITY

    def floydwarshall(self, adjacencyMatrix):
        # Copy the adjacency matrix to the distance matrix
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                self.distanceMatrix[source][destination] = adjacencyMatrix[source][destination]
        # Compute the shortest paths
        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    if self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination] < self.distanceMatrix[source][destination]:
                        self.distanceMatrix[source][destination] = self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination]

    def printDistanceMatrix(self):
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                if self.distanceMatrix[source][destination] == Main.INFINITY:
                    print("INF", end="\t")
                else:
                    print(self.distanceMatrix[source][destination], end="\t")
            print()

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    numberofvertices = int(data[index])
    index += 1
    adjacencyMatrix = [[Main.INFINITY] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            adjacencyMatrix[i][j] = int(data[index])
            index += 1

    floydWarshall = Main(numberofvertices)
    floydWarshall.floydwarshall(adjacencyMatrix)
    print("Shortest path matrix:")
    floydWarshall.printDistanceMatrix()
