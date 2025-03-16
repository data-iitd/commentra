
# Define a generic graph class with inner classes Node and Edge
class Graph(object):

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
        if start == None:
            start = Node(startNode)
            self.nodeList.append(start)

        # If end node is not found, create a new Node and add it to nodeList
        if end == None:
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
        if visited == None:
            visited = []
        visited.append(n)

        # Iterate through edgeList to mark all reachable nodes
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                # Recursively call depthFirstSearch for the reachable node
                reachableNodes = self.depthFirstSearch(e.endNode, [])
                visited.extend(reachableNodes)
        return visited

# Main class to read input and print output
if __name__ == "__main__":
    scanner = raw_input()
    charEdges = int(scanner.next())
    graphChars = Graph()

    # Read character edges and add them to the graph
    for i in range(charEdges):
        start = scanner.next().charAt(0)
        end = scanner.next().charAt(0)
        graphChars.addEdge(start, end)

    intEdges = int(scanner.next())
    graphInts = Graph()

    # Read integer edges and add them to the graph
    for i in range(intEdges):
        start = int(scanner.next())
        end = int(scanner.next())
        graphInts.addEdge(start, end)

    # Print the number of different connected components in the character and integer graphs
    print "Amount of different char-graphs: " + str(graphChars.countGraphs())
    print "Amount of different int-graphs: " + str(graphInts.countGraphs())

