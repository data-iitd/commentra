

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

    def addEdge(self, from, to):
        fromV = None
        toV = None

        # Find the vertices in the list based on their data
        for v in self.vertices:
            if from == v.data:
                fromV = v
            elif to == v.data:
                toV = v
            if fromV and toV:
                break

        # If the vertices are not found, create new ones and add them to the list
        if not fromV:
            fromV = Vertex(from)
            self.vertices.append(fromV)
        if not toV:
            toV = Vertex(to)
            self.vertices.append(toV)

        # Add the adjacent relationship between the vertices
        return fromV.addAdjacentVertex(toV)

    def removeEdge(self, from, to):
        fromV = None

        # Find the vertex based on its data
        for v in self.vertices:
            if from == v.data:
                fromV = v
                break

        # If the vertex is not found, return False
        if not fromV:
            return False

        # Remove the adjacent relationship between the vertices
        return fromV.removeAdjacentVertex(to)

    def __str__(self):
        sb = []

        # Iterate through each vertex and print its data and adjacent vertices
        for v in self.vertices:
            sb.append("Vertex: ")
            sb.append(str(v.data))
            sb.append("\n")
            sb.append("Adjacent vertices: ")
            for v2 in v.adjacentVertices:
                sb.append(str(v2.data))
                sb.append(" ")
            sb.append("\n")

        # Return the StringBuilder content as a String
        return "".join(sb)

# Main function to read edges from the user and print the graph representation
def main():
    import sys

    # Initialize an empty AdjacencyListGraph
    graph = AdjacencyListGraph()

    # Read the number of edges from the user
    edgeCount = int(input())

    # Add edges to the graph
    for i in range(edgeCount):
        from_ = int(input())
        to = int(input())
        graph.addEdge(from_, to)

    # Print the graph representation
    print("Graph Representation:")
    print(graph)

if __name__ == "__main__":
    sys.exit(main())

Translate the above Python code to C++ and end with comment "