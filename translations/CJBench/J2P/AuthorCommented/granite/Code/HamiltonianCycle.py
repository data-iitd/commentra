

import sys

def find_hamiltonian_cycle(graph):
    # Single vertex graph
    if len(graph) == 1:
        return [0, 0]

    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    # Initialize the cycle array with -1 to represent unvisited vertices
    for i in range(vertex + 1):
        cycle[i] = -1

    path_count = 1
    cycle[0] = 0
    if not is_path_found(graph, cycle, path_count, vertex):
        for i in range(vertex + 1):
            cycle[i] = -1

    cycle[vertex] = cycle[0]
    return cycle

def is_path_found(graph, cycle, path_count, vertex):
    if graph[cycle[path_count - 1]][0] == 1 and path_count == vertex:
        return True

    # If all vertices are visited but the last vertex is not connected to the start
    if path_count == vertex:
        return False

    for v in range(vertex):
        if graph[cycle[path_count - 1]][v] == 1:
            cycle[path_count] = v
            graph[cycle[path_count - 1]][v] = 0
            graph[v][cycle[path_count - 1]] = 0

            # Recursively attempt to complete the cycle
            if not is_present(cycle, v):
                return is_path_found(graph, cycle, path_count + 1, vertex)

            # Restore the edge if the path does not work
            graph[cycle[path_count - 1]][v] = 1
            graph[v][cycle[path_count - 1]] = 1
            cycle[path_count] = -1

    return False

def is_present(cycle, vertex):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True
    return False

if __name__ == "__main__":
    n = int(input())

    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))

    result = find_hamiltonian_cycle(graph)

    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result:
            print(vertex, end=" ")

