class Main:
    """
    Implementation of Bellman-Ford to detect negative cycles. Graph accepts
    inputs in the form of edges which have start vertex, end vertex, and weights.
    Vertices should be labeled with a number between 0 and total number of vertices-1,
    both inclusive.
    """

    class Edge:
        def __init__(self, u, v, w):
            """
            :param u: Source Vertex
            :param v: End vertex
            :param w: Weight
            """
            self.u = u
            self.v = v
            self.w = w

    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []

    def add_edge(self, x, y, z):
        """Adds unidirectional edge"""
        self.edges.append(self.Edge(x, y, z))

    def print_path(self, parent, vertex):
        if parent[vertex] == -1:  # Found the path back to parent
            return
        self.print_path(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [float('inf')] * self.vertex
        parent = [-1] * self.vertex

        dist[source] = 0

        for _ in range(self.vertex - 1):
            for e in self.edges:
                if dist[e.u] != float('inf') and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w
                    parent[e.v] = e.u

        for e in self.edges:
            if dist[e.u] != float('inf') and dist[e.v] > dist[e.u] + e.w:
                print("Negative cycle detected")
                return

        print("Vertex distances from source:")
        for i in range(self.vertex):
            print(f"Vertex: {i}, Distance: {dist[i]}")

        print("Paths:")
        for i in range(self.vertex):
            print(f"Path to {i}: {source} ", end="")
            self.print_path(parent, i)
            print()

if __name__ == "__main__":
    v = int(input())
    e = int(input())

    bf = Main(v, e)

    for _ in range(e):
        u, ve, w = map(int, input().split())
        bf.add_edge(u, ve, w)

    source = int(input())
    bf.execute(source)

# <END-OF-CODE>
