
import sys

# Read the number of vertices, edges, and the source vertex from input
V, E, r = map(int, input().split())

# Read all edges from input and store them in the edges list
edges = []
for i in range(E):
    source, target, distance = map(int, input().split())
    edges.append((source, target, distance))

# Initialize distances list to infinity for all vertices
distances = [sys.maxsize] * V
distances[r] = 0

# Main loop to relax edges V-1 times
for i in range(1, V):
    # Copy current distances to previous distances for comparison
    prev_distances = distances.copy()
    
    # Relax all edges
    for source, target, distance in edges:
        # Update the distance to the target vertex if a shorter path is found
        distances[target] = min(distances[source] + distance, distances[target])

    # Check if any distance was updated in this iteration
    same = True
    for j in range(V):
        if distances[j]!= prev_distances[j]:
            same = False
            break

    # If no distances were updated, break out of the loop early
    if same: break

# Output the shortest distances from the source vertex to all other vertices
for i in range(V):
    if distances[i] == sys.maxsize:
        print("INF") # Print "INF" if the vertex is unreachable
    else:
        print(distances[i]) # Print the shortest distance

