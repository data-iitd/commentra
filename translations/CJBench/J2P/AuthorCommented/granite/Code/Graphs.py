

class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacentVertices = []

    def addAdjacentVertex(self, to):
        for v in self.adjacentVertices:
            if v.data == to.data:
                return False # the edge already exists
        return self.adjacentVertices.append(to) # this will return True;

    def removeAdjacentVertex(self, to):
        # use indexes here so it is possible to
        # remove easily without implementing
        # equals method that ArrayList.remove(Object o) uses
        for i in range(len(self.adjacentVertices)):
            if self.adjacentVertices[i].data == to:
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
            if from == v.data: # see if from vertex already exists
                fromV = v
            elif to == v.data: # see if to vertex already exists
                toV = v
            if fromV!= None and toV!= None:
                break # both nodes exist so stop searching
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
    edgeCount = int(input())
    graph = AdjacencyListGraph()
    for i in range(edgeCount):
        from_ = int(input())
        to = int(input())
        graph.addEdge(from_, to)
    print("Graph Representation:")
    print(graph)

