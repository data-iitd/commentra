
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n)) # Initialize parent array
        self.r = [0] * n # Initialize rank array
        # Each element is its own parent initially
        for i in range(n):
            self.p[i] = i

    def find(self, i):
        parent = self.p[i] # Get the parent of the current element
        # If the current element is its own parent, return it
        if i == parent:
            return i
        # Recursively find the root and apply path compression
        result = self.find(parent)
        self.p[i] = result # Update the parent of 'i' to its root
        return result # Return the root

    def union(self, x, y):
        r0 = self.find(x) # Find the root of x
        r1 = self.find(y) # Find the root of y
        # If both elements have the same root, they are already connected
        if r1 == r0:
            return
        # Union by rank to keep the tree flat
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0 # Make r0 the parent of r1
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1 # Make r1 the parent of r0
        else:
            self.p[r1] = r0 # Make r0 the parent of r1
            self.r[r0] += 1 # Increase the rank of r0

    def count(self):
        parents = set() # Set to hold unique roots
        # Iterate through all elements to find their roots
        for i in range(len(self.p)):
            root = self.find(i) # Find the root of the current element
            # Add the root to the set if it's not already present
            parents.add(root)
        # Return the number of unique roots, which is the number of disjoint sets
        return len(parents)

# Main method to execute the program
if __name__ == "__main__":
    import sys # Import the sys module for input
    n = int(input()) # Read the number of elements
    uf = UnionFind(n) # Initialize the union-find structure
    unionOps = int(input()) # Read the number of union operations
    # Perform union operations based on user input
    for i in range(unionOps):
        x = int(input()) # Read first element for union
        y = int(input()) # Read second element for union
        uf.union(x, y) # Perform the union operation
    findOps = int(input()) # Read the number of find operations
    # Perform find operations based on user input
    for i in range(findOps):
        x = int(input()) # Read element to find
        print("Find({}) -> Root: {}".format(x, uf.find(x))) # Output the root
    # Output the number of disjoint sets
    print("Number of disjoint sets: {}".format(uf.count()))

