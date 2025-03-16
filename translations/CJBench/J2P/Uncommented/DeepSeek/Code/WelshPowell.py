import array
from collections import defaultdict
from typing import List, Set

class Graph:
    def __init__(self, vertices: int):
        self.adjacency_lists = defaultdict(set)
        self.vertices = vertices

    def add_edge(self, node_a: int, node_b: int):
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex: int) -> Set:
        return self.adjacency_lists[vertex]

    def get_num_vertices(self) -> int:
        return self.vertices

def find_coloring(graph: Graph) -> List[int]:
    colors = initialize_colors(graph.get_num_vertices())
    sorted_nodes = get_sorted_nodes(graph)
    for vertex in sorted_nodes:
        if is_blank(colors[vertex]):
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
    return colors

def is_blank(color: int) -> bool:
    return color == BLANK_COLOR

def initialize_colors(number_of_vertices: int) -> List[int]:
    return [BLANK_COLOR] * number_of_vertices

def get_sorted_nodes(graph: Graph) -> List[int]:
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

def compute_used_colors(graph: Graph, vertex: int, colors: List[int]) -> List[bool]:
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

def first_unused_color(used_colors: List[bool]) -> int:
    for color in range(len(used_colors)):
        if not used_colors[color]:
            return color
    return -1

BLANK_COLOR = -1

# Main function to run the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    vertices = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1
    
    graph = Graph(vertices)
    for _ in range(edges):
        from_node = int(data[index])
        to_node = int(data[index + 1])
        graph.add_edge(from_node, to_node)
        index += 2
    
    colors = find_coloring(graph)
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")
