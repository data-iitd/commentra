
import sys

class Main:
    def __init__(self):
        self.time = 0 # Variable to keep track of the time steps during DFS
        self.sccList = [] # List to store the list of strongly connected components

    # Method to find strongly connected components using Tarjan's algorithm
    def stronglyConnectedComponents(self, v, graph):
        lowTime = [-1] * v # Array to store the lowest insertion time of any node reachable from the current node
        insertionTime = [-1] * v # Array to store the insertion time of each node
        isInStack = [False] * v # Array to keep track of nodes currently in the stack
        stack = [] # Stack to keep track of nodes in the current SCC

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
            while stack[-1]!= u: # Pop nodes from the stack until the current node is reached
                w = stack.pop() # Pop a node from the stack
                isInStack[w] = False # Mark the node as not being in the stack
                scc.append(w) # Add the node to the SCC list
            w = stack.pop() # Pop the current node from the stack
            isInStack[w] = False # Mark the node as not being in the stack
            scc.append(w) # Add the node to the SCC list
            self.sccList.append(scc) # Add the SCC to the list of SCCs

    # Main method to read input, construct the graph, and find and print SCCs
    def main(self):
        vertices, edges = map(int, input().split()) # Read the number of vertices and edges
        graph = [[] for _ in range(vertices)]
        for _ in range(edges):
            from_v, to_v = map(int, input().split()) # Read an edge
            graph[from_v].append(to_v) # Add an edge to the graph
        sccs = self.stronglyConnectedComponents(vertices, graph)
        for scc in sccs:
            print(scc) # Print each SCC

if __name__ == "__main__":
    Main().main()

