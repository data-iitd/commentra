import sys

class Main:
    # Adjacency list representation of the graph
    graph = []
    # Array to track visited nodes
    visited = []
    # Array to store colors of nodes for bipartite checking
    color = []
    # Counters for specific conditions
    one = 0
    bipartite = 0
    count = 0
    # Flag to check if the graph is not bipartite
    mujun = False

    # Depth-First Search (DFS) method to explore the graph
    def dfs(self, a, c):
        # If the node has already been visited
        if self.visited[a]:
            # Check for color conflict indicating the graph is not bipartite
            if self.color[a] >= 0 and self.color[a]!= c: self.mujun = True
            return 0
        # Mark the node as visited and assign it a color
        self.visited[a] = True
        self.color[a] = c
        total = 1 # Count the current node

        # Recursively visit all adjacent nodes with alternate color
        for b in self.graph[a]:
            total += self.dfs(b, 1 - c)
        return total # Return the total count of nodes in this component

    # Main execution method for the program
    def run(self):
        # Read number of nodes and edges
        n = int(sys.stdin.readline())
        m = int(sys.stdin.readline())

        # Initialize the graph
        self.graph = [[] for i in range(n)]

        # Read edges and populate the graph
        for i in range(m):
            u = int(sys.stdin.readline()) - 1 # Read first node of the edge
            v = int(sys.stdin.readline()) - 1 # Read second node of the edge
            self.graph[u].append(v) # Add edge to the graph
            self.graph[v].append(u) # Add edge in both directions

        # Initialize visited and color arrays
        self.visited = [False] * n
        self.color = [-1] * n

        # Initialize counters
        self.one = 0
        self.bipartite = 0
        self.count = 0

        # Iterate through all nodes to find connected components
        for i in range(n):
            if self.visited[i]: continue # Skip already visited nodes
            self.count += 1 # Increment component count
            self.mujun = False # Reset bipartite flag
            kind = self.dfs(i, 0) # Perform DFS starting from node i

            # Update counters based on the results of DFS
            if kind == 1: self.one += 1
            elif not self.mujun: self.bipartite += 1

        # Calculate the total based on the counts of components
        total = self.one * (2 * n - self.one)
        total += (self.count - self.one) * (self.count - self.one)
        total += self.bipartite * self.bipartite

        # Output the final result
        print(total)

# Main method to start the program
if __name__ == "__main__":
    Main().run()

