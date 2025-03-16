
class Vertex:
    def __init__(self, data):
        self.data = data
        self.adjacentVertices = []

    def addAdjacentVertex(self, to):
        if to not in self.adjacentVertices:
            self.adjacentVertices.append(to)
            return True
        return False

    def removeAdjacentVertex(self, to):
        if to in self.adjacentVertices:
            self.adjacentVertices.remove(to)
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
        if fromV is None:
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
            if fromV is not None and toV is not None:
                break
        if fromV is None:
            fromV = Vertex(from)
            self.vertices.append(fromV)
        if toV is None:
            toV = Vertex(to)
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

# Main class to run the graph operations.
class Main:
    # Private constructor to prevent instantiation.
    def __init__():
        pass

    # Main method to take input and print the graph representation.
    def main():
        edgeCount = int(input())
        graph = AdjacencyListGraph()
        for i in range(edgeCount):
            from_to = input().split()
            from_ = int(from_to[0])
            to = int(from_to[1])
            graph.addEdge(from_, to)
        print("Graph Representation:")
        print(graph)

if __name__ == "__main__":
    Main.main()

