
import sys

# This function implements the Johnson's algorithm to find the shortest paths between all pairs of vertices in a weighted graph.
def johnsons_algorithm(graph):
    vertices = len(graph)
    modified_weights = bellman_ford(graph) # Compute the modified weights using Bellman-Ford algorithm.
    reweighted_graph = reweight_graph(graph, modified_weights) # Create the reweighted graph.
    shortest_paths = [[INF for _ in range(vertices)] for _ in range(vertices)] # Initialize a 2D array to store the shortest paths.

    # Run Dijkstra's algorithm from each vertex to find the shortest paths to all other vertices in the reweighted graph.
    for i in range(vertices):
        shortest_paths[i] = dijkstra(reweighted_graph, i, modified_weights)

    return shortest_paths

# This function computes the modified weights for each vertex using the Bellman-Ford algorithm.
def bellman_ford(graph):
    vertices = len(graph) + 1
    dist = [INF] * vertices # Initialize an array to store the shortest distances from the source vertex to all other vertices.
    dist[vertices - 1] = 0 # Set the distance from the source vertex to itself to 0.

    edges = [] # Initialize a list to store the edges in the order they will be processed.

    # Add the edges to the list.
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j]!= INF:
                edges.append((i, j, graph[i][j]))

    # Process the edges V - 1 times.
    for _ in range(vertices - 1):
        for u, v, w in edges:
            if dist[u]!= INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w # Update the distance if a shorter path is found.

    # Check for negative-weight cycles.
    for u, v, w in edges:
        if dist[u]!= INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")

    return dist[:vertices] # Return the modified weights as an array.

# This function reweights the graph using the modified weights computed in the Bellman-Ford algorithm.
def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = [[INF for _ in range(vertices)] for _ in range(vertices)] # Initialize a 2D array to store the reweighted graph.

    # Set the weights of the edges in the reweighted graph.
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j]!= INF:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = INF

    return reweighted_graph # Return the reweighted graph as a 2D array.

# This function finds the shortest path from a source vertex to all other vertices in a weighted graph using Dijkstra's algorithm.
def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [INF] * vertices # Initialize an array to store the shortest distances from the source vertex to all other vertices.
    visited = [False] * vertices # Initialize a boolean array to mark the visited vertices.

    dist[source] = 0 # Set the distance from the source vertex to itself to 0.

    for _ in range(vertices - 1):
        u = min_distance(dist, visited) # Find the unvisited vertex with the minimum distance.
        visited[u] = True # Mark the vertex as visited.

        for v in range(vertices):
            if not visited[v] and graph[u][v]!= INF and dist[u]!= INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v] # Update the distance if a shorter path is found.

    return dist # Return the shortest distances from the source vertex to all other vertices.

# This function finds the vertex with the minimum distance from the distances array that has not been visited yet.
def min_distance(dist, visited):
    min_dist, min_index = sys.maxsize, -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_dist:
            min_dist, min_index = dist[v], v
    return min_index

# This function prints the shortest distances from each vertex to all other vertices in the shortest paths array.
def print_distances(shortest_paths):
    print("All-pairs shortest paths:")
    for row in shortest_paths:
        print(" ".join(str(dist) if dist!= INF else "INF" for dist in row))

# END-OF-CODE