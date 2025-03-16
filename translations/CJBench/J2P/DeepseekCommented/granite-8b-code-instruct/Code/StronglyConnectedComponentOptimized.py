
import sys

class Main:
    def btrack(self, adjList, visited, dfsCallsNodes, currentNode):
        visited[currentNode] = 1 # Mark the current node as visited
        neighbors = adjList.get(currentNode, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack
                self.btrack(adjList, visited, dfsCallsNodes, neighbor)
        dfsCallsNodes.append(currentNode) # Push the current node onto the stack after exploring all neighbors

    def btrack2(self, adjRevList, visited, currentNode, newScc):
        visited[currentNode] = 1 # Mark the current node as visited
        newScc.append(currentNode) # Add the current node to the current SCC
        neighbors = adjRevList.get(currentNode, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack2
                self.btrack2(adjRevList, visited, neighbor, newScc)

    def getOutput(self, adjList, n):
        visited = [-1] * n # Initialize visited array with -1 (unvisited)
        dfsCallsNodes = []
        for i in range(n):
            if visited[i] == -1: # If the node is not visited, start DFS from it
                self.btrack(adjList, visited, dfsCallsNodes, i)
        adjRevList = {}
        for i in range(n):
            adjRevList[i] = [] # Initialize the reversed adjacency list
        for i in range(n):
            neighbors = adjList.get(i, [])
            for neighbor in neighbors:
                adjRevList[neighbor].append(i) # Reverse the edges to create the reversed adjacency list
        visited = [-1] * n # Reset the visited array for the second DFS traversal
        stronglyConnectedComponents = 0
        while dfsCallsNodes:
            node = dfsCallsNodes.pop()
            if visited[node] == -1: # If the node is not visited, start a new SCC search from it
                newScc = []
                self.btrack2(adjRevList, visited, node, newScc)
                stronglyConnectedComponents += 1 # Increment the count of SCCs
        return stronglyConnectedComponents # Return the total number of SCCs

    def main(self):
        n = int(input("Enter the number of nodes: ")) # Read the number of nodes
        e = int(input("Enter the number of edges: ")) # Read the number of edges
        adjList = {}
        for i in range(e):
            src, dest = map(int, input("Enter the source and destination nodes for edge {}: ".format(i+1)).split())
            adjList[src] = adjList.get(src, []) + [dest] # Construct the adjacency list
        sccFinder = Main()
        result = sccFinder.getOutput(adjList, n)
        print("Number of strongly connected components: ", result) # Print the result

if __name__ == "__main__":
    Main().main()

