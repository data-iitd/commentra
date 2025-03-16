
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
    def depthFirstSearch(self, n, visited):
        visited.append(n)

        # Iterate through edgeList to mark all reachable nodes
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                # Recursively call depthFirstSearch for the reachable node
                reachableNodes = self.depthFirstSearch(e.endNode, [])
                visited.extend(reachableNodes)

        # Return the list of visited nodes
        return visited

# Define a Node class
class Node:
    def __init__(self, name):
        self.name = name

# Define an Edge class
class Edge:
    def __init__(self, startNode, endNode):
        self.startNode = startNode
        self.endNode = endNode

# Main class to read input and print output
def main():
    # Read the number of character edges
    charEdges = int(sys.stdin.readline())

    # Initialize a Graph object for characters
    graphChars = Graph()

    # Read character edges and add them to the graph
    for i in range(charEdges):
        start, end = sys.stdin.readline().split()
        graphChars.addEdge(start, end)

    # Read the number of integer edges
    intEdges = int(sys.stdin.readline())

    # Initialize a Graph object for integers
    graphInts = Graph()

    # Read integer edges and add them to the graph
    for i in range(intEdges):
        start, end = sys.stdin.readline().split()
        graphInts.addEdge(int(start), int(end))

    # Print the number of different connected components in the character and integer graphs
    print("Amount of different char-graphs:", graphChars.countGraphs())
    print("Amount of different int-graphs:", graphInts.countGraphs())

if __name__ == "__main__":
    main()

