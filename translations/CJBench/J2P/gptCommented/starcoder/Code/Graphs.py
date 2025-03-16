import java.util.ArrayList;
import java.util.Scanner;

# Class representing a graph using an adjacency list
class AdjacencyListGraph<E extends Comparable<E>>:
    # List to hold all vertices in the graph
    vertices = []

    # Constructor to initialize the graph
    def __init__(self):
        self.vertices = []

    # Inner class representing a vertex in the graph
    class Vertex:
        data = None # Data contained in the vertex
        adjacentVertices = [] # List of adjacent vertices

        # Constructor to initialize a vertex with given data
        def __init__(self, data):
            self.adjacentVertices = []
            self.data = data

        # Method to add an adjacent vertex; returns false if it already exists
        def addAdjacentVertex(self, to):
            for v in self.adjacentVertices:
                if v.data.compareTo(to.data) == 0:
                    return False # Vertex already adjacent
            return self.adjacentVertices.add(to) # Add the vertex if not already adjacent

        # Method to remove an adjacent vertex; returns true if successful
        def removeAdjacentVertex(self, to):
            for i in range(len(self.adjacentVertices)):
                if self.adjacentVertices[i].data.compareTo(to) == 0:
                    self.adjacentVertices.remove(i) # Remove the vertex
                    return True
            return False # Vertex not found

    # Method to remove an edge from the graph; returns true if successful
    def removeEdge(self, from, to):
        fromV = None # Vertex from which the edge is to be removed
        # Find the vertex corresponding to 'from'
        for v in self.vertices:
            if from.compareTo(v.data) == 0:
                fromV = v
                break
        if fromV == None:
            return False # 'From' vertex not found
        return fromV.removeAdjacentVertex(to) # Remove the edge

    # Method to add an edge to the graph; creates vertices if they don't exist
    def addEdge(self, from, to):
        fromV = None # Vertex from which the edge starts
        toV = None # Vertex to which the edge points
        # Find or create the vertices for 'from' and 'to'
        for v in self.vertices:
            if from.compareTo(v.data) == 0: 
                fromV = v
            elif to.compareTo(v.data) == 0: 
                toV = v
            if fromV!= None and toV!= None:
                break # Both vertices found
        # Create 'from' vertex if it doesn't exist
        if fromV == None:
            fromV = self.Vertex(from)
            self.vertices.add(fromV)
        # Create 'to' vertex if it doesn't exist
        if toV == None:
            toV = self.Vertex(to)
            self.vertices.add(toV)
        return fromV.addAdjacentVertex(toV) # Add the edge

    # Method to represent the graph as a string
    def __str__(self):
        sb = []
        # Iterate through each vertex to build the string representation
        for v in self.vertices:
            sb.append("Vertex: ")
            sb.append(v.data)
            sb.append("\n")
            sb.append("Adjacent vertices: ")
            # List all adjacent vertices
            for v2 in v.adjacentVertices:
                sb.append(v2.data)
                sb.append(" ")
            sb.append("\n")
        return "".join(sb) # Return the complete string representation

# Main class to execute the program
if __name__ == "__main__":
    scanner = Scanner(System.in) # Scanner for user input
    graph = AdjacencyListGraph() # Create a graph instance
    edgeCount = scanner.nextInt() # Read the number of edges
    # Loop to read edges and add them to the graph
    for i in range(edgeCount):
        from = scanner.nextInt() # Read starting vertex
        to = scanner.nextInt() # Read ending vertex
        graph.addEdge(from, to) # Add edge to the graph
    # Output the graph representation
    print("Graph Representation:")
    print(graph)
    scanner.close() # Close the scanner

