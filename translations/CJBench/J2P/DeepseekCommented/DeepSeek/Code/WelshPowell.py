import sys
from collections import defaultdict

BLANK_COLOR = -1

class Graph:
    def __init__(self, vertices):
        self.adjacency_lists = defaultdict(list)
        self.vertices = vertices

    def add_edge(self, nodeA, nodeB):
        self.adjacency_lists[nodeA].append(nodeB)
        self.adjacency_lists[nodeB].append(nodeA)

    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        return self.vertices

def find_coloring(graph):
    colors = initialize_colors(graph.get_num_vertices())
    sorted_nodes = get_sorted_nodes(graph)
    for vertex in sorted_nodes:
        if is_blank(colors[vertex]):
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
    return colors

def is_blank(color):
    return color == BLANK_COLOR

def initialize_colors(number_of_vertices):
    return [BLANK_COLOR] * number_of_vertices

def get_sorted_nodes(graph):
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

def first_unused_color(used_colors):
    for color in range(len(used_colors)):
        if not used_colors[color]:
            return color
    return -1

if __name__ == "__main__":
    input_data = sys.stdin.readline().split()
    vertices = int(input_data[0])
    edges = int(input_data[1])
    graph = Graph(vertices)
    for _ in range(edges):
        from_node, to_node = map(int, sys.stdin.readline().split())
        graph.add_edge(from_node, to_node)
    colors = find_coloring(graph)
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")
