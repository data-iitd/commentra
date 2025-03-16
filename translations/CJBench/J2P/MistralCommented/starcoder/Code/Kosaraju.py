import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Scanner; // Import necessary libraries

class Main:
    # Declare instance variables
    def __init__(self):
        self.stack = Stack()
        self.scc = []
        self.sccsList = []

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
        self.stack.push(node)

    # Create the transpose graph
    def createTransposeMatrix(self, v, list):
        transposeGraph = [] # Initialize the transpose graph

        # Create an adjacency list for the transpose graph
        for i in range(v):
            transposeGraph.append([])

        # Add edges from the transpose graph
        for i in range(v):
            for neighbor in list[i]:
                transposeGraph[neighbor].append(i)

        return transposeGraph

    # Find strongly connected components in the transpose graph
    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v # Initialize a visited array

        # DFS traversal to find SCCs
        while not self.stack.isEmpty():
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
    @staticmethod
    def main(args):
        sc = Scanner(System.in) # Initialize a scanner to read input

        vertices = sc.nextInt() # Read the number of vertices
        edges = sc.nextInt() # Read the number of edges

        list = [] # Initialize an empty adjacency list

        # Create the adjacency list based on input
        for i in range(vertices):
            list.append([])

        for i in range(edges):
            u = sc.nextInt() # Read the source vertex
            v = sc.nextInt() # Read the destination vertex
            list[u].append(v) # Add the edge from u to v

        kosaraju = Main() # Initialize an instance of the Main class
        sccs = kosaraju.kosaraju(vertices, list) # Call the kosaraju method

        print("Strongly Connected Components:") # Print the header for SCCs
        for scc in sccs:
            print(scc) # Print each SCC

        sc.close() # Close the scanner

# 