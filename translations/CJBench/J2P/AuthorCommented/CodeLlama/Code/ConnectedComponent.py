
import sys

class Graph:
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

        for n in self.nodeList:
            if n not in markedNodes:
                markedNodes.add(n)
                markedNodes.update(self.depthFirstSearch(n, []))
                count += 1
        return count

    def depthFirstSearch(self, n, visited):
        visited.append(n)
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                self.depthFirstSearch(e.endNode, visited)
        return visited

class Node:
    def __init__(self, name):
        self.name = name

class Edge:
    def __init__(self, startNode, endNode):
        self.startNode = startNode
        self.endNode = endNode

def main():
    charEdges = int(sys.stdin.readline())
    graphChars = Graph()
    for i in range(charEdges):
        start, end = sys.stdin.readline().split()
        graphChars.addEdge(start, end)

    intEdges = int(sys.stdin.readline())
    graphInts = Graph()
    for i in range(intEdges):
        start, end = sys.stdin.readline().split()
        graphInts.addEdge(int(start), int(end))

    print("Amount of different char-graphs:", graphChars.countGraphs())
    print("Amount of different int-graphs:", graphInts.countGraphs())

if __name__ == "__main__":
    main()

