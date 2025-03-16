from typing import List, Set, Generic, TypeVar

class Graph(Generic):
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
        start = next((node for node in self.nodeList if node.name == startNode), None)
        end = next((node for node in self.nodeList if node.name == endNode), None)
        if start is None:
            start = self.Node(startNode)
            self.nodeList.append(start)
        if end is None:
            end = self.Node(endNode)
            self.nodeList.append(end)
        self.edgeList.append(self.Edge(start, end))

    def countGraphs(self):
        count = 0
        markedNodes = set()
        for node in self.nodeList:
            if node not in markedNodes:
                markedNodes.update(self.depthFirstSearch(node, []))
                count += 1
        return count

    def depthFirstSearch(self, n, visited):
        visited.append(n)
        for edge in self.edgeList:
            if edge.startNode.name == n.name and edge.endNode not in visited:
                self.depthFirstSearch(edge.endNode, visited)
        return visited

# Main class in Python
class Main:
    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        charEdges = int(data[0])
        graphChars = Graph()
        index = 1
        for i in range(charEdges):
            start = data[index]
            end = data[index + 1]
            graphChars.addEdge(start, end)
            index += 2
        intEdges = int(data[index])
        graphInts = Graph()
        index += 1
        for i in range(intEdges):
            start = int(data[index])
            end = int(data[index + 1])
            graphInts.addEdge(start, end)
            index += 2
        print("Amount of different char-graphs:", graphChars.countGraphs())
        print("Amount of different int-graphs:", graphInts.countGraphs())

Main.main()
