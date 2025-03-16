
class DSU:
    def __init__(self, n):
        self.p = list(range(n)) # Initialize the parent array with the index of each element
        self.r = [0] * n # Initialize the rank array with zeros

    def find(self, i):
        parent = self.p[i]

        # Base case: if the given element is its own parent, return it
        if i == parent:
            return i

        # Recursive call to find the root of the parent element
        result = self.find(parent)
        self.p[i] = result # Update the parent of the given element
        return result

    def union(self, x, y):
        r0 = self.find(x) # Find the root of set x
        r1 = self.find(y) # Find the root of set y

        # Base case: if the two roots are already the same, return
        if r1 == r0:
            return

        # Update the parent of the smaller rank set to point to the root of the larger rank set
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1
        else:
            self.p[r1] = r0 # Update the parent of the smaller rank set
            self.r[r0] += 1 # Increment the rank of the larger rank set

    def count(self):
        parents = set() # Initialize an empty set to store unique parents

        # Iterate through the parent array and find the unique parents
        for i in range(len(self.p)):
            root = self.find(i) # Find the root of the current element
            parents.add(root) # Add the parent to the set

        # Return the size of the set, which represents the number of disjoint sets
        return len(parents)

# Main method to read input and test the DSU implementation
if __name__ == "__main__":
    import sys

    n = int(input()) # Read the number of elements in the DSU
    uf = DSU(n) # Create a new instance of the DSU with the given size

    unionOps = int(input()) # Read the number of union operations
    for i in range(unionOps): # Iterate through the union operations
        x, y = map(int, input().split()) # Read the first and second elements
        uf.union(x, y) # Perform the union operation

    findOps = int(input()) # Read the number of find operations
    for i in range(findOps): # Iterate through the find operations
        x = int(input()) # Read the element to find the root of
        print("Find({}) -> Root: {}".format(x, uf.find(x))) # Print the root of the given element

    print("Number of disjoint sets: {}".format(uf.count())) # Print the number of disjoint sets in the DSU