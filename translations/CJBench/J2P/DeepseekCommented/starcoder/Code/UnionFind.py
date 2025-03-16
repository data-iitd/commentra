import sys

class Main:
    def __init__(self, n):
        self.p = [i for i in range(n)] # Array to store the parent of each element
        self.r = [0 for i in range(n)] # Array to store the rank of each element

    # Method to find the root of a given element using path compression
    def find(self, i):
        parent = self.p[i]
        if i == parent:
            return i # If i is the root, return i
        final int result = find(parent) # Recursively find the root
        self.p[i] = result # Path compression: set the parent of i to the root
        return result

    # Method to union two sets represented by x and y
    def union(self, x, y):
        r0 = find(x) # Find the root of x
        r1 = find(y) # Find the root of y
        if r1 == r0:
            return # If they are already in the same set, do nothing
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0 # If rank of r0 is greater, make r0 the parent of r1
        else if self.r[r1] > self.r[r0]:
            self.p[r0] = r1 # If rank of r1 is greater, make r1 the parent of r0
        else:
            self.p[r1] = r0 # If ranks are equal, make r0 the parent of r1 and increment rank of r0
            self.r[r0] += 1

    # Method to count the number of distinct sets
    def count(self):
        parents = []
        for i in range(len(self.p)):
            root = find(i) # Find the root of each element
            if root not in parents:
                parents.append(root) # Add the root to the list if not already present
        return len(parents) # Return the number of unique roots

    # Method to print the parent and rank arrays
    def __str__(self):
        return "p " + str(self.p) + " r " + str(self.r) + "\n"

# Main method to run the program
if __name__ == "__main__":
    n = int(input()) # Read the number of elements
    uf = Main(n)
    unionOps = int(input()) # Read the number of union operations
    for i in range(unionOps):
        x = int(input())
        y = int(input())
        uf.union(x, y) # Perform union operations
    findOps = int(input()) # Read the number of find operations
    for i in range(findOps):
        x = int(input())
        print("Find(" + str(x) + ") -> Root: " + str(uf.find(x))) # Perform find operations and print results
    print("Number of disjoint sets: " + str(uf.count())) # Print the number of disjoint sets

