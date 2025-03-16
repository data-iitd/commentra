from collections import defaultdict, deque

class AdjacencyList:
    def __init__(self):
        self.adj = defaultdict(list)

    def add_edge(self, from_v, to_v):
        self.adj[from_v].append(to_v)

    def get_adjacents(self, v):
        return self.adj[v]

    def get_vertices(self):
        return list(self.adj.keys())

class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
        self.in_degree = defaultdict(int)

    def calculate_in_degree(self):
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] += 1

    def top_sort_order(self):
        self.calculate_in_degree()
        q = deque()
        answer = []

        for vertex, degree in self.in_degree.items():
            if degree == 0:
                q.append(vertex)

        while q:
            current = q.popleft()
            answer.append(current)
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)

        if len(answer) != len(self.graph.get_vertices()):
            raise ValueError("Graph contains a cycle, topological sort not possible")

        return answer

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertices = int(data[index])
    edges = int(data[index + 1])
    index += 2

    graph = AdjacencyList()
    for i in range(edges):
        from_v = data[index]
        to_v = data[index + 1]
        graph.add_edge(from_v, to_v)
        index += 2

    top_sort = TopologicalSort(graph)

    try:
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        print(" ".join(sorted_order))
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
