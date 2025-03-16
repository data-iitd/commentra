def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    v = int(data[0])
    index = 1
    adj = [[] for _ in range(v)]
    
    for i in range(v - 1):
        from_v = int(data[index])
        to_v = int(data[index + 1])
        index += 2
        adj[from_v].append(to_v)
        adj[to_v].append(from_v)
    
    parent = [0] * v
    depth = [0] * v
    
    def dfs(s, p):
        for adjacent in adj[s]:
            if adjacent != p:
                parent[adjacent] = s
                depth[adjacent] = depth[s] + 1
                dfs(adjacent, s)
    
    dfs(0, -1)
    
    v1 = int(data[index])
    v2 = int(data[index + 1])
    index += 2
    
    def get_lca(v1, v2, depth, parent):
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
    
    print(get_lca(v1, v2, depth, parent))

main()
