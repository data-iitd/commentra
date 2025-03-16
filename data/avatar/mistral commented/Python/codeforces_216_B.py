#######
# Code
#######

# Function to read an array of integers from standard input
def readInts():
    return map(int, input().split())

# Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
def dfs(g, seen, i):
    # Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if i in seen:
        return 0, 0

    # Mark the current vertex as visited by adding it to the seen set
    seen.add(i)

    # Initialize nodes and edges counters
    nodes = 1
    edges = len(g[i])

    # Recursively traverse the graph for all neighbors of the current vertex
    for j in g[i]:
        # Recursive call to DFS function for the neighbor vertex
        x, y = dfs(g, seen, j)

        # Update nodes and edges counters based on the result of the recursive call
        nodes += x
        edges += y

    # Return the final count of nodes and edges for the current vertex
    return nodes, edges

# Main function to solve the problem
def solve():
    # Read the first line of input containing the number of vertices and edges in the graph
    line0 = []
    try:
        line0 = readInts()
    except EOFError:
        # If there is no more input, return False to indicate the end of the program
        return False

    n, m = line0 # Extract the number of vertices and edges from the input line

    # Initialize the graph as a dictionary with vertices as keys and empty sets as values
    g = {}
    seen = set()

    # Initialize an empty dictionary to store the neighbors of each vertex
    for i in range(1, n+1):
        g[i] = set()

    # Read the remaining lines of input containing the edges of the graph and add them to the graph
    for _ in range(m):
        a, b = readInts()
        g[a].add(b)
        g[b].add(a)

    # Initialize the answer counter to 0
    ans = 0

    # Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for i in range(1, n+1):
        if i not in seen:
            nodes, edges = dfs(g, seen, i)
            if nodes > 1 and nodes % 2 == 1 and 2 * nodes == edges:
                ans += 1

    # Update the answer counter based on the parity of the total number of vertices
    if (n - ans) % 2 == 1:
        ans += 1

    # Print the final answer and return True to indicate the success of the program
    print(ans)
    return True

# Main loop to repeatedly call the solve function until there is no more input
while solve():
    pass
