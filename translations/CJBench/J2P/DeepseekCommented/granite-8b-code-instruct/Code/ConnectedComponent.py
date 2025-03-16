
import sys

# Graph class definition
class Graph:
    # Inner class Node represents a node in the graph
    class Node:
        def __init__(self, name):
            self.name = name

    # Inner class Edge represents an edge between two nodes
    class Edge:
        def __init__(self, startNode, endNode):
            self.startNode = startNode
            self.endNode = endNode

    # ArrayList to store edges
    edgeList = []
    # ArrayList to store nodes
    nodeList = []
    # Constructor to initialize the graph
    def __init__(self):
        self.edgeList = []
        self.nodeList = []

    # Method to add an edge between two nodes
    def addEdge(self, startNode, endNode):
        start = None
        end = None
        # Check if the start and end nodes already exist in the node list
        for node in self.nodeList:
            if startNode == node.name:
                start = node
            elif endNode == node.name:
                end = node
        # If the start node does not exist, create a new node and add it to the list
        if start is None:
            start = Graph.Node(startNode)
            self.nodeList.append(start)
        # If the end node does not exist, create a new node and add it to the list
        if end is None:
            end = Graph.Node(endNode)
            self.nodeList.append(end)
        # Add the new edge to the edge list
        self.edgeList.append(Graph.Edge(start, end))

    # Method to count the number of connected components in the graph
    def countGraphs(self):
        count = 0
        # Set to keep track of marked nodes
        markedNodes = set()
        # Iterate through each node in the node list
        for n in self.nodeList:
            # If the node has not been marked, perform a depth-first search
            if n not in markedNodes:
                markedNodes.update(self.depthFirstSearch(n, set()))
                count += 1
        return count

    # Helper method for countGraphs to perform depth-first search
    def depthFirstSearch(self, n, visited):
        visited.add(n)
        # Iterate through each edge in the edge list
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                self.depthFirstSearch(e.endNode, visited)
        return visited

# Main class containing the main method
class Main:
    def main(self):
        # Read the number of edges for characters
        charEdges = int(input())
        # Create a graph for characters
        graphChars = Graph()
        # Add edges for characters
        for i in range(charEdges):
            start = input().strip()[0]
            end = input().strip()[0]
            graphChars.addEdge(start, end)
        # Read the number of edges for integers
        intEdges = int(input())
        # Create a graph for integers
        graphInts = Graph()
        # Add edges for integers
        for i in range(intEdges):
            start = int(input())
            end = int(input())
            graphInts.addEdge(start, end)
        # Print the number of different connected components for character graph
        print("Amount of different char-graphs: " + str(graphChars.countGraphs()))
        # Print the number of different connected components for integer graph
        print("Amount of different int-graphs: " + str(graphInts.countGraphs()))

if __name__ == "__main__":
    Main().main()

