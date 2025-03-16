
import sys
from collections import defaultdict

def main():
    # Read input
    num_vertices, num_edges = map(int, sys.stdin.readline().split())
    graph = defaultdict(set)
    for _ in range(num_edges):
        node_a, node_b = map(int, sys.stdin.readline().split())
        graph[node_a].add(node_b)
        graph[node_b].add(node_a)

    # Find coloring
    colors = [None] * num_vertices
    sorted_vertices = sorted(range(num_vertices), key=lambda v: -len(graph[v]))
    for vertex in sorted_vertices:
        if colors[vertex] is None:
            used_colors = [False] * num_vertices
            for neighbor in graph[vertex]:
                if colors[neighbor] is not None:
                    used_colors[colors[neighbor]] = True
            colors[vertex] = next(i for i in range(num_vertices) if not used_colors[i])

    # Print coloring
    print("Vertex Colors:")
    for vertex, color in enumerate(colors):
        print(f"Vertex {vertex}: Color {color}")

if __name__ == "__main__":
    main()

