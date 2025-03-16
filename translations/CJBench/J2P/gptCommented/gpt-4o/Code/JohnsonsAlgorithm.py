import sys
import numpy as np

# Constant representing infinity
INF = sys.maxsize

def main():
    # Read the number of vertices in the graph
    vertices = int(input())
    
    # Initialize the adjacency matrix for the graph
    graph = np.zeros((vertices, vertices), dtype=int)
    
    # Read the graph's edge weights from input
    for i in range(vertices):
        row = input().split()
        for j in range(vertices):
            value = row[j]
            # Set the weight to INF if the input is "INF", otherwise parse the integer
            graph[i][j] = INF if value == "INF" else int(value)
    
    # Compute the shortest paths using Johnson's algorithm
    shortest_paths = johnsons_algorithm(graph)
    
    # Print the resulting shortest path distances
    print_distances(shortest_paths)

# Method to implement Johnson's algorithm for finding all-pairs shortest paths
def johnsons_algorithm(graph):
    vertices = len(graph)
    
    # Step 1: Use Bellman-Ford to find modified weights
    modified_weights = bellman_ford(graph)
    
    # Step 2: Reweight the graph using the modified weights
    reweighted_graph = reweight_graph(graph, modified_weights)
    
    # Initialize the shortest paths array
    shortest_paths = np.zeros((vertices, vertices), dtype=int)
    
    # Step 3: Use Dijkstra's algorithm for each vertex to find shortest paths
    for i in range(vertices):
        shortest_paths[i] = dijkstra(reweighted_graph, i, modified_weights)
    
    return shortest_paths

# Method to perform the Bellman-Ford algorithm to detect negative weight cycles
def bellman_ford(graph):
    vertices = len(graph) + 1  # Include an extra vertex for the algorithm
    dist = [INF] * vertices
    
    # Initialize distances to infinity
    dist[vertices - 1] = 0  # Distance to the new vertex is 0
    
    # Create a list to store edges for relaxation
    edges = []
    
    # Add all edges from the original graph to the edge list
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != INF:
                edges.append((i, j, graph[i][j]))
    
    # Add edges from the new vertex to all other vertices with weight 0
    for i in range(vertices - 1):
        edges.append((vertices - 1, i, 0))
    
    # Relax edges up to (vertices - 1) times
    for _ in range(vertices):
        for u, v, w in edges:
            # Relaxation step
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    
    # Check for negative weight cycles
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            raise ValueError("Graph contains a negative weight cycle.")
    
    # Return the distance array excluding the extra vertex
    return dist[:-1]

# Method to reweight the graph based on the distances obtained from Bellman-Ford
def reweight_graph(graph, weights):
    vertices = len(graph)
    reweighted_graph = np.zeros((vertices, vertices), dtype=int)
    
    # Reweight each edge in the graph
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != INF:
                reweighted_graph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweighted_graph[i][j] = INF  # Maintain INF for no connection
    
    return reweighted_graph

# Method to perform Dijkstra's algorithm from a given source vertex
def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [INF] * vertices
    visited = [False] * vertices
    
    # Initialize distances to infinity
    dist[source] = 0  # Distance to the source is 0
    
    # Main loop to find shortest paths
    for _ in range(vertices - 1):
        # Get the vertex with the minimum distance that hasn't been visited
        u = min_distance(dist, visited)
        visited[u] = True  # Mark the vertex as visited
        
        # Update distances for adjacent vertices
        for v in range(vertices):
            if not visited[v] and graph[u][v] != INF and dist[u] != INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
    
    # Adjust distances based on the original weights
    for i in range(vertices):
        if dist[i] != INF:
            dist[i] = dist[i] - weights[source] + weights[i]
    
    return dist

# Helper method to find the vertex with the minimum distance
def min_distance(dist, visited):
    min_dist = INF
    min_index = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min_dist:
            min_dist = dist[v]
            min_index = v  # Update the index of the minimum distance vertex
    return min_index

# Method to print the shortest path distances
def print_distances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        for dist in row:
            # Print "INF" for infinite distances, otherwise print the distance
            print("INF" if dist == INF else dist, end=" ")
        print()  # New line for each row

if __name__ == "__main__":
    main()

# <END-OF-CODE>
