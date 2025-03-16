import sys
import numpy as np

INF = sys.maxsize

def johnsons_algorithm(graph):
    vertices = len(graph)
    modified_weights = bellman_ford(graph)
    reweighted_graph = reweight_graph(graph, modified_weights)
    shortest_paths = np.zeros((vertices, vertices), dtype=int)

    for i in range(vertices):
        shortest_paths[i] = dijkstra(reweighted_graph, i, modified_weights)

    return shortest_paths

def bellman_ford(graph):
    vertices = len(graph) + 1
    dist = [INF] * vertices
    dist[vertices - 1] = 0
    edges = []

    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != INF:
                edges.append([i, j, graph[i][j]])

    for _ in range(vertices - 1):
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = np.zeros((vertices, vertices), dtype=int)

    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != INF:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = INF

    return reweighted_graph

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [INF] * vertices
    visited = [False] * vertices
    dist[source] = 0

    for _ in range(vertices - 1):
        u = min_distance(dist, visited)
        visited[u] = True

        for v in range(vertices):
            if not visited[v] and graph[u][v] != INF and dist[u] != INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

    return dist

def min_distance(dist, visited):
    min_val = INF
    min_index = -1

    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_val:
            min_val = dist[v]
            min_index = v

    return min_index

def print_distances(shortest_paths):
    print("All-pairs shortest paths:")
    for row in shortest_paths:
        for dist in row:
            print("INF" if dist == INF else dist, end=" ")
        print()

# Read input
vertices = int(input())
graph = []

for _ in range(vertices):
    row = input().split()
    graph.append([INF if val == "INF" else int(val) for val in row])

shortest_paths = johnsons_algorithm(graph)
print_distances(shortest_paths)
