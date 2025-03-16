
import sys

def main():
    # Input the number of vertices
    v = int(sys.stdin.readline())

    # Adjacency list to represent the tree
    adj = [[] for _ in range(v)]

    # Input edges
    for i in range(v - 1):
        from_, to = map(int, sys.stdin.readline().split())
        adj[from_].append(to)
        adj[to].append(from_)

    # Array to store parent and depth of each vertex
    parent = [-1] * v
    depth = [0] * v

    # Perform DFS to calculate parent and depth
    dfs(adj, 0, -1, parent, depth)

    # Input the two vertices whose Main is to be calculated
    v1, v2 = map(int, sys.stdin.readline().split())

    # Output the Main
    print(getMain(v1, v2, depth, parent))

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        if adjacent != p:
            parent[adjacent] = s
            depth[adjacent] = 1 + depth[s]
            dfs(adj, adjacent, s, parent, depth)

def getMain(v1, v2, depth, parent):
    if depth[v1] < depth[v2]:
        v1, v2 = v2, v1
    while depth[v1] != depth[v2]:
        v1 = parent[v1]
    if v1 == v2:
        return v1
    while v1 != v2:
        v1 = parent[v1]
        v2 = parent[v2]
    return v1

if __name__ == "__main__":
    main()

