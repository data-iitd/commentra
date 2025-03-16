import sys

# Variable to keep track of the time during DFS
time = 0
# List to store the strongly connected components
sccList = []

# Method to find strongly connected components using Tarjan's algorithm
def stronglyConnectedComponents(v, graph):
    # Arrays to store the low time and insertion time of each vertex
    lowTime = [-1] * v
    insertionTime = [-1] * v
    # Boolean array to check if a vertex is in the stack
    isInStack = [False] * v
    # Stack to hold the vertices during DFS
    stack = []

    # Initialize insertion and low times for all vertices
    for i in range(v):
        insertionTime[i] = -1
        lowTime[i] = -1

    # Perform DFS for each vertex that has not been visited
    for i in range(v):
        if insertionTime[i] == -1:
            dfs(i, lowTime, insertionTime, isInStack, stack, graph)

    # Return the list of strongly connected components
    return sccList

# Depth-First Search method to explore the graph and find SCCs
def dfs(u, lowTime, insertionTime, isInStack, stack, graph):
    # Set the insertion and low time for the current vertex
    insertionTime[u] = time
    lowTime[u] = time
    time += 1
    # Push the current vertex onto the stack
    stack.append(u)
    isInStack[u] = True

    # Explore all adjacent vertices
    for v in graph[u]:
        # If the vertex has not been visited, perform DFS on it
        if insertionTime[v] == -1:
            dfs(v, lowTime, insertionTime, isInStack, stack, graph)
            # Update the low time of the current vertex
            lowTime[u] = min(lowTime[u], lowTime[v])
        # If the vertex is in the stack, update the low time
        elif isInStack[v]:
            lowTime[u] = min(lowTime[u], insertionTime[v])

    # If the current vertex is a root node, pop the stack and form an SCC
    if lowTime[u] == insertionTime[u]:
        scc = []
        w = 0
        while w != u:
            # Pop from the stack and add to the current SCC
            w = stack.pop()
            scc.append(w)
            isInStack[w] = False # Mark the vertex as not in the stack
        # Add the found SCC to the list of SCCs
        sccList.append(scc)

# Main method to read input and execute the algorithm
def main():
    # Read the number of vertices and edges
    vertices, edges = map(int, sys.stdin.readline().split())
    # Initialize the graph as an adjacency list
    graph = [[] for _ in range(vertices)]
    # Read the edges and populate the graph
    for _ in range(edges):
        from_, to = map(int, sys.stdin.readline().split())
        graph[from_].append(to)

    # Create an instance of the Main class and find SCCs
    tarjans = Main()
    sccs = tarjans.stronglyConnectedComponents(vertices, graph)
    
    # Print the strongly connected components
    for scc in sccs:
        print(scc)

if __name__ == "__main__":
    main()

