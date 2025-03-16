class AdjacencyListGraph:
    # Class representing a graph using an adjacency list

    class Vertex:
        # Inner class representing a vertex in the graph
        def __init__(self, data):
            self.data = data  # Data contained in the vertex
            self.adjacent_vertices = []  # List of adjacent vertices

        def add_adjacent_vertex(self, to):
            # Method to add an adjacent vertex; returns False if it already exists
            for v in self.adjacent_vertices:
                if v.data == to.data:
                    return False  # Vertex already adjacent
            self.adjacent_vertices.append(to)  # Add the vertex if not already adjacent
            return True

        def remove_adjacent_vertex(self, to):
            # Method to remove an adjacent vertex; returns True if successful
            for i in range(len(self.adjacent_vertices)):
                if self.adjacent_vertices[i].data == to:
                    del self.adjacent_vertices[i]  # Remove the vertex
                    return True
            return False  # Vertex not found

    def __init__(self):
        # Constructor to initialize the graph
        self.vertices = []  # List to hold all vertices in the graph

    def remove_edge(self, from_data, to):
        # Method to remove an edge from the graph; returns True if successful
        from_vertex = None  # Vertex from which the edge is to be removed
        # Find the vertex corresponding to 'from'
        for v in self.vertices:
            if v.data == from_data:
                from_vertex = v
                break
        if from_vertex is None:
            return False  # 'From' vertex not found
        return from_vertex.remove_adjacent_vertex(to)  # Remove the edge

    def add_edge(self, from_data, to_data):
        # Method to add an edge to the graph; creates vertices if they don't exist
        from_vertex = None  # Vertex from which the edge starts
        to_vertex = None  # Vertex to which the edge points
        # Find or create the vertices for 'from' and 'to'
        for v in self.vertices:
            if v.data == from_data:
                from_vertex = v
            elif v.data == to_data:
                to_vertex = v
            if from_vertex is not None and to_vertex is not None:
                break
        # Create 'from' vertex if it doesn't exist
        if from_vertex is None:
            from_vertex = self.Vertex(from_data)
            self.vertices.append(from_vertex)
        # Create 'to' vertex if it doesn't exist
        if to_vertex is None:
            to_vertex = self.Vertex(to_data)
            self.vertices.append(to_vertex)
        return from_vertex.add_adjacent_vertex(to_vertex)  # Add the edge

    def __str__(self):
        # Method to represent the graph as a string
        sb = []
        # Iterate through each vertex to build the string representation
        for v in self.vertices:
            sb.append(f"Vertex: {v.data}\n")
            sb.append("Adjacent vertices: ")
            # List all adjacent vertices
            for v2 in v.adjacent_vertices:
                sb.append(f"{v2.data} ")
            sb.append("\n")
        return ''.join(sb)  # Return the complete string representation


# Main function to execute the program
if __name__ == "__main__":
    import sys

    graph = AdjacencyListGraph()  # Create a graph instance
    edge_count = int(sys.stdin.readline().strip())  # Read the number of edges
    # Loop to read edges and add them to the graph
    for _ in range(edge_count):
        from_vertex, to_vertex = map(int, sys.stdin.readline().strip().split())  # Read starting and ending vertices
        graph.add_edge(from_vertex, to_vertex)  # Add edge to the graph
    # Output the graph representation
    print("Graph Representation:")
    print(graph)

# <END-OF-CODE>
