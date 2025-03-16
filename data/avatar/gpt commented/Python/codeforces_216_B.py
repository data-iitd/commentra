def readInts():
    # Reads a line of input, splits it into components, and converts them to integers
    return map(int, input().split())

def dfs(g, seen, i):
    # Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    # 'seen' keeps track of visited nodes to avoid cycles
    if i in seen:
        # If the node has already been visited, return 0 nodes and 0 edges
        return 0, 0
    seen.add(i)  # Mark the current node as seen
    nodes = 1  # Count the current node
    edges = len(g[i])  # Count the edges connected to the current node
    for j in g[i]:
        # Recursively visit all adjacent nodes
        x, y = dfs(g, seen, j)
        nodes += x  # Accumulate the number of nodes found
        edges += y  # Accumulate the number of edges found
    return nodes, edges  # Return the total count of nodes and edges

def solve():
    # Main function to solve the problem
    line0 = []
    try:
        # Attempt to read the first line of input
        line0 = readInts()
    except EOFError:
        # If end of input is reached, return False to stop processing
        return False
    n, m = line0  # Unpack the number of nodes (n) and edges (m)
    g = {}  # Initialize the graph as a dictionary
    seen = set()  # Initialize a set to keep track of seen nodes
    for i in range(1, n + 1):
        # Initialize each node's adjacency list as an empty set
        g[i] = set()
    for _ in range(m):
        # Read each edge and add it to the graph (undirected)
        a, b = readInts()
        g[a].add(b)
        g[b].add(a)
    ans = 0  # Initialize the answer counter
    for i in range(1, n + 1):
        # Iterate through each node to find connected components
        if i not in seen:
            # If the node has not been seen, perform DFS
            nodes, edges = dfs(g, seen, i)
            # Check the conditions for counting valid components
            if nodes > 1 and nodes % 2 == 1 and 2 * nodes == edges:
                ans += 1  # Increment the answer if conditions are met
    if (n - ans) % 2 == 1:
        # Adjust the answer if the remaining nodes are odd
        ans += 1
    print(ans)  # Output the final answer
    return True  # Return True to indicate successful processing

# Continuously solve the problem until EOF is reached
while solve():
    pass
