class Main:
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []

    class Edge:
        def __init__(self, u, v, w):
            self.u = u
            self.v = v
            self.w = w

    def add_edge(self, x, y, z):
        self.edges.append(self.Edge(x, y, z))

    def get_edge_array(self):
        return self.edges

    def print_path(self, parent, vertex):
        if parent[vertex] == -1:
            return
        self.print_path(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [float('inf')] * self.vertex
        parent = [-1] * self.vertex
        dist[source] = 0

        for _ in range(self.vertex - 1):
            for j in range(self.edge):
                e = self.edges[j]
                u = e.u
                v = e.v
                weight = e.w
                if dist[u] != float('inf') and dist[v] > dist[u] + weight:
                    dist[v] = dist[u] + weight
                    parent[v] = u

        for j in range(self.edge):
            e = self.edges[j]
            u = e.u
            v = e.v
            weight = e.w
            if dist[u] != float('inf') and dist[v] > dist[u] + weight:
                print("Negative cycle detected")
                return

        print("Vertex distances from source:")
        for i in range(self.vertex):
            print(f"Vertex: {i}, Distance: {dist[i]}")
        print("Paths:")
        for i in range(self.vertex):
            print(f"Path to {i}: {source}", end=" ")
            self.print_path(parent, i)
            print()


# Main method to read input and execute the algorithm
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    v = int(data[0])
    e = int(data[1])
    bf = Main(v, e)
    index = 2
    for i in range(e):
        u = int(data[index])
        ve = int(data[index + 1])
        w = int(data[index + 2])
        bf.add_edge(u, ve, w)
        index += 3
    source = int(data[-1])
    bf.execute(source)
