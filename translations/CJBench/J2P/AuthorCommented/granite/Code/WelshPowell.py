

import sys
from typing import List

def main():
    """
    The Welsh-Powell algorithm is a graph coloring algorithm that aims to color a graph
    using the minimum number of colors such that no two adjacent vertices share the same color.

    The algorithm works by:
    <ol>
    <li>Sorting the vertices in descending order based on their degrees (number of edges connected).</li>
    <li>Iterating through each vertex and assigning it the smallest available color that has not been used by its adjacent vertices.</li>
    <li>Coloring adjacent vertices with the same color is avoided.</li>
    </ol>

    For more information, see <a href="https://en.wikipedia.org/wiki/Graph_coloring">Graph Coloring</a>.
    """
    vertices, edges = map(int, input().split())
    graph = Graph(vertices)

    for _ in range(edges):
        from_node, to_node = map(int, input().split())
        graph.add_edge(from_node, to_node)

    colors = find_coloring(graph)

    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")

class Graph:
    """
    Represents a graph using an adjacency list.
    """
    def __init__(self, vertices: int):
        self.adjacency_lists = [set() for _ in range(vertices)]

    def add_edge(self, node_a: int, node_b: int):
        """
        Adds an edge between two vertices in the graph.
        """
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex: int) -> List[int]:
        """
        Returns the adjacency list of the specified vertex.
        """
        return list(self.adjacency_lists[vertex])

    def get_num_vertices(self) -> int:
        """
        Returns the number of vertices in the graph.
        """
        return len(self.adjacency_lists)

def find_coloring(graph: Graph) -> List[int]:
    """
    Finds the coloring of the given graph using the Welsh-Powell algorithm.
    """
    colors = [None] * graph.get_num_vertices()
    sorted_vertices = sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))
    for vertex in sorted_vertices:
        if colors[vertex] is None:
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
    return colors

def is_blank(color: int) -> bool:
    """
    Checks if a color is unassigned.
    """
    return color is None

def initialize_colors(num_vertices: int) -> List[int]:
    """
    Initializes the colors array with blank color.
    """
    return [None] * num_vertices

def get_sorted_nodes(graph: Graph) -> List[int]:
    """
    Sorts the vertices by their degree in descending order.
    """
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))

def compute_used_colors(graph: Graph, vertex: int, colors: List[int]) -> List[bool]:
    """
    Computes the colors already used by the adjacent vertices.
    """
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        if not is_blank(colors[neighbor]):
            used_colors[colors[neighbor]] = True
    return used_colors

def first_unused_color(used_colors: List[bool]) -> int:
    """
    Finds the first unused color.
    """
    return next((color for color, used in enumerate(used_colors) if not used), -1)

if __name__ == "__main__":
    main()

