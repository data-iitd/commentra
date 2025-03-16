import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

# Main class to encapsulate the functionality
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Edge class to represent edges in the graph
    class Edge:
        def __init__(self, src, dest, weight):
            self.src = src
            self.dest = dest
            self.weight = weight

    # Graph class to represent the graph
    class Graph:
        def __init__(self, vertex):
            self.vertex = vertex
            self.edges = []

        # Method to add an edge to the graph
        def addEdge(self, src, dest, weight):
            self.edges.append(Edge(src, dest, weight))

    # Component class to manage disjoint sets
    class Component:
        def __init__(self, parent, rank):
            self.parent = parent
            self.rank = rank

    # BoruvkaState class to manage the state of Boruvka's algorithm
    class BoruvkaState:
        def __init__(self, graph):
            self.result = []
            self.components = self.initializeComponents(graph)
            self.graph = graph

        # Method to merge components using the cheapest edge
        def merge(self, cheapest):
            for i in range(self.graph.vertex):
                if cheapest[i]!= None:
                    component1 = self.find(self.components, cheapest[i].src)
                    component2 = self.find(self.components, cheapest[i].dest)
                    if component1!= component2:
                        self.result.append(cheapest[i])
                        self.union(self.components, component1, component2)

        # Method to check if there are more edges to add to the MST
        def hasMoreEdgesToAdd(self):
            return len(self.result) < self.graph.vertex - 1

        # Method to compute the cheapest edges for each component
        def computeCheapestEdges(self):
            cheapest = [None] * self.graph.vertex
            for edge in self.graph.edges:
                set1 = self.find(self.components, edge.src)
                set2 = self.find(self.components, edge.dest)
                if set1!= set2:
                    if cheapest[set1] == None or edge.weight < cheapest[set1].weight:
                        cheapest[set1] = edge
                    if cheapest[set2] == None or edge.weight < cheapest[set2].weight:
                        cheapest[set2] = edge
            return cheapest

        # Method to initialize components for disjoint set
        def initializeComponents(self, graph):
            components = [None] * graph.vertex
            for v in range(graph.vertex):
                components[v] = Component(v, 0)
            return components

    # Method to find the parent of a component
    def find(self, components, i):
        if components[i].parent!= i:
            components[i].parent = self.find(components, components[i].parent)
        return components[i].parent

    # Method to union two components
    def union(self, components, x, y):
        xroot = self.find(components, x)
        yroot = self.find(components, y)
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1

    # Method to find the Minimum Spanning Tree using Boruvka's algorithm
    def boruvkaMST(self, graph):
        boruvkaState = BoruvkaState(graph)
        while boruvkaState.hasMoreEdgesToAdd():
            cheapest = boruvkaState.computeCheapestEdges()
            boruvkaState.merge(cheapest)
        return boruvkaState.result

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in)
        vertices = scanner.nextInt()
        edges = scanner.nextInt()
        graph = Graph(vertices)
        for i in range(edges):
            src = scanner.nextInt()
            dest = scanner.nextInt()
            weight = scanner.nextInt()
            graph.addEdge(src, dest, weight)
        mst = self.boruvkaMST(graph)
        totalWeight = 0
        print("Edges in MST:")
        for edge in mst:
            print(edge.src + " - " + edge.dest + " : " + edge.weight)
            totalWeight += edge.weight
        print("Total Weight: " + totalWeight)

# 