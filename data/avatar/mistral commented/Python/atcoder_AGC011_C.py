# Importing the queue module for implementing Depth First Search (DFS) using a stack
import queue

# Taking the number of vertices (n) and edges (m) as input
n, m = map(int, input().split())

# Initializing the visited list and other variables
vis = [0] * (n + 1)
ci, cb, cc = 0, 0, 0
g = [[] for i in range(n + 1)]

# Function to perform DFS traversal from a given vertex 'x'
def dfs(x):
    """
    This function performs Depth First Search traversal from a given vertex 'x'.
    It returns True if all vertices in the connected component are of the same color,
    and False otherwise.
    """
    # Creating an empty stack and initializing a flag
    stk = queue.LifoQueue()
    flag = True

    # Pushing the current vertex 'x' into the stack with color '1'
    stk.put((x, 1))

    # Traversing the graph until the stack is empty
    while not stk.empty():
        u, col = stk.get()

        # If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
        if vis[u]:
            flag &= (vis[u] == col)
            continue

        # Mark the current vertex 'u' as visited with the current color 'col'
        vis[u] = col

        # Recursively traverse all the adjacent vertices of 'u'
        for i in g[u]:
            stk.put((i, 3 - col))

    # Return the flag indicating whether all vertices in the connected component have the same color or not
    return flag

# Adding edges to the graph
for i in range(m):
    u, v = map(int, input().split())
    # Adding an edge between vertices 'u' and 'v' in both the adjacency lists
    g[u].append(v)
    g[v].append(u)

# Finding the number of isolated vertices and connected components
for i in range(1, n + 1):
    # If the current vertex 'i' is not visited yet
    if vis[i] == 0:
        # If the current vertex 'i' has no edges, then it is an isolated vertex
        if len(g[i]) == 0:
            ci += 1
        # Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
        else:
            if dfs(i):
                cb += 1
            else:
                cc += 1

# Calculating and printing the final answer
print(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb)
