
import sys

class Main:
    def __init__(self):
        self.count = 0
        self.seen = []
        self.path = 0
        self.cycle = 1
        self.graph = []

    # Depth-first search method to detect cycles
    def dfs(self, child, par):
        if self.seen[child]: return self.cycle # If child is already seen, return cycle
        self.seen[child] = True # Mark the child as seen
        for i in self.graph[child]: # Iterate over neighbors of child
            if i!= par: # Avoid going back to parent
                self.count += 1 # Increment count for each edge traversed
                if self.dfs(i, child) == self.cycle: return self.cycle # If cycle is detected, return cycle
        return self.path # Return path if no cycle is detected

    # Main method to handle input and output
    def main(self):
        m = int(sys.stdin.readline()) # Number of nodes
        n = int(sys.stdin.readline()) # Number of edges
        self.graph = [[] for i in range(m + 1)] # Initialize adjacency list for each node
        self.seen = [False] * (m + 1) # Initialize seen array
        for i in range(n):
            x = int(sys.stdin.readline()) # Read edge from
            y = int(sys.stdin.readline()) # Read edge to
            self.graph[x].append(y) # Add edge to adjacency list of node x
            self.graph[y].append(x) # Add edge to adjacency list of node y
        toremove = 0 # Initialize removal count
        for i in range(1, m + 1):
            if not self.seen[i]: # If node is not visited
                self.count = 0 # Reset count for each DFS call
                if self.dfs(i, 0) == self.cycle: # If cycle is detected
                    if self.count % 2 == 1: toremove += 1 # Increment removal count if cycle length is odd
        if (m - toremove) % 2 == 1: toremove += 1 # Adjust removal count if total nodes minus removed nodes is odd
        print(toremove) # Print the final removal count

if __name__ == "__main__":
    obj = Main()
    obj.main()

