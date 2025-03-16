import sys

def main():
    v = int(sys.stdin.readline())
    adj = [[] for _ in range(v)]
    for i in range(v - 1):
        from_, to = map(int, sys.stdin.readline().split())
        adj[from_].append(to)
        adj[to].append(from_)
    parent = [-1] * v
    depth = [0] * v
    dfs(adj, 0, -1, parent, depth)
    v1, v2 = map(int, sys.stdin.readline().split())
    print(get_main(v1, v2, depth, parent))

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

if __name__ == "__main__":
    main()


