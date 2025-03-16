
import sys

# Define the constant for infinity
INFINITY = 999

# Function to perform the Floyd-Warshall algorithm
def floyd_warshall(adjacency_matrix):
    # Initialize the distance matrix with the adjacency matrix values
    distance_matrix = [[0 for _ in range(len(adjacency_matrix))] for _ in range(len(adjacency_matrix))]
    for source in range(len(adjacency_matrix)):
        for destination in range(len(adjacency_matrix)):
            distance_matrix[source][destination] = adjacency_matrix[source][destination]

    # Update the distance matrix with the shortest paths
    for intermediate in range(len(adjacency_matrix)):
        for source in range(len(adjacency_matrix)):
            for destination in range(len(adjacency_matrix)):
                # Check if a shorter path exists through the intermediate vertex
                if distance_matrix[source][intermediate] + distance_matrix[intermediate][destination] < distance_matrix[source][destination]:
                    distance_matrix[source][destination] = distance_matrix[source][intermediate] + distance_matrix[intermediate][destination]

    return distance_matrix

# Function to print the distance matrix
def print_distance_matrix(distance_matrix):
    for source in range(len(distance_matrix)):
        for destination in range(len(distance_matrix)):
            # Print "INF" for unreachable paths
            if distance_matrix[source][destination] == INFINITY:
                print("INF", end="\t")
            else:
                # Print the distance for reachable paths
                print(distance_matrix[source][destination], end="\t")
        # Move to the next line after printing each row
        print()

# Main function to execute the program
def main():
    # Read the number of vertices from user input
    number_of_vertices = int(input("Enter the number of vertices: "))
    # Initialize the adjacency matrix
    adjacency_matrix = [[0 for _ in range(number_of_vertices)] for _ in range(number_of_vertices)]

    # Read the adjacency matrix values from user input
    for i in range(number_of_vertices):
        for j in range(number_of_vertices):
            adjacency_matrix[i][j] = int(input(f"Enter the value for adjacency matrix[{i}][{j}]: "))

    # Execute the Floyd-Warshall algorithm
    distance_matrix = floyd_warshall(adjacency_matrix)

    # Print the resulting shortest path matrix
    print("Shortest path matrix:")
    print_distance_matrix(distance_matrix)

# Call the main function to start the program
if __name__ == "__main__":
    main()

