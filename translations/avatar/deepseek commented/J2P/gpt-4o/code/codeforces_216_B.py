from collections import defaultdict

class Main:
    def __init__(self):
        self.count = 0  # To count the number of nodes in a cycle
        self.seen = []  # To keep track of visited nodes
        self.path = 0
        self.cycle = 1  # Constants for path and cycle
        self.graph = defaultdict(list)  # Graph represented as an adjacency list

    # Depth-first search method to detect cycles
    def dfs(self, child, par):
        if self.seen[child]: 
            return self.cycle  # If child is already seen, return cycle
        self.seen[child] = True  # Mark the child as seen
        for i in self.graph[child]:  # Iterate over neighbors of child
            if i != par:  # Avoid going back to parent
                self.count += 1  # Increment count for each edge traversed
                if self.dfs(i, child) == self.cycle: 
                    return self.cycle  # If cycle is detected, return cycle
        return self.path  # Return path if no cycle is detected

    # Main method to handle input and output
    @staticmethod
    def main():
        m = int(input())  # Number of nodes
        n = int(input())  # Number of edges
        ft = Main()
        ft.seen = [False] * (m + 1)  # Initialize seen array
        for _ in range(n):
            x, y = map(int, input().split())  # Read edges
            ft.graph[x].append(y)  # Add edge to adjacency list of node x
            ft.graph[y].append(x)  # Add edge to adjacency list of node y
        toremove = 0  # Initialize removal count
        for i in range(1, m + 1):
            if not ft.seen[i]:  # If node is not visited
                ft.count = 0  # Reset count for each DFS call
                if ft.dfs(i, 0) == ft.cycle:  # If cycle is detected
                    if ft.count % 2 == 1: 
                        toremove += 1  # Increment removal count if cycle length is odd
        if (m - toremove) % 2 == 1: 
            toremove += 1  # Adjust removal count if total nodes minus removed nodes is odd
        print(toremove)  # Print the final removal count

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
