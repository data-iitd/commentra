

import sys

def johnsons_algorithm(graph):
    vertices = len(graph)
    modified_weights = bellman_ford(graph)
    reweighted_graph = reweight_graph(graph, modified_weights)
    shortest_paths = []
    for i in range(vertices):
        shortest_paths.append(dijkstra(reweighted_graph, i, modified_weights))
    return shortest_paths

def bellman_ford(graph):
    vertices = len(graph) + 1
    dist = [sys.maxsize] * vertices
    dist[vertices - 1] = 0
    edges = []
    for i in range(vertices - 1):
        for j in range(vertices - 1):
            if graph[i][j]!= sys.maxsize:
                edges.append((i, j, graph[i][j]))
    for i in range(vertices - 1):
        edges.append((vertices - 1, i, 0))
    for i in range(vertices):
        for u, v, w in edges:
            if dist[u]!= sys.maxsize and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    for u, v, w in edges:
        if dist[u]!= sys.maxsize and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")
    return dist[:vertices - 1]

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[sys.maxsize] * vertices for _ in range(vertices)]
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j]!= sys.maxsize:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
    return reweighted_graph

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [sys.maxsize] * vertices
    visited = [False] * vertices
    dist[source] = 0
    for _ in range(vertices - 1):
        u = min_distance(dist, visited)
        visited[u] = True
        for v in range(vertices):
            if not visited[v] and graph[u][v]!= sys.maxsize and dist[u]!= sys.maxsize and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
    for i in range(vertices):
        if dist[i]!= sys.maxsize:
            dist[i] = dist[i] - weights[source] + weights[i]
    return dist

def min_distance(dist, visited):
    min_dist, min_index = sys.maxsize, -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_dist:
            min_dist = dist[v]
            min_index = v
    return min_index

def print_distances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        print(" ".join(map(lambda x: str(x) if x!= sys.maxsize else "INF", row)))

# 