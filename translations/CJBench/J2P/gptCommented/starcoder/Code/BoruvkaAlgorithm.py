import sys

# Class representing an edge in the graph
class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight


# Class representing a graph
class Graph:
    def __init__(self, vertex):
        self.vertex = vertex
        self.edges = []

    def addEdge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))


# Class representing a component in the union-find structure
class Component:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank


# Class to maintain the state of Boruvka's algorithm
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
                # If the components are different, merge them
                if component1!= component2:
                    self.result.append(cheapest[i])  # Add edge to the result
                    self.union(self.components, component1, component2)  # Union the components

    def hasMoreEdgesToAdd(self):
        return len(self.result) < self.graph.vertex - 1

    def computeCheapestEdges(self):
        cheapest = [None] * self.graph.vertex
        for edge in self.graph.edges:
            set1 = self.find(self.components, edge.src)
            set2 = self.find(self.components, edge.dest)
            # If the edge connects different components, check for the cheapest
            if set1!= set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge  # Update cheapest edge for component 1
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge  # Update cheapest edge for component 2
        return cheapest

    @staticmethod
    def initializeComponents(graph):
        components = [Component(v, 0) for v in range(graph.vertex)]
        return components

    @staticmethod
    def find(components, i):
        if components[i].parent!= i:
            components[i].parent = BoruvkaState.find(components, components[i].parent)  # Path compression
        return components[i].parent

    @staticmethod
    def union(components, x, y):
        xroot = BoruvkaState.find(components, x)
        yroot = BoruvkaState.find(components, y)
        # Union by rank
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1  # Increase rank if they are of the same rank


# Method to execute Boruvka's algorithm and find the MST
def boruvkaMST(graph):
    boruvkaState = BoruvkaState(graph)  # Initialize Boruvka's state
    while boruvkaState.hasMoreEdgesToAdd():
        cheapest = boruvkaState.computeCheapestEdges()  # Compute cheapest edges
        boruvkaState.merge(cheapest)  # Merge components based on cheapest edges
    return boruvkaState.result  # Return the resulting edges of the MST


# Main method to read input and execute the algorithm
def main():
    graph = Graph(int(sys.stdin.readline().strip()))  # Read number of vertices
    edges = int(sys.stdin.readline().strip())  # Read number of edges
    # Read edges and add them to the graph
    for i in range(edges):
        src, dest, weight = [int(x) for x in sys.stdin.readline().strip().split()]
        graph.addEdge(src, dest, weight)
    # Execute Boruvka's algorithm to find the MST
    mst = boruvkaMST(graph)
    totalWeight = 0  # Variable to store total weight of the MST
    print("Edges in MST:")
    # Print the edges in the MST and calculate total weight
    for edge in mst:
        print(edge.src, "-", edge.dest, ":", edge.weight)
        totalWeight += edge.weight
    # Print the total weight of the MST
    print("Total Weight:", totalWeight)


if __name__ == "__main__":
    main()

# 