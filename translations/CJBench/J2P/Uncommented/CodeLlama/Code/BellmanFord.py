
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
        self.edges = [None] * e
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
        dist = [sys.maxsize] * self.vertex
        parent = [-1] * self.vertex
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
            self.printPath(parent, i)
            print()

if __name__ == "__main__":
    v = int(input())
    e = int(input())
    bf = Main(v, e)
    for i in range(e):
        u = int(input())
        ve = int(input())
        w = int(input())
        bf.addEdge(u, ve, w)
    source = int(input())
    bf.execute(source)

