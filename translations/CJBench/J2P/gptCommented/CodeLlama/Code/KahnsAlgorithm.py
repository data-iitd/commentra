
# Import modules
from collections import defaultdict

# Class representing an adjacency list for a directed graph
class AdjacencyList:
    # Map to hold the adjacency list representation of the graph
    adj = defaultdict(list)

    # Constructor to initialize the adjacency list
    def __init__(self):
        pass

    # Method to add a directed edge from 'from' to 'to'
    def add_edge(self, from_vertex, to_vertex):
        # Ensure 'from' vertex is present in the adjacency list
        self.adj[from_vertex] = self.adj.get(from_vertex, [])
        # Add 'to' vertex to the adjacency list of 'from'
        self.adj[from_vertex].append(to_vertex)
        # Ensure 'to' vertex is present in the adjacency list
        self.adj[to_vertex] = self.adj.get(to_vertex, [])

    # Method to get the list of adjacent vertices for a given vertex
    def get_adjacents(self, vertex):
        return self.adj[vertex]

    # Method to get all vertices in the graph
    def get_vertices(self):
        return self.adj.keys()

# Class to perform topological sorting on a directed graph
class TopologicalSort:
    # The graph represented as an adjacency list
    graph = None
    # Map to store the in-degree of each vertex
    in_degree = None

    # Constructor to initialize the topological sort with a graph
    def __init__(self, graph):
        self.graph = graph

    # Method to calculate the in-degree of each vertex in the graph
    def calculate_in_degree(self):
        self.in_degree = {}
        # Initialize in-degree for each vertex
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
            # Update in-degree for adjacent vertices
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] = self.in_degree.get(adjacent, 0) + 1

    # Method to perform topological sorting and return the sorted order
    def top_sort_order(self):
        # Calculate in-degrees of all vertices
        self.calculate_in_degree()
        # Queue to hold vertices with in-degree of 0
        q = []
        # Add all vertices with in-degree of 0 to the queue
        for vertex, in_degree in self.in_degree.items():
            if in_degree == 0:
                q.append(vertex)
        # List to hold the topological order
        answer = []
        processed_vertices = 0

        # Process vertices in the queue
        while q:
            current = q.pop(0)  # Get the next vertex
            answer.append(current)  # Add it to the topological order
            processed_vertices += 1  # Increment the count of processed vertices

            # Decrease in-degree for adjacent vertices
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] = self.in_degree[adjacent] - 1
                # If in-degree becomes 0, add it to the queue
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)

        # Check for cycles in the graph
        if processed_vertices != len(self.graph.get_vertices()):
            raise ValueError("Graph contains a cycle, topological sort not possible")
        return answer  # Return the topologically sorted order

# Main function to execute the topological sort
def main():
    # Read number of vertices and edges from input
    vertices = int(input())
    edges = int(input())
    # Create a new adjacency list for the graph
    graph = AdjacencyList()
    # Read edges and add them to the graph
    for i in range(edges):
        from_vertex = input()
        to_vertex = input()
        graph.add_edge(from_vertex, to_vertex)
    # Create a TopologicalSort object with the graph
    top_sort = TopologicalSort(graph)
    try:
        # Get the topological order of the graph
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        # Print the sorted order
        for vertex in sorted_order:
            print(vertex, end=" ")
        print()
    except ValueError as e:
        # Handle the case where the graph has a cycle
        print(e)

if __name__ == "__main__":
    main()

