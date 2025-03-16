
class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacentVertices = []
    def addAdjacentVertex(self, to):
        for v in self.adjacentVertices:
            if v.data == to.data:
                return False
        self.adjacentVertices.append(to)
        return True
    def removeAdjacentVertex(self, to):
        for i in range(len(self.adjacentVertices)):
            if self.adjacentVertices[i].data == to:
                self.adjacentVertices.pop(i)
                return True
        return False
class AdjacencyListGraph:
    def __init__(self):
        self.vertices = []
    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if v.data == from:
                fromV = v
                break
        if fromV == None:
            return False
        return fromV.removeAdjacentVertex(to)
    def addEdge(self, from, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if v.data == from:
                fromV = v
            elif v.data == to:
                toV = v
            if fromV != None and toV != None:
                break
        if fromV == None:
            fromV = Vertex(from)
            self.vertices.append(fromV)
        if toV == None:
            toV = Vertex(to)
            self.vertices.append(toV)
        return fromV.addAdjacentVertex(toV)
    def __str__(self):
        sb = ""
        for v in self.vertices:
            sb += "Vertex: " + str(v.data) + "\n"
            sb += "Adjacent vertices: "
            for v2 in v.adjacentVertices:
                sb += str(v2.data) + " "
            sb += "\n"
        return sb
def main():
    graph = AdjacencyListGraph()
    edgeCount = int(input())
    for i in range(edgeCount):
        from, to = map(int, input().split())
        graph.addEdge(from, to)
    print("Graph Representation:")
    print(graph)
if __name__ == "__main__":
    main()
