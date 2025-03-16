
#!/usr/bin/env python3

import sys

# Function to print the edges of the graph in a readable format
def printEdge(e):
    for i in range(1, len(e)):
        print(i, ": ", end="")
        for v in e[i]:
            print(v, end=" ")
        print()

# Depth-First Search (DFS) function to count connected components in the graph
def dfs(v, visited):
    # Mark the current node as visited
    # print(v, visited)

    # Check if all nodes are visited
    comp = True
    for i in range(1, len(visited)):
        if not visited[i]:
            comp = False

    if comp:
        return 1

    count = 0
    for ne in e[v]:
        # print("ne=", ne)
        if visited[ne]:
            continue
        visited[ne] = True
        # if cmp, _ := dfs(ne, visited, count); cmp:
        #     count += 1
        count += dfs(ne, visited)
        visited[ne] = False
    return count

# Main function to read input, initialize the graph, and perform DFS
def main():
    n, m = map(int, input().split())

    # Initialize the graph edges
    e = [[] for i in range(n+1)]

    # Read the edges and populate the graph
    for i in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)
    # printEdge(e)

    # Initialize visited slice and start DFS from node 1
    visited = [False for i in range(n+1)]
    visited[1] = True
    count = dfs(1, visited)
    print(count)

if __name__ == "__main__":
    main()

