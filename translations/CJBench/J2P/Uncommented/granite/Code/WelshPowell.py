

import sys
import itertools

def main():
    vertices, edges = map(int, input().split())
    graph = {i: set() for i in range(vertices)}
    for _ in range(edges):
        from_node, to_node = map(int, input().split())
        graph[from_node].add(to_node)
        graph[to_node].add(from_node)
    colors = find_coloring(graph)
    print("Vertex Colors:")
    for i, color in enumerate(colors):
        print(f"Vertex {i}: Color {color}")

def find_coloring(graph):
    colors = [None] * len(graph)
    sorted_vertices = sorted(graph, key=lambda v: -len(graph[v]))
    for vertex in sorted_vertices:
        if colors[vertex] is None:
            used_colors = compute_used_colors(graph, vertex, colors)
            new_color = first_unused_color(used_colors)
            colors[vertex] = new_color
    return colors

def compute_used_colors(graph, vertex, colors):
    used_colors = [False] * len(graph)
    for neighbor in graph[vertex]:
        if colors[neighbor] is not None:
            used_colors[colors[neighbor]] = True
    return used_colors

def first_unused_color(used_colors):
    return next((i for i, used in enumerate(used_colors) if not used), -1)

if __name__ == "__main__":
    main()

