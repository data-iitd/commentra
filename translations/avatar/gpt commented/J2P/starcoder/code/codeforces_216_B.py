import sys

class Main:
    # Variable to count the number of nodes in the current DFS traversal
    count = 0
    # Array to track which nodes have been visited
    seen = []
    # Constants to represent the state of the traversal
    path = 0
    cycle = 1
    # Adjacency list representation of the graph
    graph = []

    # Depth-First Search (DFS) method to explore the graph
    def dfs(self, child, par):
        # If the current node has already been seen, return cycle indicator
        if self.seen[child] == True: return self.cycle
        # Mark the current node as seen
        self.seen[child] = True
        
        # Iterate through all adjacent nodes of the current node
        for i in self.graph[child]:
            # Avoid going back to the parent node
            if i!= par:
                self.count += 1 # Increment the count of nodes visited
                # Recursively call DFS on the adjacent node
                if self.dfs(i, child) == self.cycle: return self.cycle # Check for cycles
        # Return path indicator if no cycle is found
        return self.path

    def main(self):
        # Read the number of nodes (m) and edges (n)
        m = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        
        # Create an instance of Main to access graph and related variables
        ft = Main()
        ft.graph = [[] for i in range(m + 1)]
        
        # Initialize the seen array to track visited nodes
        ft.seen = [False] * (m + 1)
        
        # Read the edges and populate the graph
        for i in range(n):
            x = int(sys.stdin.readline())
            y = int(sys.stdin.readline())
            # Add the edge in both directions (undirected graph)
            ft.graph[x].append(y)
            ft.graph[y].append(x)
        
        # Variable to count the number of nodes to remove
        toremove = 0
        
        # Iterate through all nodes to check for unvisited nodes
        for i in range(1, m + 1):
            # If the node has not been seen, perform DFS
            if not ft.seen[i]:
                ft.count = 0 # Reset count for the new component
                # Check if the DFS from this node finds a cycle
                if ft.dfs(i, 0) == ft.cycle:
                    # If a cycle is found and the count of nodes is odd, increment toremove
                    if ft.count % 2 == 1: toremove += 1
            # Adjust the number of nodes to remove if the remaining nodes are odd
            if (m - toremove) % 2 == 1: toremove += 1
        
        # Output the result: number of nodes to remove
        print(toremove)

# Create a new instance of Main and run the main method
if __name__ == "__main__":
    Main().main()

