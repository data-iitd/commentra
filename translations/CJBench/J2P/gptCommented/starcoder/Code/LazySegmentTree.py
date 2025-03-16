import sys

# Node class represents a segment of the array with lazy propagation support
class Node:
    def __init__(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.lazy = 0
        self.left = None
        self.right = None

    # Apply an update to the current node
    def applyUpdate(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

    # Shift the lazy updates down to the children nodes
    def shift(self):
        if self.lazy == 0:
            return
        if self.left is None and self.right is None:
            return
        self.value += self.lazy
        if self.left is not None:
            self.left.applyUpdate(self.lazy)
        if self.right is not None:
            self.right.applyUpdate(self.lazy)
        self.lazy = 0

    # Merge two nodes into a single node
    @staticmethod
    def merge(left, right):
        if left is None:
            return right
        if right is None:
            return left
        # Create a new node that combines the values of left and right
        result = Node(left.start, right.end, left.value + right.value)
        result.left = left
        result.right = right
        return result

    # Get the value of the node
    def getValue(self):
        return self.value

    # Get the left child node
    def getLeft(self):
        return self.left

    # Get the right child node
    def getRight(self):
        return self.right


# Segment tree class
class SegmentTree:
    def __init__(self, array):
        self.root = self.buildTree(array, 0, len(array))

    # Recursively build the segment tree
    def buildTree(self, array, start, end):
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) >> 1
        left = self.buildTree(array, start, mid)
        right = self.buildTree(array, mid, end)
        return Node.merge(left, right)

    # Update a range of values in the segment tree
    def updateRange(self, left, right, diff):
        self.updateRange(left, right, diff, self.root)

    # Update a range of values in the segment tree
    def updateRange(self, left, right, diff, curr):
        if left <= curr.start and curr.end <= right:
            curr.applyUpdate(diff)
            return
        if left >= curr.end or right <= curr.start:
            return
        curr.shift()
        self.updateRange(left, right, diff, curr.left)
        self.updateRange(left, right, diff, curr.right)
        merge = Node.merge(curr.left, curr.right)
        curr.value = merge.value

    # Retrieve the sum of values in a specified range
    def getRange(self, left, right):
        return self.getRange(left, right, self.root)

    # Retrieve the sum of values in a specified range
    def getRange(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        return Node.merge(self.getRange(left, right, curr.left), self.getRange(left, right, curr.right))


# Main method to execute the program
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for i in range(n)]
    tree = SegmentTree(array)
    q = int(sys.stdin.readline())
    for i in range(q):
        op = sys.stdin.readline().strip()
        if op == "update":
            left = int(sys.stdin.readline())
            right = int(sys.stdin.readline())
            diff = int(sys.stdin.readline())
            tree.updateRange(left, right, diff)
        else:
            left = int(sys.stdin.readline())
            right = int(sys.stdin.readline())
            print(tree.getRange(left, right))

