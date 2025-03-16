
import sys

def find_main(graph):
    # If the graph has only one vertex, return a trivial cycle
    if len(graph) == 1:
        return [0, 0]
    
    # Initialize the number of vertices and cycle array
    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    cycle[0] = 0
    path_count = 1
    
    # Check if a Hamiltonian path can be found starting from vertex 0
    if not is_path_found(graph, cycle, path_count):
        cycle = [-1] * (vertex + 1) # Reset cycle if no path is found
    
    # Close the cycle
    cycle[vertex] = cycle[0]
    
    return cycle

# Recursive method to find the Hamiltonian path
def is_path_found(graph, cycle, path_count):
    # Check if we have returned to the starting vertex and visited all vertices
    if graph[cycle[path_count - 1]][0] == 1 and path_count == vertex:
        return True # Hamiltonian cycle found
    
    # If all vertices are visited but not returning to start, return false
    if path_count == vertex:
        return False
    
    # Explore all adjacent vertices
    for v in range(vertex):
        # If there is an edge to the adjacent vertex
        if graph[cycle[path_count - 1]][v] == 1:
            cycle[path_count] = v # Add vertex to cycle
            graph[cycle[path_count - 1]][v] = 0 # Remove edge from graph
            graph[v][cycle[path_count - 1]] = 0 # Remove reverse edge
            
            # Check if the vertex is already in the cycle
            if not is_present(cycle, v):
                # Recursively search for the next vertex
                if is_path_found(graph, cycle, path_count + 1):
                    return True # Path found
            
            # Backtrack: restore the edge and remove the vertex from the cycle
            graph[cycle[path_count - 1]][v] = 1 # Restore edge
            graph[v][cycle[path_count - 1]] = 1 # Restore reverse edge
            cycle[path_count] = -1 # Remove vertex from cycle
    
    return False # No path found

# Method to check if a vertex is already in the cycle
def is_present(cycle, vertex):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True # Vertex is present in the cycle
    
    return False # Vertex is not present

# Main method to execute the program
def main():
    n = int(input("Enter the number of vertices: "))
    graph = [[0 for _ in range(n)] for _ in range(n)] # Initialize the graph
    
    # Read the adjacency matrix from input
    for i in range(n):
        for j in range(n):
            graph[i][j] = int(input(f"Enter the value for graph[{i}][{j}]: "))
    
    # Find the Hamiltonian cycle
    result = find_main(graph)
    
    # Output the result
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.") # No cycle found
    else:
        for vertex in result:
            print(vertex, end=" ") # Print the cycle
    
    sys.exit(0)

if __name__ == "__main__":
    main()

