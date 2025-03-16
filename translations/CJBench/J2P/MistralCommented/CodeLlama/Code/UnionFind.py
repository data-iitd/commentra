
import sys

# Class definition for the Disjoint Set Union (DSU) data structure
class Main:

    # Initialize the parent array and rank array for the DSU
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.r = [0 for i in range(n)]

    # Find the root of the given element in the DSU
    def find(self, i):
        parent = self.p[i]

        # Base case: if the given element is its own parent, return it
        if i == parent:
            return i

        # Recursive call to find the root of the parent element
        result = self.find(parent)
        self.p[i] = result # Update the parent of the given element
        return result

    # Merge two disjoint sets in the DSU
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

    # Count the number of disjoint sets in the DSU
    def count(self):
        parents = [] # Initialize an empty list to store unique parents

        # Iterate through the parent array and find the unique parents
        for i in range(len(self.p)):
            root = self.find(i) # Find the root of the current element
            if root not in parents: # If the parent is not already in the list, add it
                parents.append(root)

        # Return the size of the list, which represents the number of disjoint sets
        return len(parents)

    # Override the toString method to print the parent and rank arrays for debugging purposes
    def __str__(self):
        return "p " + str(self.p) + " r " + str(self.r) + "\n"

# Main method to read input and test the DSU implementation
if __name__ == "__main__":
    n = int(sys.stdin.readline()) # Read the number of elements in the DSU
    uf = Main(n) # Create a new instance of the DSU with the given size

    unionOps = int(sys.stdin.readline()) # Read the number of union operations
    for i in range(unionOps): # Iterate through the union operations
        x, y = map(int, sys.stdin.readline().split()) # Read the first and second elements
        uf.union(x, y) # Perform the union operation

    findOps = int(sys.stdin.readline()) # Read the number of find operations
    for i in range(findOps): # Iterate through the find operations
        x = int(sys.stdin.readline()) # Read the element to find the root of
        print("Find(" + str(x) + ") -> Root: " + str(uf.find(x))) # Print the root of the given element

    print("Number of disjoint sets: " + str(uf.count())) # Print the number of disjoint sets in the DSU

