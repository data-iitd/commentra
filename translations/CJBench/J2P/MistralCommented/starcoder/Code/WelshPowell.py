import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main:
    # Class constants
    BLANK_COLOR = -1

    def __init__(self):
        pass

    # Class inner static class: Graph
    class Graph:
        # Class fields
        adjacencyLists = None

        # Constructor
        def __init__(self, vertices):
            self.adjacencyLists = [set() for _ in range(vertices)]

        # Methods
        def addEdge(self, nodeA, nodeB):
            self.adjacencyLists[nodeA].add(nodeB)
            self.adjacencyLists[nodeB].add(nodeA)

        def getAdjacencyList(self, vertex):
            return self.adjacencyLists[vertex]

        def getNumVertices(self):
            return len(self.adjacencyLists)

    def main(self):
        # Initialize scanner
        scanner = Scanner(System.in)

        # Read input: number of vertices and edges
        vertices = scanner.nextInt()
        edges = scanner.nextInt()

        # Initialize graph
        graph = self.Graph(vertices)

        # Read input: edges and add them to the graph
        for i in range(edges):
            from_ = scanner.nextInt()
            to = scanner.nextInt()
            graph.addEdge(from_, to)

        # Find vertex colors
        colors = self.findColoring(graph)

        # Print vertex colors
        print("Vertex Colors:")
        for i in range(len(colors)):
            print("Vertex " + str(i) + ": Color " + str(colors[i]))

        # Close scanner
        scanner.close()

    # Method to find vertex colors using Depth First Search algorithm
    def findColoring(self, graph):
        # Initialize colors array with blank color for all vertices
        colors = self.initializeColors(graph.getNumVertices())

        # Sort vertices by the number of their neighbors in descending order
        sortedVertices = self.getSortedNodes(graph)

        # For each vertex in sorted order
        for vertex in sortedVertices:
            # If the current vertex has not been colored yet
            if self.isBlank(colors[vertex]):
                # Compute used colors by current vertex neighbors
                usedColors = self.computeUsedColors(graph, vertex, colors)

                # Find the first unused color
                newColor = self.firstUnusedColor(usedColors)

                # Color the current vertex with the found color
                colors[vertex] = newColor

        return colors

    # Helper method: check if a color is blank
    def isBlank(self, color):
        return color == self.BLANK_COLOR

    # Helper method: initialize colors array with blank color for all vertices
    def initializeColors(self, numberOfVertices):
        colors = [self.BLANK_COLOR for _ in range(numberOfVertices)]
        return colors

    # Helper method: get sorted nodes (vertices) based on the number of their neighbors
    def getSortedNodes(self, graph):
        return sorted(range(graph.getNumVertices()), key=lambda v: -len(graph.getAdjacencyList(v)))

    # Helper method: compute used colors by current vertex neighbors
    def computeUsedColors(self, graph, vertex, colors):
        usedColors = [False for _ in range(graph.getNumVertices())]
        for neighbor in graph.getAdjacencyList(vertex):
            color = colors[neighbor]
            if not self.isBlank(color):
                usedColors[color] = True
        return usedColors

    # Helper method: find the first unused color among usedColors
    def firstUnusedColor(self, usedColors):
        return next((color for color in range(len(usedColors)) if not usedColors[color]), -1)

# 