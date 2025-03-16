
import sys

def main():
    # Initialize scanner to read input
    sc = Scanner(sys.stdin)
    
    # Read the number of nodes and edges from input
    numNode = sc.nextInt()
    numEdge = sc.nextInt()
    
    # Create an adjacency list to represent the graph
    connect = [[] for _ in range(numNode)]
    
    # Read edges and populate the adjacency list
    for _ in range(numEdge):
        a = sc.nextInt() - 1
        b = sc.nextInt() - 1
        connect[a].append(b)
        connect[b].append(a)
    
    # Check if the number of edges is odd; if so, output -1 and exit
    if numEdge % 2!= 0:
        print(-1)
        return
    
    # Initialize arrays for tracking visited nodes and odd/even connections
    visited = [0] * numNode
    odd = [False] * numNode
    print = [] # List to accumulate output
    
    # Perform depth-first search starting from node 0
    dfs(0, -1)
    
    # Output the result
    for edge in print:
        print(edge[0], edge[1])

# Depth-first search method to explore the graph
def dfs(crt, parent):
    visited[crt] = 1 # Mark the current node as visited
    crtConnect = connect[crt] # Get the current node's connections
    
    # Iterate through each child node connected to the current node
    for child in crtConnect:
        # Skip the parent node and already visited nodes
        if child == parent or visited[child] == 1:
            continue
        elif visited[child] == 2:
            # If the child has been fully processed, append the edge to output
            print.append((crt + 1, child + 1))
            odd[crt] = not odd[crt] # Toggle the odd/even state
        else:
            # Recursively call DFS on the child node
            dfs(child, crt)
            
            # Check the odd/even state of the child node after DFS
            if odd[child]:
                print.append((child + 1, crt + 1))
                odd[child] = not odd[child] # Toggle the state
            else:
                print.append((crt + 1, child + 1))
                odd[crt] = not odd[crt] # Toggle the state
    
    visited[crt] = 2 # Mark the current node as fully processed

# Call the main function
main()
