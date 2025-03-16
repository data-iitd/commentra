class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = [[] for _ in range(2 * V)]  # Adjacency list for the bipartite graph
        self.match = [-1] * (2 * V)           # Array to store matches for vertices
        self.used = [False] * (2 * V)         # Array to track visited vertices during DFS

    def init(self):
        for i in range(2 * self.V):
            self.G[i].clear()

    def add(self, a, b):
        self.G[a].append(b + self.V)  # Connect a to b in the second set
        self.G[b + self.V].append(a)   # Connect b to a in the first set

    def dfs(self, v):
        self.used[v] = True  # Mark the current vertex as visited
        for u in self.G[v]:
            w = self.match[u]  # Get the matched vertex for u
            # If u is unmatched or we can find an augmenting path
            if w < 0 or (not self.used[w] and self.dfs(w)):
                self.match[v] = u  # Match v with u
                self.match[u] = v  # Match u with v
                return True  # Found a match
        return False  # No match found

    def exec(self):
        res = 0  # Result variable to count matches
        for v in range(self.V):
            if self.match[v] < 0:  # If vertex v is unmatched
                self.used = [False] * (2 * self.V)  # Reset visited array
                if self.dfs(v):  # Try to find a match for v
                    res += 1  # Increment the result if a match is found
        return res  # Return the total number of matches


def gcd(a, b):
    if b == 0:
        return a  # Base case: if b is 0, return a
    return gcd(b, a % b)  # Recursive case: GCD of b and a mod b


if __name__ == "__main__":
    MN = 520  # Maximum number of vertices
    bm = BitMatching(MN)  # Create an instance of BitMatching

    while True:
        n, m = map(int, input().split())  # Read the sizes of the two sets
        if n == 0:  # Exit if n is 0 (no more input)
            break

        bm.init()  # Initialize the BitMatching instance
        a = list(map(int, input().split()))  # Read elements of the first set
        b = list(map(int, input().split()))  # Read elements of the second set

        # Build the bipartite graph based on the GCD condition
        for i in range(n):
            for j in range(m):
                if gcd(a[i], b[j]) != 1:  # If GCD is not 1, add an edge
                    bm.add(i, j)

        # Execute the matching algorithm and print the result
        print(bm.exec())
        
# <END-OF-CODE>
