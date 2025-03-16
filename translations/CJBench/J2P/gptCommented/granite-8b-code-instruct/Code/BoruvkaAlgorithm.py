
import sys

# Main class containing the implementation of Boruvka's algorithm
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

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

        # Method to add an edge to the graph
        def addEdge(self, src, dest, weight):
            self.edges.append(Main.Edge(src, dest, weight))

    # Class representing a component in the union-find structure
    class Component:
        def __init__(self, parent, rank):
            self.parent = parent
            self.rank = rank

    # Class to maintain the state of Boruvka's algorithm
    class BoruvkaState:
        def __init__(self, graph):
            self.result = []
            self.components = Main.initializeComponents(graph)
            self.graph = graph

        # Method to merge components based on the cheapest edges found
        def merge(self, cheapest):
            for i in range(self.graph.vertex):
                if cheapest[i] is not None:
                    component1 = Main.find(self.components, cheapest[i].src)
                    component2 = Main.find(self.components, cheapest[i].dest)
                    # If the components are different, merge them
                    if component1!= component2:
                        self.result.append(cheapest[i])  # Add edge to the result
                        Main.union(self.components, component1, component2)  # Union the components

        # Method to check if more edges can be added to the MST
        def hasMoreEdgesToAdd(self):
            return len(self.result) < self.graph.vertex - 1  # MST has (V-1) edges

        # Method to compute the cheapest edges for each component
        def computeCheapestEdges(self):
            cheapest = [None] * self.graph.vertex  # Array to store cheapest edges
            for edge in self.graph.edges:
                set1 = Main.find(self.components, edge.src)
                set2 = Main.find(self.components, edge.dest)
                # If the edge connects different components, check for the cheapest
                if set1!= set2:
                    if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                        cheapest[set1] = edge  # Update cheapest edge for component 1
                    if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                        cheapest[set2] = edge  # Update cheapest edge for component 2
            return cheapest  # Return the array of cheapest edges

        # Method to initialize the components for each vertex
        @staticmethod
        def initializeComponents(graph):
            components = [Main.Component(i, 0) for i in range(graph.vertex)]
            return components  # Return the initialized components

    # Method to find the root of a component using path compression
    @staticmethod
    def find(components, i):
        if components[i].parent!= i:
            components[i].parent = Main.find(components, components[i].parent)  # Path compression
        return components[i].parent  # Return the root of the component

    # Method to union two components
    @staticmethod
    def union(components, x, y):
        xroot = Main.find(components, x)
        yroot = Main.find(components, y)
        # Union by rank
        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1  # Increase rank if they are of the same rank

    # Method to execute Boruvka's algorithm and find the MST
    @staticmethod
    def boruvkaMST(graph):
        boruvkaState = Main.BoruvkaState(graph)  # Initialize Boruvka's state
        while boruvkaState.hasMoreEdgesToAdd():
            cheapest = boruvkaState.computeCheapestEdges()  # Compute cheapest edges
            boruvkaState.merge(cheapest)  # Merge components based on cheapest edges
        return boruvkaState.result  # Return the resulting edges of the MST

    # Main method to read input and execute the algorithm
    @staticmethod
    def main():
        vertices, edges = map(int, sys.stdin.readline().split())  # Read number of vertices and edges
        graph = Main.Graph(vertices)  # Initialize the graph
        # Read edges and add them to the graph
        for _ in range(edges):
            src, dest, weight = map(int, sys.stdin.readline().split())
            graph.addEdge(src, dest, weight)
        # Execute Boruvka's algorithm to find the MST
        mst = Main.boruvkaMST(graph)
        total_weight = 0  # Variable to store total weight of the MST
        print("Edges in MST:")
        # Print the edges in the MST and calculate total weight
        for edge in mst:
            print(f"{edge.src} - {edge.dest} : {edge.weight}")
            total_weight += edge.weight
        # Print the total weight of the MST
        print(f"Total Weight: {total_weight}")

# Call the main method to execute the program
Main.main()
