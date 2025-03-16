
class Graph:
    class Node:
        def __init__(self, name):
            self.name = name
    class Edge:
        def __init__(self, startNode, endNode):
            self.startNode = startNode
            self.endNode = endNode
    def __init__(self):
        self.edgeList = []
        self.nodeList = []
    def addEdge(self, startNode, endNode):
        start = None
        end = None
        for node in self.nodeList:
            if startNode == node.name:
                start = node
            elif endNode == node.name:
                end = node
        if start == None:
            start = Node(startNode)
            self.nodeList.append(start)
        if end == None:
            end = Node(endNode)
            self.nodeList.append(end)
        self.edgeList.append(Edge(start, end))
    def countGraphs(self):
        count = 0
        markedNodes = set()
        for node in self.nodeList:
            if node not in markedNodes:
                markedNodes.add(node)
                markedNodes.update(self.depthFirstSearch(node, []))
                count += 1
        return count
    def depthFirstSearch(self, n, visited):
        visited.append(n)
        for edge in self.edgeList:
            if edge.startNode == n and edge.endNode not in visited:
                self.depthFirstSearch(edge.endNode, visited)
        return visited

def main():
    scanner = input
    charEdges = int(scanner())
    graphChars = Graph()
    for i in range(charEdges):
        start = scanner()[0]
        end = scanner()[0]
        graphChars.addEdge(start, end)
    intEdges = int(scanner())
    graphInts = Graph()
    for i in range(intEdges):
        start = int(scanner())
        end = int(scanner())
        graphInts.addEdge(start, end)
    print("Amount of different char-graphs:", graphChars.countGraphs())
    print("Amount of different int-graphs:", graphInts.countGraphs())

main()

