import sys
from collections import defaultdict

# Class representing an adjacency list for a directed graph
class AdjacencyList(object):
    # Map to hold the adjacency list representation of the graph
    adj = defaultdict(list)

    # Constructor to initialize the adjacency list
    def __init__(self):
        pass

    # Method to add a directed edge from 'from' to 'to'
    def addEdge(self, fromVertex, toVertex):
        # Ensure 'from' vertex is present in the adjacency list
        self.adj[fromVertex].append(toVertex)
        # Ensure 'to' vertex is present in the adjacency list
        self.adj[toVertex]

    # Method to get the list of adjacent vertices for a given vertex
    def getAdjacents(self, v):
        return self.adj[v]

    # Method to get all vertices in the graph
    def getVertices(self):
        return self.adj.keys()

# Class to perform topological sorting on a directed graph
class TopologicalSort(object):
    # The graph represented as an adjacency list
    graph = None
    # Map to store the in-degree of each vertex
    inDegree = None

    # Constructor to initialize the topological sort with a graph
    def __init__(self, graph):
        self.graph = graph

    # Method to calculate the in-degree of each vertex in the graph
    def calculateInDegree(self):
        self.inDegree = {}
        # Initialize in-degree for each vertex
        for vertex in self.graph.getVertices():
            self.inDegree[vertex] = 0
            # Update in-degree for adjacent vertices
            for adjacent in self.graph.getAdjacents(vertex):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1

    # Method to perform topological sorting and return the sorted order
    def topSortOrder(self):
        # Calculate in-degrees of all vertices
        self.calculateInDegree()
        # Queue to hold vertices with in-degree of 0
        q = []
        # Add all vertices with in-degree of 0 to the queue
        for vertex in self.inDegree:
            if self.inDegree[vertex] == 0:
                q.append(vertex)
        # List to hold the topological order
        answer = []
        processedVertices = 0

        # Process vertices in the queue
        while len(q) > 0:
            current = q.pop() # Get the next vertex
            answer.append(current)   # Add it to the topological order
            processedVertices += 1   # Increment the count of processed vertices

            # Decrease in-degree for adjacent vertices
            for adjacent in self.graph.getAdjacents(current):
                self.inDegree[adjacent] -= 1
                # If in-degree becomes 0, add it to the queue
                if self.inDegree[adjacent] == 0:
                    q.append(adjacent)

        # Check for cycles in the graph
        if processedVertices!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer # Return the topologically sorted order

# Main class to execute the topological sort
if __name__ == '__main__':
    # Read number of vertices and edges from input
    vertices = int(raw_input().strip())
    edges = int(raw_input().strip())
    # Create a new adjacency list for the graph
    graph = AdjacencyList()
    # Read edges and add them to the graph
    for i in range(edges):
        fromVertex = raw_input().strip()
        toVertex = raw_input().strip()
        graph.addEdge(fromVertex, toVertex)
    # Create a TopologicalSort object with the graph
    topSort = TopologicalSort(graph)
    try:
        # Get the topological order of the graph
        sortedOrder = topSort.topSortOrder()
        print "Topological Order:"
        # Print the sorted order
        for s in sortedOrder:
            print s,
        print
    except Exception as e:
        # Handle the case where the graph has a cycle
        print e.message

