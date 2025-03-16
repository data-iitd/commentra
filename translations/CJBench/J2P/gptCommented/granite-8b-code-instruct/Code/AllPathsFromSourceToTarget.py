
import sys

class Main:
    # Number of vertices in the graph
    v = 0
    # List to store all paths from source to destination
    paths = []
    # Adjacency list representation of the graph
    adjList = {}

    # Constructor to initialize the graph with a given number of vertices
    def __init__(self, vertices):
        self.v = vertices
        self.initAdjList() # Initialize the adjacency list

    # Method to initialize the adjacency list for the graph
    def initAdjList(self):
        self.adjList = {i: [] for i in range(self.v)} # Create an empty dictionary for each vertex

    # Method to add an edge from vertex u to vertex v
    def addEdge(self, u, v):
        self.adjList[u].append(v) # Add vertex v to the adjacency list of vertex u

    # Method to find and store all paths from source s to destination d
    def storeAllPaths(self, s, d):
        isVisited = [False] * self.v # Track visited vertices
        pathList = [s] # List to store the current path
        self.storeAllPathsUtil(s, d, isVisited, pathList) # Call the utility method to find paths

    # Utility method to recursively find all paths from u to d
    def storeAllPathsUtil(self, u, d, isVisited, pathList):
        # If the current vertex is the destination, add the current path to the list of paths
        if u == d:
            self.paths.append(pathList[:]) # Store a copy of the current path
            return
        isVisited[u] = True # Mark the current vertex as visited
        # Explore all adjacent vertices of the current vertex
        for i in self.adjList[u]:
            # If the adjacent vertex has not been visited, continue the path
            if not isVisited[i]:
                pathList.append(i) # Add the adjacent vertex to the current path
                self.storeAllPathsUtil(i, d, isVisited, pathList) # Recur for the adjacent vertex
                pathList.pop() # Backtrack: remove the vertex from the current path
        isVisited[u] = False # Unmark the current vertex for other paths

    # Method to get all stored paths
    def getPaths(self):
        return self.paths # Return the list of all paths found

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of vertices and edges from input
    v, e = map(int, input().split())
    # Create a graph instance
    graph = Main(v)
    # Read the edges from input
    for _ in range(e):
        u, v = map(int, input().split())
        graph.addEdge(u, v)
    # Read the source and destination vertices from input
    s, d = map(int, input().split())
    # Find all paths from source to destination
    graph.storeAllPaths(s, d)
    # Print all paths found
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path) # Print each path

