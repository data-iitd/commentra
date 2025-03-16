
class UF:
    def __init__(self, n):
        self.p = list(range(n)) # Array to store the parent of each element
        self.r = [0] * n # Array to store the rank of each element

    # Method to find the root of a given element using path compression
    def find(self, i):
        p = self.p
        if i == p[i]:
            return i # If i is the root, return i
        result = self.find(p[i]) # Recursively find the root
        p[i] = result # Path compression: set the parent of i to the root
        return result

    # Method to union two sets represented by x and y
    def union(self, x, y):
        p = self.p
        r = self.r
        r0 = self.find(x) # Find the root of x
        r1 = self.find(y) # Find the root of y
        if r1 == r0:
            return # If they are already in the same set, do nothing
        if r[r0] > r[r1]:
            p[r1] = r0 # If rank of r0 is greater, make r0 the parent of r1
        elif r[r1] > r[r0]:
            p[r0] = r1 # If rank of r1 is greater, make r1 the parent of r0
        else:
            p[r1] = r0 # If ranks are equal, make r0 the parent of r1 and increment rank of r0
            r[r0] += 1

    # Method to count the number of distinct sets
    def count(self):
        parents = set()
        for i in range(len(self.p)):
            root = self.find(i) # Find the root of each element
            parents.add(root) # Add the root to the set if not already present
        return len(parents) # Return the number of unique roots

    # Method to print the parent and rank arrays
    def __str__(self):
        return "p {} r {}\n".format(self.p, self.r)

# Main method to run the program
if __name__ == "__main__":
    import sys
    n = int(input()) # Read the number of elements
    uf = UF(n)
    unionOps = int(input()) # Read the number of union operations
    for i in range(unionOps):
        x, y = map(int, input().split())
        uf.union(x, y) # Perform union operations
    findOps = int(input()) # Read the number of find operations
    for i in range(findOps):
        x = int(input())
        print("Find({}) -> Root: {}".format(x, uf.find(x))) # Perform find operations and print results
    print("Number of disjoint sets: {}".format(uf.count())) # Print the number of disjoint sets
    sys.stdout.flush()

Translate the above Python code to C++ and end with comment "