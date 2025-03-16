import sys

# Class to represent a graph
class Graph:
    # Constructor to initialize the graph
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
        for i in range(self.V):
            self.graph.append([])

    # Function to add an edge to the graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

    # Function to find strongly connected components in the graph
    def stronglyConnectedComponents(self):
        # Array to store the low time and insertion time of each vertex
        lowTime = [0] * self.V
        # Array to store the parent of each vertex
        parent = [0] * self.V
        # Array to store the visited status of each vertex
        visited = [False] * self.V
        # List to store the strongly connected components
        sccList = []

        # Initialize the parent of each vertex
        for i in range(self.V):
            parent[i] = -1

        # Function to find the Strongly Connected Components
        def dfs(u, lowTime, parent, visited, sccList):
            # Set the visited status of the current vertex
            visited[u] = True
            # Set the low time of the current vertex
            lowTime[u] = time
            # Increment the time
            time += 1
            # Push the current vertex onto the stack
            stack.append(u)
            # Explore all adjacent vertices
            for v in self.graph[u]:
                # If the vertex has not been visited, perform DFS on it
                if not visited[v]:
                    parent[v] = u
                    dfs(v, lowTime, parent, visited, sccList)
                    # Update the low time of the current vertex
                    lowTime[u] = min(lowTime[u], lowTime[v])
                # If the vertex is in the stack, update the low time
                elif v in stack:
                    lowTime[u] = min(lowTime[u], lowTime[v])

            # If the current vertex is a root node, pop the stack and form an SCC
            if lowTime[u] == time:
                scc = []
                v = stack.pop()
                while v!= u:
                    # Pop from the stack and add to the current SCC
                    scc.append(v)
                    v = stack.pop()
                # Add the found SCC to the list of SCCs
                sccList.append(scc)

        # Perform DFS for each vertex that has not been visited
        time = 0
        stack = []
        for i in range(self.V):
            if not visited[i]:
                dfs(i, lowTime, parent, visited, sccList)

        # Return the list of strongly connected components
        return sccList

# Main method to read input and execute the algorithm
if __name__ == '__main__':
    # Read the number of vertices and edges
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    # Initialize the graph as an adjacency list
    graph = Graph(vertices)
    for i in range(edges):
        u, v = map(int, sys.stdin.readline().strip().split())
        graph.addEdge(u, v)
    # Create an instance of the Graph class and find SCCs
    sccs = graph.stronglyConnectedComponents()

    # Print the strongly connected components
    for scc in sccs:
        print(scc)

