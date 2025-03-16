import sys
from collections import defaultdict

# Constant representing a blank color
BLANK_COLOR = -1

class Graph:
    def __init__(self, vertices):
        # Initialize the graph with adjacency lists
        self.adjacency_lists = defaultdict(set)

    def add_edge(self, node_a, node_b):
        # Add an edge between two nodes in the graph
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex):
        # Get the adjacency list of a specific vertex
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        # Get the number of vertices in the graph
        return len(self.adjacency_lists)

def main():
    # Read the number of vertices and edges from input
    vertices, edges = map(int, sys.stdin.readline().split())
    
    # Initialize the graph with the specified number of vertices
    graph = Graph(vertices)
    
    # Read each edge and add it to the graph
    for _ in range(edges):
        from_node, to_node = map(int, sys.stdin.readline().split())
        graph.add_edge(from_node, to_node)
    
    # Find the coloring of the graph
    colors = find_coloring(graph)
    
    # Output the colors assigned to each vertex
    print("Vertex Colors:")
    for i in range(len(colors)):
        print(f"Vertex {i}: Color {colors[i]}")

def find_coloring(graph):
    # Initialize colors for all vertices to blank
    colors = initialize_colors(graph.get_num_vertices())
    
    # Get the vertices sorted by their degree in descending order
    sorted_vertices = get_sorted_nodes(graph)
    
    # Assign colors to each vertex
    for vertex in sorted_vertices:
        # If the vertex is uncolored, proceed to color it
        if is_blank(colors[vertex]):
            # Determine which colors are already used by adjacent vertices
            used_colors = compute_used_colors(graph, vertex, colors)
            
            # Find the first unused color
            new_color = first_unused_color(used_colors)
            
            # Assign the new color to the vertex
            colors[vertex] = new_color
            
    return colors  # Return the array of colors assigned to vertices

def is_blank(color):
    # Check if a color is blank (unassigned)
    return color == BLANK_COLOR

def initialize_colors(number_of_vertices):
    # Initialize the colors array with blank colors
    return [BLANK_COLOR] * number_of_vertices

def get_sorted_nodes(graph):
    # Get the vertices sorted by their degree in descending order
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

def compute_used_colors(graph, vertex, colors):
    # Compute which colors are used by adjacent vertices
    used_colors = [False] * graph.get_num_vertices()
    
    # Check the colors of all adjacent vertices
    for neighbor in graph.get_adjacency_list(vertex):
        color = colors[neighbor]
        if not is_blank(color):
            used_colors[color] = True
            
    return used_colors  # Return the array indicating used colors

def first_unused_color(used_colors):
    # Find the first unused color
    for color, used in enumerate(used_colors):
        if not used:
            return color
    return -1  # Return -1 if no unused color is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
