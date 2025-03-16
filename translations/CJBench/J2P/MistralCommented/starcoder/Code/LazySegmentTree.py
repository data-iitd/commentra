
import sys

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
    def applyUpdate(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

    # Propagate lazy updates to children
    def shift(self):
        if self.lazy == 0:
            return
        if self.left == None and self.right == None:
            return
        self.value += self.lazy
        if self.left!= None:
            self.left.applyUpdate(self.lazy)
        if self.right!= None:
            self.right.applyUpdate(self.lazy)
        self.lazy = 0

    # Merge two nodes into one
    @staticmethod
    def merge(left, right):
        if left == None:
            return right
        if right == None:
            return left
        result = Node(left.start, right.end, left.value + right.value)
        result.left = left
        result.right = right
        return result

    # Get the value of this node
    def getValue(self):
        return self.value

    # Get the left child of this node
    def getLeft(self):
        return self.left

    # Get the right child of this node
    def getRight(self):
        return self.right

class Main:
    def __init__(self, array):
        # Initialize the root of the segment tree with the given array
        self.root = self.buildTree(array, 0, len(array))

    def buildTree(self, array, start, end):
        # Build the segment tree recursively
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) >> 1
        left = self.buildTree(array, start, mid)
        right = self.buildTree(array, mid, end)
        return Node.merge(left, right)

    def updateRange(self, left, right, diff, curr):
        # Update the given range in the segment tree recursively
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

    def getRange(self, left, right, curr):
        # Get the sum of the given range from the segment tree recursively
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        return Node.merge(self.getRange(left, right, curr.left), self.getRange(left, right, curr.right))

    def getRange(self, left, right):
        # Get the sum of the given range from the segment tree
        result = self.getRange(left, right, self.root)
        return result == None and 0 or result.getValue()

    def updateRange(self, left, right, diff):
        # Update the given range in the segment tree
        self.updateRange(left, right, diff, self.root)

    def getRoot(self):
        # Get the root of the segment tree
        return self.root

if __name__ == "__main__":
    # Initialize the scanner and read input
    scanner = sys.stdin
    n = int(scanner.readline())
    array = [0] * n
    for i in range(n):
        array[i] = int(scanner.readline())
    tree = Main(array)
    q = int(scanner.readline())
    # Process the input queries and updates
    for i in range(q):
        op = scanner.readline().strip()
        if op == "update":
            left = int(scanner.readline())
            right = int(scanner.readline())
            diff = int(scanner.readline())
            tree.updateRange(left, right, diff)
        else:
            left = int(scanner.readline())
            right = int(scanner.readline())
            print(tree.getRange(left, right))

