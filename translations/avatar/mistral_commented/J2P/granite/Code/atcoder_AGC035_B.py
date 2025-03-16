

import sys

# Reading the number of nodes and edges from the input.
numNode, numEdge = map(int, input().split())

# Initializing the connect dictionary to store the list of neighbors for each node.
connect = {i: [] for i in range(numNode)}

# Reading the edges and adding them to the connect dictionary.
for _ in range(numEdge):
    a, b = map(int, input().split())
    connect[a-1].append(b-1)
    connect[b-1].append(a-1)

# Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
if numEdge % 2!= 0:
    print(-1)
    sys.exit()

# Initializing the visited, odd, and print lists and objects.
visited = [0] * numNode
odd = [False] * numNode
print = []

# Recursive depth-first search method to perform bipartite traversal.
def dfs(crt, parent):
    # Marking the current node as visited.
    visited[crt] = 1

    # Iterating through the neighbors of the current node.
    for child in connect[crt]:
        # Skipping the neighbor if it is the parent node or already visited.
        if child == parent or visited[child] == 1:
            continue

        # If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        # Otherwise, we swap the components and continue the traversal.
        if visited[child] == 2:
            print.append((crt+1, child+1))
            odd[crt] = not odd[crt]
        else:
            dfs(child, crt)
            if odd[child]:
                print.append((child+1, crt+1))
                odd[child] = not odd[child]
            else:
                print.append((crt+1, child+1))
                odd[crt] = not odd[crt]

    # Marking the current node as visited with component 2.
    visited[crt] = 2

# Calling the dfs method with the first node and -1 as the parent node.
dfs(0, -1)

# Printing the output.
for edge in print:
    print(*edge)

These comments should provide a clear understanding of the logic behind each block of code in the given Python program.