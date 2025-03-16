
import sys

# Function to find the main path or cycle in the graph
def find_main(graph):
    # Base case: If the graph has only one vertex, return an empty cycle
    if len(graph) == 1:
        return [0, 0]

    # Initialize the variables
    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    cycle[0] = 0
    path_count = 1

    # If no path is found, initialize the cycle array with -1 and return it
    if not is_path_found(0):
        cycle = [-1] * (vertex + 1)
        return cycle

    # Set the last vertex of the cycle to the first vertex
    cycle[len(cycle) - 1] = cycle[0]

    return cycle

# Function to check if a path is found from the given vertex
def is_path_found(vertex):
    # Base case: If all vertices have been visited and the path count equals the number of vertices,
    # return true as a Hamiltonian path or cycle has been found
    if graph[vertex][0] == 1 and path_count == vertex:
        return True

    # If all vertices have been visited, return false as no Hamiltonian path or cycle exists
    if path_count == vertex:
        return False

    # Iterate through all the adjacent vertices and check if a path exists to them
    for v in range(vertex):
        if graph[vertex][v] == 1:
            # Add the current vertex to the path and recursively check if a path exists to the adjacent vertex
            cycle[path_count] = v
            graph[vertex][v] = 0
            graph[v][vertex] = 0

            # If a path is found, return true
            if is_path_found(v):
                return True

            # Backtrack and restore the graph to its original state
            graph[vertex][v] = 1
            graph[v][vertex] = 1
            cycle[path_count] = -1

    # If no path is found, return false
    return False

# Function to check if a vertex is already present in the cycle
def is_present(vertex):
    # Iterate through the cycle array and check if the given vertex is present
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True

    # If the vertex is not present, return false
    return False

# Main function to read the input and call the find_main function
def main():
    # Initialize the scanner to read the input
    scanner = sys.stdin

    # Read the number of vertices from the input
    n = int(scanner.readline().strip())

    # Initialize the 2D array to represent the graph
    graph = [[0] * n for _ in range(n)]

    # Read the edges of the graph from the input
    for i in range(n):
        for j in range(n):
            graph[i][j] = int(scanner.readline().strip())

    # Initialize the Main class and call the find_main function
    hamiltonian_cycle = find_main(graph)

    # Print the result
    print("Hamiltonian Cycle:")
    if hamiltonian_cycle[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        # Print the vertices of the Hamiltonian cycle
        for vertex in hamiltonian_cycle:
            print(vertex, end=" ")

# End of code
