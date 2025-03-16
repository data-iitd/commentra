import sys

# Private constructor to prevent instantiation
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    def main(self):
        # Create a scanner object to read input
        scanner = sys.stdin

        # Read the number of vertices in the graph
        v = int(scanner.readline())

        # Initialize an adjacency list to represent the graph
        adj = []
        for i in range(v):
            adj.append([])

        # Read edges and populate the adjacency list
        for i in range(v - 1):
            from_ = int(scanner.readline())
            to = int(scanner.readline())
            # Add the edge in both directions (undirected graph)
            adj[from_].append(to)
            adj[to].append(from_)

        # Arrays to store the parent and depth of each vertex
        parent = [0] * v
        depth = [0] * v

        # Perform DFS to populate parent and depth arrays
        self.dfs(adj, 0, -1, parent, depth)

        # Read the two vertices for which we want to find the lowest common ancestor (Main)
        v1 = int(scanner.readline())
        v2 = int(scanner.readline())

        # Output the lowest common ancestor of the two vertices
        print(self.getMain(v1, v2, depth, parent))

        # Close the scanner to free resources
        scanner.close()

    # Depth-First Search (DFS) to compute parent and depth of each vertex
    def dfs(self, adj, s, p, parent, depth):
        for adjacent in adj[s]:
            # Avoid going back to the parent node
            if adjacent!= p:
                # Set the parent of the adjacent node
                parent[adjacent] = s
                # Set the depth of the adjacent node
                depth[adjacent] = 1 + depth[s]
                # Recursively call DFS for the adjacent node
                self.dfs(adj, adjacent, s, parent, depth)

    # Function to find the lowest common ancestor (Main) of two nodes
    def getMain(self, v1, v2, depth, parent):
        # Ensure v1 is the deeper node
        if depth[v1] < depth[v2]:
            temp = v1
            v1 = v2
            v2 = temp

        # Bring v1 and v2 to the same depth
        while depth[v1]!= depth[v2]:
            v1 = parent[v1]

        # If they are the same, return the ancestor
        if v1 == v2:
            return v1

        # Move both nodes up until we find the common ancestor
        while v1!= v2:
            v1 = parent[v1]
            v2 = parent[v2]

        # Return the lowest common ancestor
        return v1

# Main function
if __name__ == "__main__":
    # Create a Main object
    main = Main()

    # Run the main function
    main.main()

