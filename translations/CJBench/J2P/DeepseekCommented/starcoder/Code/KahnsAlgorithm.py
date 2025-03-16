import sys
from collections import defaultdict

# AdjacencyList class to represent a graph using an adjacency list
class AdjacencyList:
    # Map to store the graph's edges
    adj = defaultdict(list)
    # Constructor to initialize the adjacency list
    def __init__(self):
        pass
    # Method to add an edge between two vertices
    def addEdge(self, fromVertex, toVertex):
        # Ensure the from vertex is in the adjacency list
        self.adj[fromVertex].append(toVertex)
        # Ensure the to vertex is in the adjacency list
        self.adj[toVertex]
    # Method to get the adjacent vertices of a given vertex
    def getAdjacents(self, v):
        return self.adj[v]
    # Method to get all the vertices in the graph
    def getVertices(self):
        return self.adj.keys()

# TopologicalSort class to perform topological sort on a graph
class TopologicalSort:
    # The graph to be sorted
    graph = None
    # Map to store the in-degree of each vertex
    inDegree = None
    # Constructor to initialize the topological sort object with a graph
    def __init__(self, graph):
        self.graph = graph
    # Method to calculate the in-degree of each vertex
    def calculateInDegree(self):
        self.inDegree = {}
        for vertex in self.graph.getVertices():
            self.inDegree[vertex] = 0
            for adjacent in self.graph.getAdjacents(vertex):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1
    # Method to return the vertices in topological order
    def topSortOrder(self):
        self.calculateInDegree() # Calculate in-degrees of all vertices
        q = []
        # Add all vertices with in-degree 0 to the queue
        for vertex in self.inDegree:
            if self.inDegree[vertex] == 0:
                q.append(vertex)
        answer = []
        processedVertices = 0
        # Process vertices from the queue
        while len(q) > 0:
            current = q.pop(0)
            answer.append(current)
            processedVertices += 1
            for adjacent in self.graph.getAdjacents(current):
                self.inDegree[adjacent] -= 1
                if self.inDegree[adjacent] == 0:
                    q.append(adjacent)
        # If not all vertices were processed, a cycle exists
        if processedVertices!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer

# Main class to run the topological sort program
if __name__ == "__main__":
    vertices = int(sys.stdin.readline()) # Read the number of vertices
    edges = int(sys.stdin.readline()) # Read the number of edges
    graph = AdjacencyList()
    for i in range(edges):
        fromVertex = sys.stdin.readline().strip() # Read the from vertex
        toVertex = sys.stdin.readline().strip() # Read the to vertex
        graph.addEdge(fromVertex, toVertex) # Add an edge between the vertices
    topSort = TopologicalSort(graph)
    try:
        sortedOrder = topSort.topSortOrder()
        print("Topological Order:")
        for s in sortedOrder:
            print(s, end=" ") # Print the sorted order of vertices
        print()
    except Exception as e:
        print(e) # Print an error message if a cycle is detected

