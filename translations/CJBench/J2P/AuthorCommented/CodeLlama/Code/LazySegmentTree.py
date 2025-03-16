
import sys

class Node:

    def __init__(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.lazy = 0
        self.left = None
        self.right = None

    def apply_update(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

    def shift(self):
        if self.lazy == 0:
            return
        if self.left == None and self.right == None:
            return
        self.value += self.lazy
        if self.left != None:
            self.left.apply_update(self.lazy)
        if self.right != None:
            self.right.apply_update(self.lazy)
        self.lazy = 0

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

    def get_value(self):
        return self.value

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right

class Main:

    def __init__(self, array):
        self.root = self.build_tree(array, 0, len(array))

    def build_tree(self, array, start, end):
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) // 2
        left = self.build_tree(array, start, mid)
        right = self.build_tree(array, mid, end)
        return Node.merge(left, right)

    def update_range(self, left, right, diff, curr):
        if left <= curr.start and curr.end <= right:
            curr.apply_update(diff)
            return
        if left >= curr.end or right <= curr.start:
            return
        curr.shift()
        self.update_range(left, right, diff, curr.left)
        self.update_range(left, right, diff, curr.right)
        merge = Node.merge(curr.left, curr.right)
        curr.value = merge.value

    def get_range(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        return Node.merge(self.get_range(left, right, curr.left), self.get_range(left, right, curr.right))

    def get_range(self, left, right):
        result = self.get_range(left, right, self.root)
        return result.get_value() if result != None else 0

    def update_range(self, left, right, diff):
        self.update_range(left, right, diff, self.root)

    def get_root(self):
        return self.root

if __name__ == "__main__":
    scanner = sys.stdin

    # Input the size of the array
    n = int(scanner.readline())
    array = list(map(int, scanner.readline().split()))

    # Create a Main
    tree = Main(array)

    # Input number of operations
    q = int(scanner.readline())

    # Perform operations
    for i in range(q):
        op = scanner.readline().split()
        if op[0] == "update":
            left = int(op[1])
            right = int(op[2])
            diff = int(op[3])
            tree.update_range(left, right, diff)
        else:
            left = int(op[1])
            right = int(op[2])
            print(tree.get_range(left, right))

    scanner.close()

