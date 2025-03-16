
# Define a generic AdjacencyListGraph class with a type parameter E that extends Comparable<E>
class AdjacencyListGraph(Generic[E]):
    # Initialize an empty list to store vertices
    vertices: List[Vertex[E]]

    # Constructor initializes the list
    def __init__(self):
        self.vertices = []

    # Define an inner class Vertex with data and list to store adjacent vertices
    class Vertex(Generic[E]):
        data: E
        adjacentVertices: List[Vertex[E]]

        # Constructor initializes data and empty list for adjacent vertices
        def __init__(self, data: E):
            self.data = data
            self.adjacentVertices = []

        # Add an adjacent vertex to the list if it doesn't already exist
        def addAdjacentVertex(self, to: Vertex[E]) -> bool:
            for v in self.adjacentVertices:
                if v.data == to.data:
                    return False
            return self.adjacentVertices.append(to)

        # Remove an adjacent vertex from the list by its data
        def removeAdjacentVertex(self, to: E) -> bool:
            for i in range(len(self.adjacentVertices)):
                if self.adjacentVertices[i].data == to:
                    self.adjacentVertices.remove(i)
                    return True
            return False

    # Add an edge by adding two vertices as adjacent to each other
    def addEdge(self, from: E, to: E) -> bool:
        fromV = None
        toV = None

        # Find the vertices in the list based on their data
        for v in self.vertices:
            if from == v.data:
                fromV = v
            elif to == v.data:
                toV = v
            if fromV!= None and toV!= None:
                break

        # If the vertices are not found, create new ones and add them to the list
        if fromV == None:
            fromV = self.Vertex(from)
            self.vertices.append(fromV)
        if toV == None:
            toV = self.Vertex(to)
            self.vertices.append(toV)

        # Add the adjacent relationship between the vertices
        return fromV.addAdjacentVertex(toV)

    # Remove an edge by removing the adjacent relationship between two vertices
    def removeEdge(self, from: E, to: E) -> bool:
        fromV = None

        # Find the vertex based on its data
        for v in self.vertices:
            if from == v.data:
                fromV = v
                break

        # If the vertex is not found, return false
        if fromV == None:
            return False

        # Remove the adjacent relationship between the vertices
        return fromV.removeAdjacentVertex(to)

    # Override the __str__ method to print the graph representation
    def __str__(self) -> str:
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

        # Return the list content as a String
        return "".join(sb)

# Main class to read edges from the user and print the graph representation
if __name__ == "__main__":
    scanner = Scanner(System.in)

    # Initialize an empty AdjacencyListGraph
    graph = AdjacencyListGraph()

    # Read the number of edges from the user
    edgeCount = scanner.nextInt()

    # Add edges to the graph
    for i in range(edgeCount):
        from = scanner.nextInt()
        to = scanner.nextInt()
        graph.addEdge(from, to)

    # Print the graph representation
    print("Graph Representation:")
    print(graph)

    # Close the Scanner
    scanner.close()

