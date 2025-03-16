
import sys

def btrack(adjList, visited, dfsCallsNodes, currentNode):
    # Mark the current node as visited
    visited[currentNode] = 1

    # Get the list of neighbors for the current node
    neighbors = adjList.get(currentNode)

    # If the current node has neighbors, iterate through them and call recursively
    if neighbors != None:
        for neighbor in neighbors:
            # If the neighbor is not visited, call btrack recursively
            if visited[neighbor] == -1:
                btrack(adjList, visited, dfsCallsNodes, neighbor)

    # Add the current node to the stack of DFS call nodes
    dfsCallsNodes.append(currentNode)

def btrack2(adjRevList, visited, currentNode, newScc):
    # Mark the current node as visited
    visited[currentNode] = 1

    # Add the current node to the list of nodes in the current strongly connected component
    newScc.append(currentNode)

    # Get the list of neighbors for the current node
    neighbors = adjRevList.get(currentNode)

    # If the current node has neighbors, iterate through them and call recursively
    if neighbors != None:
        for neighbor in neighbors:
            # If the neighbor is not visited, call btrack2 recursively
            if visited[neighbor] == -1:
                btrack2(adjRevList, visited, neighbor, newScc)

def getOutput(adjList, n):
    # Initialize the visited array and fill it with -1
    visited = [-1] * n

    # Initialize the stack for DFS call nodes
    dfsCallsNodes = []

    # Iterate through all nodes in the graph and call btrack for each unvisited node
    for i in range(n):
        if visited[i] == -1:
            btrack(adjList, visited, dfsCallsNodes, i)

    # Initialize an empty HashMap for the reversed adjacency list
    adjRevList = {}

    # Initialize the visited array and fill it with -1
    visited = [-1] * n

    # Initialize an empty list to store the nodes in each strongly connected component
    newScc = []

    # Initialize the counter for the number of strongly connected components
    stronglyConnectedComponents = 0

    # While there are still nodes in the stack of DFS call nodes
    while len(dfsCallsNodes) > 0:
        # Get the next node from the stack
        node = dfsCallsNodes.pop()

        # If the node is not visited, call btrack2 recursively and increment the counter
        if visited[node] == -1:
            btrack2(adjRevList, visited, node, newScc)
            stronglyConnectedComponents += 1

    # Return the number of strongly connected components
    return stronglyConnectedComponents

# Main method to read input and call getOutput method
if __name__ == "__main__":
    # Initialize the Scanner to read input from the console
    scanner = sys.stdin

    try:
        # Read the number of nodes and edges from the input
        n = int(scanner.readline().strip())
        e = int(scanner.readline().strip())

        # Initialize the adjacency list for the graph
        adjList = {}

        # Read the edges and add them to the adjacency list
        for i in range(e):
            src, dest = map(int, scanner.readline().strip().split())
            adjList.setdefault(src, []).append(dest)

        # Create an instance of the Main class and call the getOutput method
        result = getOutput(adjList, n)

        # Print the result to the console
        print("Number of strongly connected components: " + str(result))
    except ValueError:
        # Print an error message if the input is invalid
        print("Invalid input. Please provide integers as input.")
    finally:
        # Close the Scanner
        scanner.close()

