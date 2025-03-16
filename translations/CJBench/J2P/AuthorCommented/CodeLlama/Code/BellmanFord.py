
import sys


class Main:
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = [None] * e
        self.index = 0

    class Edge:
        def __init__(self, a, b, c):
            self.u = a
            self.v = b
            self.w = c

    def add_edge(self, x, y, z):
        self.edges[self.index] = Main.Edge(x, y, z)
        self.index += 1

    def get_edge_array(self):
        return self.edges

    def print_path(self, parent, vertex):
        if parent[vertex] == -1:
            return
        self.print_path(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [sys.maxsize] * self.vertex
        parent = [-1] * self.vertex

        for i in range(self.vertex):
            dist[i] = sys.maxsize
            parent[i] = -1

        dist[source] = 0

        for i in range(self.vertex - 1):
            for j in range(self.edge):
                e = self.edges[j]
                if dist[e.u] != sys.maxsize and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w
                    parent[e.v] = e.u

        for j in range(self.edge):
            e = self.edges[j]
            if dist[e.u] != sys.maxsize and dist[e.v] > dist[e.u] + e.w:
                print("Negative cycle detected")
                return

        print("Vertex distances from source:")
        for i in range(self.vertex):
            print("Vertex: " + str(i) + ", Distance: " + str(dist[i]))

        print("Paths:")
        for i in range(self.vertex):
            print("Path to " + str(i) + ": " + str(source) + " ", end="")
            self.print_path(parent, i)
            print()


if __name__ == "__main__":
    sc = sys.stdin
    v = int(sc.readline().strip())
    e = int(sc.readline().strip())

    bf = Main(v, e)

    for i in range(e):
        u, ve, w = map(int, sc.readline().strip().split())
        bf.add_edge(u, ve, w)

    source = int(sc.readline().strip())
    bf.execute(source)


