
import sys


def main():
    # Input the number of vertices and edges
    vertices, edges = map(int, sys.stdin.readline().split())

    # Initialize a graph with the number of vertices
    graph = Graph(vertices)

    # Input edges
    for _ in range(edges):
        from_vertex, to_vertex = map(int, sys.stdin.readline().split())
        graph.add_edge(from_vertex, to_vertex)

    # Perform Welsh-Powell algorithm
    colors = find_coloring(graph)

    # Print the vertex colors
    print("Vertex Colors:")
    for vertex in range(vertices):
        print(f"Vertex {vertex}: Color {colors[vertex]}")


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjacency_lists = [set() for _ in range(vertices)]

    def add_edge(self, from_vertex, to_vertex):
        self.adjacency_lists[from_vertex].add(to_vertex)
        self.adjacency_lists[to_vertex].add(from_vertex)

    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        return self.vertices


def find_coloring(graph):
    # Initialize the colors array with blank color
    colors = [None] * graph.get_num_vertices()

    # Sort the vertices by their degree in descending order
    sorted_vertices = sorted(range(graph.get_num_vertices()),
                             key=lambda v: -len(graph.get_adjacency_list(v)))

    for vertex in sorted_vertices:
        if colors[vertex] is None:
            # Compute the colors already used by the adjacent vertices
            used_colors = [colors[neighbor] for neighbor in graph.get_adjacency_list(vertex)
                           if colors[neighbor] is not None]

            # Find the first unused color
            new_color = next((color for color in range(graph.get_num_vertices())
                              if color not in used_colors), None)

            colors[vertex] = new_color

    return colors


if __name__ == "__main__":
    main()

