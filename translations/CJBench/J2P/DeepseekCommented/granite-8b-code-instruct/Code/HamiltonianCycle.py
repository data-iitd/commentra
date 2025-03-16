
import sys
sys.setrecursionlimit(10000)

def find_main(graph, vertex, path_count, cycle):
    if len(graph) == 1:
        return [0, 0]
    n = len(graph)
    cycle = [0] * (n + 1)
    cycle[0] = 0
    path_count = 1
    if not is_path_found(graph, vertex, path_count, cycle):
        cycle = [-1] * (n + 1)
    else:
        cycle[n] = cycle[0]
    return cycle

def is_path_found(graph, vertex, path_count, cycle):
    if graph[vertex][0] == 1 and path_count == n:
        return True
    if path_count == n:
        return False
    for v in range(n):
        if graph[vertex][v] == 1:
            cycle[path_count] = v
            graph[vertex][v] = 0
            graph[v][vertex] = 0
            if not is_present(cycle, v):
                if is_path_found(graph, v, path_count + 1, cycle):
                    return True
            graph[vertex][v] = 1
            graph[v][vertex] = 1
            cycle[path_count - 1] = -1
    return False

def is_present(cycle, vertex):
    for i in range(path_count - 1):
        if cycle[i] == vertex:
            return True
    return False

if __name__ == "__main__":
    n = int(input())
    graph = [[0] * n for _ in range(n)]
    for i in range(n):
        graph[i] = list(map(int, input().split()))
    hamiltonian_cycle = find_main(graph, 0, 0, [])
    print("Hamiltonian Cycle:")
    if hamiltonian_cycle[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in hamiltonian_cycle:
            print(vertex, end=" ")

