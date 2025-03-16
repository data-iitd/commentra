import sys
import heapq

INF = sys.maxsize

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
    vertices = len(graph) + 1
    dist = [INF] * vertices
    dist[vertices - 1] = 0

    edges = []
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != INF:
                edges.append([i, j, graph[i][j]])
    for i in range(len(graph)):
        edges.append([vertices - 1, i, 0])

    for _ in range(vertices):
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[0] * vertices for _ in range(vertices)]
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
    pq = [(0, source)]

    while pq:
        d, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True

        for v in range(vertices):
            if not visited[v] and graph[u][v] != INF and d != INF and d + graph[u][v] < dist[v]:
                dist[v] = d + graph[u][v]
                heapq.heappush(pq, (dist[v], v))

    # Adjust distances back to original weights
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
        for dist in row:
            print("INF" if dist == INF else dist, end=" ")
        print()

# Example usage:
if __name__ == "__main__":
    # Input the number of vertices
    vertices = int(input())

    # Input the adjacency matrix
    graph = []
    for _ in range(vertices):
        row = list(map(lambda x: INF if x == "INF" else int(x), input().split()))
        graph.append(row)

    # Run Johnson's Algorithm and print the results
    shortest_paths = johnsons_algorithm(graph)
    print_distances(shortest_paths)
