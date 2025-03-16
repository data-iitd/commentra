
import sys
from collections import defaultdict

def main():
    v = int(sys.stdin.readline())
    adj = defaultdict(list)
    for i in range(v - 1):
        from_node, to_node = map(int, sys.stdin.readline().split())
        adj[from_node].append(to_node)
        adj[to_node].append(from_node)
    parent = [-1] * v
    depth = [0] * v
    dfs(adj, 0, -1, parent, depth)
    v1, v2 = map(int, sys.stdin.readline().split())
    print(get_main(v1, v2, depth, parent))

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        if adjacent != p:
            parent[adjacent] = s
            depth[adjacent] = 1 + depth[s]
            dfs(adj, adjacent, s, parent, depth)

def get_main(v1, v2, depth, parent):
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

