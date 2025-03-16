
import sys

# Class constants
BLANK_COLOR = -1

# Class inner static class: Graph
class Graph:
    # Class fields
    def __init__(self, vertices):
        self.adjacency_lists = [set() for _ in range(vertices)]

    # Methods
    def add_edge(self, node_a, node_b):
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        return len(self.adjacency_lists)

# Method to find vertex colors using Depth First Search algorithm
def find_coloring(graph):
    # Initialize colors array with blank color for all vertices
    colors = initialize_colors(graph.get_num_vertices())

    # Sort vertices by the number of their neighbors in descending order
    sorted_vertices = get_sorted_nodes(graph)

    # For each vertex in sorted order
    for vertex in sorted_vertices:
        # If the current vertex has not been colored yet
        if is_blank(colors[vertex]):
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
def initialize_colors(number_of_vertices):
    colors = [BLANK_COLOR] * number_of_vertices
    return colors

# Helper method: get sorted nodes (vertices) based on the number of their neighbors
def get_sorted_nodes(graph):
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

# Helper method: compute used colors by current vertex neighbors
def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

# Helper method: find the first unused color among usedColors
def first_unused_color(used_colors):
    for color in range(len(used_colors)):
        if not used_colors[color]:
            return color
    return -1

# Main method
def main():
    # Initialize scanner
    scanner = sys.stdin

    # Read input: number of vertices and edges
    vertices = int(scanner.readline().strip())
    edges = int(scanner.readline().strip())

    # Initialize graph
    graph = Graph(vertices)

    # Read input: edges and add them to the graph
    for _ in range(edges):
        from_vertex, to_vertex = map(int, scanner.readline().strip().split())
        graph.add_edge(from_vertex, to_vertex)

    # Find vertex colors
    colors = find_coloring(graph)

    # Print vertex colors
    print("Vertex Colors:")
    for vertex in range(vertices):
        print(f"Vertex {vertex}: Color {colors[vertex]}")

if __name__ == "__main__":
    main()

