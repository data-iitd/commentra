import sys
import collections

class Main:
    # Depth-first search (DFS) to explore the graph and track the order of nodes
    def btrack(self, adjList, visited, dfsCallsNodes, currentNode):
        # Mark the current node as visited
        visited[currentNode] = 1
        # Get the neighbors of the current node
        neighbors = adjList.get(currentNode)
        # Explore each neighbor that has not been visited
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1:
                    self.btrack(adjList, visited, dfsCallsNodes, neighbor)
        # Add the current node to the stack after exploring all its neighbors
        dfsCallsNodes.append(currentNode)

    # DFS for the reverse graph to find strongly connected components (SCCs)
    def btrack2(self, adjRevList, visited, currentNode, newScc):
        # Mark the current node as visited
        visited[currentNode] = 1
        # Add the current node to the current strongly connected component
        newScc.append(currentNode)
        # Get the neighbors of the current node in the reverse graph
        neighbors = adjRevList.get(currentNode)
        # Explore each neighbor that has not been visited
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1:
                    self.btrack2(adjRevList, visited, neighbor, newScc)

    # Main function to compute the number of strongly connected components
    def getOutput(self, adjList, n):
        # Initialize visited array and stack for DFS
        visited = [-1] * n
        # Perform DFS on each node to fill the stack with the finishing order
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adjList, visited, [], i)
        # Create the reverse graph
        adjRevList = collections.defaultdict(list)
        for i in range(n):
            neighbors = adjList.get(i)
            if neighbors!= None:
                for neighbor in neighbors:
                    adjRevList[neighbor].append(i)
        # Reset visited array for the second DFS
        visited = [-1] * n
        stronglyConnectedComponents = 0
        # Process nodes in the order defined by the first DFS
        while len(dfsCallsNodes) > 0:
            node = dfsCallsNodes.pop()
            # If the node has not been visited, it starts a new SCC
            if visited[node] == -1:
                newScc = []
                self.btrack2(adjRevList, visited, node, newScc)
                stronglyConnectedComponents += 1
        # Return the total number of strongly connected components found
        return stronglyConnectedComponents

if __name__ == "__main__":
    # Read number of nodes and edges from input
    n = int(input())
    e = int(input())
    adjList = collections.defaultdict(list)
    # Build the adjacency list from input edges
    for i in range(e):
        src = int(input())
        dest = int(input())
        adjList[src].append(dest)
    # Create an instance of the SCC finder and get the result
    sccFinder = Main()
    result = sccFinder.getOutput(adjList, n)
    # Output the number of strongly connected components
    print("Number of strongly connected components: " + str(result))

