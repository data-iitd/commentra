class AdjacencyList:
    def __init__(self):
        self.adj = {}

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex not in self.adj:
            self.adj[from_vertex] = []
        self.adj[from_vertex].append(to_vertex)
        if to_vertex not in self.adj:
            self.adj[to_vertex] = []

    def get_adjacents(self, vertex):
        return self.adj.get(vertex, [])

    def get_vertices(self):
        return list(self.adj.keys())


class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
        self.in_degree = {}

    def calculate_in_degree(self):
        self.in_degree = {}
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] = self.in_degree.get(adjacent, 0) + 1

    def top_sort_order(self):
        self.calculate_in_degree()
        queue = []
        for vertex, degree in self.in_degree.items():
            if degree == 0:
                queue.append(vertex)
        sorted_order = []
        processed_vertices = 0
        while queue:
            current = queue.pop(0)
            sorted_order.append(current)
            processed_vertices += 1
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                if self.in_degree[adjacent] == 0:
                    queue.append(adjacent)
        if processed_vertices != len(self.graph.get_vertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return sorted_order


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    vertices = int(data[0])
    edges = int(data[1])
    graph = AdjacencyList()
    index = 2
    for i in range(edges):
        from_vertex = data[index]
        to_vertex = data[index + 1]
        graph.add_edge(from_vertex, to_vertex)
        index += 2
    top_sort = TopologicalSort(graph)
    try:
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        print(" ".join(sorted_order))
    except Exception as e:
        print(str(e))


