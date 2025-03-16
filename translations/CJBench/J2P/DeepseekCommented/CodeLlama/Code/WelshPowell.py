
import sys

def main():
    # Read the number of vertices and edges
    vertices, edges = map(int, sys.stdin.readline().split())
    # Create a new graph with the given vertices
    graph = Graph(vertices)
    # Read each edge and add it to the graph
    for _ in range(edges):
        nodeA, nodeB = map(int, sys.stdin.readline().split())
        graph.addEdge(nodeA, nodeB)
    # Find and print the coloring of the graph
    colors = findColoring(graph)
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print("Vertex {}: Color {}".format(i, color))

# Graph class to represent the graph using adjacency lists
class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjacencyLists = [set() for _ in range(vertices)]

    def addEdge(self, nodeA, nodeB):
        self.adjacencyLists[nodeA].add(nodeB)
        self.adjacencyLists[nodeB].add(nodeA)

    def getAdjacencyList(self, vertex):
        return self.adjacencyLists[vertex]

    def getNumVertices(self):
        return self.vertices

# Method to find the coloring of the graph using a greedy approach
def findColoring(graph):
    # Initialize colors array
    colors = [None] * graph.getNumVertices()
    # Get sorted nodes based on adjacency list size
    sortedVertices = sorted(range(graph.getNumVertices()), key=lambda v: -len(graph.getAdjacencyList(v)))
    for vertex in sortedVertices:
        # Assign colors to each vertex
        if colors[vertex] is None:
            # Compute used colors by neighbors
            usedColors = [colors[neighbor] for neighbor in graph.getAdjacencyList(vertex) if colors[neighbor] is not None]
            # Find the first unused color
            newColor = firstUnusedColor(usedColors)
            # Assign the new color to the vertex
            colors[vertex] = newColor
    return colors

# Helper method to find the first available color for a vertex
def firstUnusedColor(usedColors):
    for color in range(len(usedColors)):
        if color not in usedColors:
            return color
    return -1

if __name__ == "__main__":
    main()

