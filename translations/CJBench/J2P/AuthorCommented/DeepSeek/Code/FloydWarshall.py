import sys

class Main:
    INFINITY = 999

    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices

    def floydwarshall(self, adjacencyMatrix):
        # Initialize the distance matrix with the adjacency matrix.
        for source in range(1, self.numberofvertices + 1):
            self.distanceMatrix[source][1:] = adjacencyMatrix[source][1:]

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
                if self.distanceMatrix[source][destination] == self.INFINITY:
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

    adjacencyMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            adjacencyMatrix[i][j] = int(data[index])
            index += 1

    floydWarshall = Main(numberofvertices)
    floydWarshall.floydwarshall(adjacencyMatrix)

    print("Shortest path matrix:")
    floydWarshall.printDistanceMatrix()
