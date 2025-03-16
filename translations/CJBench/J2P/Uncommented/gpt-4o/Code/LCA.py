class Main:
    @staticmethod
    def main():
        import sys
        from collections import defaultdict
        
        input = sys.stdin.read
        data = input().split()
        
        index = 0
        v = int(data[index])
        index += 1
        
        adj = defaultdict(list)
        for _ in range(v - 1):
            from_node = int(data[index])
            to_node = int(data[index + 1])
            adj[from_node].append(to_node)
            adj[to_node].append(from_node)
            index += 2
        
        parent = [-1] * v
        depth = [0] * v
        
        Main.dfs(adj, 0, -1, parent, depth)
        
        v1 = int(data[index])
        v2 = int(data[index + 1])
        
        print(Main.get_main(v1, v2, depth, parent))
    
    @staticmethod
    def dfs(adj, s, p, parent, depth):
        for adjacent in adj[s]:
            if adjacent != p:
                parent[adjacent] = s
                depth[adjacent] = 1 + depth[s]
                Main.dfs(adj, adjacent, s, parent, depth)
    
    @staticmethod
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
    Main.main()

# <END-OF-CODE>
