class AdjacencyListGraph:
    class Vertex:
        def __init__(self, data):
            self.data = data
            self.adjacent_vertices = []

        def add_adjacent_vertex(self, to):
            if to not in self.adjacent_vertices:
                self.adjacent_vertices.append(to)
                return True
            return False

        def remove_adjacent_vertex(self, to):
            if to in self.adjacent_vertices:
                self.adjacent_vertices.remove(to)
                return True
            return False

    def __init__(self):
        self.vertices = []

    def add_edge(self, from_v, to_v):
        from_vertex = next((v for v in self.vertices if v.data == from_v), None)
        to_vertex = next((v for v in self.vertices if v.data == to_v), None)
        if not from_vertex:
            from_vertex = self.Vertex(from_v)
            self.vertices.append(from_vertex)
        if not to_vertex:
            to_vertex = self.Vertex(to_v)
            self.vertices.append(to_vertex)
        return from_vertex.add_adjacent_vertex(to_vertex)

    def remove_edge(self, from_v, to_v):
        from_vertex = next((v for v in self.vertices if v.data == from_v), None)
        if not from_vertex:
            return False
        return from_vertex.remove_adjacent_vertex(to_v)

    def __str__(self):
        result = ""
        for vertex in self.vertices:
            result += f"Vertex: {vertex.data}\n"
            result += f"Adjacent vertices: " + " ".join(str(v.data) for v in vertex.adjacent_vertices) + "\n"
        return result


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    edge_count = int(data[index])
    index += 1
    graph = AdjacencyListGraph()
    for _ in range(edge_count):
        from_v = int(data[index])
        index += 1
        to_v = int(data[index])
        index += 1
        graph.add_edge(from_v, to_v)
    print("Graph Representation:")
    print(graph)


if __name__ == "__main__":
    main()
