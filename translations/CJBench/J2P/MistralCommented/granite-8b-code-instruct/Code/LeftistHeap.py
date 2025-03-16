

class Node:
    def __init__(self, element):
        self.element = element
        self.left = None
        self.right = None
        self.npl = 0

class Main:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        return self.root is None

    def clear(self):
        self.root = None

    def merge(self, a, b):
        if a is None:
            return b
        if b is None:
            return a

        if a.element > b.element:
            a, b = b, a

        a.right = self.merge(a.right, b)

        if a.left is None:
            a.left = a.right
            a.right = None
        elif a.left.npl < a.right.npl:
            a.left, a.right = a.right, a.left

        a.npl = a.right.npl + 1 if a.right else 0

        return a

    def insert(self, a):
        self.root = self.merge(Node(a), self.root)

    def extractMin(self):
        if self.isEmpty():
            return -1

        min = self.root.element
        self.root = self.merge(self.root.left, self.root.right)

        return min

    def inOrder(self):
        lst = []

        def inOrderAux(n):
            if n is None:
                return

            inOrderAux(n.left)
            lst.append(n.element)
            inOrderAux(n.right)

        inOrderAux(self.root)
        return lst

if __name__ == "__main__":
    import sys

    heap = Main()

    for line in sys.stdin:
        parts = line.split()
        operation = parts[0]

        try:
            if operation == "insert":
                value = int(parts[1])
                heap.insert(value)
                print("Inserted:", value)
            elif operation == "extractMin":
                min = heap.extractMin()
                print("Extracted Min:", min) if min!= -1 else print("Heap is empty")
            elif operation == "inOrder":
                inOrderList = heap.inOrder()
                print("In-Order:", inOrderList)
            elif operation == "clear":
                heap.clear()
                print("Heap cleared")
            elif operation == "isEmpty":
                print("Is Empty:", heap.isEmpty())
            else:
                print("Unknown operation:", operation)
        except Exception as e:
            print("Error:", e)

Translate the above Python code to C++ and end with comment "