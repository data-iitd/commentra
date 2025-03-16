import sys
import collections

def btrack(adjList, visited, dfsCallsNodes, currentNode):
    visited[currentNode] = 1 # Mark the current node as visited
    neighbors = adjList.get(currentNode)
    if neighbors != None:
        for neighbor in neighbors:
            if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack
                btrack(adjList, visited, dfsCallsNodes, neighbor)
    dfsCallsNodes.append(currentNode) # Push the current node onto the stack after exploring all neighbors

def btrack2(adjRevList, visited, currentNode, newScc):
    visited[currentNode] = 1 # Mark the current node as visited
    newScc.append(currentNode) # Add the current node to the current SCC
    neighbors = adjRevList.get(currentNode)
    if neighbors != None:
        for neighbor in neighbors:
            if visited[neighbor] == -1: # If the neighbor is not visited, recursively call btrack2
                btrack2(adjRevList, visited, neighbor, newScc)

def getOutput(adjList, n):
    visited = [-1] * n
    dfsCallsNodes = []
    for i in range(n):
        if visited[i] == -1: # If the node is not visited, start DFS from it
            btrack(adjList, visited, dfsCallsNodes, i)
    adjRevList = collections.defaultdict(list)
    for i in range(n):
        adjRevList[i] = [] # Initialize the reversed adjacency list
    for i in range(n):
        neighbors = adjList.get(i)
        if neighbors != None:
            for neighbor in neighbors:
                adjRevList[neighbor].append(i) # Reverse the edges to create the reversed adjacency list
    visited = [-1] * n
    stronglyConnectedComponents = 0
    while dfsCallsNodes:
        node = dfsCallsNodes.pop()
        if visited[node] == -1: # If the node is not visited, start a new SCC search from it
            newScc = []
            btrack2(adjRevList, visited, node, newScc)
            stronglyConnectedComponents += 1 # Increment the count of SCCs
    return stronglyConnectedComponents # Return the total number of SCCs

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip()) # Read the number of nodes
    e = int(sys.stdin.readline().strip()) # Read the number of edges
    adjList = collections.defaultdict(list)
    for i in range(e):
        src = int(sys.stdin.readline().strip()) # Read the source node
        dest = int(sys.stdin.readline().strip()) # Read the destination node
        adjList[src].append(dest) # Construct the adjacency list
    result = getOutput(adjList, n)
    print("Number of strongly connected components: " + str(result)) # Print the result
