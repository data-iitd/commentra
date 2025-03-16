# Constants
M = 100  # Maximum number of vertices in the graph
whi = 0  # Color code for white (unvisited)
gra = 1  # Color code for gray (visited but not fully explored)
bla = 2  # Color code for black (fully explored)

n = 0  # Number of vertices in the graph
T = [[0] * M for _ in range(M)]  # Adjacency matrix to represent the graph
color = [whi] * M  # Array to store the color of each vertex
d = [1000000] * M  # Array to store the distance of each vertex
Q = []  # Queue for BFS implementation

# Function to add an element to the queue
def enqueue(x):
    Q.append(x)  # Add element x to the queue

# Function to remove and return an element from the queue
def dequeue():
    return Q.pop(0)  # Remove and return the front element of the queue

# Function to perform Breadth-First Search (BFS) starting from vertex s
def bfs(s):
    global n, color, d, Q

    # Initialize all vertices as unvisited and set their distances to a large value
    for i in range(n):
        color[i] = whi  # Set color to white (unvisited)
        d[i] = 1000000  # Set distance to a large number (infinity)

    # Start BFS from the source vertex s
    color[s] = gra  # Mark the source vertex as gray (visited)
    d[s] = 0  # Distance to source vertex is 0
    enqueue(s)  # Enqueue the source vertex

    # Continue BFS until the queue is empty
    while Q:
        u = dequeue()  # Dequeue a vertex from the queue
        # Explore all adjacent vertices of u
        for v in range(n):
            # If there is an edge from u to v and v is unvisited
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra  # Mark v as gray (visited)
                d[v] = d[u] + 1  # Update distance to v
                enqueue(v)  # Enqueue vertex v for further exploration
        color[u] = bla  # Mark u as black (fully explored)

# Main function
if __name__ == "__main__":
    # Read the number of vertices
    n = int(input())

    # Initialize the adjacency matrix to zero (no edges)
    for i in range(n):
        for j in range(n):
            T[i][j] = 0  # No edge between vertices i and j

    # Read the edges of the graph
    for i in range(n):
        u, k = map(int, input().split())  # Read vertex u and number of edges k
        u -= 1  # Convert to zero-based index
        for j in range(k):
            v = int(input())  # Read each adjacent vertex v
            v -= 1  # Convert to zero-based index
            T[u][v] = 1  # Set the edge from u to v in the adjacency matrix

    # Perform BFS starting from vertex 0
    bfs(0)

    # Output the distance from the source vertex to each vertex
    for i in range(n):
        if d[i] == 1000000:
            d[i] = -1  # If distance is still infinity, set it to -1
        print(i + 1, d[i])  # Print vertex number and its distance

# <END-OF-CODE>
