import sys

# Function to perform the Floyd-Warshall algorithm
def floyd_warshall(adjacency_matrix):
    # Initialize the distance matrix with the adjacency matrix values
    distance_matrix = [[adjacency_matrix[i][j] for j in range(len(adjacency_matrix))] for i in range(len(adjacency_matrix))]

    # Update the distance matrix with the shortest paths
    for intermediate in range(len(adjacency_matrix)):
        for source in range(len(adjacency_matrix)):
            for destination in range(len(adjacency_matrix)):
                # Check if a shorter path exists through the intermediate vertex
                if distance_matrix[source][intermediate] + distance_matrix[intermediate][destination] < distance_matrix[source][destination]:
                    distance_matrix[source][destination] = distance_matrix[source][intermediate] + distance_matrix[intermediate][destination]

    return distance_matrix

# Main function to execute the program
def main():
    # Read the number of vertices from user input
    number_of_vertices = int(sys.stdin.readline())
    # Initialize the adjacency matrix
    adjacency_matrix = [[0 for i in range(number_of_vertices + 1)] for j in range(number_of_vertices + 1)]

    # Read the adjacency matrix values from user input
    for i in range(number_of_vertices):
        for j in range(number_of_vertices):
            adjacency_matrix[i + 1][j + 1] = int(sys.stdin.readline())

    # Execute the Floyd-Warshall algorithm
    distance_matrix = floyd_warshall(adjacency_matrix)

    # Print the resulting shortest path matrix
    print("Shortest path matrix:")
    for i in range(number_of_vertices):
        for j in range(number_of_vertices):
            # Print "INF" for unreachable paths
            if distance_matrix[i + 1][j + 1] == 999:
                print("INF\t", end="")
            # Print the distance for reachable paths
            else:
                print(distance_matrix[i + 1][j + 1], "\t", end="")
        print()

if __name__ == "__main__":
    main()

