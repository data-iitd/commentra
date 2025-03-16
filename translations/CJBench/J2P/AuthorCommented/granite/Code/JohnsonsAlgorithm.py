

import sys

# Define the infinity value
INF = sys.maxsize

def bellman_ford(graph, num_vertices):
    dist = [INF] * (num_vertices + 1)
    dist[-1] = 0

    edges = []
    for i in range(num_vertices):
        for j in range(num_vertices):
            if graph[i][j]!= INF:
                edges.append((i, j, graph[i][j]))

    for _ in range(num_vertices):
        for u, v, w in edges:
            if dist[u]!= INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u]!= INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]

def reweight_graph(graph, modified_weights):
    vertices = len(graph)
    reweighted_graph = [[INF] * vertices for _ in range(vertices)]
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j]!= INF:
                reweighted_graph[i][j] = graph[i][j] + modified_weights[i] - modified_weights[j]

    return reweighted_graph

def dijkstra(reweighted_graph, source, modified_weights):
    vertices = len(reweighted_graph)
    dist = [INF] * vertices
    visited = [False] * vertices
    dist[source] = 0

    for _ in range(vertices - 1):
        u = min(enumerate(dist), key=lambda x: x[1])[0]
        visited[u] = True

        for v in range(vertices):
            if not visited[v] and reweighted_graph[u][v]!= INF and dist[u]!= INF and dist[u] + reweighted_graph[u][v] < dist[v]:
                dist[v] = dist[u] + reweighted_graph[u][v]

    # Adjust distances back to original weights
    for i in range(vertices):
        if dist[i]!= INF:
            dist[i] = dist[i] - modified_weights[source] + modified_weights[i]

    return dist

def johnsons_algorithm(graph):
    vertices = len(graph)

    # Step 1: Reweight graph using Bellman-Ford
    modified_weights = bellman_ford(graph, vertices)

    # Step 2: Reweight the graph
    reweighted_graph = reweight_graph(graph, modified_weights)

    # Step 3: Run Dijkstra's for all vertices
    shortest_paths = []
    for i in range(vertices):
        shortest_paths.append(dijkstra(reweighted_graph, i, modified_weights))

    return shortest_paths

def print_distances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        print(" ".join(map(lambda x: "INF" if x == INF else str(x), row)))

# Input the number of vertices
num_vertices = int(input("Enter the number of vertices: "))

# Input the adjacency matrix
graph = []
for _ in range(num_vertices):
    row = list(map(lambda x: INF if x == "INF" else int(x), input().split()))
    graph.append(row)

# Run Johnson's Algorithm and print the results
shortest_paths = johnsons_algorithm(graph)
print_distances(shortest_paths)

