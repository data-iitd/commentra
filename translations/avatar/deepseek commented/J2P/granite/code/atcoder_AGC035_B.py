
import sys

def main():
    numNode, numEdge = map(int, input().split()) # Reading the number of nodes and edges
    connect = [[] for _ in range(numNode)] # Initializing adjacency lists for each node
    
    # Reading edges and populating the adjacency lists
    for _ in range(numEdge):
        a, b = map(int, input().split()) # Reading node a and b
        connect[a - 1].append(b - 1) # Adding edge from a to b
        connect[b - 1].append(a - 1) # Adding edge from b to a
    
    # Checking if the number of edges is odd
    if numEdge % 2!= 0:
        print(-1) # Printing -1 if the number of edges is odd
        return # Returning from the main function
    
    # Initializing arrays for DFS
    visited = [0] * numNode
    odd = [False] * numNode
    print = []
    
    # Performing DFS starting from node 0
    dfs(0, -1)
    
    # Outputting the result
    print("\n".join(map(str, print)))

# DFS method to traverse the graph
def dfs(crt, parent):
    visited[crt] = 1 # Marking the current node as visited
    crtConnect = connect[crt] # Getting the adjacency list of the current node
    
    # Traversing each child node of the current node
    for child in crtConnect:
        if child == parent or visited[child] == 1: # Skipping if the child is the parent or already visited
            continue
        elif visited[child] == 2: # Handling the case where the child is part of an already visited cycle
            print.append((crt + 1, child + 1))
            odd[crt] = not odd[crt]
        else: # Recursively calling dfs for unvisited child nodes
            dfs(child, crt)
            if odd[child]: # Updating the print and odd arrays based on the child's result
                print.append((child + 1, crt + 1))
                odd[child] = not odd[child]
            else:
                print.append((crt + 1, child + 1))
                odd[crt] = not odd[crt]
    
    visited[crt] = 2 # Marking the current node as fully processed

if __name__ == "__main__":
    main()

