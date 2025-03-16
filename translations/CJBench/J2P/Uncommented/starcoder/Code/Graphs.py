
class AdjacencyListGraph(object):
    def __init__(self):
        self.vertices = []
    class Vertex(object):
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
                if self.adjacentVertices[i].data == to:
                    self.adjacentVertices.remove(i)
                    return True
            return False
    def removeEdge(self, from_, to):
        for v in self.vertices:
            if v.data == from_:
                return v.removeAdjacentVertex(to)
        return False
    def addEdge(self, from_, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if v.data == from_:
                fromV = v
            if v.data == to:
                toV = v
            if fromV!= None and toV!= None:
                break
        if fromV == None:
            fromV = self.Vertex(from_)
            self.vertices.append(fromV)
        if toV == None:
            toV = self.Vertex(to)
            self.vertices.append(toV)
        return fromV.addAdjacentVertex(toV)
    def __str__(self):
        sb = []
        for v in self.vertices:
            sb.append("Vertex: ")
            sb.append(str(v.data))
            sb.append("\n")
            sb.append("Adjacent vertices: ")
            for v2 in v.adjacentVertices:
                sb.append(str(v2.data))
                sb.append(" ")
            sb.append("\n")
        return "".join(sb)

if __name__ == "__main__":
    graph = AdjacencyListGraph()
    edgeCount = int(raw_input())
    for i in range(edgeCount):
        from_ = int(raw_input())
        to = int(raw_input())
        graph.addEdge(from_, to)
    print "Graph Representation:"
    print graph

