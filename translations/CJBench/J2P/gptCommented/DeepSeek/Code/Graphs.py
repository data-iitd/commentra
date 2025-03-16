class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacent_vertices = []

    def add_adjacent_vertex(self, to):
        if to in self.adjacent_vertices:
            return False
        self.adjacent_vertices.append(to)
        return True

    def remove_adjacent_vertex(self, to):
        if to in self.adjacent_vertices:
            self.adjacent_vertices.remove(to)
            return True
        return False


class AdjacencyListGraph:
    def __init__(self):
        self.vertices = []

    def remove_edge(self, from_data, to_data):
        from_v = next((v for v in self.vertices if v.data == from_data), None)
        if from_v is None:
            return False
        return from_v.remove_adjacent_vertex(to_data)

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

    def __str__(self):
        result = ""
        for v in self.vertices:
            result += f"Vertex: {v.data}\n"
            result += f"Adjacent vertices: {' '.join(str(adj.data) for adj in v.adjacent_vertices)}\n"
        return result


# Main class to execute the program
class Main:
    @staticmethod
    def main():
        scanner = Scanner(System.stdin)
        graph = AdjacencyListGraph()
        edge_count = int(scanner.readline())
        for _ in range(edge_count):
            from_data, to_data = map(int, scanner.readline().split())
            graph.add_edge(from_data, to_data)
        print("Graph Representation:")
        print(graph)
        scanner.close()


# Instantiate and run the main class
Main.main()
