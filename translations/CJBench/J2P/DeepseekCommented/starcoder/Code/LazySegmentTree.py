import sys; # Import the sys module for reading input

class Node:
    def __init__(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.lazy = 0
        self.left = None
        self.right = None

    # Apply an update to the node and its children
    def applyUpdate(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

    # Push the lazy value down to children
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

    # Get the value stored at this node
    def getValue(self):
        return self.value

    # Get the left child of this node
    def getLeft(self):
        return self.left

    # Get the right child of this node
    def getRight(self):
        return self.right

class Main:
    # Constructor for Main class
    def __init__(self, array):
        self.root = self.buildTree(array, 0, len(array))

    # Build the segment tree from an array
    def buildTree(self, array, start, end):
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) >> 1
        left = self.buildTree(array, start, mid)
        right = self.buildTree(array, mid, end)
        return Node.merge(left, right)

    # Update the values in the range [left, right) by adding diff
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

    # Get the sum of values in the range [left, right)
    def getRange(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        return Node.merge(self.getRange(left, right, curr.left), self.getRange(left, right, curr.right))

    # Public method to get the sum of values in the range [left, right)
    def getRange(self, left, right):
        result = self.getRange(left, right, self.root)
        return result == None and 0 or result.getValue()

    # Public method to update the values in the range [left, right) by adding diff
    def updateRange(self, left, right, diff):
        self.updateRange(left, right, diff, self.root)

    # Get the root of the segment tree
    def getRoot(self):
        return self.root

# Main method to read input, create a Main object, and process queries
if __name__ == "__main__":
    n = int(sys.stdin.readline()) # Read the size of the array
    array = [0] * n
    for i in range(n):
        array[i] = int(sys.stdin.readline()) # Read the array elements
    tree = Main(array)
    q = int(sys.stdin.readline()) # Read the number of queries
    for i in range(q):
        op = sys.stdin.readline().strip() # Read the operation type
        if op == "update":
            left = int(sys.stdin.readline()) # Read the left index
            right = int(sys.stdin.readline()) # Read the right index
            diff = int(sys.stdin.readline()) # Read the difference
            tree.updateRange(left, right, diff) # Update the range
        else:
            left = int(sys.stdin.readline()) # Read the left index
            right = int(sys.stdin.readline()) # Read the right index
            print(tree.getRange(left, right)) # Print the sum of the range

