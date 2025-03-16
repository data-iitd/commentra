import sys

# Class to represent a strongly connected component
class SCC:
    def __init__(self):
        self.vertices = []

# Class to represent a graph
class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = []
        for i in range(vertices):
            self.graph.append([])

    # Method to add an edge to the graph
    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Method to find strongly connected components
    def strongly_connected_components(self):
        # Initialize arrays and stack
        low_time = [0] * self.vertices
        insertion_time = [0] * self.vertices
        in_stack = [False] * self.vertices
        stack = []

        # Initialize arrays with default values
        for i in range(self.vertices):
            insertion_time[i] = -1
            low_time[i] = -1

        # Iterate through each vertex that hasn't been processed yet
        for i in range(self.vertices):
            if insertion_time[i] == -1:
                # Call depth-first search recursively
                self.dfs(i, low_time, insertion_time, in_stack, stack, self.graph)

        # Return the list of strongly connected components
        return self.get_sccs()

    # Depth-first search method
    def dfs(self, u, low_time, insertion_time, in_stack, stack, graph):
        # Set the insertion time and low time for the current vertex
        insertion_time[u] = len(stack)
        low_time[u] = len(stack)
        stack.append(u)

        # Set the vertex as in the stack
        in_stack[u] = True

        # Iterate through the neighbors of the current vertex
        for v in graph[u]:
            # If the neighbor hasn't been processed yet
            if insertion_time[v] == -1:
                # Call depth-first search recursively for the neighbor
                self.dfs(v, low_time, insertion_time, in_stack, stack, graph)

                # Update the low time for the current vertex
                low_time[u] = min(low_time[u], low_time[v])
            else if in_stack[v]:
                # Update the low time for the current vertex if it's in the stack
                low_time[u] = min(low_time[u], insertion_time[v])

        # If the low time equals the insertion time, a strongly connected component has been found
        if low_time[u] == insertion_time[u]:
            # Create a new strongly connected component
            scc = SCC()

            # Pop vertices from the stack until the current vertex is reached
            w = stack.pop()
            while w!= u:
                scc.vertices.append(w)
                w = stack.pop()

            # Add the strongly connected component to the list
            scc.vertices.append(u)
            self.sccs.append(scc)

    # Method to get the list of strongly connected components
    def get_sccs(self):
        return self.sccs

# Main method to read input and call the strongly connected components method
if __name__ == '__main__':
    # Read the number of vertices and edges from the console
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())

    # Create an empty graph
    graph = Graph(vertices)

    # Read edges from the console and add them to the graph
    for i in range(edges):
        u, v = map(int, sys.stdin.readline().strip().split())
        graph.add_edge(u, v)

    # Call the strongly connected components method
    sccs = graph.strongly_connected_components()

    # Print the strongly connected components
    for scc in sccs:
        print(scc.vertices)

