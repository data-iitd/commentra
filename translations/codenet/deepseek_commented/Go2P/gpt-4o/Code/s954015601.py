# 深さ優先探索
import sys
from collections import defaultdict

# genid generates a unique identifier for an edge between two nodes.
def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

def main():
    # Read the number of nodes from standard input.
    N = read_int()

    # Initialize a list to store edges and an adjacency list for the graph.
    ab = []
    edges = defaultdict(list)
    for _ in range(N - 1):
        # Read edge information and populate the adjacency list.
        a = read_int() - 1
        b = read_int() - 1
        ab.append((a, b))
        edges[a].append(b)
        edges[b].append(a)

    # Initialize a dictionary to store the color of each edge and a stack for DFS traversal.
    colors = {}
    stack = [(0, -1, -1)]
    while stack:
        # Pop the last element from the stack for DFS traversal.
        current_node, used_color, parent_node = stack.pop()
        color = 1
        for child_node in edges[current_node]:
            if child_node == parent_node:
                continue
            if color == used_color:
                color += 1
            colors[genid(current_node, child_node)] = color
            stack.append((child_node, color, current_node))
            color += 1

    # Determine the maximum degree of any node in the graph.
    K = -1
    for i in range(N):
        t = len(edges[i])
        if t > K:
            K = t
    print(K)

    # Output the colors of the edges.
    for a, b in ab:
        print(colors[genid(a, b)])

def read_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
