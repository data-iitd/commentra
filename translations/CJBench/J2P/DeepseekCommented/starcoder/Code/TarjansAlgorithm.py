import sys

class Main:
    def __init__(self):
        self.time = 0
        self.sccList = []

    # Method to find strongly connected components using Tarjan's algorithm
    def stronglyConnectedComponents(self, v, graph):
        lowTime = [0] * v # Array to store the lowest insertion time of any node reachable from the current node
        insertionTime = [0] * v # Array to store the insertion time of each node
        isInStack = [False] * v # Array to keep track of nodes currently in the stack
        stack = [] # Stack to keep track of nodes in the current SCC

        # Initialize insertionTime and lowTime for all vertices to -1
        for i in range(v):
            insertionTime[i] = -1
            lowTime[i] = -1

        # Perform DFS for each unvisited node
        for i in range(v):
            if insertionTime[i] == -1:
                self.dfs(i, lowTime, insertionTime, isInStack, stack, graph)

        return self.sccList

    # Depth-first search method to find SCCs
    def dfs(self, u, lowTime, insertionTime, isInStack, stack, graph):
        insertionTime[u] = self.time # Set the insertion time of the current node
        lowTime[u] = self.time # Set the low time of the current node
        self.time += 1 # Increment the time step
        stack.append(u) # Push the current node onto the stack
        isInStack[u] = True # Mark the current node as being in the stack

        # Visit all adjacent nodes
        for v in graph[u]:
            if insertionTime[v] == -1: # If the adjacent node is not visited
                self.dfs(v, lowTime, insertionTime, isInStack, stack, graph)
                lowTime[u] = min(lowTime[u], lowTime[v]) # Update the low time of the current node
            elif isInStack[v]: # If the adjacent node is in the stack
                lowTime[u] = min(lowTime[u], insertionTime[v]) # Update the low time of the current node

        # If the current node is the root of an SCC
        if lowTime[u] == insertionTime[u]:
            scc = [] # List to store the current SCC
            w = 0
            while w!= u:
                w = stack.pop() # Pop nodes from the stack until the current node is reached
                scc.append(w) # Add the node to the SCC list
                isInStack[w] = False # Mark the node as not being in the stack
            self.sccList.append(scc) # Add the SCC to the list of SCCs

if __name__ == "__main__":
    main = Main()
    v = int(sys.stdin.readline()) # Read the number of vertices
    e = int(sys.stdin.readline()) # Read the number of edges
    graph = []
    for i in range(v):
        graph.append([])
    for i in range(e):
        fromVertex = int(sys.stdin.readline())
        toVertex = int(sys.stdin.readline())
        graph[fromVertex].append(toVertex) # Add an edge to the graph
    sccs = main.stronglyConnectedComponents(v, graph)
    for scc in sccs:
        print(scc) # Print each SCC

