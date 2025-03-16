
import sys

# Constant representing infinity
INF = sys.maxsize

def main():
    # Create a scanner object to read input
    scanner = sys.stdin
    
    # Read the number of vertices in the graph
    vertices = int(scanner.readline())
    
    # Initialize the adjacency matrix for the graph
    graph = [[0] * vertices for _ in range(vertices)]
    
    # Read the graph's edge weights from input
    for i in range(vertices):
        for j in range(vertices):
            value = scanner.readline().strip()
            # Set the weight to INF if the input is "INF", otherwise parse the integer
            graph[i][j] = int(value) if value != "INF" else INF
    
    # Compute the shortest paths using Johnson's algorithm
    shortestPaths = johnsonsAlgorithm(graph)
    
    # Print the resulting shortest path distances
    printDistances(shortestPaths)

def johnsonsAlgorithm(graph):
    vertices = len(graph)
    
    # Step 1: Use Bellman-Ford to find modified weights
    modifiedWeights = bellmanFord(graph)
    
    # Step 2: Reweight the graph using the modified weights
    reweightedGraph = reweightGraph(graph, modifiedWeights)
    
    # Initialize the shortest paths array
    shortestPaths = [[0] * vertices for _ in range(vertices)]
    
    # Step 3: Use Dijkstra's algorithm for each vertex to find shortest paths
    for i in range(vertices):
        shortestPaths[i] = dijkstra(reweightedGraph, i, modifiedWeights)
    
    return shortestPaths

def bellmanFord(graph):
    vertices = len(graph) + 1 # Include an extra vertex for the algorithm
    dist = [INF] * vertices
    
    # Initialize distances to infinity
    dist[-1] = 0 # Distance to the new vertex is 0
    
    # Create a list to store edges for relaxation
    edges = []
    
    # Add all edges from the original graph to the edge list
    for i in range(vertices - 1):
        for j in range(vertices - 1):
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

def reweightGraph(graph, weights):
    vertices = len(graph)
    reweightedGraph = [[0] * vertices for _ in range(vertices)]
    
    # Reweight each edge in the graph
    for i in range(vertices):
        for j in range(vertices):
            if graph[i][j] != INF:
                reweightedGraph[i][j] = graph[i][j] + weights[i] - weights[j]
            else:
                reweightedGraph[i][j] = INF # Maintain INF for no connection
    
    return reweightedGraph

def dijkstra(graph, source, weights):
    vertices = len(graph)
    dist = [INF] * vertices
    visited = [False] * vertices
    
    # Initialize distances to infinity
    dist[source] = 0 # Distance to the source is 0
    
    # Main loop to find shortest paths
    for _ in range(vertices - 1):
        # Get the vertex with the minimum distance that hasn't been visited
        u = minDistance(dist, visited)
        visited[u] = True # Mark the vertex as visited
        
        # Update distances for adjacent vertices
        for v in range(vertices):
            if not visited[v] and graph[u][v] != INF and dist[u] != INF and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
    
    # Adjust distances based on the original weights
    for i in range(vertices):
        if dist[i] != INF:
            dist[i] = dist[i] - weights[source] + weights[i]
    
    return dist

def minDistance(dist, visited):
    min = INF
    minIndex = -1
    for v in range(len(dist)):
        if not visited[v] and dist[v] <= min:
            min = dist[v]
            minIndex = v # Update the index of the minimum distance vertex
    
    return minIndex

def printDistances(distances):
    print("All-pairs shortest paths:")
    for row in distances:
        for dist in row:
            # Print "INF" for infinite distances, otherwise print the distance
            print((dist if dist != INF else "INF") + " ", end="")
        print() # New line for each row

if __name__ == "__main__":
    main()

