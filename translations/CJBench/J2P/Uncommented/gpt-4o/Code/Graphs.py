class AdjacencyListGraph:
    class Vertex:
        def __init__(self, data):
            self.data = data
            self.adjacent_vertices = []

        def add_adjacent_vertex(self, to):
            for v in self.adjacent_vertices:
                if v.data == to.data:
                    return False
            self.adjacent_vertices.append(to)
            return True

        def remove_adjacent_vertex(self, to):
            for i in range(len(self.adjacent_vertices)):
                if self.adjacent_vertices[i].data == to:
                    del self.adjacent_vertices[i]
                    return True
            return False

    def __init__(self):
        self.vertices = []

    def remove_edge(self, from_data, to_data):
        from_vertex = None
        for v in self.vertices:
            if v.data == from_data:
                from_vertex = v
                break
        if from_vertex is None:
            return False
        return from_vertex.remove_adjacent_vertex(to_data)

    def add_edge(self, from_data, to_data):
        from_vertex = None
        to_vertex = None
        for v in self.vertices:
            if v.data == from_data:
                from_vertex = v
            elif v.data == to_data:
                to_vertex = v
            if from_vertex is not None and to_vertex is not None:
                break
        if from_vertex is None:
            from_vertex = self.Vertex(from_data)
            self.vertices.append(from_vertex)
        if to_vertex is None:
            to_vertex = self.Vertex(to_data)
            self.vertices.append(to_vertex)
        return from_vertex.add_adjacent_vertex(to_vertex)

    def __str__(self):
        result = []
        for v in self.vertices:
            result.append(f"Vertex: {v.data}\nAdjacent vertices: " + " ".join(str(adj.data) for adj in v.adjacent_vertices) + "\n")
        return "".join(result)


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    graph = AdjacencyListGraph()
    edge_count = int(data[0])
    for i in range(1, edge_count + 1):
        from_data, to_data = map(int, data[i].split())
        graph.add_edge(from_data, to_data)

    print("Graph Representation:")
    print(graph)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
