import sys
import threading
import time

class Main(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        # Initialize scanner for input
        scan = sys.stdin

        # Read number of nodes
        n = int(scan.readline())

        # Read number of edges
        m = int(scan.readline())

        # Initialize graph adjacency list
        graph = [[] for _ in range(n)]

        # Initialize each node's adjacency list
        for i in range(n):
            graph[i] = []

        # Read each edge and add to graph
        for i in range(m):
            u, v = map(int, scan.readline().split())
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)

        # Initialize visited array
        visited = [False] * n

        # Initialize color array
        color = [-1] * n

        # Set all colors to -1 (uncolored)
        for i in range(n):
            color[i] = -1

        # Initialize one counter
        one = 0

        # Initialize bipartite counter
        bipartite = 0

        # Initialize component counter
        count = 0

        # Iterate through all nodes
        for i in range(n):
            if visited[i]:
                continue

            count += 1
            mujun = False
            kind = self.dfs(i, 0)
            if kind == 1:
                one += 1
            else:
                if not mujun:
                    bipartite += 1

        # Calculate total for components with exactly one node
        total = one * (2 * n - one)

        # Calculate total for components with more than one node
        total += (count - one) * (count - one)

        # Add total for bipartite components
        total += bipartite * bipartite

        # Print the total number of valid configurations
        print(total)

    # Depth-first search method to color nodes and check for bipartiteness
    def dfs(self, a, c):
        if visited[a]:
            if color[a] >= 0 and color[a] != c:
                mujun = True
            return 0

        visited[a] = True
        color[a] = c
        total = 1
        for b in graph[a]:
            total += self.dfs(b, 1 - c)

        return total


# Main method to start the program in a new thread
if __name__ == "__main__":
    Main().start()


