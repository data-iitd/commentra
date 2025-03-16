class Graph:
    def __init__(self, vertices):
        self.adjacency_lists = [set() for _ in range(vertices)]

    def add_edge(self, node_a, node_b):
        self.adjacency_lists[node_a].add(node_b)
        self.adjacency_lists[node_b].add(node_a)

    def get_adjacency_list(self, vertex):
        return self.adjacency_lists[vertex]

    def get_num_vertices(self):
        return len(self.adjacency_lists)


def main():
    vertices = int(input())
    edges = int(input())
    graph = Graph(vertices)
    
    for _ in range(edges):
        from_vertex, to_vertex = map(int, input().split())
        graph.add_edge(from_vertex, to_vertex)

    colors = find_coloring(graph)
    print("Vertex Colors:")
    for i in range(len(colors)):
        print(f"Vertex {i}: Color {colors[i]}")


def find_coloring(graph):
    colors = initialize_colors(graph.get_num_vertices())
    sorted_vertices = get_sorted_nodes(graph)
    
    for vertex in sorted_vertices:
        if is_blank(colors[vertex]):
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
            
    return colors


def is_blank(color):
    return color == -1


def initialize_colors(number_of_vertices):
    return [-1] * number_of_vertices


def get_sorted_nodes(graph):
    return sorted(range(graph.get_num_vertices()), key=lambda v: -len(graph.get_adjacency_list(v)))


def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * graph.get_num_vertices()
    for neighbor in graph.get_adjacency_list(vertex):
        color = colors[neighbor]
        if not is_blank(color):
            used_colors[color] = True
    return used_colors


def first_unused_color(used_colors):
    for color, used in enumerate(used_colors):
        if not used:
            return color
    return -1


if __name__ == "__main__":
    main()

# <END-OF-CODE>
