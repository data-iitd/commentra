import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.graph = defaultdict(list)  # Adjacency list representation of the graph
        self.visited = []  # Array to track visited nodes
        self.color = []  # Array to store colors of nodes for bipartite checking
        self.one = 0  # Counter for specific conditions
        self.bipartite = 0  # Counter for bipartite components
        self.count = 0  # Counter for total components
        self.mujun = False  # Flag to check if the graph is not bipartite

    def dfs(self, a, c):
        if self.visited[a]:  # If the node has already been visited
            if self.color[a] >= 0 and self.color[a] != c:
                self.mujun = True  # Check for color conflict
            return 0
        self.visited[a] = True  # Mark the node as visited
        self.color[a] = c  # Assign color
        total = 1  # Count the current node

        # Recursively visit all adjacent nodes with alternate color
        for b in self.graph[a]:
            total += self.dfs(b, 1 - c)
        return total  # Return the total count of nodes in this component

    def run(self):
        input = sys.stdin.read
        data = input().split()
        n = int(data[0])  # Number of nodes
        m = int(data[1])  # Number of edges

        # Initialize visited and color arrays
        self.visited = [False] * n
        self.color = [-1] * n  # Set all colors to -1 (uncolored)

        # Read edges and populate the graph
        index = 2
        for _ in range(m):
            u = int(data[index]) - 1  # Read first node of the edge
            v = int(data[index + 1]) - 1  # Read second node of the edge
            self.graph[u].append(v)  # Add edge to the graph
            self.graph[v].append(u)  # Add edge in both directions
            index += 2

        # Initialize counters
        self.one = 0
        self.bipartite = 0
        self.count = 0

        # Iterate through all nodes to find connected components
        for i in range(n):
            if self.visited[i]:
                continue  # Skip already visited nodes
            self.count += 1  # Increment component count
            self.mujun = False  # Reset bipartite flag
            kind = self.dfs(i, 0)  # Perform DFS starting from node i

            # Update counters based on the results of DFS
            if kind == 1:
                self.one += 1
            elif not self.mujun:
                self.bipartite += 1

        # Calculate the total based on the counts of components
        total = self.one * (2 * n - self.one)
        total += (self.count - self.one) * (self.count - self.one)
        total += self.bipartite * self.bipartite

        # Output the final result
        print(total)

if __name__ == "__main__":
    Main().run()

# <END-OF-CODE>
