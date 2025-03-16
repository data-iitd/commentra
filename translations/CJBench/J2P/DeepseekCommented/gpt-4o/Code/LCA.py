import sys
from collections import defaultdict

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        if adjacent != p:
            parent[adjacent] = s
            depth[adjacent] = depth[s] + 1
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

def main():
    v = int(input().strip())
    adj = defaultdict(list)
    for _ in range(v - 1):
        from_v, to_v = map(int, input().strip().split())
        adj[from_v].append(to_v)
        adj[to_v].append(from_v)
    
    parent = [0] * v
    depth = [0] * v
    dfs(adj, 0, -1, parent, depth)
    
    v1, v2 = map(int, input().strip().split())
    main_node = get_main(v1, v2, depth, parent)
    print(main_node)

if __name__ == "__main__":
    main()
