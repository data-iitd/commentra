
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

    def add_edge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))


class Component:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank


class BoruvkaState:
    def __init__(self, graph):
        self.result = []
        self.components = self.initialize_components(graph)
        self.graph = graph

    def merge(self, cheapest):
        for i in range(self.graph.vertex):
            if cheapest[i] is not None:
                set1 = self.find(self.components, cheapest[i].src)
                set2 = self.find(self.components, cheapest[i].dest)

                if set1 != set2:
                    self.result.append(cheapest[i])
                    self.union(self.components, set1, set2)

    def has_more_edges_to_add(self):
        return len(self.result) < self.graph.vertex - 1

    def compute_cheapest_edges(self):
        cheapest = [None] * self.graph.vertex
        for edge in self.graph.edges:
            set1 = self.find(self.components, edge.src)
            set2 = self.find(self.components, edge.dest)

            if set1 != set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge
        return cheapest

    @staticmethod
    def initialize_components(graph):
        components = [Component(i, 0) for i in range(graph.vertex)]
        return components

    @staticmethod
    def find(components, i):
        if components[i].parent != i:
            components[i].parent = BoruvkaState.find(components, components[i].parent)
        return components[i].parent

    @staticmethod
    def union(components, x, y):
        xroot = BoruvkaState.find(components, x)
        yroot = BoruvkaState.find(components, y)

        if components[xroot].rank < components[yroot].rank:
            components[xroot].parent = yroot
        elif components[xroot].rank > components[yroot].rank:
            components[yroot].parent = xroot
        else:
            components[yroot].parent = xroot
            components[xroot].rank += 1


def boruvka_mst(graph):
    boruvka_state = BoruvkaState(graph)

    while boruvka_state.has_more_edges_to_add():
        cheapest = boruvka_state.compute_cheapest_edges()
        boruvka_state.merge(cheapest)

    return boruvka_state.result


def main():
    vertices = int(sys.stdin.readline())
    edges = int(sys.stdin.readline())

    graph = Graph(vertices)

    for i in range(edges):
        src, dest, weight = map(int, sys.stdin.readline().split())
        graph.add_edge(src, dest, weight)

    mst = boruvka_mst(graph)
    total_weight = 0
    print("Edges in MST:")
    for edge in mst:
        print(edge.src, "-", edge.dest, ":", edge.weight)
        total_weight += edge.weight
    print("Total Weight:", total_weight)


if __name__ == "__main__":
    main()

