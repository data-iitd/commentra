from collections import defaultdict, deque

# Define a generic AdjacencyList class for comparable elements
class AdjacencyList:
    def __init__(self):
        self.adj = defaultdict(list)  # Store the adjacency list as a dictionary of vertices to their adjacent vertices

    # Add an edge between two vertices
    def add_edge(self, from_vertex, to_vertex):
        self.adj[from_vertex].append(to_vertex)  # Add to the list of adjacents for from
        if to_vertex not in self.adj:  # Ensure to_vertex is also in the adjacency list
            self.adj[to_vertex] = []

    # Get the list of adjacent vertices for a given vertex
    def get_adjacents(self, vertex):
        return self.adj[vertex]

    # Get all the vertices in the graph
    def get_vertices(self):
        return self.adj.keys()

# Define a generic TopologicalSort class for comparable elements
class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph  # Store the graph to be sorted
        self.in_degree = {}  # Store the in-degree for each vertex

    # Calculate the in-degree for each vertex
    def calculate_in_degree(self):
        for vertex in self.graph.get_vertices():
            self.in_degree[vertex] = 0  # Initialize the in-degree for each vertex to 0
        for vertex in self.graph.get_vertices():
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] = self.in_degree.get(adjacent, 0) + 1  # Increment the in-degree for each adjacent

    # Perform the topological sort
    def top_sort_order(self):
        self.calculate_in_degree()  # Calculate the in-degree for all vertices
        q = deque()  # Create a queue to store vertices with 0 in-degree
        answer = []  # Create an empty list to store the topological order

        # Add all vertices with 0 in-degree to the queue
        for vertex, degree in self.in_degree.items():
            if degree == 0:
                q.append(vertex)

        # Process vertices in the order they are removed from the queue
        while q:
            current = q.popleft()  # Get the next vertex with 0 in-degree
            answer.append(current)  # Add it to the answer
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1  # Decrease the in-degree for each adjacent
                if self.in_degree[adjacent] == 0:
                    q.append(adjacent)  # Add it to the queue if its in-degree is now 0

        # Throw an exception if there is a cycle in the graph
        if len(answer) != len(self.graph.get_vertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")

        return answer

# Main function to read input and call the topological sort algorithm
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    vertices = int(data[0])  # Read the number of vertices
    edges = int(data[1])  # Read the number of edges

    graph = AdjacencyList()  # Create an empty graph
    for i in range(2, 2 + edges):
        from_vertex, to_vertex = data[i].split()  # Read the source and destination vertices
        graph.add_edge(from_vertex, to_vertex)  # Add an edge between the vertices

    top_sort = TopologicalSort(graph)  # Create a new topological sort object

    try:
        sorted_order = top_sort.top_sort_order()  # Perform the topological sort
        print("Topological Order:")  # Print the header for the output
        print(" ".join(sorted_order))  # Print each vertex in the topological order
    except Exception as e:
        print(e)  # Print an error message if there is a cycle in the graph

# <END-OF-CODE>
