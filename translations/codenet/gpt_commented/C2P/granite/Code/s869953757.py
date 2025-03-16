
import queue

# Define the maximum number of vertices and the color codes
M = 100
whi = 0
gra = 1
bla = 2

# Read the number of vertices
n = int(input())

# Initialize the adjacency matrix to zero (no edges)
T = [[0 for _ in range(M)] for _ in range(M)]

# Read the edges of the graph
for _ in range(n):
    u, k = map(int, input().split())
    u -= 1  # Convert to zero-based index
    for _ in range(k):
        v = int(input()) - 1  # Convert to zero-based index
        T[u][v] = 1  # Set the edge from u to v in the adjacency matrix

# Function to perform Breadth-First Search (BFS) starting from vertex s
def bfs(s):
    # Initialize all vertices as unvisited and set their distances to a large value
    color = [whi for _ in range(n)]
    d = [1000000 for _ in range(n)]

    # Start BFS from the source vertex s
    color[s] = gra  # Mark the source vertex as gray (visited)
    d[s] = 0  # Distance to source vertex is 0
    q = queue.Queue()
    q.put(s)  # Enqueue the source vertex

    # Continue BFS until the queue is empty
    while not q.empty():
        u = q.get()  # Dequeue a vertex from the queue
        # Explore all adjacent vertices of u
        for v in range(n):
            # If there is an edge from u to v and v is unvisited
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra  # Mark v as gray (visited)
                d[v] = d[u] + 1  # Update distance to v
                q.put(v)  # Enqueue vertex v for further exploration
        color[u] = bla  # Mark u as black (fully explored)

    return d

# Perform BFS starting from vertex 0
d = bfs(0)

# Output the distance from the source vertex to each vertex
for i in range(n):
    if d[i] == 1000000:
        d[i] = -1  # If distance is still infinity, set it to -1
    print(f"{i+1} {d[i]}")  # Print vertex number and its distance

