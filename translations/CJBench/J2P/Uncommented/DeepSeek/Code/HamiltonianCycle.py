def find_main(graph):
    if len(graph) == 1:
        return [0, 0]
    vertex = len(graph)
    cycle = [-1] * (vertex + 1)
    path_count = 1
    graph_matrix = graph
    cycle[0] = 0

    def is_path_found(vertex):
        nonlocal path_count
        if graph_matrix[vertex][0] == 1 and path_count == vertex:
            return True
        if path_count == vertex:
            return False
        for v in range(vertex):
            if graph_matrix[vertex][v] == 1:
                cycle[path_count] = v
                path_count += 1
                graph_matrix[vertex][v] = 0
                graph_matrix[v][vertex] = 0
                if not is_present(v):
                    if is_path_found(v):
                        return True
                graph_matrix[vertex][v] = 1
                graph_matrix[v][vertex] = 1
                path_count -= 1
                cycle[path_count - 1] = -1
        return False

    def is_present(vertex):
        for i in range(path_count - 1):
            if cycle[i] == vertex:
                return True
        return False

    if not is_path_found(0):
        cycle = [-1] * (vertex + 1)
    else:
        cycle[path_count] = cycle[0]
    return cycle


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    graph = [[0] * n for _ in range(n)]
    index = 1
    for i in range(n):
        for j in range(n):
            graph[i][j] = int(data[index])
            index += 1
    result = find_main(graph)
    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result:
            print(vertex, end=" ")


main()
