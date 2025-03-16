
# Importing the required libraries
import sys

# Class to represent an edge in the graph
class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

# Class to represent a graph
class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.edges = []

    # Function to add an edge to the graph
    def addEdge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))

# Class to represent a component in the union-find structure
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

    # Function to merge components based on the cheapest edges found
    def merge(self, cheapest):
        for i in range(self.graph.vertices):
            if cheapest[i] is not None:
                set1 = self.find(self.components, cheapest[i].src)
                set2 = self.find(self.components, cheapest[i].dest)
                # If the components are different, merge them
                if set1 != set2:
                    self.result.append(cheapest[i]) # Add edge to the result
                    self.union(self.components, set1, set2) # Union the components

    # Function to check if more edges can be added to the MST
    def hasMoreEdgesToAdd(self):
        return len(self.result) < self.graph.vertices - 1 # MST has (V-1) edges

    # Function to compute the cheapest edges for each component
    def computeCheapestEdges(self):
        cheapest = [None] * self.graph.vertices
        for edge in self.graph.edges:
            set1 = self.find(self.components, edge.src)
            set2 = self.find(self.components, edge.dest)
            # If the edge connects different components, check for the cheapest
            if set1 != set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge # Update cheapest edge for component 1
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge # Update cheapest edge for component 2
        return cheapest # Return the array of cheapest edges

    # Function to initialize the components for each vertex
    def initializeComponents(self, graph):
        components = [Component(i, 0) for i in range(graph.vertices)]
        return components # Return the initialized components

    # Function to find the root of a component using path compression
    def find(self, components, i):
        if components[i].parent != i:
            components[i].parent = self.find(components, components[i].parent) # Path compression
        return components[i].parent # Return the root of the component

    # Function to union two components
    def union(self, components, x, y):
        xroot = self.find(components, x)
        yroot = self.find(components, y)
        # Union by rank
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1 # Increase rank if they are of the same rank

# Function to execute Boruvka's algorithm and find the MST
def boruvkaMST(graph):
    boruvkaState = BoruvkaState(graph) # Initialize Boruvka's state
    while boruvkaState.hasMoreEdgesToAdd():
        cheapest = boruvkaState.computeCheapestEdges() # Compute cheapest edges
        boruvkaState.merge(cheapest) # Merge components based on cheapest edges
    return boruvkaState.result # Return the resulting edges of the MST

# Main function to read input and execute the algorithm
def main():
    vertices = int(sys.stdin.readline()) # Read number of vertices
    edges = int(sys.stdin.readline()) # Read number of edges
    graph = Graph(vertices) # Initialize the graph
    # Read edges and add them to the graph
    for i in range(edges):
        src, dest, weight = map(int, sys.stdin.readline().split())
        graph.addEdge(src, dest, weight)
    # Execute Boruvka's algorithm to find the MST
    mst = boruvkaMST(graph)
    totalWeight = 0 # Variable to store total weight of the MST
    print("Edges in MST:")
    # Print the edges in the MST and calculate total weight
    for edge in mst:
        print(edge.src, " - ", edge.dest, " : ", edge.weight)
        totalWeight += edge.weight
    # Print the total weight of the MST
    print("Total Weight: ", totalWeight)

if __name__ == "__main__":
    main()

