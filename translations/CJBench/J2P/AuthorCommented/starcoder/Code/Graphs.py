
import java.util.ArrayList;
import java.util.Scanner;

class AdjacencyListGraph<E extends Comparable<E>>:

    def __init__(self):
        self.vertices = []

    class Vertex:

        def __init__(self, data):
            self.data = data
            self.adjacentVertices = []

        def addAdjacentVertex(self, to):
            for v in self.adjacentVertices:
                if v.data.compareTo(to.data) == 0:
                    return False # the edge already exists
            return self.adjacentVertices.add(to) # this will return true;

        def removeAdjacentVertex(self, to):
            # use indexes here so it is possible to
            # remove easily without implementing
            # equals method that ArrayList.remove(Object o) uses
            for i in range(0, len(self.adjacentVertices)):
                if self.adjacentVertices[i].data.compareTo(to) == 0:
                    self.adjacentVertices.remove(i)
                    return True
            return False

    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if from.compareTo(v.data) == 0:
                fromV = v
                break
        if fromV == None:
            return False
        return fromV.removeAdjacentVertex(to)

    def addEdge(self, from, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if from.compareTo(v.data) == 0: # see if from vertex already exists
                fromV = v
            else if to.compareTo(v.data) == 0: # see if to vertex already exists
                toV = v
            if fromV!= None and toV!= None:
                break # both nodes exist so stop searching
        if fromV == None:
            fromV = Vertex(from)
            self.vertices.add(fromV)
        if toV == None:
            toV = Vertex(to)
            self.vertices.add(toV)
        return fromV.addAdjacentVertex(toV)

    def __str__(self):
        sb = []
        for v in self.vertices:
            sb.append("Vertex: ")
            sb.append(v.data)
            sb.append("\n")
            sb.append("Adjacent vertices: ")
            for v2 in v.adjacentVertices:
                sb.append(v2.data)
                sb.append(" ")
            sb.append("\n")
        return "".join(sb)

if __name__ == "__main__":
    scanner = Scanner(System.in)
    graph = AdjacencyListGraph()

    edgeCount = scanner.nextInt()

    for i in range(0, edgeCount):
        from = scanner.nextInt()
        to = scanner.nextInt()
        graph.addEdge(from, to)

    print("Graph Representation:")
    print(graph)

    scanner.close()

