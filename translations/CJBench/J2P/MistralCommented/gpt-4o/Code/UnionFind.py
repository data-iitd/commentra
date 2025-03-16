class DisjointSetUnion:
    def __init__(self, n):
        self.p = list(range(n))  # Initialize the parent array
        self.r = [0] * n  # Initialize the rank array

    def find(self, i):
        parent = self.p[i]
        if i == parent:  # Base case: if the element is its own parent
            return i
        result = self.find(parent)  # Recursive call to find the root
        self.p[i] = result  # Path compression
        return result

    def union(self, x, y):
        r0 = self.find(x)  # Find the root of set x
        r1 = self.find(y)  # Find the root of set y

        if r1 == r0:  # Base case: if the roots are the same, do nothing
            return

        # Union by rank
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1
        else:
            self.p[r1] = r0  # Update the parent of the smaller rank set
            self.r[r0] += 1  # Increment the rank of the larger rank set

    def count(self):
        parents = set()  # Use a set to store unique parents
        for i in range(len(self.p)):
            root = self.find(i)  # Find the root of the current element
            parents.add(root)  # Add the root to the set
        return len(parents)  # Return the number of unique parents

    def __str__(self):
        return f"p {self.p} r {self.r}\n"


if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Read the number of elements in the DSU
    dsu = DisjointSetUnion(n)  # Create a new instance of the DSU

    union_ops = int(data[1])  # Read the number of union operations
    for i in range(2, 2 + union_ops):
        x, y = map(int, data[i].split())  # Read the elements for union
        dsu.union(x, y)  # Perform the union operation

    find_ops = int(data[2 + union_ops])  # Read the number of find operations
    for i in range(3 + union_ops, 3 + union_ops + find_ops):
        x = int(data[i])  # Read the element to find the root of
        print(f"Find({x}) -> Root: {dsu.find(x)}")  # Print the root of the given element

    print(f"Number of disjoint sets: {dsu.count()}")  # Print the number of disjoint sets
