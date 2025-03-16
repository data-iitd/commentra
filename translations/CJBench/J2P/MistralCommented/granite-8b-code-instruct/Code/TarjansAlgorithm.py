
import sys

class Main:
    # Constructor to initialize instance variables
    def __init__(self):
        self.time = 0
        self.sccList = []

    # Method to find strongly connected components
    def stronglyConnectedComponents(self, v, graph):
        # Initialize arrays and stack
        lowTime = [0] * v
        insertionTime = [0] * v
        isInStack = [False] * v
        stack = []

        # Iterate through each vertex that hasn't been processed yet
        for i in range(v):
            if insertionTime[i] == 0:
                # Call depth-first search recursively
                self.dfs(i, lowTime, insertionTime, isInStack, stack, graph)

        # Return the list of strongly connected components
        return self.sccList

    # Depth-first search method
    def dfs(self, u, lowTime, insertionTime, isInStack, stack, graph):
        # Set the insertion time and low time for the current vertex
        insertionTime[u] = self.time
        lowTime[u] = self.time
        self.time += 1

        # Push the current vertex onto the stack
        stack.append(u)

        # Set the vertex as in the stack
        isInStack[u] = True

        # Iterate through the neighbors of the current vertex
        for v in graph[u]:
            # If the neighbor hasn't been processed yet
            if insertionTime[v] == 0:
                # Call depth-first search recursively for the neighbor
                self.dfs(v, lowTime, insertionTime, isInStack, stack, graph)

                # Update the low time for the current vertex
                lowTime[u] = min(lowTime[u], lowTime[v])
            elif isInStack[v]:
                # Update the low time for the current vertex if it's in the stack
                lowTime[u] = min(lowTime[u], insertionTime[v])

        # If the low time equals the insertion time, a strongly connected component has been found
        if lowTime[u] == insertionTime[u]:
            # Create a new list for the strongly connected component
            scc = []

            # Pop vertices from the stack until the current vertex is reached
            while stack[-1]!= u:
                scc.append(stack.pop())

            # Add the strongly connected component to the list
            self.sccList.append(scc)

    # Main method to read input and call the strongly connected components method
    @staticmethod
    def main():
        # Read the number of vertices and edges from the console
        vertices, edges = map(int, sys.stdin.readline().split())

        # Create an empty list to store the graph
        graph = [[] for _ in range(vertices)]

        # Read edges from the console and add them to the graph
        for _ in range(edges):
            from_v, to_v = map(int, sys.stdin.readline().split())
            graph[from_v].append(to_v)

        # Create an instance of the Main class and call the strongly connected components method
        tarjans = Main()
        sccs = tarjans.stronglyConnectedComponents(vertices, graph)

        # Print the strongly connected components
        for scc in sccs:
            print(scc)

# Call the main method
Main.main()

