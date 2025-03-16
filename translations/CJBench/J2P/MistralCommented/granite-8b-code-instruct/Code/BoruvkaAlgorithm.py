

import sys

class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

class Graph:
    def __init__(self, vertex):
        self.vertex = vertex
        self.edges = []

    def addEdge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))

class Component:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

class BoruvkaState:
    def __init__(self, graph):
        self.result = []
        self.components = self.initializeComponents(graph)
        self.graph = graph

    def merge(self, cheapest):
        for i in range(self.graph.vertex):
            if cheapest[i] is not None:
                component1 = self.find(self.components, cheapest[i].src)
                component2 = self.find(self.components, cheapest[i].dest)
                if component1!= component2:
                    self.result.append(cheapest[i])
                    self.union(self.components, component1, component2)

    def hasMoreEdgesToAdd(self):
        return len(self.result) < self.graph.vertex - 1

    def computeCheapestEdges(self):
        cheapest = [None] * self.graph.vertex
        for edge in self.graph.edges:
            set1 = self.find(self.components, edge.src)
            set2 = self.find(self.components, edge.dest)
            if set1!= set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge
        return cheapest

    def initializeComponents(self, graph):
        components = [Component(v, 0) for v in range(graph.vertex)]
        return components

    @staticmethod
    def find(components, i):
        if components[i].parent!= i:
            components[i].parent = BoruvkaState.find(components, components[i].parent)
        return components[i].parent

    @staticmethod
    def union(components, x, y):
        xroot = BoruvkaState.find(components, x)
        yroot = BoruvkaState.find(components, y)
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1

def boruvkaMST(graph):
    boruvkaState = BoruvkaState(graph)
    while boruvkaState.hasMoreEdgesToAdd():
        cheapest = boruvkaState.computeCheapestEdges()
        boruvkaState.merge(cheapest)
    return boruvkaState.result

if __name__ == "__main__":
    vertex, edges = map(int, sys.stdin.readline().split())
    graph = Graph(vertex)
    for _ in range(edges):
        src, dest, weight = map(int, sys.stdin.readline().split())
        graph.addEdge(src, dest, weight)
    mst = boruvkaMST(graph)
    totalWeight = 0
    print("Edges in MST:")
    for edge in mst:
        print(f"{edge.src} - {edge.dest} : {edge.weight}")
        totalWeight += edge.weight
    print(f"Total Weight: {totalWeight}")

Translate the above Python code to C++ and end with comment "