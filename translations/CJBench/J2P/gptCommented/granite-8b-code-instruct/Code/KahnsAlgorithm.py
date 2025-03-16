
import sys
from collections import defaultdict, deque

# Class representing an adjacency list for a directed graph
class AdjacencyList:
    # Map to hold the adjacency list representation of the graph
    def __init__(self):
        self.adj = defaultdict(list)

    # Method to add a directed edge from 'from' to 'to'
    def addEdge(self, from_v, to_v):
        # Ensure 'from' vertex is present in the adjacency list
        self.adj[from_v].append(to_v)
        # Ensure 'to' vertex is present in the adjacency list
        self.adj[to_v]

    # Method to get the list of adjacent vertices for a given vertex
    def getAdjacents(self, v):
        return self.adj[v]

    # Method to get all vertices in the graph
    def getVertices(self):
        return self.adj.keys()

# Class to perform topological sorting on a directed graph
class TopologicalSort:
    # The graph represented as an adjacency list
    def __init__(self, graph):
        self.graph = graph

    # Method to perform topological sorting and return the sorted order
    def topSortOrder(self):
        # Map to store the in-degree of each vertex
        inDegree = defaultdict(int)
        # Initialize in-degree for each vertex
        for vertex in self.graph.getVertices():
            for adjacent in self.graph.getAdjacents(vertex):
                inDegree[adjacent] += 1
        # Queue to hold vertices with in-degree of 0
        q = deque()
        # Add all vertices with in-degree of 0 to the queue
        for vertex in self.graph.getVertices():
            if inDegree[vertex] == 0:
                q.append(vertex)
        # List to hold the topological order
        answer = []
        processedVertices = 0

        # Process vertices in the queue
        while q:
            current = q.popleft() # Get the next vertex
            answer.append(current)   # Add it to the topological order
            processedVertices += 1   # Increment the count of processed vertices

            # Decrease in-degree for adjacent vertices
            for adjacent in self.graph.getAdjacents(current):
                inDegree[adjacent] -= 1
                # If in-degree becomes 0, add it to the queue
                if inDegree[adjacent] == 0:
                    q.append(adjacent)

        # Check for cycles in the graph
        if processedVertices!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer # Return the topologically sorted order

# Main function to execute the topological sort
def main():
    # Read number of vertices and edges from input
    vertices, edges = map(int, input().split())
    # Create a new adjacency list for the graph
    graph = AdjacencyList()
    # Read edges and add them to the graph
    for _ in range(edges):
        from_v, to_v = input().split()
        graph.addEdge(from_v, to_v)
    # Create a TopologicalSort object with the graph
    topSort = TopologicalSort(graph)
    try:
        # Get the topological order of the graph
        sortedOrder = topSort.topSortOrder()
        print("Topological Order:")
        # Print the sorted order
        for s in sortedOrder:
            print(s, end=" ")
        print()
    except Exception as e:
        # Handle the case where the graph has a cycle
        print(e)

# Execute the main function
if __name__ == "__main__":
    sys.exit(main())

