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
        if self.end - self.start < 2:
            return
        self.value += self.lazy
        if self.left:
            self.left.apply_update(self.lazy)
        if self.right:
            self.right.apply_update(self.lazy)
        self.lazy = 0

    @staticmethod
    def merge(left, right):
        if not left:
            return right
        if not right:
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
        mid = (start + end) >> 1
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
        curr.value = Node.merge(curr.left, curr.right).value

    def get_range(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr
        if left >= curr.end or right <= curr.start:
            return None
        curr.shift()
        left_result = self.get_range(left, right, curr.left)
        right_result = self.get_range(left, right, curr.right)
        if left_result and right_result:
            return Node.merge(left_result, right_result)
        elif left_result:
            return left_result
        else:
            return right_result

    def get_range(self, left, right):
        result = self.get_range(left, right, self.root)
        return result.value if result else 0

    def update_range(self, left, right, diff):
        self.update_range(left, right, diff, self.root)

    def get_root(self):
        return self.root

    @staticmethod
    def main():
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
                tree.update_range(left, right, diff)
            elif op == "query":
                left = read_int()
                right = read_int()
                print(tree.get_range(left, right))


Main.main()
