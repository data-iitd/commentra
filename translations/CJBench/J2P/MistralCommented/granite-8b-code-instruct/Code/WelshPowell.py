
import sys

# Class constants
BLANK_COLOR = -1

# Class inner static class: Graph
class Graph:
    # Class fields
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

def main():
    # Initialize scanner
    scanner = sys.stdin

    # Read input: number of vertices and edges
    vertices, edges = map(int, scanner.readline().split())

    # Initialize graph
    graph = Graph(vertices)

    # Read input: edges and add them to the graph
    for _ in range(edges):
        from_node, to_node = map(int, scanner.readline().split())
        graph.addEdge(from_node, to_node)

    # Find vertex colors
    colors = find_coloring(graph)

    # Print vertex colors
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")

    # Close scanner
    scanner.close()

# Method to find vertex colors using Depth First Search algorithm
def find_coloring(graph):
    # Initialize colors array with blank color for all vertices
    colors = [BLANK_COLOR] * graph.getNumVertices()

    # Sort vertices by the number of their neighbors in descending order
    sorted_vertices = sorted(range(graph.getNumVertices()), key=lambda v: -len(graph.getAdjacencyList(v)))

    # For each vertex in sorted order
    for vertex in sorted_vertices:
        # If the current vertex has not been colored yet
        if colors[vertex] == BLANK_COLOR:
            # Compute used colors by current vertex neighbors
            used_colors = compute_used_colors(graph, vertex, colors)

            # Find the first unused color
            new_color = first_unused_color(used_colors)

            # Color the current vertex with the found color
            colors[vertex] = new_color

    return colors

# Helper method: check if a color is blank
def is_blank(color):
    return color == BLANK_COLOR

# Helper method: initialize colors array with blank color for all vertices
def initialize_colors(num_of_vertices):
    return [BLANK_COLOR] * num_of_vertices

# Helper method: get sorted nodes (vertices) based on the number of their neighbors
def get_sorted_nodes(graph):
    return sorted(range(graph.getNumVertices()), key=lambda v: -len(graph.getAdjacencyList(v)))

# Helper method: compute used colors by current vertex neighbors
def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.getNumVertices()
    for neighbor in graph.getAdjacencyList(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

# Helper method: find the first unused color among usedColors
def first_unused_color(used_colors):
    return next((color for color, used in enumerate(used_colors) if not used), -1)

if __name__ == "__main__":
    main()

