class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = [[] for _ in range(2 * V)]  # Graph representation using adjacency list
        self.match = [-1] * (2 * V)  # Array to store the match of each node
        self.used = [False] * (2 * V)  # Array to keep track of used nodes in DFS

    def init(self):
        for i in range(2 * self.V):
            self.G[i].clear()  # Clear all edges

    def add(self, a, b):
        self.G[a].append(b + self.V)  # Add edge from a to b+V
        self.G[b + self.V].append(a)  # Add edge from b+V to a

    def dfs(self, v):
        self.used[v] = True  # Mark the node as visited
        for u in self.G[v]:
            w = self.match[u]
            if w < 0 or (not self.used[w] and self.dfs(w)):  # If the node is not matched or can find an augmenting path
                self.match[v] = u  # Assign the match
                self.match[u] = v  # Assign the match
                return True  # Return true as we found an augmenting path
        return False  # Return false if no augmenting path is found

    def exec(self):
        res = 0  # Initialize the result
        for v in range(self.V):
            if self.match[v] < 0:  # If the node is not matched
                self.used = [False] * (2 * self.V)  # Reset the used array
                if self.dfs(v):  # Perform DFS from the node
                    res += 1  # Increment the result if an augmenting path is found
        return res  # Return the total number of matches found


def gcd(a, b):
    if b == 0:
        return a  # Base case: if b is 0, return a
    return gcd(b, a % b)  # Recursive call: compute GCD of b and the remainder of a divided by b


if __name__ == "__main__":
    while True:
        n, m = map(int, input().split())  # Read the number of elements in the two sets
        if n == 0:
            break  # If n is 0, break the loop
        bm = BitMatching(max(n, m))  # Create an instance of BitMatching
        a = list(map(int, input().split()))  # Read the elements of the first set
        b = list(map(int, input().split()))  # Read the elements of the second set

        for i in range(n):
            for j in range(m):
                if gcd(a[i], b[j]) != 1:  # Check if the GCD is not 1
                    bm.add(i, j)  # Add an edge between the corresponding nodes if GCD is not 1

        print(bm.exec())  # Execute the bipartite matching and print the result

# <END-OF-CODE>
