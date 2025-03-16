import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

class Main:
    # Stack to hold nodes in the order of their finishing times
    stack = Stack()
    # List to hold the current strongly connected component
    scc = []
    # List to hold all strongly connected components
    sccsList = []

    # Main method to find strongly connected components using Main's algorithm
    def kosaraju(self, v, list):
        # Step 1: Sort the edges by their finishing times
        self.sortEdgesByLowestFinishTime(v, list)
        # Step 2: Create the transpose of the graph
        transposeGraph = self.createTransposeMatrix(v, list)
        # Step 3: Find strongly connected components in the transposed graph
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList # Return the list of strongly connected components

    # Method to perform DFS and fill the stack with nodes based on their finishing times
    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v # Array to track visited nodes
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list) # Perform DFS if the node is not visited
        return

    # Method to create the transpose of the given graph
    def createTransposeMatrix(self, v, list):
        transposeGraph = []
        # Initialize the transpose graph
        for i in range(v):
            transposeGraph.append([])
        # Fill the transpose graph with reversed edges
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i) # Reverse the direction of edges
        return transposeGraph # Return the transposed graph

    # Method to find strongly connected components in the transposed graph
    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v # Array to track visited nodes
        # Process nodes in the order defined by the stack
        while not self.stack.isEmpty():
            node = self.stack.pop() # Get the top node from the stack
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph) # Perform DFS on the transposed graph
                self.sccsList.append(self.scc) # Add the found SCC to the list
                self.scc = [] # Reset the current SCC for the next component
        return

    # Depth-first search method to fill the stack with nodes based on finishing times
    def dfs(self, node, vis, list):
        vis[node] = 1 # Mark the node as visited
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list) # Recursively visit unvisited neighbours
        self.stack.push(node) # Push the node onto the stack after visiting all neighbours
        return

    # Depth-first search method to collect nodes in the current strongly connected component
    def dfs2(self, node, vis, list):
        vis[node] = 1 # Mark the node as visited
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list) # Recursively visit unvisited neighbours
        self.scc.append(node) # Add the node to the current SCC
        return

    # Main method to execute the program
    def main(self):
        sc = Scanner(System.in)
        v = sc.nextInt() # Read number of vertices
        e = sc.nextInt() # Read number of edges
        list = []
        # Initialize the adjacency list for the graph
        for i in range(v):
            list.append([])
        # Read edges and populate the adjacency list
        for i in range(e):
            u = sc.nextInt() # Read start vertex of the edge
            v = sc.nextInt() # Read end vertex of the edge
            list[u].append(v) # Add the edge to the adjacency list
        # Create an instance of Main to use the kosaraju method
        kosaraju = Main()
        # Find strongly connected components
        sccs = kosaraju.kosaraju(v, list)
        # Print the strongly connected components
        print("Strongly Connected Components:")
        for scc in sccs:
            print(scc) # Print each SCC
        sc.close() # Close the scanner
        return

# 