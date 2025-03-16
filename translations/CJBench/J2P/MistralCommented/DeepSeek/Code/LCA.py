def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    v = int(data[0])
    adj = [[] for _ in range(v)]
    
    index = 1
    for i in range(v - 1):
        from_ = int(data[index])
        to_ = int(data[index + 1])
        adj[from_].append(to_)
        adj[to_].append(from_)
        index += 2
    
    parent = [0] * v
    depth = [0] * v
    
    dfs(adj, 0, -1, parent, depth)
    
    v1 = int(data[index])
    v2 = int(data[index + 1])
    index += 2
    
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

main()
