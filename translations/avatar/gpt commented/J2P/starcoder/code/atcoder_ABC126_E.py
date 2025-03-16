import sys

class Main:
    # Scanner object to read input from the console
    sc = sys.stdin

    # Constant for modulo operation
    MOD = 1000000007

    # Method to execute the main logic
    def doIt(self):
        # Read the number of elements (nodes)
        n = int(self.sc.readline())
        # Initialize Union-Find data structure with n elements
        utf = UnionFindTree(n)
        # Read the number of connections (edges)
        m = int(self.sc.readline())

        # Process each connection
        for i in range(m):
            # Read the two nodes to unite and the weight (not used in this implementation)
            x, y, z = map(int, self.sc.readline().split())
            # Unite the two nodes
            utf.unite(x - 1, y - 1)

        # Count the number of unique connected components
        cnt = 0
        for i in range(n):
            # Check if the current node is a root of a component
            if utf.par[i] == i:
                cnt += 1

        # Output the count of unique connected components
        print(cnt)

    # Inner class implementing Union-Find (Disjoint Set Union)
    class UnionFindTree:
        n = 0  # Number of elements
        par = []  # Parent array
        rank = []  # Rank array for union by rank

        # Constructor to initialize the Union-Find structure
        def __init__(self, n):
            self.n = n
            self.par = [i for i in range(n)]
            self.rank = [0 for i in range(n)]

        # Find the root of the set containing x with path compression
        def find(self, x):
            if self.par[x] == x:
                return x
            else:
                return self.par[x] = self.find(self.par[x])

        # Unite the sets containing x and y
        def unite(self, x, y):
            x = self.find(x)
            y = self.find(y)
            # If they are already in the same set, do nothing
            if x == y:
                return
            # Union by rank
            if self.rank[x] < self.rank[y]:
                self.par[x] = y
            else:
                self.par[y] = x
                if self.rank[x] == self.rank[y]:
                    self.rank[x] += 1

        # Check if x and y are in the same set
        def same(self, x, y):
            return self.find(x) == self.find(y)


# Main method to start the program
if __name__ == "__main__":
    Main().doIt()

