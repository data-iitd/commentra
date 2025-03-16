class UnionFind:
    """
    The Union-Find data structure, also known as Disjoint Set Union (DSU),
    is a data structure that tracks a set of elements partitioned into
    disjoint (non-overlapping) subsets. It supports two main operations:

    1. **Find**: Determine which subset a particular element is in.
    2. **Union**: Join two subsets into a single subset.

    This implementation uses path compression in the `find` operation
    and union by rank in the `union` operation for efficiency.
    """

    def __init__(self, n):
        """
        Initializes a Union-Find data structure with n elements.
        Each element is its own parent initially.

        :param n: the number of elements
        """
        self.p = list(range(n))  # Parent array
        self.r = [0] * n          # Rank array

    def find(self, i):
        """
        Finds the root of the set containing the element i.
        Uses path compression to flatten the structure.

        :param i: the element to find
        :return: the root of the set
        """
        if self.p[i] != i:
            self.p[i] = self.find(self.p[i])  # Path compression
        return self.p[i]

    def union(self, x, y):
        """
        Unites the sets containing elements x and y.
        Uses union by rank to attach the smaller tree under the larger tree.

        :param x: the first element
        :param y: the second element
        """
        r0 = self.find(x)
        r1 = self.find(y)

        if r0 == r1:
            return

        # Union by rank
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1
        else:
            self.p[r1] = r0
            self.r[r0] += 1

    def count(self):
        """
        Counts the number of disjoint sets.

        :return: the number of disjoint sets
        """
        parents = set()
        for i in range(len(self.p)):
            root = self.find(i)
            parents.add(root)
        return len(parents)

    def __str__(self):
        return f"p {self.p} r {self.r}\n"


if __name__ == "__main__":
    import sys

    # Input: number of elements
    n = int(sys.stdin.readline().strip())
    uf = UnionFind(n)

    # Input: number of union operations
    union_ops = int(sys.stdin.readline().strip())

    # Perform union operations
    for _ in range(union_ops):
        x, y = map(int, sys.stdin.readline().strip().split())
        uf.union(x, y)

    # Input: number of find operations
    find_ops = int(sys.stdin.readline().strip())

    # Perform find operations
    for _ in range(find_ops):
        x = int(sys.stdin.readline().strip())
        print(f"Find({x}) -> Root: {uf.find(x)}")

    # Output: number of disjoint sets
    print(f"Number of disjoint sets: {uf.count()}")

# <END-OF-CODE>
