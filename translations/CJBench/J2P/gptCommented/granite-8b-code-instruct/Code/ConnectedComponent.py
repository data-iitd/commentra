
import sys

# Generic Graph class that can hold nodes of any type that is comparable
class Graph:
    # Inner class representing a Node in the graph
    class Node:
        def __init__(self, name):
            self.name = name # Constructor to initialize the node's name

    # Inner class representing an Edge in the graph
    class Edge:
        def __init__(self, startNode, endNode):
            self.startNode = startNode # Constructor to initialize the edge's start node
            self.endNode = endNode     # Constructor to initialize the edge's end node

    # Lists to hold edges and nodes of the graph
    edgeList = []
    nodeList = []

    # Constructor to initialize the graph
    def __init__(self):
        self.edgeList = [] # Initialize the edge list
        self.nodeList = [] # Initialize the node list

    # Method to add an edge between two nodes in the graph
    def addEdge(self, startNode, endNode):
        start = None # Variable to hold the starting node
        end = None   # Variable to hold the ending node

        # Search for existing nodes in the node list
        for node in self.nodeList:
            if startNode == node.name:
                start = node # Found the starting node
            elif endNode == node.name:
                end = node # Found the ending node

        # If the starting node does not exist, create and add it to the node list
        if start is None:
            start = Graph.Node(startNode)
            self.nodeList.append(start)
        # If the ending node does not exist, create and add it to the node list
        if end is None:
            end = Graph.Node(endNode)
            self.nodeList.append(end)

        # Add a new edge connecting the start and end nodes
        self.edgeList.append(Graph.Edge(start, end))

    # Method to count the number of distinct graphs in the graph
    def countGraphs(self):
        count = 0 # Counter for distinct graphs
        markedNodes = set() # Set to keep track of visited nodes

        # Iterate through all nodes in the node list
        for n in self.nodeList:
            # If the node has not been visited, perform DFS
            if n not in markedNodes:
                markedNodes.update(self.depthFirstSearch(n, set())) # Mark all reachable nodes
                count += 1 # Increment the graph count
        return count # Return the total count of distinct graphs

    # Private method to perform depth-first search (DFS) on the graph
    def depthFirstSearch(self, n, visited):
        visited.add(n) # Mark the current node as visited

        # Explore all edges starting from the current node
        for e in self.edgeList:
            # If the edge starts from the current node and the end node is not visited
            if e.startNode == n and e.endNode not in visited:
                self.depthFirstSearch(e.endNode, visited) # Recursively visit the end node
        return visited # Return the list of visited nodes

# Main function to execute the program
def main():
    # Read the number of edges for character graph
    charEdges = int(input())
    graphChars = Graph() # Create a graph for characters

    # Read edges for the character graph
    for i in range(charEdges):
        start = input().strip()[0] # Read starting character
        end = input().strip()[0]   # Read ending character
        graphChars.addEdge(start, end) # Add the edge to the graph

    # Read the number of edges for integer graph
    intEdges = int(input())
    graphInts = Graph() # Create a graph for integers

    # Read edges for the integer graph
    for i in range(intEdges):
        start = int(input()) # Read starting integer
        end = int(input())   # Read ending integer
        graphInts.addEdge(start, end) # Add the edge to the graph

    # Output the number of distinct character graphs
    print("Amount of different char-graphs: " + str(graphChars.countGraphs()))
    # Output the number of distinct integer graphs
    print("Amount of different int-graphs: " + str(graphInts.countGraphs()))

# Call the main function
if __name__ == "__main__":
    main()

