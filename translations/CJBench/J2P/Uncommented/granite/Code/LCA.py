

v = int(input())
adj = [[] for _ in range(v)]
for _ in range(v - 1):
    from_v, to_v = map(int, input().split())
    adj[from_v].append(to_v)
    adj[to_v].append(from_v)
parent = [0] * v
depth = [0] * v
def dfs(s, p):
    for adjacent in adj[s]:
        if adjacent!= p:
            parent[adjacent] = s
            depth[adjacent] = 1 + depth[s]
            dfs(adjacent, s)
dfs(0, -1)
v1, v2 = map(int, input().split())
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
print(get_main(v1, v2, depth, parent))
