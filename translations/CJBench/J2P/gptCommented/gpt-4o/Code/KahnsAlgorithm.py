from collections import defaultdict, deque

# Class representing an adjacency list for a directed graph
class AdjacencyList:
    def __init__(self):
        # Dictionary to hold the adjacency list representation of the graph
        self.adj = defaultdict(list)

    # Method to add a directed edge from 'from' to 'to'
    def add_edge(self, from_vertex, to_vertex):
        # Add 'to' vertex to the adjacency list of 'from'
        self.adj[from_vertex].append(to_vertex)
        # Ensure 'to' vertex is present in the adjacency list
        if to_vertex not in self.adj:
            self.adj[to_vertex] = []

    # Method to get the list of adjacent vertices for a given vertex
    def get_adjacents(self, vertex):
        return self.adj[vertex]

    # Method to get all vertices in the graph
    def get_vertices(self):
        return self.adj.keys()

# Class to perform topological sorting on a directed graph
class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
        self.in_degree = {}

    # Method to calculate the in-degree of each vertex in the graph
    def calculate_in_degree(self):
        # Initialize in-degree for each vertex
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0
        # Update in-degree for adjacent vertices
        for vertex in self.graph.get_vertices():
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] += 1

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
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer  # Return the topologically sorted order

# Main function to execute the topological sort
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Read number of vertices and edges from input
    vertices, edges = map(int, data[0].split())
    # Create a new adjacency list for the graph
    graph = AdjacencyList()
    # Read edges and add them to the graph
    for i in range(1, edges + 1):
        from_vertex, to_vertex = data[i].split()
        graph.add_edge(from_vertex, to_vertex)
    
    # Create a TopologicalSort object with the graph
    top_sort = TopologicalSort(graph)
    try:
        # Get the topological order of the graph
        sorted_order = top_sort.top_sort_order()
        print("Topological Order:")
        # Print the sorted order
        print(" ".join(sorted_order))
    except Exception as e:
        # Handle the case where the graph has a cycle
        print(e)

# <END-OF-CODE>
