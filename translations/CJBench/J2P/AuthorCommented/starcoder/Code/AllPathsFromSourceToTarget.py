
import sys

# Class to represent a graph
class Graph:

    # Constructor
    def __init__(self, vertices):
        self.v = vertices
        self.graph = []
        self.paths = []

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph.append([u, v])

    # A recursive function to print all paths from 'u' to 'd'.
    # isVisited[] keeps track of vertices in current path.
    # localPathList<> stores actual vertices in the current path
    def storeAllPathsUtil(self, u, d, isVisited, localPathList):
        if u == d:
            self.paths.append(localPathList)
            return

        # Mark the current node
        isVisited[u] = True

        # Recursion for all the vertices adjacent to current vertex
        for i in self.graph:
            if not isVisited[i[0]]:
                # store current node in path[]
                localPathList.append(i[0])
                self.storeAllPathsUtil(i[0], d, isVisited, localPathList)
                # remove current node in path[]
                localPathList.remove(i[0])

        # Mark the current node
        isVisited[u] = False

    # Prints all paths from's' to 'd'
    def storeAllPaths(self, s, d):
        # Mark all the vertices as not visited
        isVisited = [False] * (self.v)

        # Create an array to store paths
        localPathList = []

        # Call the recursive helper function to print all paths
        self.storeAllPathsUtil(s, d, isVisited, localPathList)

    # Returns all paths from's' to 'd'
    def getPaths(self):
        return self.paths


# Driver Code
if __name__ == '__main__':
    # Read the number of vertices and edges
    v, e = map(int, input().split())

    # Create a graph
    graph = Graph(v)

    # Read all edges and store in graph
    for i in range(e):
        u, v = map(int, input().split())
        graph.addEdge(u, v)

    # Read source and destination
    s, d = map(int, input().split())

    # Print all paths from source to destination
    graph.storeAllPaths(s, d)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

