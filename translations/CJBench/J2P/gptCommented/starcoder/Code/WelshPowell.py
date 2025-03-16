import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main:
    # Constant representing a blank color
    BLANK_COLOR = -1

    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Inner class representing a Graph using adjacency lists
    class Graph:
        def __init__(self, vertices):
            self.adjacencyLists = [set() for _ in range(vertices)]

        # Method to add an edge between two nodes in the graph
        def addEdge(self, nodeA, nodeB):
            self.adjacencyLists[nodeA].add(nodeB)
            self.adjacencyLists[nodeB].add(nodeA)

        # Method to get the adjacency list of a specific vertex
        def getAdjacencyList(self, vertex):
            return self.adjacencyLists[vertex]

        # Method to get the number of vertices in the graph
        def getNumVertices(self):
            return len(self.adjacencyLists)

    # Method to find a valid coloring for the graph
    def findColoring(self, graph):
        # Initialize colors for all vertices to blank
        colors = self.initializeColors(graph.getNumVertices())

        # Get the vertices sorted by their degree in descending order
        sortedVertices = self.getSortedNodes(graph)

        # Assign colors to each vertex
        for vertex in sortedVertices:
            # If the vertex is uncolored, proceed to color it
            if self.isBlank(colors[vertex]):
                # Determine which colors are already used by adjacent vertices
                usedColors = self.computeUsedColors(graph, vertex, colors)

                # Find the first unused color
                newColor = self.firstUnusedColor(usedColors)

                # Assign the new color to the vertex
                colors[vertex] = newColor

        return colors # Return the array of colors assigned to vertices

    # Method to check if a color is blank (unassigned)
    def isBlank(self, color):
        return color == self.BLANK_COLOR

    # Method to initialize the colors array with blank colors
    def initializeColors(self, numberOfVertices):
        colors = [self.BLANK_COLOR for _ in range(numberOfVertices)]
        colors.fill(self.BLANK_COLOR) # Fill with blank color
        return colors

    # Method to get the vertices sorted by their degree in descending order
    def getSortedNodes(self, graph):
        return sorted(range(graph.getNumVertices()), key=lambda v: -len(graph.getAdjacencyList(v)))

    # Method to compute which colors are used by adjacent vertices
    def computeUsedColors(self, graph, vertex, colors):
        usedColors = [False for _ in range(graph.getNumVertices())]

        # Check the colors of all adjacent vertices
        for neighbor in graph.getAdjacencyList(vertex):
            color = colors[neighbor]
            if not self.isBlank(color):
                usedColors[color] = True

        return usedColors # Return the array indicating used colors

    # Method to find the first unused color
    def firstUnusedColor(self, usedColors):
        return next((color for color in range(len(usedColors)) if not usedColors[color]), -1) # Return -1 if no unused color is found

if __name__ == '__main__':
    # Create a scanner to read input from the console
    scanner = Scanner(System.in)

    # Read the number of vertices and edges from input
    vertices = scanner.nextInt()
    edges = scanner.nextInt()

    # Initialize the graph with the specified number of vertices
    graph = Graph(vertices)

    # Read each edge and add it to the graph
    for i in range(edges):
        from = scanner.nextInt()
        to = scanner.nextInt()
        graph.addEdge(from, to)

    # Find the coloring of the graph
    colors = findColoring(graph)

    # Output the colors assigned to each vertex
    print("Vertex Colors:")
    for i in range(len(colors)):
        print("Vertex " + i + ": Color " + colors[i])

    # Close the scanner to free resources
    scanner.close()

# 