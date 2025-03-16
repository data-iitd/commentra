
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
        self.edgeList = ArrayList()
        self.nodeList = ArrayList()
    def addEdge(self, startNode, endNode):
        start = None
        end = None
        for node in self.nodeList:
            if startNode.compareTo(node.name) == 0:
                start = node
            elif endNode.compareTo(node.name) == 0:
                end = node
        if start == None:
            start = Node(startNode)
            self.nodeList.add(start)
        if end == None:
            end = Node(endNode)
            self.nodeList.add(end)
        self.edgeList.add(Edge(start, end))
    def countGraphs(self):
        count = 0
        markedNodes = HashSet()
        for n in self.nodeList:
            if markedNodes.add(n):
                markedNodes.addAll(self.depthFirstSearch(n, ArrayList()))
                count += 1
        return count
    def depthFirstSearch(self, n, visited):
        visited.add(n)
        for e in self.edgeList:
            if e.startNode.equals(n) and not visited.contains(e.endNode):
                self.depthFirstSearch(e.endNode, visited)
        return visited

def main():
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

if __name__ == "__main__":
    main()

