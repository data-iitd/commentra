import sys
import math

INF = float('inf')

def main():
    vertices = int(input())  # Read the number of vertices from the standard input.
    graph = []  # Initialize a list to represent the weighted graph.

    # Read the weights of the edges from the standard input and store them in the graph list.
    for i in range(vertices):
        row = input().split()
        graph.append([INF if value == "INF" else int(value) for value in row])

    shortest_paths = johnsons_algorithm(graph)  # Compute the shortest paths using Johnson's algorithm.
    print_distances(shortest_paths)  # Print the results to the standard output.

def johnsons_algorithm(graph):
    vertices = len(graph)
    modified_weights = bellman_ford(graph)  # Compute the modified weights using Bellman-Ford algorithm.
    reweighted_graph = reweight_graph(graph, modified_weights)  # Create the reweighted graph.
    shortest_paths = [[0] * vertices for _ in range(vertices)]  # Initialize a 2D list to store the shortest paths.

    # Run Dijkstra's algorithm from each vertex to find the shortest paths to all other vertices in the reweighted graph.
    for i in range(vertices):
        shortest_paths[i] = dijkstra(reweighted_graph, i, modified_weights)

    return shortest_paths

def bellman_ford(graph):
    vertices = len(graph) + 1
    dist = [INF] * vertices  # Initialize an array to store the shortest distances from the source vertex to all other vertices.
    dist[vertices - 1] = 0  # Set the distance from the source vertex to itself to 0.

    edges = []  # Initialize a list to store the edges in the order they will be processed.

    # Add the edges to the list.
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != INF:
                edges.append((i, j, graph[i][j]))

    # Process the edges V - 1 times.
    for _ in range(vertices - 1):
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w  # Update the distance if a shorter path is found.

    # Check for negative-weight cycles.
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:-1]  # Return the modified weights as an array.

def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[0] * vertices for _ in range(vertices)]  # Initialize a 2D list to store the reweighted graph.

    # Set the weights of the edges in the reweighted graph.
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != INF:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = INF

    return reweighted_graph  # Return the reweighted graph as a 2D list.

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [INF] * vertices  # Initialize an array to store the shortest distances from the source vertex to all other vertices.
    visited = [False] * vertices  # Initialize a boolean array to mark the visited vertices.

    dist[source] = 0  # Set the distance from the source vertex to itself to 0.

    for _ in range(vertices - 1):
        u = min_distance(dist, visited)  # Find the unvisited vertex with the minimum distance.
        visited[u] = True  # Mark the vertex as visited.

        for v in range(vertices):
            if not visited[v] and graph[u][v] != INF and dist[u] != INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]  # Update the distance if a shorter path is found.

    return dist  # Return the shortest distances from the source vertex to all other vertices.

def min_distance(dist, visited):
    min_dist = INF
    min_index = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_dist:
            min_dist = dist[v]
            min_index = v
    return min_index

def print_distances(shortest_paths):
    print("All-pairs shortest paths:")
    for row in shortest_paths:
        print(" ".join("INF" if dist == INF else str(dist) for dist in row))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
