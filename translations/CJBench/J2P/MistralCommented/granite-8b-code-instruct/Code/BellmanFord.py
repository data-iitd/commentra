

import sys

class Edge: # Class to represent an edge with source, destination and weight
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

class Graph: # Class to represent a graph with vertices and edges
    def __init__(self, v, e):
        self.vertex = v # Number of vertices in the graph
        self.edge = e # Number of edges in the graph
        self.edges = [None] * e # Array to store edges
        self.index = 0 # Index for adding edges to the array

    def addEdge(self, x, y, z): # Method to add an edge to the graph
        self.edges[self.index] = Edge(x, y, z)
        self.index += 1

    def getEdgeArray(self): # Method to get the array of edges
        return self.edges

    def printPath(self, parent, vertex): # Method to print the path from source to destination vertex
        if parent[vertex] == -1: # Base case: if the current vertex is the source, return
            return
        self.printPath(parent, parent[vertex]) # Recursive call: print the path from the parent to the current vertex
        print(vertex, end=" ") # Print the current vertex

    def execute(self, source): # Method to execute the breadth-first search algorithm from a given source vertex
        dist = [sys.maxsize] * self.vertex # Array to store the shortest distance from the source to each vertex
        parent = [-1] * self.vertex # Array to store the parent of each vertex in the shortest path tree

        # Initialize all distances as infinity and parents as null
        for i in range(self.vertex):
            dist[i] = sys.maxsize
            parent[i] = -1

        # Set the distance of the source vertex to 0 and mark it as visited
        dist[source] = 0

        # Perform breadth-first search for vertex-1 times
        for i in range(self.vertex - 1):
            for j in range(self.edge): # Iterate through all edges
                e = self.edges[j] # Get the current edge
                u = e.u # Get the source vertex
                v = e.v # Get the destination vertex
                weight = e.w # Get the weight of the edge

                # If the distance to the source vertex is not infinity and the distance to the destination vertex can be improved, update the distance and parent
                if dist[u]!= sys.maxsize and dist[v] > dist[u] + weight:
                    dist[v] = dist[u] + weight
                    parent[v] = u

        # Check for negative weight cycle
        for j in range(self.edge):
            e = self.edges[j]
            u = e.u
            v = e.v
            weight = e.w

            if dist[u]!= sys.maxsize and dist[v] > dist[u] + weight:
                print("Negative cycle detected")
                return

        # Print the vertex distances from the source and their corresponding paths
        print("Vertex distances from source:")
        for i in range(self.vertex):
            print("Vertex: " + str(i) + ", Distance: " + str(dist[i]))
        print("Paths:")
        for i in range(self.vertex):
            print("Path to " + str(i) + ": " + str(source) + " ", end="")
            self.printPath(parent, i)
            print()

if __name__ == "__main__": # Main method to read input and execute the algorithm
    v, e = map(int, input().split()) # Read the number of vertices and edges
    bf = Graph(v, e) # Create a new graph with the given number of vertices and edges

    for i in range(e): # Read and add edges to the graph
        u, ve, w = map(int, input().split())
        bf.addEdge(u, ve, w)

    source = int(input()) # Read the source vertex
    bf.execute(source) # Execute the breadth-first search algorithm from the source vertex

Translate the above Python code to C++ and end with comment "