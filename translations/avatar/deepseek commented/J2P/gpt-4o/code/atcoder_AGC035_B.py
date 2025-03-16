import sys
from collections import defaultdict

def dfs(crt, parent):
    visited[crt] = 1  # Marking the current node as visited
    crt_connect = connect[crt]  # Getting the adjacency list of the current node

    # Traversing each child node of the current node
    for child in crt_connect:
        if child == parent or visited[child] == 1:  # Skipping if the child is the parent or already visited
            continue
        elif visited[child] == 2:  # Handling the case where the child is part of an already visited cycle
            print(f"{crt + 1} {child + 1}")  # Outputting the edge
            odd[crt] = not odd[crt]
        else:  # Recursively calling dfs for unvisited child nodes
            dfs(child, crt)
            if odd[child]:  # Updating the print and odd arrays based on the child's result
                print(f"{child + 1} {crt + 1}")  # Outputting the edge
                odd[child] = not odd[child]
            else:
                print(f"{crt + 1} {child + 1}")  # Outputting the edge
                odd[crt] = not odd[crt]

    visited[crt] = 2  # Marking the current node as fully processed

# Main function
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    
    numNode, numEdge = map(int, data[0].split())  # Reading the number of nodes and edges

    # Initializing adjacency lists for each node
    connect = defaultdict(list)

    # Reading edges and populating the adjacency lists
    for i in range(1, numEdge + 1):
        a, b = map(int, data[i].split())
        connect[a - 1].append(b - 1)  # Adding edge from a to b
        connect[b - 1].append(a - 1)  # Adding edge from b to a

    # Checking if the number of edges is odd
    if numEdge % 2 != 0:
        print(-1)  # Printing -1 if the number of edges is odd
    else:
        # Initializing arrays for DFS
        visited = [0] * numNode
        odd = [False] * numNode

        # Performing DFS starting from node 0
        dfs(0, -1)

# <END-OF-CODE>
