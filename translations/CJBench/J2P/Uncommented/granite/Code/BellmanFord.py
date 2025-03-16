

class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

class Main:
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = [Edge(0, 0, 0) for i in range(e)]
        self.index = 0

    def addEdge(self, x, y, z):
        self.edges[self.index] = Edge(x, y, z)
        self.index += 1

    def getEdgeArray(self):
        return self.edges

    def printPath(self, parent, vertex):
        if parent[vertex] == -1:
            return
        self.printPath(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [float("inf") for i in range(self.vertex)]
        parent = [-1 for i in range(self.vertex)]
        dist[source] = 0
        for i in range(self.vertex - 1):
            for j in range(self.edge):
                e = self.edges[j]
                if dist[e.u]!= float("inf") and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w
                    parent[e.v] = e.u
        for j in range(self.edge):
            e = self.edges[j]
            if dist[e.u]!= float("inf") and dist[e.v] > dist[e.u] + e.w:
                print("Negative cycle detected")
                return
        print("Vertex distances from source:")
        for i in range(self.vertex):
            print("Vertex: {}, Distance: {}".format(i, dist[i]))
        print("Paths:")
        for i in range(self.vertex):
            print("Path to {}: {} ".format(i, source), end="")
            self.printPath(parent, i)
            print()

if __name__ == "__main__":
    import sys
    sc = iter(sys.stdin.read().splitlines())
    v = int(next(sc))
    e = int(next(sc))
    bf = Main(v, e)
    for i in range(e):
        u, ve, w = map(int, next(sc).split())
        bf.addEdge(u, ve, w)
    source = int(next(sc))
    bf.execute(source)
