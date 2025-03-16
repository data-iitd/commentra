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
                component1 = self.find(cheapest[i].src)
                component2 = self.find(cheapest[i].dest)

                if component1 != component2:
                    self.result.append(cheapest[i])
                    self.union(component1, component2)

    def has_more_edges_to_add(self):
        return len(self.result) < self.graph.vertex - 1

    def compute_cheapest_edges(self):
        cheapest = [None] * self.graph.vertex
        for edge in self.graph.edges:
            set1 = self.find(edge.src)
            set2 = self.find(edge.dest)

            if set1 != set2:
                if cheapest[set1] is None or edge.weight < cheapest[set1].weight:
                    cheapest[set1] = edge
                if cheapest[set2] is None or edge.weight < cheapest[set2].weight:
                    cheapest[set2] = edge
        return cheapest

    @staticmethod
    def initialize_components(graph):
        components = [Component(v, 0) for v in range(graph.vertex)]
        return components

    def find(self, i):
        if self.components[i].parent != i:
            self.components[i].parent = self.find(self.components[i].parent)
        return self.components[i].parent

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)

        if self.components[xroot].rank < self.components[yroot].rank:
            self.components[xroot].parent = yroot
        elif self.components[xroot].rank > self.components[yroot].rank:
            self.components[yroot].parent = xroot
        else:
            self.components[yroot].parent = xroot
            self.components[xroot].rank += 1


def boruvka_mst(graph):
    boruvka_state = BoruvkaState(graph)

    while boruvka_state.has_more_edges_to_add():
        cheapest = boruvka_state.compute_cheapest_edges()
        boruvka_state.merge(cheapest)

    return boruvka_state.result


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertices = int(data[index])
    edges = int(data[index + 1])
    index += 2

    graph = Graph(vertices)

    for i in range(edges):
        src = int(data[index])
        dest = int(data[index + 1])
        weight = int(data[index + 2])
        graph.add_edge(src, dest, weight)
        index += 3

    mst = boruvka_mst(graph)
    total_weight = 0
    print("Edges in MST:")
    for edge in mst:
        print(f"{edge.src} - {edge.dest} : {edge.weight}")
        total_weight += edge.weight
    print("Total Weight:", total_weight)


if __name__ == "__main__":
    main()
