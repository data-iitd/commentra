

vertex = int(input())
graph = [[0 for _ in range(vertex)] for _ in range(vertex)]
for i in range(vertex):
    graph[i] = list(map(int, input().split()))
cycle = [-1 for _ in range(vertex + 1)]
cycle[0] = 0
path_count = 1
def is_path_found(vertex):
    global path_count
    if graph[vertex][0] == 1 and path_count == vertex + 1:
        return True
    if path_count == vertex + 1:
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
cycle[vertex] = cycle[0]
if not is_path_found(0):
    cycle = [-1 for _ in range(vertex + 1)]
print("Hamiltonian Cycle:")
if cycle[0] == -1:
    print("No Hamiltonian Cycle exists.")
else:
    for vertex in cycle:
        print(vertex, end=" ")
