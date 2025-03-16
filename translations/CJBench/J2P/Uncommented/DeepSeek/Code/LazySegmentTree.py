class Node:
    def __init__(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.lazy = 0
        self.left = None
        self.right = None

    def applyUpdate(self, diff):
        self.lazy += diff
        self.value += (self.end - self.start) * diff

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

    def getValue(self):
        return self.value

    def getLeft(self):
        return self.left

    def getRight(self):
        return self.right


class Main:
    def __init__(self, array):
        self.root = self.buildTree(array, 0, len(array))

    def buildTree(self, array, start, end):
        if end - start < 2:
            return Node(start, end, array[start])
        mid = (start + end) >> 1
        left = self.buildTree(array, start, mid)
        right = self.buildTree(array, mid, end)
        return Node.merge(left, right)

    def updateRange(self, left, right, diff, curr):
        if left <= curr.start and curr.end <= right:
            curr.applyUpdate(diff)
            return
        if left >= curr.end or right <= curr.start:
            return
        curr.shift()
        self.updateRange(left, right, diff, curr.left)
        self.updateRange(left, right, diff, curr.right)
        curr.value = Node.merge(curr.left, curr.right).value

    def getRange(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        left_result = self.getRange(left, right, curr.left)
        right_result = self.getRange(left, right, curr.right)
        if left_result is None:
            return right_result
        if right_result is None:
            return left_result
        return Node.merge(left_result, right_result)

    def getRange(self, left, right):
        result = self.getRange(left, right, self.root)
        return result.getValue() if result is not None else 0

    def updateRange(self, left, right, diff):
        self.updateRange(left, right, diff, self.root)

    def getRoot(self):
        return self.root


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0

    def read_int():
        nonlocal index
        result = int(data[index])
        index += 1
        return result

    n = read_int()
    array = [read_int() for _ in range(n)]
    tree = Main(array)
    q = read_int()
    for _ in range(q):
        op = data[index]
        index += 1
        if op == "update":
            left = read_int()
            right = read_int()
            diff = read_int()
            tree.updateRange(left, right, diff)
        elif op == "query":
            left = read_int()
            right = read_int()
            print(tree.getRange(left, right))
