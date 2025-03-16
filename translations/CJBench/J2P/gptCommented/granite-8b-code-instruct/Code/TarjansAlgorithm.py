
import sys

class Main:
    # Variable to keep track of the time during DFS
    time = 0
    # List to store the strongly connected components
    sccList = []

    # Method to find strongly connected components using Tarjan's algorithm
    def stronglyConnectedComponents(self, v, graph):
        # Arrays to store the low time and insertion time of each vertex
        lowTime = [-1] * v
        insertionTime = [-1] * v
        # Boolean array to check if a vertex is in the stack
        isInStack = [False] * v
        # Stack to hold the vertices during DFS
        stack = []

        # Initialize insertion and low times for all vertices
        for i in range(v):
            if insertionTime[i] == -1:
                self.dfs(i, lowTime, insertionTime, isInStack, stack, graph)

        # Return the list of strongly connected components
        return self.sccList

    # Depth-First Search method to explore the graph and find SCCs
    def dfs(self, u, lowTime, insertionTime, isInStack, stack, graph):
        # Set the insertion and low time for the current vertex
        insertionTime[u] = self.time
        lowTime[u] = self.time
        self.time += 1
        # Push the current vertex onto the stack
        stack.append(u)
        isInStack[u] = True

        # Explore all adjacent vertices
        for v in graph[u]:
            # If the vertex has not been visited, perform DFS on it
            if insertionTime[v] == -1:
                self.dfs(v, lowTime, insertionTime, isInStack, stack, graph)
                # Update the low time of the current vertex
                lowTime[u] = min(lowTime[u], lowTime[v])
            # If the vertex is in the stack, update the low time
            elif isInStack[v]:
                lowTime[u] = min(lowTime[u], insertionTime[v])

        # If the current vertex is a root node, pop the stack and form an SCC
        if lowTime[u] == insertionTime[u]:
            scc = []
            w = -1
            while w!= u:
                # Pop from the stack and add to the current SCC
                w = stack.pop()
                isInStack[w] = False
                scc.append(w)
            # Add the found SCC to the list of SCCs
            self.sccList.append(scc)

    # Main method to read input and execute the algorithm
    def main(self):
        # Read the number of vertices and edges
        vertices, edges = map(int, input().split())
        # Initialize the graph as an adjacency list
        graph = [[] for _ in range(vertices)]
        # Read the edges and populate the graph
        for _ in range(edges):
            from_v, to_v = map(int, input().split())
            graph[from_v].append(to_v)

        # Create an instance of the Main class and find SCCs
        tarjans = Main()
        sccs = tarjans.stronglyConnectedComponents(vertices, graph)

        # Print the strongly connected components
        for scc in sccs:
            print(scc)

if __name__ == "__main__":
    Main().main()

