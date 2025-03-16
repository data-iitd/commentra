class Node:
    def __init__(self, element):
        self.element = element
        self.npl = 0
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    def is_empty(self):
        return self.root is None

    def clear(self):
        self.root = None

    def merge(self, h1):
        self.root = self._merge(self.root, h1.root)
        h1.root = None

    def _merge(self, a, b):
        if a is None:
            return b
        if b is None:
            return a

        if a.element > b.element:
            a, b = b, a

        a.right = self._merge(a.right, b)

        if a.left is None:
            a.left = a.right
            a.right = None
        elif a.left.npl < a.right.npl:
            a.left, a.right = a.right, a.left

        a.npl = a.right.npl + 1 if a.right else 0
        return a

    def insert(self, a):
        self.root = self._merge(Node(a), self.root)

    def extract_min(self):
        if self.is_empty():
            return -1
        min_val = self.root.element
        self.root = self._merge(self.root.left, self.root.right)
        return min_val

    def in_order(self):
        result = []
        self._in_order_aux(self.root, result)
        return result

    def _in_order_aux(self, node, result):
        if node is None:
            return
        self._in_order_aux(node.left, result)
        result.append(node.element)
        self._in_order_aux(node.right, result)

    def main(self):
        import sys
        for line in sys.stdin:
            command = line.strip()
            if not command:
                break
            parts = command.split()
            operation = parts[0]

            try:
                if operation == "insert":
                    value = int(parts[1])
                    self.insert(value)
                    print(f"Inserted: {value}")
                elif operation == "extractMin":
                    min_val = self.extract_min()
                    print(f"Extracted Min: {min_val if min_val != -1 else 'Heap is empty'}")
                elif operation == "inOrder":
                    in_order_list = self.in_order()
                    print(f"In-Order: {in_order_list}")
                elif operation == "clear":
                    self.clear()
                    print("Heap cleared")
                elif operation == "isEmpty":
                    print(f"Is Empty: {self.is_empty()}")
                else:
                    print(f"Unknown operation: {operation}")
            except Exception as e:
                print(f"Error: {e}")

if __name__ == "__main__":
    heap = Main()
    heap.main()
