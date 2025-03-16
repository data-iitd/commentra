# 深さ優先探索
import sys
from collections import defaultdict

# genid generates a unique identifier for an edge between two nodes a and b
# by ensuring a is less than b and combining them into a single integer.
def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

def main():
    # Read the number of nodes in the graph
    N = read_int()

    # Initialize a list to hold the edges and an adjacency list for the graph
    ab = [None] * (N - 1)
    edges = defaultdict(list)

    # Read edges from input and populate the adjacency list
    for i in range(N - 1):
        a = read_int() - 1  # Convert to zero-based index
        b = read_int() - 1  # Convert to zero-based index
        ab[i] = (a, b)
        edges[a].append(b)
        edges[b].append(a)

    # Map to store colors assigned to edges
    colors = {}
    # Stack for depth-first search (DFS) with current node, used color, and parent node
    q = [(0, -1, -1)]  # Start DFS from node 0 with no used color and no parent

    # Perform DFS to assign colors to edges
    while q:
        current_node, used_color, parent_node = q.pop()  # Pop the last element from the stack
        color = 1  # Start coloring from color 1

        # Iterate through child nodes of the current node
        for child_node in edges[current_node]:
            if child_node == parent_node:
                continue  # Skip the parent node to avoid backtracking
            if color == used_color:
                color += 1  # Skip the color that was used by the parent
            # Assign color to the edge between current_node and child_node
            colors[genid(current_node, child_node)] = color
            # Push the child node onto the stack for further exploration
            q.append((child_node, color, current_node))
            color += 1  # Move to the next color for the next edge

    # Find the maximum degree of any node in the graph
    K = -1
    for i in range(N):
        t = len(edges[i])  # Degree of the current node
        if t > K:
            K = t  # Update maximum degree if current node's degree is greater
    print(K)  # Print the maximum degree

    # Print the colors assigned to each edge
    for i in range(N - 1):
        print(colors[genid(ab[i][0], ab[i][1])])

# Constants for input buffer size
ioBufferSize = 1 * 1024 * 1024  # 1 MB

# read_int reads an integer from standard input and handles any conversion errors
def read_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
