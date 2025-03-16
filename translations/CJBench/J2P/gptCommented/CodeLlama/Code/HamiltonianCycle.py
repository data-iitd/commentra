import sys

def find_main(graph):
    # If the graph has only one vertex, return a trivial cycle
    if len(graph) == 1:
        return [0, 0]
    
    # Initialize the number of vertices and cycle array
    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    cycle[0] = 0 # Start the cycle with the first vertex
    path_count = 1 # Initialize path count
    
    # Check if a Hamiltonian path can be found starting from vertex 0
    if not is_path_found(0, graph):
        cycle = [-1] * (vertex + 1) # Reset cycle if no path is found
    else:
        cycle[vertex] = cycle[0] # Close the cycle
    
    return cycle # Return the found cycle

def is_path_found(vertex, graph):
    # Check if we have returned to the starting vertex and visited all vertices
    if graph[vertex][0] == 1 and path_count == vertex:
        return True # Hamiltonian cycle found
    
    # If all vertices are visited but not returning to start, return false
    if path_count == vertex:
        return False
    
    # Explore all adjacent vertices
    for v in range(vertex):
        # If there is an edge to the adjacent vertex
        if graph[vertex][v] == 1:
            cycle[path_count] = v # Add vertex to cycle
            graph[vertex][v] = 0 # Remove edge from graph
            graph[v][vertex] = 0 # Remove reverse edge
            
            # Check if the vertex is already in the cycle
            if not is_present(v, cycle):
                # Recursively search for the next vertex
                if is_path_found(v, graph):
                    return True # Path found
            else:
                graph[vertex][v] = 1 # Restore edge
                graph[v][vertex] = 1 # Restore reverse edge
                cycle[path_count] = -1 # Remove vertex from cycle
    
    return False # No path found

def is_present(vertex, cycle):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True # Vertex is present in the cycle
    return False # Vertex is not present

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of vertices
    n = int(sys.stdin.readline())
    graph = [[0] * n for _ in range(n)] # Initialize the graph
    
    # Read the adjacency matrix from input
    for i in range(n):
        for j in range(n):
            graph[i][j] = int(sys.stdin.readline())
    
    # Create an instance of Main to find the Hamiltonian cycle
    result = find_main(graph) # Find the cycle
    
    # Output the result
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.") # No cycle found
    else:
        for vertex in result:
            print(vertex, end=" ") # Print the cycle
    print()

