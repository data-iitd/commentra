
import sys

# The Floyd-Warshall algorithm to compute the shortest paths between all pairs of vertices in a weighted graph.
# It handles both positive and negative edge weights but does not support negative cycles.
# The algorithm is based on dynamic programming and runs in O(V^3) time complexity,
# where V is the number of vertices in the graph.
#
# The distance matrix is updated iteratively to find the shortest distance between any two vertices
# by considering each vertex as an intermediate step.
#
# Reference: <a href="https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm">Floyd-Warshall Algorithm</a>

class FloydWarshall:
    def __init__(self, numberofvertices):
        self.distanceMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
        self.numberofvertices = numberofvertices

    # Executes the Floyd-Warshall algorithm to compute the shortest path between all pairs of vertices.
    # It uses an adjacency matrix to calculate the distance matrix by considering each vertex as an intermediate point.
    def floydwarshall(self, adjacencyMatrix):
        # Initialize the distance matrix with the adjacency matrix.
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                self.distanceMatrix[source][destination] = adjacencyMatrix[source][destination]

        for intermediate in range(1, self.numberofvertices + 1):
            for source in range(1, self.numberofvertices + 1):
                for destination in range(1, self.numberofvertices + 1):
                    # Update distance if a shorter path through the intermediate vertex exists.
                    if self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination] < self.distanceMatrix[source][destination]:
                        self.distanceMatrix[source][destination] = self.distanceMatrix[source][intermediate] + self.distanceMatrix[intermediate][destination]

    # Prints the distance matrix representing the shortest paths between all pairs of vertices.
    # The rows and columns correspond to the source and destination vertices.
    def printDistanceMatrix(self):
        # Print the distance matrix
        for source in range(1, self.numberofvertices + 1):
            for destination in range(1, self.numberofvertices + 1):
                if self.distanceMatrix[source][destination] == 999:
                    print("INF\t", end="")
                else:
                    print(self.distanceMatrix[source][destination] + "\t", end="")
            print()

if __name__ == "__main__":
    numberofvertices = int(sys.stdin.readline())

    adjacencyMatrix = [[0] * (numberofvertices + 1) for _ in range(numberofvertices + 1)]
    for i in range(1, numberofvertices + 1):
        for j in range(1, numberofvertices + 1):
            adjacencyMatrix[i][j] = int(sys.stdin.readline())

    floydWarshall = FloydWarshall(numberofvertices)
    floydWarshall.floydwarshall(adjacencyMatrix)

    print("Shortest path matrix:")
    floydWarshall.printDistanceMatrix()

