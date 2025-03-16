from collections import deque

M = 100
whi = 0
gra = 1
bla = 2

n = 0
T = [[0] * M for _ in range(M)]
color = [whi] * M
d = [0] * M

# Breadth First Search Algorithm
def bfs(s):
    global n
    # Initialize all vertices with white color and infinite distance
    for i in range(n):
        color[i] = whi
        d[i] = 1000000

    # Initialize source vertex with gray color and zero distance
    color[s] = gra
    d[s] = 0
    queue = deque([s])  # Use deque for efficient queue operations

    # Traverse the queue until it is empty
    while queue:
        u = queue.popleft()  # Dequeue a vertex
        for v in range(n):  # Iterate through all adjacent vertices
            if T[u][v] == 1 and color[v] == whi:  # If the adjacent vertex is unvisited
                color[v] = gra  # Mark it as visited
                d[v] = d[u] + 1  # Update its distance
                queue.append(v)  # Enqueue the adjacent vertex
        color[u] = bla  # Mark the current vertex as black

# Main function
if __name__ == "__main__":
    # Read the number of vertices
    n = int(input())

    # Initialize the adjacency matrix with zeros
    for i in range(n):
        for j in range(n):
            T[i][j] = 0

    # Read the edges and add them to the adjacency matrix
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1  # Decrease the index of the source vertex by 1
        for j in range(k):
            v = int(input())
            v -= 1  # Decrease the index of the neighbor vertex by 1
            T[u][v] = 1  # Add an edge between the vertices

    # Perform BFS algorithm starting from the source vertex 0
    bfs(0)

    # Print the results
    for i in range(n):
        if d[i] == 1000000:
            d[i] = -1  # Set the distance to -1 if it is unreachable
        print(i + 1, d[i])  # Print the vertex index and its distance from the source

# <END-OF-CODE>
