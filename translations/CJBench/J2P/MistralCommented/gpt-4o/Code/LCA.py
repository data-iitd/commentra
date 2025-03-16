class Main:
    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().splitlines()
        
        v = int(data[0])  # Read the number of vertices (nodes) from the input

        adj = [[] for _ in range(v)]  # Initialize a list to store the adjacency list

        for i in range(1, v):  # Iterate through each edge and add it to the adjacency list
            from_node, to_node = map(int, data[i].split())
            adj[from_node].append(to_node)  # Add the neighbor to the list of neighbors of the current vertex
            adj[to_node].append(from_node)  # Add the current vertex to the list of neighbors of the neighbor

        parent = [-1] * v  # Initialize a list to store the parent of each vertex
        depth = [0] * v  # Initialize a list to store the depth of each vertex

        Main.dfs(adj, 0, -1, parent, depth)  # Call the depth-first search algorithm starting from vertex 0

        v1, v2 = map(int, data[v].split())  # Read the first and second vertex from the input

        print(Main.get_main(v1, v2, depth, parent))  # Call the function to find the Main (Lowest Common Ancestor) of the two vertices and print the result

    @staticmethod
    def dfs(adj, s, p, parent, depth):
        for adjacent in adj[s]:  # Iterate through each neighbor of the current vertex
            if adjacent != p:  # Check if the neighbor is not the parent of the current vertex
                parent[adjacent] = s  # Set the parent of the neighbor to the current vertex
                depth[adjacent] = 1 + depth[s]  # Update the depth of the neighbor by adding 1 to the depth of the current vertex
                Main.dfs(adj, adjacent, s, parent, depth)  # Recursively call the DFS algorithm for the neighbor

    @staticmethod
    def get_main(v1, v2, depth, parent):
        if depth[v1] < depth[v2]:  # Check if the depth of v1 is smaller than the depth of v2
            v1, v2 = v2, v1  # Swap the values of v1 and v2 if the depth of v1 is smaller

        while depth[v1] != depth[v2]:  # Traverse up the tree from v1 to find the Main
            v1 = parent[v1]

        if v1 == v2:  # Check if v1 and v2 are the same vertex
            return v1  # Return the vertex if they are the same

        while v1 != v2:  # Traverse up the tree from v1 to find the Main
            v1 = parent[v1]
            v2 = parent[v2]

        return v1  # Return the Main of v1 and v2

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
