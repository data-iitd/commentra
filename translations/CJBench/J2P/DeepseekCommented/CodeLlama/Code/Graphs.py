
# This class represents a graph using an adjacency list.
class AdjacencyListGraph:
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
                if v.data == to.data:
                    return False
            return self.adjacentVertices.append(to)

        # Method to remove an adjacent vertex from this vertex.
        # Returns true if the vertex was removed, false otherwise.
        def removeAdjacentVertex(self, to):
            for i in range(len(self.adjacentVertices)):
                if self.adjacentVertices[i].data == to:
                    self.adjacentVertices.pop(i)
                    return True
            return False

    # Method to remove an edge between two vertices.
    # Returns true if the edge was removed, false if the edge did not exist.
    def removeEdge(self, from, to):
        fromV = None
        for v in self.vertices:
            if from == v.data:
                fromV = v
                break
        if fromV is None:
            return False
        return fromV.removeAdjacentVertex(to)

    # Method to add an edge between two vertices.
    # Returns true if the edge was added, false if the edge already existed.
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
            fromV = self.Vertex(from)
            self.vertices.append(fromV)
        if toV is None:
            toV = self.Vertex(to)
            self.vertices.append(toV)
        return fromV.addAdjacentVertex(toV)

    # Method to provide a string representation of the graph.
    def __str__(self):
        sb = ""
        for v in self.vertices:
            sb += "Vertex: " + str(v.data) + "\n"
            sb += "Adjacent vertices: "
            for v2 in v.adjacentVertices:
                sb += str(v2.data) + " "
            sb += "\n"
        return sb

# Main class to run the graph operations.
class Main:
    # Private constructor to prevent instantiation.
    def __init__(self):
        pass

    # Main method to take input and print the graph representation.
    def main(self):
        edgeCount = int(input())
        graph = AdjacencyListGraph()
        for i in range(edgeCount):
            from = int(input())
            to = int(input())
            graph.addEdge(from, to)
        print("Graph Representation:")
        print(graph)

# Main method to run the program.
if __name__ == "__main__":
    Main().main()
