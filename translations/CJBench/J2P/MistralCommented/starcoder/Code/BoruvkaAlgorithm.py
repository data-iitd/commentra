
import sys

class Edge:
    def __init__(self, src, dest, weight):
        # Constructor for creating an edge with source, destination and weight
        self.src = src
        self.dest = dest
        self.weight = weight

class Graph:
    def __init__(self, vertex):
        # Constructor for creating a graph with given number of vertices
        self.vertex = vertex
        self.edges = []

    def addEdge(self, src, dest, weight):
        # Method for adding an edge between two vertices with given weight
        self.edges.append(Edge(src, dest, weight))

class Component:
    def __init__(self, parent, rank):
        # Constructor for creating a component with given parent and rank
        self.parent = parent
        self.rank = rank

class BoruvkaState:
    def __init__(self, graph):
        # Constructor for creating a Boruvka state with given graph
        self.result = []
        self.components = self.initializeComponents(graph)
        self.graph = graph

    def merge(self, cheapest):
        # Method for merging two components with the cheapest edge between them
        for i in range(self.graph.vertex):
            if cheapest[i]!= None:
                component1 = self.find(self.components, cheapest[i].src)
                component2 = self.find(self.components, cheapest[i].dest)
                if component1!= component2:
                    self.result.append(cheapest[i])
                    self.union(self.components, component1, component2)

    def hasMoreEdgesToAdd(self):
        # Method for checking if there are more edges to add to the MST
        return len(self.result) < self.graph.vertex - 1

    def computeCheapestEdges(self):
        # Method for finding the cheapest edges between different components
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

    def initializeComponents(self, graph):
        # Method for initializing the components with each vertex as a separate set
        components = [None] * graph.vertex
        for v in range(graph.vertex):
            components[v] = Component(v, 0)
        return components

    def find(self, components, i):
        # Method for finding the root of the component containing the given vertex
        if components[i].parent!= i:
            components[i].parent = self.find(components, components[i].parent)
        return components[i].parent

    def union(self, components, x, y):
        # Method for merging two components into one
        xroot = self.find(components, x)
        yroot = self.find(components, y)
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1

def boruvkaMST(graph):
    # Method for finding the minimum spanning tree using Boruvka's algorithm
    boruvkaState = BoruvkaState(graph)
    while boruvkaState.hasMoreEdgesToAdd():
        cheapest = boruvkaState.computeCheapestEdges()
        boruvkaState.merge(cheapest)
    return boruvkaState.result

def main():
    scanner = sys.stdin # Creating a Scanner object for reading input

    vertices = int(scanner.readline()) # Reading the number of vertices from the input
    edges = int(scanner.readline()) # Reading the number of edges from the input

    graph = Graph(vertices) # Creating a graph with the given number of vertices
    for i in range(edges):
        src = int(scanner.readline()) # Reading the source vertex from the input
        dest = int(scanner.readline()) # Reading the destination vertex from the input
        weight = int(scanner.readline()) # Reading the weight of the edge from the input
        graph.addEdge(src, dest, weight) # Adding the edge to the graph

    mst = boruvkaMST(graph) # Finding the minimum spanning tree using Boruvka's algorithm

    totalWeight = 0 # Initializing the total weight of the MST to zero
    print("Edges in MST:") # Printing the header for the output
    for edge in mst:
        print(edge.src, " - ", edge.dest, " : ", edge.weight) # Printing each edge and its weight
        totalWeight += edge.weight # Adding the weight of each edge to the total weight

    print("Total Weight: ", totalWeight) # Printing the total weight of the MST

if __name__ == "__main__":
    main()

