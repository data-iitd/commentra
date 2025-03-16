
import sys

def johnsons_algorithm(graph):
    vertices = len(graph)
    modified_weights = bellman_ford(graph)
    reweighted_graph = reweight_graph(graph, modified_weights)
    shortest_paths = [[0] * vertices for _ in range(vertices)]

    for i in range(vertices):
        shortest_paths[i] = dijkstra(reweighted_graph, i, modified_weights)

    return shortest_paths

def bellman_ford(graph):
    vertices = len(graph)
    dist = [sys.maxsize] * (vertices + 1)
    dist[-1] = 0

    edges = []
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != sys.maxsize:
                edges.append((i, j, graph[i][j]))

    for i in range(vertices - 1):
        for edge in edges:
            u, v, w = edge
            if dist[u] != sys.maxsize and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for edge in edges:
        u, v, w = edge
        if dist[u] != sys.maxsize and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[0] * vertices for _ in range(vertices)]

    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != sys.maxsize:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = sys.maxsize

    return reweighted_graph

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [sys.maxsize] * vertices
    visited = [False] * vertices

    dist[source] = 0

    for count in range(vertices - 1):
        u = min_distance(dist, visited)
        visited[u] = True

        for v in range(vertices):
            if not visited[v] and graph[u][v] != sys.maxsize and dist[u] != sys.maxsize and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

    return dist

def min_distance(dist, visited):
    min = sys.maxsize
    min_index = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min:
            min = dist[v]
            min_index = v

    return min_index

def print_distances(shortest_paths):
    print("All-pairs shortest paths:")
    for row in shortest_paths:
        for dist in row:
            print((dist if dist != sys.maxsize else "INF") + " ", end="")
        print()

if __name__ == "__main__":
    scanner = sys.stdin
    vertices = int(scanner.readline())
    graph = [[0] * vertices for _ in range(vertices)]

    for i in range(vertices):
        for j in range(vertices):
            value = scanner.readline().strip()
            graph[i][j] = int(value) if value != "INF" else sys.maxsize

    shortest_paths = johnsons_algorithm(graph)
    print_distances(shortest_paths)

