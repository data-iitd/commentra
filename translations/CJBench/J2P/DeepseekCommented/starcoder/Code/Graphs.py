import java.util.ArrayList;
import java.util.Scanner;

# This class represents a graph using an adjacency list.
class AdjacencyListGraph<E extends Comparable<E>>:
    # List to store all vertices in the graph.
    vertices = []

    # Constructor to initialize the graph with an empty list of vertices.
    def __init__(self):
        self.vertices = []

    # Inner class representing a vertex in the graph.
    class Vertex:
        # Data stored in the vertex.
        data = None
        # List of adjacent vertices.
        adjacentVertices = []

        # Constructor to initialize a vertex with given data.
        def __init__(self, data):
            self.adjacentVertices = []
            self.data = data

        # Method to add an adjacent vertex to this vertex.
        # Returns false if the vertex already exists in the adjacency list.
        def addAdjacentVertex(self, to):
            for v in self.adjacentVertices:
                if v.data.compareTo(to.data) == 0:
                    return False
            return self.adjacentVertices.add(to)

        # Method to remove an adjacent vertex from this vertex.
        # Returns true if the vertex was removed, false otherwise.
        def removeAdjacentVertex(self, to):
            for i in range(0, len(self.adjacentVertices)):
                if self.adjacentVertices.get(i).data.compareTo(to) == 0:
                    self.adjacentVertices.remove(i)
                    return True
            return False

    # Method to remove an edge between two vertices.
    # Returns true if the edge was removed, false if the edge did not exist.
    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if from.compareTo(v.data) == 0:
                fromV = v
                break
        if fromV == None:
            return False
        return fromV.removeAdjacentVertex(to)

    # Method to add an edge between two vertices.
    # Returns true if the edge was added, false if the edge already existed.
    def addEdge(self, from, to):
        fromV = None
        toV = None
        for v in self.vertices:
            if from.compareTo(v.data) == 0: 
                fromV = v
            elif to.compareTo(v.data) == 0: 
                toV = v
            if fromV!= None and toV!= None:
                break
        if fromV == None:
            fromV = Vertex(from)
            self.vertices.add(fromV)
        if toV == None:
            toV = Vertex(to)
            self.vertices.add(toV)
        return fromV.addAdjacentVertex(toV)

    # Method to provide a string representation of the graph.
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

# Main class to run the graph operations.
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

