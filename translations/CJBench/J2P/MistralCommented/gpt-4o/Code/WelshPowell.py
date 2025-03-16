import sys
from collections import defaultdict

# Class constants
BLANK_COLOR = -1

class Graph:
    def __init__(self, vertices):
        self.adjacency_lists = defaultdict(set)
        self.num_vertices = vertices

    def add_edge(self, node_a, node_b):
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        return self.num_vertices

def main():
    # Read input: number of vertices and edges
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())

    # Initialize graph
    graph = Graph(vertices)

    # Read input: edges and add them to the graph
    for _ in range(edges):
        from_vertex, to_vertex = map(int, sys.stdin.readline().strip().split())
        graph.add_edge(from_vertex, to_vertex)

    # Find vertex colors
    colors = find_coloring(graph)

    # Print vertex colors
    print("Vertex Colors:")
    for i in range(len(colors)):
        print(f"Vertex {i}: Color {colors[i]}")

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
    return [BLANK_COLOR] * number_of_vertices

# Helper method: get sorted nodes (vertices) based on the number of their neighbors
def get_sorted_nodes(graph):
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

# Helper method: compute used colors by current vertex neighbors
def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        color = colors[neighbor]
        if not is_blank(color):
            used_colors[color] = True
    return used_colors

# Helper method: find the first unused color among used_colors
def first_unused_color(used_colors):
    for color, used in enumerate(used_colors):
        if not used:
            return color
    return -1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
