from collections import defaultdict, deque

class AdjacencyList:
    def __init__(self):
        self.adj = defaultdict(list)

    def add_edge(self, from_vertex, to_vertex):
        self.adj[from_vertex].append(to_vertex)
        if to_vertex not in self.adj:
            self.adj[to_vertex]  # Ensure to_vertex is in the adjacency list

    def get_adjacents(self, vertex):
        return self.adj[vertex]

    def get_vertices(self):
        return self.adj.keys()

class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
        self.in_degree = {}

    def calculate_in_degree(self):
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
        for vertex in self.graph.get_vertices():
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] += 1

    def top_sort_order(self):
        self.calculate_in_degree()
        q = deque()
        for vertex, degree in self.in_degree.items():
            if degree == 0:
                q.append(vertex)
        answer = []
        processed_vertices = 0
        while q:
            current = q.popleft()
            answer.append(current)
            processed_vertices += 1
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)
        if processed_vertices != len(self.graph.get_vertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer

def main():
    vertices = int(input())
    edges = int(input())
    graph = AdjacencyList()
    for _ in range(edges):
        from_vertex, to_vertex = input().split()
        graph.add_edge(from_vertex, to_vertex)
    top_sort = TopologicalSort(graph)
    try:
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        print(" ".join(sorted_order))
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
