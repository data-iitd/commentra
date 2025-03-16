

import sys

def main():
    # Input the number of vertices
    v = int(input())

    # Adjacency list to represent the tree
    adj = [[] for _ in range(v)]

    # Input edges
    for _ in range(v - 1):
        from_v, to_v = map(int, input().split())
        adj[from_v].append(to_v)
        adj[to_v].append(from_v)

    # Array to store parent and depth of each vertex
    parent = [0] * v
    depth = [0] * v

    # Perform DFS to calculate parent and depth
    dfs(adj, 0, -1, parent, depth)

    # Input the two vertices whose Main is to be calculated
    v1, v2 = map(int, input().split())

    # Output the Main
    print(get_main(v1, v2, depth, parent))

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        if adjacent!= p:
            parent[adjacent] = s
            depth[adjacent] = 1 + depth[s]
            dfs(adj, adjacent, s, parent, depth)

def get_main(v1, v2, depth, parent):
    if depth[v1] < depth[v2]:
        v1, v2 = v2, v1
    while depth[v1]!= depth[v2]:
        v1 = parent[v1]
    if v1 == v2:
        return v1
    while v1!= v2:
        v1 = parent[v1]
        v2 = parent[v2]
    return v1

if __name__ == "__main__":
    main()

