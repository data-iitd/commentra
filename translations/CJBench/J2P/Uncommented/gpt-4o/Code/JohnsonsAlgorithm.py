import sys
import heapq

INF = sys.maxsize

def main():
    vertices = int(input())
    graph = []
    for i in range(vertices):
        row = input().split()
        graph.append([INF if value == "INF" else int(value) for value in row])
    
    shortest_paths = johnsons_algorithm(graph)
    print_distances(shortest_paths)

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
    dist = [INF] * vertices
    dist[vertices - 1] = 0
    edges = []

    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != INF:
                edges.append((i, j, graph[i][j]))

    for i in range(vertices - 1):
        edges.append((vertices - 1, i, 0))

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
    reweighted_graph = [[INF] * vertices for _ in range(vertices)]
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

    for i in range(vertices):
        if dist[i] != INF:
            dist[i] = dist[i] - weights[source] + weights[i]

    return dist

def min_distance(dist, visited):
    min_dist = INF
    min_index = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_dist:
            min_dist = dist[v]
            min_index = v
    return min_index

def print_distances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        print(" ".join("INF" if dist == INF else str(dist) for dist in row))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
