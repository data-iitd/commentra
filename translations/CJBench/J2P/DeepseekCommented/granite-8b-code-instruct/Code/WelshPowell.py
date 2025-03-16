
import sys
from collections import defaultdict

# Constants
BLANK_COLOR = -1

# Graph class to represent the graph using adjacency lists
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

# Main method to run the program
def main():
    vertices, edges = map(int, input().split())
    graph = Graph(vertices)
    for _ in range(edges):
        node_a, node_b = map(int, input().split())
        graph.add_edge(node_a, node_b)
    colors = find_coloring(graph)
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")

# Method to find the coloring of the graph using a greedy approach
def find_coloring(graph):
    colors = [BLANK_COLOR] * graph.get_num_vertices()
    sorted_vertices = sorted(graph.adjacency_lists, key=lambda v: -len(graph.adjacency_lists[v]))
    for vertex in sorted_vertices:
        if colors[vertex] == BLANK_COLOR:
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
    return colors

# Helper method to check if a color is blank (unassigned)
def is_blank(color):
    return color == BLANK_COLOR

# Helper method to compute which colors are used by the neighbors of a vertex
def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

# Helper method to find the first available color for a vertex
def first_unused_color(used_colors):
    return next((i for i, used in enumerate(used_colors) if not used), -1)

if __name__ == "__main__":
    main()

