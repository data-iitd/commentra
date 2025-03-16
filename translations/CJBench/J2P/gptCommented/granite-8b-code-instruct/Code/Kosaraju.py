
import sys

class Main:
    def __init__(self):
        self.stack = []
        self.scc = []
        self.sccsList = []

    def kosaraju(self, v, list):
        # Step 1: Sort the edges by their finishing times
        self.sortEdgesByLowestFinishTime(v, list)
        # Step 2: Create the transpose of the graph
        transposeGraph = self.createTransposeMatrix(v, list)
        # Step 3: Find strongly connected components in the transposed graph
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList

    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v # Array to track visited nodes
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list) # Perform DFS if the node is not visited

    def createTransposeMatrix(self, v, list):
        transposeGraph = [[] for _ in range(v)]
        # Fill the transpose graph with reversed edges
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i) # Reverse the direction of edges
        return transposeGraph

    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v # Array to track visited nodes
        # Process nodes in the order defined by the stack
        while self.stack:
            node = self.stack.pop() # Get the top node from the stack
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph) # Perform DFS on the transposed graph
                self.sccsList.append(self.scc) # Add the found SCC to the list
                self.scc = [] # Reset the current SCC for the next component

    def dfs(self, node, vis, list):
        vis[node] = 1 # Mark the node as visited
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list) # Recursively visit unvisited neighbours
        self.stack.append(node) # Push the node onto the stack after visiting all neighbours

    def dfs2(self, node, vis, list):
        vis[node] = 1 # Mark the node as visited
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list) # Recursively visit unvisited neighbours
        self.scc.append(node) # Add the node to the current SCC

# Main method to execute the program
if __name__ == "__main__":
    v, e = map(int, input().split()) # Read number of vertices and edges
    adjacencyList = [[] for _ in range(v)]
    # Read edges and populate the adjacency list
    for _ in range(e):
        u, v = map(int, input().split()) # Read start vertex and end vertex of the edge
        adjacencyList[u].append(v) # Add the edge to the adjacency list
    # Create an instance of Main to use the kosaraju method
    kosaraju = Main()
    # Find strongly connected components
    sccs = kosaraju.kosaraju(v, adjacencyList)
    # Print the strongly connected components
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc) # Print each SCC
    sys.exit(0) # End of code

Translate the above Python code to C++ and end with comment "