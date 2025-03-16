
import sys
import array

def find_main(graph):
    if len(graph) == 1:
        return [0, 0]
    vertex = len(graph)
    cycle = array.array('i', [-1] * (vertex + 1))
    path_count = 1
    cycle[0] = 0
    if not is_path_found(0):
        cycle.fill(-1)
    else:
        cycle[cycle.length - 1] = cycle[0]
    return cycle

def is_path_found(vertex):
    if graph[vertex][0] == 1 and path_count == vertex:
        return True
    if path_count == vertex:
        return False
    for v in range(vertex):
        if graph[vertex][v] == 1:
            cycle[path_count] = v
            graph[vertex][v] = 0
            graph[v][vertex] = 0
            if not is_present(v):
                return is_path_found(v)
            graph[vertex][v] = 1
            graph[v][vertex] = 1
            cycle[path_count - 1] = -1
    return False

def is_present(vertex):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True
    return False

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    graph = []
    for _ in range(n):
        graph.append([int(i) for i in sys.stdin.readline().split()])
    hamiltonian_cycle = find_main(graph)
    print("Hamiltonian Cycle:")
    if hamiltonian_cycle[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in hamiltonian_cycle:
            print(vertex, end=" ")
    print("