import sys

def find_main(graph):
    if len(graph) == 1:
        return [0, 0]
    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    cycle[0] = 0
    path_count = 1
    if not is_path_found(0, graph):
        cycle = [-1] * (vertex + 1)
    else:
        cycle[vertex] = cycle[0]
    return cycle

def is_path_found(vertex, graph):
    if graph[vertex][0] == 1 and path_count == vertex:
        return True
    if path_count == vertex:
        return False
    for v in range(vertex):
        if graph[vertex][v] == 1:
            cycle[path_count] = v
            graph[vertex][v] = 0
            graph[v][vertex] = 0
            if not is_present(v, graph):
                if is_path_found(v, graph):
                    return True
            graph[vertex][v] = 1
            graph[v][vertex] = 1
            cycle[path_count] = -1
    return False

def is_present(vertex, graph):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True
    return False

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    graph = [[int(i) for i in sys.stdin.readline().split()] for _ in range(n)]
    result = find_main(graph)
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result:
            print(vertex, end=" ")
    print("