

class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacentVertices = []
    def addAdjacentVertex(self, to):
        for v in self.adjacentVertices:
            if v.data == to.data:
                return False
        return self.adjacentVertices.append(to)
    def removeAdjacentVertex(self, to):
        for i in range(len(self.adjacentVertices)):
            if self.adjacentVertices[i].data == to.data:
                self.adjacentVertices.remove(i)
                return True
        return False

class AdjacencyListGraph:
    def __init__(self):
        self.vertices = []
    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if from == v.data:
                fromV = v
                break
        if fromV == None:
            return False
        return fromV.removeAdjacentVertex(to)
    def addEdge(self, from, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if from == v.data:
                fromV = v
            elif to == v.data:
                toV = v
            if fromV!= None and toV!= None:
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

if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    edgeCount = int(scanner.readline())
    graph = AdjacencyListGraph()
    for i in range(edgeCount):
        fromTo = scanner.readline().split()
        from_ = int(fromTo[0])
        to = int(fromTo[1])
        graph.addEdge(from_, to)
    print("Graph Representation:")
    print(graph)
    scanner.close()

