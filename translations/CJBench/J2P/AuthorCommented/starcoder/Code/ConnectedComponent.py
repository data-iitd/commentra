
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Graph(object):

    class Node(object):
        def __init__(self, name):
            self.name = name

    class Edge(object):
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
        if start is None:
            start = Node(startNode)
            self.nodeList.append(start)
        if end is None:
            end = Node(endNode)
            self.nodeList.append(end)
        self.edgeList.append(Edge(start, end))

    def countGraphs(self):
        count = 0
        markedNodes = set()

        for n in self.nodeList:
            if markedNodes.add(n):
                markedNodes.update(self.depthFirstSearch(n, []))
                count += 1
        return count

    def depthFirstSearch(self, n, visited):
        visited.append(n)
        for e in self.edgeList:
            if e.startNode == n and e.endNode not in visited:
                self.depthFirstSearch(e.endNode, visited)
        return visited

if __name__ == "__main__":
    scanner = Scanner(System.in)

    charEdges = scanner.nextInt()
    graphChars = Graph()
    for i in range(charEdges):
        start = scanner.next().charAt(0)
        end = scanner.next().charAt(0)
        graphChars.addEdge(start, end)

    intEdges = scanner.nextInt()
    graphInts = Graph()
    for i in range(intEdges):
        start = scanner.nextInt()
        end = scanner.nextInt()
        graphInts.addEdge(start, end)

    print("Amount of different char-graphs: " + graphChars.countGraphs())
    print("Amount of different int-graphs: " + graphInts.countGraphs())

