
import sys

class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0 for i in range(nodes)] for j in range(nodes)]
        self.visited = [False for i in range(nodes)]
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1
            self.adjacencyMatrix[end][start] = 1 # Add comment: Set bidirectional edge
        self.cycles = []

    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacencyMatrix[i][j] = 0
                self.adjacencyMatrix[j][i] = 0 # Add comment: Reset edge to zero

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True # Add comment: Mark the current node as visited
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1:
                if i == start: # Add comment: Check if the current node is the starting node
                    self.cycles.append(temp)
                    return # Add comment: Add the cycle to the list and exit the method
                else:
                    if not self.visited[i]: # Add comment: Check if the neighboring node is not visited yet
                        self.dfs(start, i, temp) # Add comment: Recursively call the dfs method for the neighboring node
        if len(temp) > 0: # Add comment: If there are nodes in the temp list, remove the last one
            temp.pop()
        self.visited[curr] = False # Add comment: Mark the current node as not visited

    def printAll(self):
        if len(self.cycles) == 0: # Add comment: Check if there are any cycles found
            print("No cycles found.")
            return
        for cycle in self.cycles: # Add comment: Iterate through each cycle found
            print("Cycle: ", end="")
            for i in range(len(cycle)): # Add comment: Print each node in the cycle
                print(cycle[i], end=" -> ")
            print(cycle[0]) # Add comment: Print the starting node of the cycle
            print() # Add comment: Print a new line after each cycle

if __name__ == '__main__':
    nodes = int(sys.stdin.readline())
    edges = int(sys.stdin.readline())
    edgesInput = []
    for i in range(edges):
        edgesInput.append([int(x) for x in sys.stdin.readline().split()])
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start()
    cycleFinder.printAll()

