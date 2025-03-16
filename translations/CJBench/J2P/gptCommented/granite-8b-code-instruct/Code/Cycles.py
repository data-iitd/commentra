
import sys

# Class to find cycles in a directed graph using Depth First Search (DFS)
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes # Number of nodes in the graph
        self.adjacencyMatrix = [[0 for _ in range(nodes)] for _ in range(nodes)] # Adjacency matrix to represent the graph
        self.visited = [False for _ in range(nodes)] # Array to track visited nodes during DFS
        self.cycles = [] # List to store found cycles
        # Populate the adjacency matrix based on the input edges
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1 # Mark the edge in the adjacency matrix

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
                    self.cycles.append(temp[:]) # Store the found cycle
                else:
                    if not self.visited[i]: # If the node is not visited, continue DFS
                        self.dfs(start, i, temp)
        # Backtrack: remove the current node from the path
        if len(temp) > 0:
            temp.pop()
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

# Main function to execute the cycle detection program
def main():
    # Read the number of nodes and edges from input
    nodes = int(input())
    edges = int(input())
    edgesInput = [] # Initialize the edges input array
    # Read the edges from input
    for _ in range(edges):
        edgesInput.append([int(x) for x in input().split()])
    # Create a Cycle object to find cycles in the graph
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start() # Start the cycle detection process
    cycleFinder.printAll() # Print all found cycles

if __name__ == "__main__":
    sys.exit(main())

