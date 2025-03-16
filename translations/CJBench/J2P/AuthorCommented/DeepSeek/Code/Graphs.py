class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacent_vertices = []

    def add_adjacent_vertex(self, to):
        if to in self.adjacent_vertices:
            return False  # the edge already exists
        self.adjacent_vertices.append(to)
        return True  # this will return True

    def remove_adjacent_vertex(self, to):
        for i, v in enumerate(self.adjacent_vertices):
            if v.data == to:
                self.adjacent_vertices.pop(i)
                return True
        return False


class AdjacencyListGraph:
    def __init__(self):
        self.vertices = []

    def add_edge(self, from_data, to_data):
        from_v = next((v for v in self.vertices if v.data == from_data), None)
        to_v = next((v for v in self.vertices if v.data == to_data), None)
        if from_v is None:
            from_v = Vertex(from_data)
            self.vertices.append(from_v)
        if to_v is None:
            to_v = Vertex(to_data)
            self.vertices.append(to_v)
        return from_v.add_adjacent_vertex(to_v)

    def remove_edge(self, from_data, to_data):
        from_v = next((v for v in self.vertices if v.data == from_data), None)
        if from_v is None:
            return False
        return from_v.remove_adjacent_vertex(to_data)

    def __str__(self):
        result = ""
        for v in self.vertices:
            result += f"Vertex: {v.data}\n"
            result += f"Adjacent vertices: "
            for v2 in v.adjacent_vertices:
                result += f"{v2.data} "
            result += "\n"
        return result


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    graph = AdjacencyListGraph()
    edge_count = int(data[0])

    for i in range(1, edge_count + 1):
        from_data = int(data[i])
        to_data = int(data[i + edge_count])
        graph.add_edge(from_data, to_data)

    print("Graph Representation:")
    print(graph)


if __name__ == "__main__":
    main()
