

import sys

# Define a generic graph class with inner classes Node and Edge
class Graph:

    # Initialize inner classes edgeList and nodeList
    def __init__(self):
        self.edgeList = []
        self.nodeList = []

    # Add an edge between two nodes
    def addEdge(self, startNode, endNode):
        start = None
        end = None

        # Iterate through nodeList to find start and end nodes
        for node in self.nodeList:
            if startNode == node.name:
                start = node
            elif endNode == node.name:
                end = node

        # If start node is not found, create a new Node and add it to nodeList
        if start is None:
            start = Node(startNode)
            self.nodeList.append(start)

        # If end node is not found, create a new Node and add it to nodeList
        if end is None:
            end = Node(endNode)
            self.nodeList.append(end)

        # Add the edge to edgeList
        self.edgeList.append(Edge(start, end))

    # Count the number of connected components in the graph
    def countGraphs(self):
        count = 0
        markedNodes = set()

        # Iterate through nodeList and mark each unvisited node and its connected components
        for n in self.nodeList:
            if n not in markedNodes:
                # Recursively mark all nodes reachable from n
                markedNodes.update(self.depthFirstSearch(n))
                count += 1
        return count

    # Perform depth-first search from a given node and mark all reachable nodes
    def depthFirstSearch(self, n, visited=None):
        if visited is None:
            visited = set()
        visited.add(n)

        # Iterate through edgeList to mark all reachable nodes
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                # Recursively call depthFirstSearch for the reachable node
                visited.update(self.depthFirstSearch(e.endNode))
        return visited

# Main class to read input and print output
class Main:

    def __init__(self):
        self.graphChars = Graph()
        self.graphInts = Graph()

    def readInput(self):
        # Read the number of character edges
        self.charEdges = int(input())

        # Read character edges and add them to the graph
        for i in range(self.charEdges):
            start = input()[0]
            end = input()[0]
            self.graphChars.addEdge(start, end)

        # Read the number of integer edges
        self.intEdges = int(input())

        # Read integer edges and add them to the graph
        for i in range(self.intEdges):
            start = int(input())
            end = int(input())
            self.graphInts.addEdge(start, end)

    def printOutput(self):
        # Print the number of different connected components in the character and integer graphs
        print("Amount of different char-graphs: " + str(self.graphChars.countGraphs()))
        print("Amount of different int-graphs: " + str(self.graphInts.countGraphs()))

    def run(self):
        self.readInput()
        self.printOutput()

if __name__ == "__main__":
    Main().run()

Translate the above Python code to C++ and end with comment "