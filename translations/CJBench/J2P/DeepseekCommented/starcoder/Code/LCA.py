import sys
import math

def main():
    v = int(input())
    adj = [[] for i in range(v)]
    for i in range(v - 1):
        from_ = int(input())
        to = int(input())
        adj[from_].append(to)
        adj[to].append(from_)
    parent = [0] * v
    depth = [0] * v
    dfs(adj, 0, -1, parent, depth)
    v1 = int(input())
    v2 = int(input())
    print(get_main(v1, v2, depth, parent))

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        if adjacent!= p:
            parent[adjacent] = s
            depth[adjacent] = 1 + depth[s]
            dfs(adj, adjacent, s, parent, depth)

def get_main(v1, v2, depth, parent):
    if depth[v1] < depth[v2]:
        temp = v1
        v1 = v2
        v2 = temp
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

