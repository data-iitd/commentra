import sys

def btrack(adjList, visited, dfsCallsNodes, currentNode):
    # Mark the current node as visited
    visited[currentNode] = 1
    # Get the neighbors of the current node
    neighbors = adjList.get(currentNode)
    # Explore each neighbor that has not been visited
    if neighbors is not None:
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                btrack(adjList, visited, dfsCallsNodes, neighbor)
    # Add the current node to the stack after exploring all its neighbors
    dfsCallsNodes.append(currentNode)

def btrack2(adjRevList, visited, currentNode, newScc):
    # Mark the current node as visited
    visited[currentNode] = 1
    # Add the current node to the current strongly connected component
    newScc.append(currentNode)
    # Get the neighbors of the current node in the reverse graph
    neighbors = adjRevList.get(currentNode)
    # Explore each neighbor that has not been visited
    if neighbors is not None:
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                btrack2(adjRevList, visited, neighbor, newScc)

def getOutput(adjList, n):
    # Initialize visited array and stack for DFS
    visited = [-1] * n
    dfsCallsNodes = []
    
    # Perform DFS on each node to fill the stack with the finishing order
    for i in range(n):
        if visited[i] == -1:
            btrack(adjList, visited, dfsCallsNodes, i)

    # Create the reverse graph
    adjRevList = {}
    for i in range(n):
        adjRevList[i] = []
    # Populate the reverse graph
    for i in range(n):
        neighbors = adjList.get(i)
        if neighbors is not None:
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
            btrack2(adjRevList, visited, node, newScc)
            stronglyConnectedComponents += 1
    # Return the total number of strongly connected components found
    return stronglyConnectedComponents

if __name__ == "__main__":
    try:
        # Read number of nodes and edges from input
        n = int(input())
        e = int(input())
        adjList = {}
        # Build the adjacency list from input edges
        for i in range(e):
            src = int(input())
            dest = int(input())
            adjList.setdefault(src, [])
            adjList[src].append(dest)
        # Create an instance of the SCC finder and get the result
        sccFinder = Main()
        result = sccFinder.getOutput(adjList, n)
        # Output the number of strongly connected components
        print("Number of strongly connected components: " + str(result))
    except ValueError:
        # Handle invalid input
        print("Invalid input. Please provide integers as input.")
    except:
        # Handle unexpected errors
        print("Unexpected error.")
    finally:
        # Close the scanner to prevent resource leaks
        pass

