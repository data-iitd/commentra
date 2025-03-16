
import sys

def johnsons_algorithm(graph):
    vertices = len(graph)

    # Step 1: Reweight graph using Bellman-Ford
    modified_weights = bellman_ford(graph)

    # Step 2: Reweight the graph
    reweighted_graph = reweight_graph(graph, modified_weights)

    # Step 3: Run Dijkstra's for all vertices
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
        edges.append((vertices - 1, i, 0))

    for i in range(vertices):
        for edge in edges:
            u, v, w = edge
            if dist[u] != sys.maxsize and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for edge in edges:
        u, v, w = edge
        if dist[u] != sys.maxsize and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]

def reweight_graph(graph, modified_weights):
    vertices = len(graph)
    reweighted_graph = [[0] * vertices for _ in range(vertices)]
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != sys.maxsize:
                reweighted_graph[i][j] = graph[i][j] + modified_weights[i] - modified_weights[j]
            else:
                reweighted_graph[i][j] = sys.maxsize
    return reweighted_graph

def dijkstra(reweighted_graph, source, modified_weights):
    vertices = len(reweighted_graph)
    dist = [sys.maxsize] * vertices
    dist[source] = 0

    visited = [False] * vertices
    for count in range(vertices - 1):
        u = min_distance(dist, visited)
        visited[u] = True

        for v in range(vertices):
            if not visited[v] and reweighted_graph[u][v] != sys.maxsize and dist[u] != sys.maxsize and dist[u] + reweighted_graph[u][v] < dist[v]:
                dist[v] = dist[u] + reweighted_graph[u][v]

    # Adjust distances back to original weights
    for i in range(vertices):
        if dist[i] != sys.maxsize:
            dist[i] = dist[i] - modified_weights[source] + modified_weights[i]

    return dist

def min_distance(dist, visited):
    min = sys.maxsize
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
            print((dist if dist != sys.maxsize else "INF") + " ", end="")
        print()

if __name__ == "__main__":
    # Input the number of vertices
    vertices = int(input())

    # Input the adjacency matrix
    graph = [[0] * vertices for _ in range(vertices)]
    for i in range(vertices):
        for j in range(vertices):
            value = input()
            graph[i][j] = int(value) if value != "INF" else sys.maxsize

    # Run Johnson's Algorithm and print the results
    shortest_paths = johnsons_algorithm(graph)
    print_distances(shortest_paths)

