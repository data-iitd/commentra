

import sys

class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

class Graph:
    def __init__(self, vertex):
        self.vertex = vertex
        self.edges = []

    def addEdge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))

class Component:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

def find(components, i):
    if components[i].parent!= i:
        components[i].parent = find(components, components[i].parent)
    return components[i].parent

def union(components, x, y):
    xroot = find(components, x)
    yroot = find(components, y)
    if components[xroot].rank < components[yroot].rank:
        components[xroot].parent = yroot
    elif components[xroot].rank > components[yroot].rank:
        components[yroot].parent = xroot
    else:
        components[yroot].parent = xroot
        components[xroot].rank += 1

def boruvkaMST(graph):
    result = []
    components = [Component(i, 0) for i in range(graph.vertex)]
    while len(result) < graph.vertex - 1:
        cheapest = [None] * graph.vertex
        for edge in graph.edges:
            set1 = find(components, edge.src)
            set2 = find(components, edge.dest)
            if set1!= set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge
        for i in range(graph.vertex):
            if cheapest[i] is not None:
                result.append(cheapest[i])
                set1 = find(components, cheapest[i].src)
                set2 = find(components, cheapest[i].dest)
                union(components, set1, set2)
    return result

if __name__ == "__main__":
    vertices, edges = map(int, input().split())
    graph = Graph(vertices)
    for _ in range(edges):
        src, dest, weight = map(int, input().split())
        graph.addEdge(src, dest, weight)
    mst = boruvkaMST(graph)
    total_weight = 0
    print("Edges in MST:")
    for edge in mst:
        print(f"{edge.src} - {edge.dest} : {edge.weight}")
        total_weight += edge.weight
    print(f"Total Weight: {total_weight}")

