
import sys

# Class to detect cycles in a directed graph using DFS
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0 for _ in range(nodes)] for _ in range(nodes)]
        self.visited = [False for _ in range(nodes)]
        self.cycles = []
        for start, end in edgesInput:
            self.adjacencyMatrix[start][end] = 1

    # Method to start the cycle detection process
    def start(self):
        for start in range(self.nodes):
            temp = []
            self.dfs(start, start, temp) # Call DFS for each node to detect cycles
            for i in range(self.nodes):
                self.adjacencyMatrix[start][i] = 0
                self.adjacencyMatrix[i][start] = 0

    # Private method to perform DFS and detect cycles
    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True # Mark the current node as visited
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1: # Check for adjacent nodes
                if i == start:
                    self.cycles.append(temp[:]) # If cycle is detected, add to cycles list
                else:
                    if not self.visited[i]:
                        self.dfs(start, i, temp) # Recursively call DFS for unvisited adjacent nodes
        if len(temp) > 0:
            temp.pop() # Backtrack
        self.visited[curr] = False # Mark the current node as not visited for other paths

    # Method to print all detected cycles
    def printAll(self):
        if len(self.cycles) == 0:
            print("No cycles found.")
            return
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ") # Print each node in the cycle
            print(cycle[0]) # Print the first node again to complete the cycle
            print()

# Main function to run the cycle detection program
def main():
    nodes, edges = map(int, input().split()) # Read the number of nodes and edges
    edgesInput = []
    for _ in range(edges):
        start, end = map(int, input().split()) # Read the start node and end node of each edge
        edgesInput.append((start, end))
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start() # Start cycle detection
    cycleFinder.printAll() # Print all detected cycles

if __name__ == "__main__":
    sys.exit(main())

