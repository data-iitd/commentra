class Main:
    class Edge:
        def __init__(self, a, b, c):
            self.u = a
            self.v = b
            self.w = c

    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []
        self.index = 0

    def add_edge(self, x, y, z):
        self.edges.append(self.Edge(x, y, z))
        self.index += 1

    def print_path(self, parent, vertex):
        if parent[vertex] == -1:
            return
        self.print_path(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [float('inf')] * self.vertex
        parent = [-1] * self.vertex
        dist[source] = 0

        for i in range(self.vertex - 1):
            for j in range(self.edge):
                e = self.edges[j]
                if dist[e.u] != float('inf') and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w
                    parent[e.v] = e.u

        for j in range(self.edge):
            e = self.edges[j]
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
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    v, e = map(int, data[0].split())
    bf = Main(v, e)
    
    for i in range(1, e + 1):
        u, ve, w = map(int, data[i].split())
        bf.add_edge(u, ve, w)
    
    source = int(data[e + 1])
    bf.execute(source)

# <END-OF-CODE>
