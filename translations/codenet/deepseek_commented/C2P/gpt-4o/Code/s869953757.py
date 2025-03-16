M = 100
whi = 0
gra = 1
bla = 2

n = 0  # Number of nodes in the graph
T = [[0] * M for _ in range(M)]  # Adjacency matrix to represent the graph
color = [0] * M  # Array to keep track of colors
d = [0] * M  # Array to keep track of distances
Q = []  # Queue for BFS

# Function to enqueue an element into the queue
def enqueue(x):
    Q.append(x)

# Function to dequeue an element from the queue
def dequeue():
    return Q.pop(0)

# Function to perform Breadth-First Search (BFS) starting from node s
def bfs(s):
    global n
    # Initialize all nodes to white, set distance to infinity
    for i in range(n):
        color[i] = whi
        d[i] = 1000000

    # Set the color and distance of the source node
    color[s] = gra
    d[s] = 0
    enqueue(s)

    # Continue BFS until the queue is empty
    while Q:
        u = dequeue()  # Dequeue the front node
        # Explore all adjacent nodes
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra  # Mark as gray
                d[v] = d[u] + 1  # Update distance
                enqueue(v)  # Enqueue the node
        color[u] = bla  # Mark as black

# Main function to read the graph, execute BFS, and print distances
if __name__ == "__main__":
    n = int(input())  # Read the number of nodes

    # Read the edges and construct the adjacency matrix
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1  # Convert to 0-based index
        for j in range(k):
            v = int(input())
            v -= 1  # Convert to 0-based index
            T[u][v] = 1  # Set the edge in the adjacency matrix

    bfs(0)  # Execute BFS starting from node 0

    # Print the distances from the source node to all other nodes
    for i in range(n):
        if d[i] == 1000000:
            d[i] = -1  # If unreachable, set distance to -1
        print(i + 1, d[i])  # Print node number and distance

# <END-OF-CODE>
