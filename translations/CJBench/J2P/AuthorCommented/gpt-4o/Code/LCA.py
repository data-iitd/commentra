class Main:
    @staticmethod
    def main():
        import sys
        from collections import defaultdict

        input = sys.stdin.read
        data = input().splitlines()

        # Input the number of vertices
        v = int(data[0])

        # Adjacency list to represent the tree
        adj = defaultdict(list)

        # Input edges
        for i in range(1, v):
            from_vertex, to_vertex = map(int, data[i].split())
            adj[from_vertex].append(to_vertex)
            adj[to_vertex].append(from_vertex)

        # Arrays to store parent and depth of each vertex
        parent = [-1] * v
        depth = [0] * v

        # Perform DFS to calculate parent and depth
        Main.dfs(adj, 0, -1, parent, depth)

        # Input the two vertices whose Main is to be calculated
        v1, v2 = map(int, data[v].split())

        # Output the Main
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
