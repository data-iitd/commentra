import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.graph = []  # Adjacency list of the graph
        self.visited = []  # Track visited nodes
        self.color = []  # Store colors of nodes
        self.one = 0  # Count of nodes in a single connected component
        self.bipartite = 0  # Count of bipartite connected components
        self.count = 0  # Total number of nodes in the graph
        self.mujun = False  # Check for odd cycles

    def run(self):
        input = sys.stdin.read
        data = input().split()
        n = int(data[0])  # Number of nodes
        m = int(data[1])  # Number of edges
        self.graph = defaultdict(list)  # Initialize graph as a dictionary of lists

        index = 2
        for _ in range(m):
            u = int(data[index]) - 1  # Source node
            v = int(data[index + 1]) - 1  # Destination node
            self.graph[u].append(v)  # Add edge to the graph
            self.graph[v].append(u)  # Add edge to the graph
            index += 2

        self.visited = [False] * n  # Initialize visited array
        self.color = [-1] * n  # Initialize color array

        for i in range(n):
            if self.visited[i]:
                continue
            self.count += 1  # Increment count of nodes
            self.mujun = False  # Reset mujun flag
            kind = self.dfs(i, 0)  # Perform DFS
            if kind == 1:
                self.one += 1  # Increment count of single connected components
            elif not self.mujun:
                self.bipartite += 1  # Increment count of bipartite components

        total = self.one * (2 * n - self.one)  # Calculate total edges
        total += (self.count - self.one) * (self.count - self.one)  # Isolated nodes
        total += self.bipartite * self.bipartite  # Bipartite components
        print(total)  # Output total edges

    def dfs(self, a, c):
        if self.visited[a]:  # If already visited
            if self.color[a] >= 0 and self.color[a] != c:
                self.mujun = True  # Odd cycle detected
            return 0  # Return 0 if already visited
        self.visited[a] = True  # Mark as visited
        self.color[a] = c  # Set color
        total = 1  # Count of nodes in the connected component
        for b in self.graph[a]:  # Iterate through neighbors
            total += self.dfs(b, 1 - c)  # Recursive DFS
        return total  # Return total nodes in the component

if __name__ == "__main__":
    Main().run()  # Execute the main function

# <END-OF-CODE>
