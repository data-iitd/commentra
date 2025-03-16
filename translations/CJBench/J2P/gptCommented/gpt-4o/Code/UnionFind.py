class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))  # Initialize parent array
        self.r = [0] * n  # Initialize rank array

    def find(self, i):
        parent = self.p[i]  # Get the parent of the current element
        if i == parent:
            return i  # If the current element is its own parent, return it
        result = self.find(parent)  # Recursively find the root
        self.p[i] = result  # Update the parent of 'i' to its root
        return result  # Return the root

    def union(self, x, y):
        r0 = self.find(x)  # Find the root of x
        r1 = self.find(y)  # Find the root of y
        if r1 == r0:
            return  # If both elements have the same root, they are already connected
        # Union by rank to keep the tree flat
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0  # Make r0 the parent of r1
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1  # Make r1 the parent of r0
        else:
            self.p[r1] = r0  # Make r0 the parent of r1
            self.r[r0] += 1  # Increase the rank of r0

    def count(self):
        parents = []  # List to hold unique roots
        for i in range(len(self.p)):
            root = self.find(i)  # Find the root of the current element
            if root not in parents:
                parents.append(root)  # Add the root to the list if it's not already present
        return len(parents)  # Return the number of unique roots

    def __str__(self):
        return f"p {self.p} r {self.r}\n"  # Override toString method for easy debugging


if __name__ == "__main__":
    n = int(input())  # Read the number of elements
    uf = UnionFind(n)  # Initialize the union-find structure
    union_ops = int(input())  # Read the number of union operations
    for _ in range(union_ops):
        x, y = map(int, input().split())  # Read elements for union
        uf.union(x, y)  # Perform the union operation
    find_ops = int(input())  # Read the number of find operations
    for _ in range(find_ops):
        x = int(input())  # Read element to find
        print(f"Find({x}) -> Root: {uf.find(x)}")  # Output the root
    print(f"Number of disjoint sets: {uf.count()}")  # Output the number of disjoint sets
