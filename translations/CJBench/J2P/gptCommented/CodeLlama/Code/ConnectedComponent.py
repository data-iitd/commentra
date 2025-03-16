
# Import modules
import sys

# Class to represent a node in the graph
class Node:
    def __init__(self, name):
        self.name = name

# Class to represent an edge in the graph
class Edge:
    def __init__(self, startNode, endNode):
        self.startNode = startNode
        self.endNode = endNode

# Class to represent a graph
class Graph:
    def __init__(self):
        self.edgeList = []
        self.nodeList = []

    # Method to add an edge between two nodes in the graph
    def addEdge(self, startNode, endNode):
        start = None
        end = None

        # Search for existing nodes in the node list
        for node in self.nodeList:
            if startNode == node.name:
                start = node
            elif endNode == node.name:
                end = node

        # If the starting node does not exist, create and add it to the node list
        if start is None:
            start = Node(startNode)
            self.nodeList.append(start)

        # If the ending node does not exist, create and add it to the node list
        if end is None:
            end = Node(endNode)
            self.nodeList.append(end)

        # Add a new edge connecting the start and end nodes
        self.edgeList.append(Edge(start, end))

    # Method to count the number of distinct graphs in the graph
    def countGraphs(self):
        count = 0
        markedNodes = set()

        # Iterate through all nodes in the node list
        for n in self.nodeList:
            # If the node has not been visited, perform DFS
            if n not in markedNodes:
                markedNodes.update(self.depthFirstSearch(n, []))
                count += 1

        return count

    # Private method to perform depth-first search (DFS) on the graph
    def depthFirstSearch(self, n, visited):
        visited.append(n)

        # Explore all edges starting from the current node
        for e in self.edgeList:
            # If the edge starts from the current node and the end node is not visited
            if e.startNode == n and e.endNode not in visited:
                self.depthFirstSearch(e.endNode, visited)

        return visited

# Main function to execute the program
def main():
    # Read the number of edges for character graph
    charEdges = int(sys.stdin.readline())
    graphChars = Graph()

    # Read edges for the character graph
    for i in range(charEdges):
        start = sys.stdin.readline().strip()[0]
        end = sys.stdin.readline().strip()[0]
        graphChars.addEdge(start, end)

    # Read the number of edges for integer graph
    intEdges = int(sys.stdin.readline())
    graphInts = Graph()

    # Read edges for the integer graph
    for i in range(intEdges):
        start = int(sys.stdin.readline().strip())
        end = int(sys.stdin.readline().strip())
        graphInts.addEdge(start, end)

    # Output the number of distinct character graphs
    print("Amount of different char-graphs:", graphChars.countGraphs())
    # Output the number of distinct integer graphs
    print("Amount of different int-graphs:", graphInts.countGraphs())

if __name__ == "__main__":
    main()
