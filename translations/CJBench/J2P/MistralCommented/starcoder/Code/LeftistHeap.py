
import sys

# Initialize an empty heap
class Node:
    def __init__(self, element):
        self.element = element
        self.npl = 0
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    # Check if the heap is empty
    def isEmpty(self):
        return self.root == None

    # Clear the heap
    def clear(self):
        self.root = None

    # Merge two heaps
    def merge(self, h1):
        self.root = self.merge(self.root, h1.root)
        h1.root = None

    # Merge two nodes recursively
    def merge(self, a, b):
        if a == None: return b
        if b == None: return a

        if a.element > b.element:
            temp = a
            a = b
            b = temp

        a.right = self.merge(a.right, b)

        if a.left == None:
            a.left = a.right
            a.right = None
        elif a.left.npl < a.right.npl:
            temp = a.left
            a.left = a.right
            a.right = temp

        a.npl = a.right == None and 0 or a.right.npl + 1

        return a

    # Insert a value into the heap
    def insert(self, a):
        self.root = self.merge(Node(a), self.root)

    # Extract and return the minimum value from the heap
    def extractMin(self):
        if self.isEmpty(): return -1

        min = self.root.element
        self.root = self.merge(self.root.left, self.root.right)

        return min

    # Traverse the heap in-order and return a list of the values
    def inOrder(self):
        lst = []
        self.inOrderAux(self.root, lst)
        return lst

    # Traverse the heap in-order recursively and add the values to the list
    def inOrderAux(self, n, lst):
        if n == None: return

        self.inOrderAux(n.left, lst)
        lst.append(n.element)
        self.inOrderAux(n.right, lst)

    # Main method to read commands from the user and execute them
    def main(self):
        scanner = sys.stdin
        heap = Main()

        while True:
            command = scanner.readline().strip()
            if command == "": break

            parts = command.split(" ")
            operation = parts[0]

            try:
                if operation == "insert":
                    value = int(parts[1])
                    heap.insert(value)
                    print("Inserted: " + str(value))
                elif operation == "extractMin":
                    min = heap.extractMin()
                    print(min == -1 and "Heap is empty" or "Extracted Min: " + str(min))
                elif operation == "inOrder":
                    inOrderList = heap.inOrder()
                    print("In-Order: " + str(inOrderList))
                elif operation == "clear":
                    heap.clear()
                    print("Heap cleared")
                elif operation == "isEmpty":
                    print("Is Empty: " + str(heap.isEmpty()))
                else:
                    print("Unknown operation: " + operation)
            except Exception as e:
                print("Error: " + str(e))

        scanner.close()

# 