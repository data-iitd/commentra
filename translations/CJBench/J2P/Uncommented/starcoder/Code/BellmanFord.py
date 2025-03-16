
import sys
class Main:
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []
    class Edge:
        def __init__(self, a, b, c):
            self.u = a
            self.v = b
            self.w = c
    def addEdge(self, x, y, z):
        self.edges.append(self.Edge(x, y, z))
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
            for j in range(self.edge):
                e = self.edges[j]
                if dist[e.u]!= sys.maxsize and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w
                    parent[e.v] = e.u
        for j in range(self.edge):
            e = self.edges[j]
            if dist[e.u]!= sys.maxsize and dist[e.v] > dist[e.u] + e.w:
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
    def main(self):
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

if __name__ == "__main__":
    Main().main()

