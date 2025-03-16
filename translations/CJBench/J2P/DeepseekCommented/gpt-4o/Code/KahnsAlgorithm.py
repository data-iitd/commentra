from collections import defaultdict, deque

# AdjacencyList class to represent a graph using an adjacency list
class AdjacencyList:
    # Constructor to initialize the adjacency list
    def __init__(self):
        self.adj = defaultdict(list)

    # Method to add an edge between two vertices
    def add_edge(self, from_v, to_v):
        # Ensure the from vertex is in the adjacency list
        self.adj[from_v].append(to_v)
        # Ensure the to vertex is in the adjacency list
        if to_v not in self.adj:
            self.adj[to_v] = []

    # Method to get the adjacent vertices of a given vertex
    def get_adjacents(self, v):
        return self.adj[v]

    # Method to get all the vertices in the graph
    def get_vertices(self):
        return list(self.adj.keys())

# TopologicalSort class to perform topological sort on a graph
class TopologicalSort:
    # Constructor to initialize the topological sort object with a graph
    def __init__(self, graph):
        self.graph = graph
        self.in_degree = defaultdict(int)

    # Method to calculate the in-degree of each vertex
    def calculate_in_degree(self):
        for vertex in self.graph.get_vertices():
            for adjacent in self.graph.get_adjacents(vertex):
                self.in_degree[adjacent] += 1

    # Method to return the vertices in topological order
    def top_sort_order(self):
        self.calculate_in_degree()  # Calculate in-degrees of all vertices
        queue = deque()
        # Add all vertices with in-degree 0 to the queue
        for vertex, degree in self.in_degree.items():
            if degree == 0:
                queue.append(vertex)
        sorted_order = []
        processed_vertices = 0
        # Process vertices from the queue
        while queue:
            current = queue.popleft()
            sorted_order.append(current)
            processed_vertices += 1
            for adjacent in self.graph.get_adjacents(current):
                self.in_degree[adjacent] -= 1
                if self.in_degree[adjacent] == 0:
                    queue.append(adjacent)
        # If not all vertices were processed, a cycle exists
        if processed_vertices != len(self.graph.get_vertices()):
            raise ValueError("Graph contains a cycle, topological sort not possible")
        return sorted_order

# Main class to run the topological sort program
class Main:
    @staticmethod
    def main():
        vertices = int(input())  # Read the number of vertices
        edges = int(input())  # Read the number of edges
        graph = AdjacencyList()
        for _ in range(edges):
            from_v, to_v = input().split()  # Read the from and to vertices
            graph.add_edge(from_v, to_v)  # Add an edge between the vertices
        top_sort = TopologicalSort(graph)
        try:
            sorted_order = top_sort.top_sort_order()
            print("Topological Order:")
            print(" ".join(sorted_order))  # Print the sorted order of vertices
        except ValueError as e:
            print(e)  # Print an error message if a cycle is detected

Main.main()
