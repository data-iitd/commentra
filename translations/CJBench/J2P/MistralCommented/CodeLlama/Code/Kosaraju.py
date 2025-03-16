
import sys

class Main:
    # Declare instance variables
    stack = []
    scc = []
    sccsList = []

    # Method to find strongly connected components using Main's algorithm
    def kosaraju(self, v, list):
        # Sort edges by their finish time (LTS)
        self.sortEdgesByLowestFinishTime(v, list)

        # Create the transpose graph
        transposeGraph = self.createTransposeMatrix(v, list)

        # Find strongly connected components in the transpose graph
        self.findStronglyConnectedComponents(v, transposeGraph)

        return self.sccsList

    # Sort edges by their lowest finish time (LTS)
    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v # Initialize a visited array

        # DFS traversal to compute LTS for all vertices
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    # Depth-First Search (DFS) to compute LTS
    def dfs(self, node, vis, list):
        # Mark the current node as visited
        vis[node] = 1

        # Recur for all neighbors
        for neighbor in list[node]:
            if vis[neighbor] == 0:
                self.dfs(neighbor, vis, list)

        # Push the current node to the stack
        self.stack.append(node)

    # Create the transpose graph
    def createTransposeMatrix(self, v, list):
        transposeGraph = [[] for i in range(v)] # Initialize the transpose graph

        # Create an adjacency list for the transpose graph
        for i in range(v):
            for neighbor in list[i]:
                transposeGraph[neighbor].append(i)

        return transposeGraph

    # Find strongly connected components in the transpose graph
    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v # Initialize a visited array

        # DFS traversal to find SCCs
        while self.stack:
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph)
                self.sccsList.append(self.scc) # Add the SCC to the list
                self.scc = [] # Initialize a new SCC

    # Depth-First Search (DFS) to find SCCs
    def dfs2(self, node, vis, list):
        # Mark the current node as visited
        vis[node] = 1

        # Add the current node to the SCC
        self.scc.append(node)

        # Recur for all neighbors
        for neighbor in list[node]:
            if vis[neighbor] == 0:
                self.dfs2(neighbor, vis, list)

    # Main method to read input and call the kosaraju method
    def main(self):
        sc = sys.stdin # Initialize a scanner to read input

        vertices = int(sc.readline()) # Read the number of vertices
        edges = int(sc.readline()) # Read the number of edges

        adjacencyList = [[] for i in range(vertices)] # Initialize an empty adjacency list

        # Create the adjacency list based on input
        for i in range(edges):
            u, v = map(int, sc.readline().split()) # Read the source vertex and destination vertex
            adjacencyList[u].append(v) # Add the edge from u to v

        kosaraju = Main() # Initialize an instance of the Main class
        sccs = kosaraju.kosaraju(vertices, adjacencyList) # Call the kosaraju method

        print("Strongly Connected Components:") # Print the header for SCCs
        for scc in sccs:
            print(scc) # Print each SCC

        sc.close() # Close the scanner

if __name__ == "__main__":
    Main().main()

