
# Import the necessary libraries
from collections import defaultdict

# Class representing a graph using an adjacency list
class AdjacencyListGraph:
    # List to hold all vertices in the graph
    vertices = []

    # Constructor to initialize the graph
    def __init__(self):
        self.vertices = []

    # Inner class representing a vertex in the graph
    class Vertex:
        data = None # Data contained in the vertex
        adjacent_vertices = [] # List of adjacent vertices

        # Constructor to initialize a vertex with given data
        def __init__(self, data):
            self.adjacent_vertices = []
            self.data = data

        # Method to add an adjacent vertex; returns false if it already exists
        def add_adjacent_vertex(self, to):
            for v in self.adjacent_vertices:
                if v.data == to.data:
                    return False # Vertex already adjacent
            return self.adjacent_vertices.append(to) # Add the vertex if not already adjacent

        # Method to remove an adjacent vertex; returns true if successful
        def remove_adjacent_vertex(self, to):
            for i in range(len(self.adjacent_vertices)):
                if self.adjacent_vertices[i].data == to:
                    self.adjacent_vertices.pop(i) # Remove the vertex
                    return True
            return False # Vertex not found

    # Method to remove an edge from the graph; returns true if successful
    def remove_edge(self, from, to):
        from_v = None # Vertex from which the edge is to be removed
        # Find the vertex corresponding to 'from'
        for v in self.vertices:
            if from == v.data:
                from_v = v
                break
        if from_v == None:
            return False # 'From' vertex not found
        return from_v.remove_adjacent_vertex(to) # Remove the edge

    # Method to add an edge to the graph; creates vertices if they don't exist
    def add_edge(self, from, to):
        from_v = None # Vertex from which the edge starts
        to_v = None # Vertex to which the edge points
        # Find or create the vertices for 'from' and 'to'
        for v in self.vertices:
            if from == v.data:
                from_v = v
            elif to == v.data:
                to_v = v
            if from_v != None and to_v != None:
                break # Both vertices found
        # Create 'from' vertex if it doesn't exist
        if from_v == None:
            from_v = self.Vertex(from)
            self.vertices.append(from_v)
        # Create 'to' vertex if it doesn't exist
        if to_v == None:
            to_v = self.Vertex(to)
            self.vertices.append(to_v)
        return from_v.add_adjacent_vertex(to_v) # Add the edge

    # Method to represent the graph as a string
    def __str__(self):
        sb = "" # String builder to build the string representation
        # Iterate through each vertex to build the string representation
        for v in self.vertices:
            sb += "Vertex: "
            sb += str(v.data)
            sb += "\n"
            sb += "Adjacent vertices: "
            # List all adjacent vertices
            for v2 in v.adjacent_vertices:
                sb += str(v2.data)
                sb += " "
            sb += "\n"
        return sb # Return the complete string representation

# Main class to execute the program
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Main method to run the graph program
    def main(self):
        scanner = input() # Scanner for user input
        graph = AdjacencyListGraph() # Create a graph instance
        edge_count = int(scanner) # Read the number of edges
        # Loop to read edges and add them to the graph
        for i in range(edge_count):
            from_ = int(input()) # Read starting vertex
            to = int(input()) # Read ending vertex
            graph.add_edge(from_, to) # Add edge to the graph
        # Output the graph representation
        print("Graph Representation:")
        print(graph)

# Create an instance of the Main class and run the program
Main().main()

