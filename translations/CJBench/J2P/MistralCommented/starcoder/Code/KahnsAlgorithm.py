
import sys
from collections import defaultdict

# Define a generic AdjacencyList class for Comparable elements
class AdjacencyList(object):
    def __init__(self):
        self.adj = defaultdict(list) # Use a defaultdict to maintain insertion order

    # Add an edge between two vertices
    def addEdge(self, fromVertex, toVertex):
        self.adj[fromVertex].append(toVertex)
        self.adj[toVertex] # Create an empty list if toVertex doesn't have one yet

    # Get the list of adjacent vertices for a given vertex
    def getAdjacents(self, v):
        return self.adj[v]

    # Get all the vertices in the graph
    def getVertices(self):
        return self.adj.keys()

# Define a generic TopologicalSort class for Comparable elements
class TopologicalSort(object):
    def __init__(self, graph):
        self.graph = graph
        self.inDegree = {}

    # Calculate the in-degree for each vertex
    def calculateInDegree(self):
        for vertex in self.graph.getVertices():
            self.inDegree[vertex] = 0 # Initialize the in-degree for each vertex to 0
            for adjacent in self.graph.getAdjacents(vertex):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1 # Increment the in-degree for each adjacent

    # Perform the topological sort
    def topSortOrder(self):
        self.calculateInDegree() # Calculate the in-degree for all vertices
        q = [] # Create a queue to store vertices with 0 in-degree
        answer = [] # Create an empty list to store the topological order

        # Add all vertices with 0 in-degree to the queue
        for vertex in self.inDegree:
            if self.inDegree[vertex] == 0:
                q.append(vertex)

        # Process vertices in the order they are removed from the queue
        while len(q) > 0:
            current = q.pop(0) # Get the next vertex with 0 in-degree
            answer.append(current) # Add it to the answer
            for adjacent in self.graph.getAdjacents(current):
                self.inDegree[adjacent] = self.inDegree[adjacent] - 1 # Decrease the in-degree for each adjacent
                if self.inDegree[adjacent] == 0:
                    q.append(adjacent) # Add it to the queue if its in-degree is now 0

        # Throw an exception if there is a cycle in the graph
        if len(answer)!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")

        return answer

# Main class to read input and call the topological sort algorithm
if __name__ == "__main__":
    vertices = int(raw_input().strip()) # Read the number of vertices
    edges = int(raw_input().strip()) # Read the number of edges

    graph = AdjacencyList() # Create an empty graph
    for i in range(edges):
        fromVertex = raw_input().strip() # Read the source vertex
        toVertex = raw_input().strip() # Read the destination vertex
        graph.addEdge(fromVertex, toVertex) # Add an edge between the vertices

    topSort = TopologicalSort(graph) # Create a new topological sort object

    try:
        sortedOrder = topSort.topSortOrder() # Perform the topological sort
        print "Topological Order:" # Print the header for the output
        for s in sortedOrder:
            print s, # Print each vertex in the topological order
        print # Print a newline after all vertices have been printed
    except Exception as e:
        print e.message # Print an error message if there is a cycle in the graph

