from collections import defaultdict

class BitMatching:
    def __init__(self, V):
        self.V = V
        self.G = defaultdict(list)  # Adjacency list for the graph
        self.match = [-1] * (2 * V)  # Stores the matching result for each vertex
        self.used = [False] * (2 * V)  # Stores whether a vertex is being processed or not

    def init(self):
        self.G.clear()  # Clears the adjacency list for the current vertex

    def add(self, a, b):
        self.G[a].append(b + self.V)  # Adds the destination vertex to the adjacency list of the source vertex
        self.G[b + self.V].append(a)  # Adds the source vertex to the adjacency list of the destination vertex

    def dfs(self, v):
        self.used[v] = True  # Marks the current vertex as being processed

        for u in self.G[v]:  # Iterate through neighbors
            w = self.match[u]  # Gets the matching vertex

            if w < 0 or (not self.used[w] and self.dfs(w)):  # If the neighboring vertex is not matched or can be matched
                self.match[v] = u
                self.match[u] = v
                return True
        return False  # If no matching is found, return false

    def exec(self):
        res = 0  # Initializes the result variable
        self.match = [-1] * (2 * self.V)  # Initializes the matching array with -1

        for v in range(self.V):  # Iterates through all vertices in the graph
            if self.match[v] < 0:  # If the current vertex is not matched
                self.used = [False] * (2 * self.V)  # Reset used array
                if self.dfs(v):
                    res += 1
        return res  # Returns the number of matched vertices

def gcd(a, b):
    if b == 0:
        return a  # Base case: if b is 0, return a
    return gcd(b, a % b)  # Recursive case: call gcd with b and the remainder of a divided by b

def main():
    MN = 520  # Constants for the maximum number of vertices in the graph
    bm = BitMatching(MN)  # Instantiates the BitMatching class with the given constant

    while True:  # Loops through multiple test cases
        n, m = map(int, input().split())  # Reads the number of vertices and edges in the graph

        if n == 0:  # If the number of vertices is 0, breaks the loop
            break

        bm.init()  # Initializes the graph data structures

        a = list(map(int, input().split()))  # Reads the input data for vertices a
        b = list(map(int, input().split()))  # Reads the input data for vertices b

        for i in range(n):  # Iterates through all vertices a
            for j in range(m):  # Iterates through all vertices b
                if gcd(a[i], b[j]) != 1:  # If the GCD of a[i] and b[j] is not 1
                    bm.add(i, j)  # Adds an edge between them

        print(bm.exec())  # Executes the Bipartite Graph Matching algorithm and prints the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
