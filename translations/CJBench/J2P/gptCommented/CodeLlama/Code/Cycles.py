
# Import the necessary libraries
import sys

# Class to find cycles in a directed graph using Depth First Search (DFS)
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.edges = edges
        self.edgesInput = edgesInput
        self.adjacencyMatrix = [[0 for i in range(nodes)] for j in range(nodes)]
        self.visited = [False for i in range(nodes)]
        self.cycles = []

        # Populate the adjacency matrix based on the input edges
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1

    # Method to start the cycle detection process
    def start(self):
        # Iterate through each node to initiate DFS
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            # Reset the adjacency matrix for the current node to avoid duplicate cycles
            for j in range(self.nodes):
                self.adjacencyMatrix[i][j] = 0
                self.adjacencyMatrix[j][i] = 0

    # Depth First Search method to explore the graph and find cycles
    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True
        # Explore all adjacent nodes
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(temp[:])
                else:
                    if not self.visited[i]:
                        self.dfs(start, i, temp)
        # Backtrack: remove the current node from the path
        if len(temp) > 0:
            temp.pop()
        self.visited[curr] = False

    # Method to print all found cycles
    def printAll(self):
        if len(self.cycles) == 0:
            print("No cycles found.")
            return
        # Print each cycle
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])
            print()

# Main class to execute the cycle detection program
class Main:
    def __init__(self):
        pass

    # Main method to run the program
    def main(self):
        # Read the number of nodes and edges from input
        nodes = int(sys.stdin.readline())
        edges = int(sys.stdin.readline())
        edgesInput = []
        # Read the edges from input
        for i in range(edges):
            edgesInput.append([int(j) for j in sys.stdin.readline().split()])
        # Create a Cycle object to find cycles in the graph
        cycleFinder = Cycle(nodes, edges, edgesInput)
        cycleFinder.start()
        cycleFinder.printAll()

# Main function to start the program
if __name__ == "__main__":
    main = Main()
    main.main()

