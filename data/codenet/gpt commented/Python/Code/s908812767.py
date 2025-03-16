# -*- coding: utf-8 -*-
# https://atcoder.jp/contests/abc126/tasks/abc126_d

import sys
# Set the maximum recursion limit to handle deep recursions
sys.setrecursionlimit(100000)

def dfs(i):
    # Perform a depth-first search starting from vertex i
    for v, w in V.get(i, []):
        # Check if the edge weight is even
        if (w % 2) == 0:
            # If the adjacent vertex has not been colored, color it the same as the current vertex
            if color[v] == -1:
                color[v] = color[i]
            # If the adjacent vertex is colored the same as the current vertex, continue
            elif color[v] == color[i]:
                continue
            # If the adjacent vertex is colored differently, return False (not bipartite)
            elif color[v] != color[i]:
                return False
        else:
            # If the edge weight is odd
            if color[v] == -1:
                # Color the adjacent vertex with the opposite color
                color[v] = 0 if color[i] else 1
            # If the adjacent vertex is colored the same as the current vertex, return False
            elif color[v] == color[i]:
                return False
            # If the adjacent vertex is colored differently, continue
            elif color[v] != color[i]:
                continue
        # Recursively call dfs for the adjacent vertex
        dfs(v)
    return True

if __name__ == '__main__':
    # Read the number of vertices
    n = int(input())
    # Initialize the graph as an adjacency list
    V = {}  # key: vertex, value: [[vertex opposite, weight]]
    # Initialize the color dictionary to keep track of vertex colors
    color = {}  # 0 or 1 or -1 (uncolored)
    
    # Read edges and construct the graph
    for i in range(1, n):
        u, v, w = map(int, input().split())
        # Add the edge from u to v
        if not V.get(u, False):
            V[u] = [[v, w]]
        else:
            V[u].append([v, w])

        # Add the edge from v to u (undirected graph)
        if not V.get(v, False):
            V[v] = [[u, w]]
        else:
            V[v].append([u, w])
        # Assume no multiple edges between the same vertices

    # Initialize all vertices as uncolored
    for i in range(1, n + 1):
        color[i] = -1

    while True:
        i = 0
        # Find the first uncolored vertex
        for j in range(1, n + 1):
            if color[j] == -1:
                i = j
                color[i] = 0  # Start coloring with 0
                break
        # If no uncolored vertex is found, print the colors and exit
        if i == 0:
            for j in range(1, n + 1):
                print(color[j])
            break
        else:
            # Perform DFS from the found uncolored vertex
            if not dfs(i):
                print('No')  # If the graph is not bipartite, print 'No'
                break
