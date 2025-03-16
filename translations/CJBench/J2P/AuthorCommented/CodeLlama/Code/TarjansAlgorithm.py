
import sys


def strongly_connected_components(v, graph):
    # Initialize arrays for insertion time and low-link values
    low_time = [0] * v
    insertion_time = [0] * v
    is_in_stack = [False] * v
    stack = []

    for i in range(v):
        insertion_time[i] = -1
        low_time[i] = -1

    for i in range(v):
        if insertion_time[i] == -1:
            dfs(i, low_time, insertion_time, is_in_stack, stack, graph)

    return scc_list


def dfs(u, low_time, insertion_time, is_in_stack, stack, graph):
    global time
    insertion_time[u] = time
    low_time[u] = time
    time += 1

    stack.append(u)
    is_in_stack[u] = True

    for v in graph[u]:
        if insertion_time[v] == -1:
            dfs(v, low_time, insertion_time, is_in_stack, stack, graph)
            low_time[u] = min(low_time[u], low_time[v])
        elif is_in_stack[v]:
            low_time[u] = min(low_time[u], insertion_time[v])

    if low_time[u] == insertion_time[u]:
        scc = []
        w = 0
        while w != u:
            w = stack.pop()
            scc.append(w)
            is_in_stack[w] = False
        scc_list.append(scc)


if __name__ == "__main__":
    # Read number of vertices and edges
    vertices = int(sys.stdin.readline())
    edges = int(sys.stdin.readline())

    # Build adjacency list
    graph = [[] for _ in range(vertices)]
    for _ in range(edges):
        from_vertex, to_vertex = map(int, sys.stdin.readline().split())
        graph[from_vertex].append(to_vertex)

    # Run Tarjan's Algorithm
    time = 0
    scc_list = []
    strongly_connected_components(vertices, graph)

    # Print the results
    for scc in scc_list:
        print(scc)

    # 