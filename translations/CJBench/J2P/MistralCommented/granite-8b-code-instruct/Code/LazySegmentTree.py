

class Node:
    # A Node represents a segment tree node with a start index, end index, value, lazy update, left and right children
    def __init__(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.lazy = 0
        self.left = None
        self.right = None

    # Apply update to this node and its descendants
    def apply_update(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

    # Propagate lazy updates to children
    def shift(self):
        if self.lazy == 0:
            return
        if self.left is None and self.right is None:
            return
        self.value += self.lazy
        if self.left is not None:
            self.left.apply_update(self.lazy)
        if self.right is not None:
            self.right.apply_update(self.lazy)
        self.lazy = 0

    # Merge two nodes into one
    @staticmethod
    def merge(left, right):
        if left is None:
            return right
        if right is None:
            return left
        result = Node(left.start, right.end, left.value + right.value)
        result.left = left
        result.right = right
        return result

    # Get the value of this node
    def get_value(self):
        return self.value

    # Get the left child of this node
    def get_left(self):
        return self.left

    # Get the right child of this node
    def get_right(self):
        return self.right

class SegmentTree:
    def __init__(self, array):
        # Initialize the root of the segment tree with the given array
        self.root = self.build_tree(array, 0, len(array))

    def build_tree(self, array, start, end):
        # Build the segment tree recursively
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) // 2
        left = self.build_tree(array, start, mid)
        right = self.build_tree(array, mid, end)
        return Node.merge(left, right)

    def update_range(self, left, right, diff, curr):
        # Update the given range in the segment tree recursively
        if left <= curr.start and curr.end <= right:
            curr.apply_update(diff)
            return
        if left >= curr.end or right <= curr.start:
            return
        curr.shift()
        self.update_range(left, right, diff, curr.left)
        self.update_range(left, right, diff, curr.right)
        curr.value = Node.merge(curr.left, curr.right).value

    def get_range(self, left, right, curr):
        # Get the sum of the given range from the segment tree recursively
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        return Node.merge(self.get_range(left, right, curr.left), self.get_range(left, right, curr.right))

    def get_range(self, left, right):
        # Get the sum of the given range from the segment tree
        result = self.get_range(left, right, self.root)
        return result.get_value() if result is not None else 0

    def update_range(self, left, right, diff):
        # Update the given range in the segment tree
        self.update_range(left, right, diff, self.root)

    def get_root(self):
        # Get the root of the segment tree
        return self.root

if __name__ == "__main__":
    # Initialize the scanner and read input
    import sys
    n = int(input())
    array = list(map(int, input().split()))
    tree = SegmentTree(array)
    q = int(input())
    # Process the input queries and updates
    for _ in range(q):
        op = input().split()
        if op[0] == "update":
            left, right, diff = map(int, op[1:])
            tree.update_range(left, right, diff)
        else:
            left, right = map(int, op[1:])
            print(tree.get_range(left, right))

Translate the above Python code to C++ and end with comment "