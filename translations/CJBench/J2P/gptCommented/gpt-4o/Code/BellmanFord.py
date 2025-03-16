class Main:
    # Number of vertices and edges in the graph
    def __init__(self, v, e):
        self.vertex = v
        self.edge = e
        self.edges = []  # Initialize the edges list

    # Inner class to represent an edge in the graph
    class Edge:
        def __init__(self, a, b, c):
            self.u = a  # Start vertex of the edge
            self.v = b  # End vertex of the edge
            self.w = c  # Weight of the edge

    # Method to add an edge to the graph
    def add_edge(self, x, y, z):
        self.edges.append(self.Edge(x, y, z))  # Create a new edge and add it to the list

    # Recursive method to print the path from the source to a given vertex
    def print_path(self, parent, vertex):
        if parent[vertex] == -1:  # Base case: if there is no parent
            return
        self.print_path(parent, parent[vertex])  # Recursively print the parent path
        print(vertex, end=" ")  # Print the current vertex

    # Method to execute the Bellman-Ford algorithm from a given source vertex
    def execute(self, source):
        # Arrays to store distances and parent vertices
        dist = [float('inf')] * self.vertex
        parent = [-1] * self.vertex

        # Initialize distances and parents
        dist[source] = 0  # Distance from source to itself is 0

        # Relax edges repeatedly
        for i in range(self.vertex - 1):
            for e in self.edges:
                # Check if the edge can be relaxed
                if dist[e.u] != float('inf') and dist[e.v] > dist[e.u] + e.w:
                    dist[e.v] = dist[e.u] + e.w  # Update distance
                    parent[e.v] = e.u  # Update parent

        # Check for negative weight cycles
        for e in self.edges:
            if dist[e.u] != float('inf') and dist[e.v] > dist[e.u] + e.w:
                print("Negative cycle detected")
                return  # Exit the method if a negative cycle is found

        # Print the distances from the source to each vertex
        print("Vertex distances from source:")
        for i in range(self.vertex):
            print(f"Vertex: {i}, Distance: {dist[i]}")

        # Print the paths from the source to each vertex
        print("Paths:")
        for i in range(self.vertex):
            print(f"Path to {i}: {source} ", end="")
            self.print_path(parent, i)  # Print the path using the parent array
            print()  # New line after each path

# Main method to run the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    v, e = map(int, data[0].split())  # Read number of vertices and edges
    bf = Main(v, e)  # Create