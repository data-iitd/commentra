from collections import defaultdict, deque

# Class representing an adjacency list for a directed graph
class AdjacencyList:
    # Constructor to initialize the adjacency list
    def __init__(self):
        self.adj = defaultdict(list)

    # Method to add a directed edge from 'from' to 'to'
    def add_edge(self, from_vertex, to_vertex):
        # Ensure 'from' vertex is present in the adjacency list
        if from_vertex not in self.adj:
            self.adj[from_vertex] = []
        # Add 'to' vertex to the adjacency list of 'from'
        self.adj[from_vertex].append(to_vertex)
        # Ensure 'to' vertex is present in the adjacency list
        if to_vertex not in self.adj:
            self.adj[to_vertex] = []

    # Method to get the list of adjacent vertices for a given vertex
    def get_adjacents(self, v):
        return self.adj[v]

    # Method to get all vertices in the graph
    def get_vertices(self):
        return list(self.adj.keys())

# Class to perform topological sorting on a directed graph
class TopologicalSort:
    # The graph represented as an adjacency list
    def __init__(self, graph):
        self.graph = graph
        # Map to store the in-degree of each vertex
        self.in_degree = {}

    # Method to calculate the in-degree of each vertex in the graph
    def calculate_in_degree(self):
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] = self.in_degree.get(adjacent, 0) + 1

    # Method to perform topological sorting and return the sorted order
    def top_sort_order(self):
        # Calculate in-degrees of all vertices
        self.calculate_in_degree()
        # Queue to hold vertices with in-degree of 0
        q = deque()
        # Add all vertices with in-degree of 0 to the queue
        for vertex, degree in self.in_degree.items():
            if degree == 0:
                q.append(vertex)
        # List to hold the topological order
        answer = []
        processed_vertices = 0

        # Process vertices in the queue
        while q:
            current = q.popleft()  # Get the next vertex
            answer.append(current)  # Add it to the topological order
            processed_vertices += 1  # Increment the count of processed vertices

            # Decrease in-degree for adjacent vertices
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                # If in-degree becomes 0, add it to the queue
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)

        # Check for cycles in the graph
        if processed_vertices != len(self.graph.get_vertices()):
            raise ValueError("Graph contains a cycle, topological sort not possible")
        return answer  # Return the topologically sorted order

# Main class to execute the topological sort
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Main method to run the program
    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        # Read number of vertices and edges from input
        vertices = int(data[0])
        edges = int(data[1])
        # Create a new adjacency list for the graph
        graph = AdjacencyList()
        # Read edges and add them to the graph
        index = 2
        for i in range(edges):
            from_vertex = data[index]
            to_vertex = data[index + 1]
            graph.add_edge(from_vertex, to_vertex)
            index += 2
        # Create a TopologicalSort object with the graph
        top_sort = TopologicalSort(graph)
        try:
            # Get the topological order of the graph
            sorted_order = top_sort.top_sort_order()
            print("Topological Order:")
            # Print the sorted order
            for s in sorted_order:
                print(s, end=" ")
            print()
        except ValueError as e:
            # Handle the case where the graph has a cycle
            print(e)

# Execute the main method
Main.main()
