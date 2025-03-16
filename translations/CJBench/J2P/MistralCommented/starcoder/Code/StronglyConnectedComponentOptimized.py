
import sys

# Class to represent a graph
class Graph:
    # Constructor to initialize the graph
    def __init__(self, n):
        self.adjList = [[] for i in range(n)]

    # Method to add an edge to the graph
    def addEdge(self, src, dest):
        self.adjList[src].append(dest)

    # Method to perform Depth First Search (DFS) and find strongly connected components
    def btrack(self, visited, dfsCallsNodes, currentNode):
        # Mark the current node as visited
        visited[currentNode] = 1

        # Get the list of neighbors for the current node
        neighbors = self.adjList[currentNode]

        # If the current node has neighbors, iterate through them and call recursively
        if neighbors!= None:
            for neighbor in neighbors:
                # If the neighbor is not visited, call btrack recursively
                if visited[neighbor] == -1:
                    self.btrack(visited, dfsCallsNodes, neighbor)

        # Add the current node to the stack of DFS call nodes
        dfsCallsNodes.append(currentNode)

    # Method to find strongly connected components using Depth First Search (DFS) and recursion
    def btrack2(self, visited, currentNode, newScc):
        # Mark the current node as visited
        visited[currentNode] = 1

        # Add the current node to the list of nodes in the current strongly connected component
        newScc.append(currentNode)

        # Get the list of neighbors for the current node
        neighbors = self.adjList[currentNode]

        # If the current node has neighbors, iterate through them and call recursively
        if neighbors!= None:
            for neighbor in neighbors:
                # If the neighbor is not visited, call btrack2 recursively
                if visited[neighbor] == -1:
                    self.btrack2(visited, neighbor, newScc)

    # Method to find the number of strongly connected components in the given graph
    def getOutput(self, n):
        # Initialize the visited array and fill it with -1
        visited = [-1] * n

        # Initialize the stack for DFS call nodes
        dfsCallsNodes = []

        # Iterate through all nodes in the graph and call btrack for each unvisited node
        for i in range(n):
            if visited[i] == -1:
                self.btrack(visited, dfsCallsNodes, i)

        # Initialize an empty list to store the nodes in each strongly connected component
        newScc = []

        # Initialize the visited array and fill it with -1
        visited = [-1] * n

        # Initialize the counter for the number of strongly connected components
        stronglyConnectedComponents = 0

        # While there are still nodes in the stack of DFS call nodes
        while dfsCallsNodes:
            # Get the next node from the stack
            node = dfsCallsNodes.pop()

            # If the node is not visited, call btrack2 recursively and increment the counter
            if visited[node] == -1:
                self.btrack2(visited, node, newScc)
                stronglyConnectedComponents += 1

        # Return the number of strongly connected components
        return stronglyConnectedComponents

# Main method to read input and call getOutput method
if __name__ == "__main__":
    # Initialize the Scanner to read input from the console
    scanner = sys.stdin

    try:
        # Read the number of nodes and edges from the input
        n = int(scanner.readline())
        e = int(scanner.readline())

        # Initialize the adjacency list for the graph
        adjList = Graph(n)

        # Read the edges and add them to the adjacency list
        for i in range(e):
            src = int(scanner.readline())
            dest = int(scanner.readline())
            adjList.addEdge(src, dest)

        # Create an instance of the Graph class and call the getOutput method
        sccFinder = Graph(n)
        result = sccFinder.getOutput(n)

        # Print the result to the console
        print("Number of strongly connected components: " + str(result))
    except ValueError:
        # Print an error message if the input is invalid
        print("Invalid input. Please provide integers as input.")
    finally:
        # Close the Scanner
        scanner.close()

