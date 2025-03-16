import sys
import collections

class Main:
    # First Depth-First Search (DFS) Traversal to populate the stack with nodes in finishing times order
    def btrack(self, adjList, visited, dfsCallsNodes, currentNode):
        visited[currentNode] = 1 # Mark the current node as visited
        neighbors = adjList.get(currentNode)
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack
                    self.btrack(adjList, visited, dfsCallsNodes, neighbor)
        dfsCallsNodes.append(currentNode) # Push the current node onto the stack after exploring all neighbors

    # Second DFS Traversal to find Strongly Connected Components (SCCs) in the reversed graph
    def btrack2(self, adjRevList, visited, currentNode, newScc):
        visited[currentNode] = 1 # Mark the current node as visited
        newScc.append(currentNode) # Add the current node to the current SCC
        neighbors = adjRevList.get(currentNode)
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack2
                    self.btrack2(adjRevList, visited, neighbor, newScc)

    # Method to get the number of strongly connected components in the graph
    def getOutput(self, adjList, n):
        visited = [-1] * n # Initialize visited array with -1 (unvisited)
        dfsCallsNodes = []
        for i in range(n):
            if visited[i] == -1: # If the node is not visited, start DFS from it
                self.btrack(adjList, visited, dfsCallsNodes, i)
        adjRevList = collections.defaultdict(list)
        for i in range(n):
            neighbors = adjList.get(i)
            if neighbors!= None:
                for neighbor in neighbors:
                    adjRevList[neighbor].append(i) # Reverse the edges to create the reversed adjacency list
        visited = [-1] * n # Reset the visited array for the second DFS traversal
        stronglyConnectedComponents = 0
        while dfsCallsNodes:
            node = dfsCallsNodes.pop()
            if visited[node] == -1: # If the node is not visited, start a new SCC search from it
                newScc = []
                self.btrack2(adjRevList, visited, node, newScc)
                stronglyConnectedComponents += 1 # Increment the count of SCCs
        return stronglyConnectedComponents # Return the total number of SCCs

    # Main method to read input, construct the graph, and find the number of SCCs
    def main(self):
        try:
            n = int(input()) # Read the number of nodes
            e = int(input()) # Read the number of edges
            adjList = collections.defaultdict(list)
            for i in range(e):
                src = int(input()) # Read the source node
                dest = int(input()) # Read the destination node
                adjList[src].append(dest) # Construct the adjacency list
            sccFinder = Main()
            result = sccFinder.getOutput(adjList, n)
            print("Number of strongly connected components: " + str(result)) # Print the result
        except ValueError:
            print("Invalid input. Please provide integers as input.") # Handle invalid input

if __name__ == "__main__":
    main = Main()
    main.main()

