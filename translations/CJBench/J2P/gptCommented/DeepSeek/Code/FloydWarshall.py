import sys

class Main:
    # 2D array to hold the distance matrix
    distance_matrix = []
    # Number of vertices in the graph
    number_of_vertices = 0
    # Constant to represent infinity
    INFINITY = 999

    # Constructor to initialize the distance matrix and number of vertices
    def __init__(self, number_of_vertices):
        self.number_of_vertices = number_of_vertices
        self.distance_matrix = [[0] * (number_of_vertices + 1) for _ in range(number_of_vertices + 1)]
        for i in range(number_of_vertices + 1):
            for j in range(number_of_vertices + 1):
                if i == j:
                    self.distance_matrix[i][j] = 0
                else:
                    self.distance_matrix[i][j] = self.INFINITY

    # Method to perform the Floyd-Warshall algorithm
    def floyd_warshall(self, adjacency_matrix):
        # Initialize the distance matrix with the adjacency matrix values
        for source in range(1, self.number_of_vertices + 1):
            for destination in range(1, self.number_of_vertices + 1):
                self.distance_matrix[source][destination] = adjacency_matrix[source][destination]

        # Update the distance matrix with the shortest paths
        for intermediate in range(1, self.number_of_vertices + 1):
            for source in range(1, self.number_of_vertices + 1):
                for destination in range(1, self.number_of_vertices + 1):
                    # Check if a shorter path exists through the intermediate vertex
                    if self.distance_matrix[source][intermediate] + self.distance_matrix[intermediate][destination] < self.distance_matrix[source][destination]:
                        self.distance_matrix[source][destination] = self.distance_matrix[source][intermediate] + self.distance_matrix[intermediate][destination]

    # Method to print the distance matrix
    def print_distance_matrix(self):
        for source in range(1, self.number_of_vertices + 1):
            for destination in range(1, self.number_of_vertices + 1):
                # Print "INF" for unreachable paths
                if self.distance_matrix[source][destination] == self.INFINITY:
                    print("INF", end="\t")
                else:
                    # Print the distance for reachable paths
                    print(self.distance_matrix[source][destination], end="\t")
            # Move to the next line after printing each row
            print()

    # Main method to execute the program
    @staticmethod
    def main():
        # Create a scanner object for input
        scanner = sys.stdin
        # Read the number of vertices from user input
        number_of_vertices = int(next(scanner).strip())
        # Initialize the adjacency matrix
        adjacency_matrix = [[0] * (number_of_vertices + 1) for _ in range(number_of_vertices + 1)]

        # Read the adjacency matrix values from user input
        for i in range(1, number_of_vertices + 1):
            row = list(map(int, next(scanner).strip().split()))
            for j in range(1, number_of_vertices + 1):
                adjacency_matrix[i][j] = row[j - 1]

        # Create an instance of Main and execute the Floyd-Warshall algorithm
        floyd_warshall = Main(number_of_vertices)
        floyd_warshall.floyd_warshall(adjacency_matrix)

        # Print the resulting shortest path matrix
        print("Shortest path matrix:")
        floyd_warshall.print_distance_matrix()

# Call the main method to execute the program
Main.main()
