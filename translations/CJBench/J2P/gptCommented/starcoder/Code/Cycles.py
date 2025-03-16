import java.util.ArrayList;
import java.util.Scanner;

# Class to find cycles in a directed graph using Depth First Search (DFS)
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0 for i in range(nodes)] for j in range(nodes)]
        self.visited = [False for i in range(nodes)]
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1

    # Method to start the cycle detection process
    def start(self):
        # Iterate through each node to initiate DFS
        for i in range(self.nodes):
            temp = [] # Temporary list to store the current path
            self.dfs(i, i, temp) # Start DFS from the current node
            # Reset the adjacency matrix for the current node to avoid duplicate cycles
            for j in range(self.nodes):
                self.adjacencyMatrix[i][j] = 0
                self.adjacencyMatrix[j][i] = 0

    # Depth First Search method to explore the graph and find cycles
    def dfs(self, start, curr, temp):
        temp.append(curr) # Add the current node to the path
        self.visited[curr] = True # Mark the current node as visited
        # Explore all adjacent nodes
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1: # Check if there is an edge
                if i == start: # Check if we found a cycle
                    self.cycles.append(temp) # Store the found cycle
                else:
                    if not self.visited[i]: # If the node is not visited, continue DFS
                        self.dfs(start, i, temp)
        # Backtrack: remove the current node from the path
        if len(temp) > 0:
            temp.remove(temp.size() - 1)
        self.visited[curr] = False # Mark the current node as unvisited for future searches

    # Method to print all found cycles
    def printAll(self):
        if len(self.cycles) == 0: # Check if no cycles were found
            print("No cycles found.")
            return
        # Print each cycle
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ") # Print the cycle path
            print(cycle[0]) # Complete the cycle by returning to the start
            print() # Print a new line for better readability

# Main class to execute the cycle detection program
if __name__ == '__main__':
    scanner = Scanner(System.in) # Create a scanner for input
    nodes = scanner.nextInt() # Read the number of nodes
    edges = scanner.nextInt() # Read the number of edges
    edgesInput = [[0 for i in range(2)] for j in range(edges)] # Initialize the edges input array
    # Read the edges from input
    for i in range(edges):
        edgesInput[i][0] = scanner.nextInt() # Start node of the edge
        edgesInput[i][1] = scanner.nextInt() # End node of the edge
    # Create a Cycle object to find cycles in the graph
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start() # Start the cycle detection process
    cycleFinder.printAll() # Print all found cycles

