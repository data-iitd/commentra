def readInts():  # Function to read integers from input
    return map(int, input().split())

def dfs(g, seen, i):  # Depth-First Search to count nodes and edges in a graph
    if i in seen:  # If node is already seen, return 0, 0
        return 0, 0
    seen.add(i)  # Mark the node as seen
    nodes = 1  # Initialize node count
    edges = len(g[i])  # Count edges from the current node
    for j in g[i]:  # Traverse all adjacent nodes
        x, y = dfs(g, seen, j)  # Recursively call dfs for each adjacent node
        nodes += x  # Update node count
        edges += y  # Update edge count
    return nodes, edges  # Return the count of nodes and edges

def solve():  # Main function to solve the problem
    line0 = []
    try:
        line0 = readInts()  # Read the first line of input
    except EOFError:
        return False  # Return False if EOF is encountered
    n, m = line0  # Unpack the number of nodes and edges
    g = {}  # Initialize an empty graph
    seen = set()  # Initialize an empty set to keep track of visited nodes
    for i in range(1, n + 1):  # Initialize the graph with empty sets for each node
        g[i] = set()
    for _ in range(m):  # Read each edge and add it to the graph
        a, b = readInts()
        g[a].add(b)
        g[b].add(a)
    ans = 0  # Initialize the answer variable
    for i in range(1, n + 1):  # Traverse each node in the graph
        if i not in seen:  # If the node is not seen, perform DFS
            nodes, edges = dfs(g, seen, i)  # Get the count of nodes and edges
            if nodes > 1 and nodes % 2 == 1 and 2 * nodes == edges:  # Check the conditions
                ans += 1  # Increment the answer if the conditions are met
    if (n - ans) % 2 == 1:  # Check if the number of disconnected components is odd
        ans += 1  # Increment the answer if necessary
    print(ans)  # Print the final answer
    return True  # Return True to continue the loop

while solve():  # Continuously call solve until it returns False
    pass
