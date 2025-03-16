
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

    def addEdge(self, from, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if from == v.data:
                fromV = v
            elif to == v.data:
                toV = v
            if fromV and toV:
                break
        if not fromV:
            fromV = Vertex(from)
            self.vertices.append(fromV)
        if not toV:
            toV = Vertex(to)
            self.vertices.append(toV)
        return fromV.addAdjacentVertex(toV)

    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if from == v.data:
                fromV = v
                break
        if not fromV:
            return False
        return fromV.removeAdjacentVertex(to)

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

