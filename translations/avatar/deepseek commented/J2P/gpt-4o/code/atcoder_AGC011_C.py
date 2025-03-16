import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.graph = []  # Adjacency list to represent the graph
        self.visited = []  # Array to keep track of visited nodes
        self.color = []  # Array to store colors for bipartite check
        self.one = 0  # Counter for components with exactly one node
        self.bipartite = 0  # Counter for bipartite components
        self.count = 0  # Counter for total number of connected components
        self.mujun = False  # Flag to check for non-bipartite conditions

    def dfs(self, a, c):
        if self.visited[a]:  # If node is already visited
            if self.color[a] >= 0 and self.color[a] != c:
                self.mujun = True  # Check if color conflict and set mujun flag
            return 0  # Return 0 as we don't want to count this node again
        self.visited[a] = True  # Mark node as visited
        self.color[a] = c  # Assign color to the node
        total = 1  # Initialize total count for this component
        for b in self.graph[a]:  # Iterate through neighbors
            total += self.dfs(b, 1 - c)  # Recursively call dfs and accumulate total
        return total  # Return total count for this component

    def run(self):
        input = sys.stdin.read
        data = input().split()
        n = int(data[0])  # Read number of nodes
        m = int(data[1])  # Read number of edges
        self.graph = [[] for _ in range(n)]  # Initialize graph adjacency list
        index = 2
        for _ in range(m):  # Read each edge and add to graph
            u = int(data[index]) - 1  # Read node u
            v = int(data[index + 1]) - 1  # Read node v
            self.graph[u].append(v)  # Add edge u -> v
            self.graph[v].append(u)  # Add edge v -> u
            index += 2
        self.visited = [False] * n  # Initialize visited array
        self.color = [-1] * n  # Initialize color array
        self.one = 0  # Initialize one counter
        self.bipartite = 0  # Initialize bipartite counter
        self.count = 0  # Initialize component counter
        for i in range(n):  # Iterate through all nodes
            if self.visited[i]:
                continue  # Skip if already visited
            self.count += 1  # Increment component count
            self.mujun = False  # Reset mujun flag
            kind = self.dfs(i, 0)  # Perform DFS and get component size
            if kind == 1:
                self.one += 1  # If component has exactly one node, increment one counter
            elif not self.mujun:
                self.bipartite += 1  # If component is bipartite, increment bipartite counter
        total = self.one * (2 * n - self.one)  # Calculate total for components with exactly one node
        total += (self.count - self.one) * (self.count - self.one)  # Calculate total for components with more than one node
        total += self.bipartite * self.bipartite  # Add total for bipartite components
        print(total)  # Print the total number of valid configurations

if __name__ == "__main__":
    Main().run()

# <END-OF-CODE>
