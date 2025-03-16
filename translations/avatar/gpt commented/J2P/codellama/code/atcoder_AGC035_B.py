
# Import modules
import sys

# Read input
numNode = int(sys.stdin.readline())
numEdge = int(sys.stdin.readline())

# Create an adjacency list to represent the graph
connect = [[] for _ in range(numNode)]

# Read edges and populate the adjacency list
for _ in range(numEdge):
    a, b = map(int, sys.stdin.readline().split())
    connect[a - 1].append(b - 1)
    connect[b - 1].append(a - 1)

# Check if the number of edges is odd; if so, output -1 and exit
if numEdge % 2 != 0:
    print(-1)
    sys.exit()

# Initialize arrays for tracking visited nodes and odd/even connections
visited = [0] * numNode
odd = [False] * numNode
print = ""

# Perform depth-first search starting from node 0
dfs(0, -1)

# Output the result
print(print)

# Declare global variables for the graph representation and state tracking
connect = [[] for _ in range(numNode)]
visited = [0] * numNode
odd = [False] * numNode
print = ""

# Depth-first search method to explore the graph
def dfs(crt, parent):
    visited[crt] = 1
    crtConnect = connect[crt]

    # Iterate through each child node connected to the current node
    for child in crtConnect:
        # Skip the parent node and already visited nodes
        if child == parent or visited[child] == 1:
            continue
        elif visited[child] == 2:
            # If the child has been fully processed, append the edge to output
            print += str(child + 1) + " " + str(crt + 1) + "\n"
            odd[crt] = not odd[crt]
        else:
            # Recursively call DFS on the child node
            dfs(child, crt)

            # Check the odd/even state of the child node after DFS
            if odd[child]:
                print += str(child + 1) + " " + str(crt + 1) + "\n"
                odd[child] = not odd[child]
            else:
                print += str(crt + 1) + " " + str(child + 1) + "\n"
                odd[crt] = not odd[crt]
    visited[crt] = 2

# END-OF-CODE
