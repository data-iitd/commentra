
import sys
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
        return self.root == None
    def clear(self):
        self.root = None
    def merge(self, h1):
        self.root = self.merge(self.root, h1.root)
        h1.root = None
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
    def insert(self, a):
        self.root = self.merge(Node(a), self.root)
    def extractMin(self):
        if self.isEmpty(): return -1
        min = self.root.element
        self.root = self.merge(self.root.left, self.root.right)
        return min
    def inOrder(self):
        lst = []
        self.inOrderAux(self.root, lst)
        return lst
    def inOrderAux(self, n, lst):
        if n == None: return
        self.inOrderAux(n.left, lst)
        lst.append(n.element)
        self.inOrderAux(n.right, lst)
def main():
    heap = Main()
    while True:
        try:
            command = raw_input().strip()
            if command.isEmpty(): break
            parts = command.split(" ")
            operation = parts[0]
            if operation == "insert":
                value = int(parts[1])
                heap.insert(value)
                print "Inserted: " + str(value)
            elif operation == "extractMin":
                min = heap.extractMin()
                if min == -1:
                    print "Heap is empty"
                else:
                    print "Extracted Min: " + str(min)
            elif operation == "inOrder":
                inOrderList = heap.inOrder()
                print "In-Order: " + str(inOrderList)
            elif operation == "clear":
                heap.clear()
                print "Heap cleared"
            elif operation == "isEmpty":
                print "Is Empty: " + str(heap.isEmpty())
            else:
                print "Unknown operation: " + operation
        except Exception as e:
            print "Error: " + e.getMessage()
if __name__ == "__main__":
    main()

