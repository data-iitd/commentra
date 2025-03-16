
import sys

# Constant representing a blank color
BLANK_COLOR = -1

# Inner class representing a Graph using adjacency lists
class Graph:
    # Constructor to initialize the graph with a given number of vertices
    def __init__(self, vertices):
        self.adjacency_lists = [set() for _ in range(vertices)]

    # Method to add an edge between two nodes in the graph
    def add_edge(self, node_a, node_b):
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    # Method to get the adjacency list of a specific vertex
    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    # Method to get the number of vertices in the graph
    def get_num_vertices(self):
        return len(self.adjacency_lists)

# Method to find a valid coloring for the graph
def find_coloring(graph):
    # Initialize colors for all vertices to blank
    colors = [BLANK_COLOR] * graph.get_num_vertices()

    # Get the vertices sorted by their degree in descending order
    sorted_vertices = sorted(range(graph.get_num_vertices()),
                             key=lambda v: -len(graph.get_adjacency_list(v)))

    # Assign colors to each vertex
    for vertex in sorted_vertices:
        # If the vertex is uncolored, proceed to color it
        if colors[vertex] == BLANK_COLOR:
            # Determine which colors are already used by adjacent vertices
            used_colors = compute_used_colors(graph, vertex, colors)

            # Find the first unused color
            new_color = first_unused_color(used_colors)

            # Assign the new color to the vertex
            colors[vertex] = new_color

    return colors  # Return the array of colors assigned to vertices

# Method to check if a color is blank (unassigned)
def is_blank(color):
    return color == BLANK_COLOR

# Method to initialize the colors array with blank colors
def initialize_colors(number_of_vertices):
    colors = [BLANK_COLOR] * number_of_vertices
    return colors

# Method to get the vertices sorted by their degree in descending order
def get_sorted_nodes(graph):
    return sorted(range(graph.get_num_vertices()),
                  key=lambda v: -len(graph.get_adjacency_list(v)))

# Method to compute which colors are used by adjacent vertices
def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()

    # Check the colors of all adjacent vertices
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True

    return used_colors  # Return the array indicating used colors

# Method to find the first unused color
def first_unused_color(used_colors):
    for color in range(len(used_colors)):
        if not used_colors[color]:
            return color
    return -1  # Return -1 if no unused color is found

# Main method to read input, find a valid coloring, and output the colors
def main():
    # Read the number of vertices and edges from input
    vertices, edges = map(int, input().split())

    # Initialize the graph with the specified number of vertices
    graph = Graph(vertices)

    # Read each edge and add it to the graph
    for _ in range(edges):
        from_vertex, to_vertex = map(int, input().split())
        graph.add_edge(from_vertex, to_vertex)

    # Find the coloring of the graph
    colors = find_coloring(graph)

    # Output the colors assigned to each vertex
    print("Vertex Colors:")
    for vertex in range(vertices):
        print("Vertex {}: Color {}".format(vertex, colors[vertex]))

if __name__ == "__main__":
    main()

