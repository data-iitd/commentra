
import sys

class AdjacencyList:
    def __init__(self):
        self.adj = {}

    def add_edge(self, from_vertex, to_vertex):
        self.adj.setdefault(from_vertex, [])
        self.adj[from_vertex].append(to_vertex)
        self.adj.setdefault(to_vertex, [])

    def get_adjacents(self, vertex):
        return self.adj.get(vertex, [])

    def get_vertices(self):
        return set(self.adj.keys())

class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph

    def calculate_in_degree(self):
        self.in_degree = {}
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] = self.in_degree.get(adjacent, 0) + 1

    def top_sort_order(self):
        self.calculate_in_degree()
        q = []

        for vertex, degree in self.in_degree.items():
            if degree == 0:
                q.append(vertex)

        answer = []
        processed_vertices = 0

        while q:
            current = q.pop(0)
            answer.append(current)
            processed_vertices += 1

            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)

        if processed_vertices != len(self.graph.get_vertices()):
            raise ValueError("Graph contains a cycle, topological sort not possible")

        return answer

if __name__ == "__main__":
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())

    graph = AdjacencyList()
    for _ in range(edges):
        from_vertex, to_vertex = sys.stdin.readline().strip().split()
        graph.add_edge(from_vertex, to_vertex)

    top_sort = TopologicalSort(graph)
    try:
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        for vertex in sorted_order:
            print(vertex, end=" ")
        print()
    except ValueError as e:
        print(e)

