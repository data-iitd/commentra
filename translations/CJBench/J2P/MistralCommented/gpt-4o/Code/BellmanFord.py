class Main:
    def __init__(self, v, e):  # Constructor to initialize the graph with given number of vertices and edges
        self.vertex = v
        self.edge = e
        self.edges = []  # List to store edges

    class Edge:  # Class to represent an edge with source, destination and weight
        def __init__(self, a, b, c):
            self.u = a
            self.v = b
            self.w = c

    def add_edge(self, x, y, z):  # Method to add an edge to the graph
        self.edges.append(self.Edge(x, y, z))

    def print_path(self, parent, vertex):  # Method to print the path from source to destination vertex
        if parent[vertex] == -1:  # Base case: if the current vertex is the source, return
            return
        self.print_path(parent, parent[vertex])  # Recursive call: print the path from the parent to the current vertex
        print(vertex, end=" ")  # Print the current vertex

    def execute(self, source):  # Method to execute the algorithm
        dist = [float('inf')] * self.vertex  # Array to store the shortest distance from the source to each vertex
        parent = [-1] * self.vertex  # Array to store the parent of each vertex in the shortest path tree

        dist[source] = 0  # Set the distance of the source vertex to 0

        # Perform relaxation for vertex-1 times
        for i in range(self.vertex - 1):
            for e in self.edges:  # Iterate through all edges
                u = e.u  # Get the source vertex
                v = e.v  # Get the destination vertex
                weight = e.w  # Get the weight of the edge

                # If the distance to the source vertex is not infinity and the distance to the destination vertex can be improved
                if dist[u] != float('inf') and dist[v] > dist[u] + weight:
                    dist[v] = dist[u] + weight
                    parent[v] = u

        # Check for negative weight cycle
        for e in self.edges:
            u = e.u
            v = e.v
            weight = e.w

            if dist[u] != float('inf') and dist[v] > dist[u] + weight:
                print("Negative cycle detected")
                return

        # Print the vertex distances from the source and their corresponding paths
        print("Vertex distances from source:")
        for i in range(self.vertex):
            print(f"Vertex: {i}, Distance: {dist[i]}")
        print("Paths:")
        for i in range(self.vertex):
            print(f"Path to {i}: {source} ", end="")
            self.print_path(parent, i)
            print()

if __name__ == "__main__":  # Main method to read input and execute the algorithm
    v = int(input())  # Read the number of vertices
    e = int(input())  # Read the number of edges
    bf = Main(v, e)  # Create a new graph with the given number of vertices and edges

    for _ in range(e):  # Read and add edges to the graph
        u, ve, w = map(int, input().split())
        bf.add_edge(u, ve, w)

    source = int(input())  # Read the source vertex
    bf.execute(source)  # Execute the algorithm from the source vertex

# <END-OF-CODE>
