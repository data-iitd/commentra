MAX = 101
WHITE = 0
GRAY = 1
BLACK = 2

time = 0
n = 0
g = [[0] * MAX for _ in range(MAX)]
d = [0] * MAX
f = [0] * MAX
color = [WHITE] * MAX

def visit(u):
    global time
    color[u] = GRAY  # Set the color of the current node to gray.
    time += 1
    d[u] = time  # Record the discovery time.

    for i in range(n):
        if g[u][i] == 0:
            continue  # Skip if there is no edge between u and i.
        if color[i] == WHITE:
            visit(i)  # Recursively visit adjacent white nodes.

    color[u] = BLACK  # Set the color of the current node to black.
    time += 1
    f[u] = time  # Record the finishing time.

def dfs():
    global time
    time = 0  # Initialize the time.

    for i in range(n):
        if color[i] == WHITE:
            visit(i)  # Call visit for any white node.

    for i in range(n):
        print(i + 1, d[i], f[i])  # Print the discovery and finishing times of each node.

if __name__ == "__main__":
    n = int(input())  # Read the number of nodes.

    for _ in range(n):
        x, y = map(int, input().split())
        for _ in range(y):
            z = int(input())
            g[x - 1][z - 1] = 1  # Populate the adjacency matrix.

    dfs()  # Call the dfs function to compute and print the discovery and finishing times.
# <END-OF-CODE>
