class FloydWarshall:
    INFINITY = 999

    def __init__(self, number_of_vertices):
        self.distance_matrix = [[0] * (number_of_vertices + 1) for _ in range(number_of_vertices + 1)]
        self.number_of_vertices = number_of_vertices

    def floyd_warshall(self, adjacency_matrix):
        # Initialize the distance matrix with the adjacency matrix.
        for source in range(1, self.number_of_vertices + 1):
            for destination in range(1, self.number_of_vertices + 1):
                self.distance_matrix[source][destination] = adjacency_matrix[source][destination]

        for intermediate in range(1, self.number_of_vertices + 1):
            for source in range(1, self.number_of_vertices + 1):
                for destination in range(1, self.number_of_vertices + 1):
                    # Update distance if a shorter path through the intermediate vertex exists.
                    if (self.distance_matrix[source][intermediate] + 
                        self.distance_matrix[intermediate][destination] < 
                        self.distance_matrix[source][destination]):
                        self.distance_matrix[source][destination] = (self.distance_matrix[source][intermediate] + 
                                                                     self.distance_matrix[intermediate][destination])

    def print_distance_matrix(self):
        # Print the distance matrix
        for source in range(1, self.number_of_vertices + 1):
            for destination in range(1, self.number_of_vertices + 1):
                if self.distance_matrix[source][destination] == self.INFINITY:
                    print("INF", end="\t")
                else:
                    print(self.distance_matrix[source][destination], end="\t")
            print()

if __name__ == "__main__":
    number_of_vertices = int(input())

    adjacency_matrix = [[0] * (number_of_vertices + 1) for _ in range(number_of_vertices + 1)]
    for i in range(1, number_of_vertices + 1):
        for j in range(1, number_of_vertices + 1):
            adjacency_matrix[i][j] = int(input())

    floyd_warshall = FloydWarshall(number_of_vertices)
    floyd_warshall.floyd_warshall(adjacency_matrix)

    print("Shortest path matrix:")
    floyd_warshall.print_distance_matrix()

# <END-OF-CODE>
