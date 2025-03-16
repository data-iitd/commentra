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
        a.npl = 0 if a.right is None else a.right.npl + 1
        return a

    def insert(self, a):
        self.root = self._merge(Node(a), self.root)

    def extract_min(self):
        if self.is_empty():
            return -1
        min_element = self.root.element
        self.root = self._merge(self.root.left, self.root.right)
        return min_element

    def in_order(self):
        lst = []
        self._in_order_aux(self.root, lst)
        return lst

    def _in_order_aux(self, n, lst):
        if n is None:
            return
        self._in_order_aux(n.left, lst)
        lst.append(n.element)
        self._in_order_aux(n.right, lst)

if __name__ == "__main__":
    import sys
    heap = Main()
    for line in sys.stdin:
        command = line.strip()
        if not command:
            break
        parts = command.split()
        operation = parts[0]
        try:
            if operation == "insert":
                value = int(parts[1])
                heap.insert(value)
                print(f"Inserted: {value}")
            elif operation == "extractMin":
                min_value = heap.extract_min()
                print("Heap is empty" if min_value == -1 else f"Extracted Min: {min_value}")
            elif operation == "inOrder":
                in_order_list = heap.in_order()
                print(f"In-Order: {in_order_list}")
            elif operation == "clear":
                heap.clear()
                print("Heap cleared")
            elif operation == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")

# <END-OF-CODE>
