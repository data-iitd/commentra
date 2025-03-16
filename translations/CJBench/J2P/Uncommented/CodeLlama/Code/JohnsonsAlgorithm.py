
import sys
import math

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
    dist = [math.inf] * (vertices + 1)
    dist[-1] = 0
    edges = []
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != math.inf:
                edges.append((i, j, graph[i][j]))
    for i in range(vertices - 1):
        edges.append((vertices - 1, i, 0))
    for i in range(vertices):
        for edge in edges:
            u, v, w = edge
            if dist[u] != math.inf and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    for edge in edges:
        u, v, w = edge
        if dist[u] != math.inf and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")
    return dist[:-1]

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[0] * vertices for _ in range(vertices)]
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != math.inf:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = math.inf
    return reweighted_graph

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [math.inf] * vertices
    visited = [False] * vertices
    dist[source] = 0
    for count in range(vertices - 1):
        u = min_distance(dist, visited)
        visited[u] = True
        for v in range(vertices):
            if not visited[v] and graph[u][v] != math.inf and dist[u] != math.inf and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
    for i in range(vertices):
        if dist[i] != math.inf:
            dist[i] = dist[i] - weights[source] + weights[i]
    return dist

def min_distance(dist, visited):
    min = math.inf
    min_index = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min:
            min = dist[v]
            min_index = v
    return min_index

def print_distances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        for dist in row:
            print((dist if dist != math.inf else "INF") + " ", end="")
        print()

if __name__ == "__main__":
    graph = [[0, 5, 10, 15, 20],
             [5, 0, 3, 8, 12],
             [10, 3, 0, 1, 5],
             [15, 8, 1, 0, 7],
             [20, 12, 5, 7, 0]]
    distances = johnsons_algorithm(graph)
    print_distances(distances)

