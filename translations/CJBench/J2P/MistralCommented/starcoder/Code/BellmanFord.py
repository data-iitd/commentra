
import sys

class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

class Main:
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []

    def addEdge(self, x, y, z):
        self.edges.append(Edge(x, y, z))

    def getEdgeArray(self):
        return self.edges

    def printPath(self, parent, vertex):
        if parent[vertex] == -1:
            return
        self.printPath(parent, parent[vertex])
        print(vertex, end=" ")

    def execute(self, source):
        dist = [sys.maxsize] * self.vertex
        parent = [-1] * self.vertex

        for i in range(self.vertex):
            dist[i] = sys.maxsize
            parent[i] = -1

        dist[source] = 0

        for i in range(self.vertex - 1):
            for e in self.edges:
                u = e.u
                v = e.v
                weight = e.w

                if dist[u]!= sys.maxsize and dist[v] > dist[u] + weight:
                    dist[v] = dist[u] + weight
                    parent[v] = u

        for e in self.edges:
            u = e.u
            v = e.v
            weight = e.w

            if dist[u]!= sys.maxsize and dist[v] > dist[u] + weight:
                print("Negative cycle detected")
                return

        print("Vertex distances from source:")
        for i in range(self.vertex):
            print("Vertex: " + str(i) + ", Distance: " + str(dist[i]))
        print("Paths:")
        for i in range(self.vertex):
            print("Path to " + str(i) + ": " + str(source) + " ", end="")
            self.printPath(parent, i)
            print()

if __name__ == "__main__":
    v, e = map(int, input().split())
    bf = Main(v, e)
    for i in range(e):
        x, y, z = map(int, input().split())
        bf.addEdge(x, y, z)
    source = int(input())
    bf.execute(source)

