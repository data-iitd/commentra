
import sys

# Node class representing each element in the Leftist Heap
class Node:
    def __init__(self, element):
        self.element = element
        self.npl = 0
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    # Checks if the heap is empty
    def isEmpty(self):
        return self.root == None

    # Resets the heap to its initial state, effectively clearing all elements
    def clear(self):
        self.root = None

    # Merges the contents of another Leftist Heap into this one
    def merge(self, h1):
        self.root = self.merge(self.root, h1.root)
        h1.root = None

    # Merges two nodes, maintaining the leftist property
    def merge(self, a, b):
        if a == None: return b
        if b == None: return a

        # Ensure that the leftist property is maintained
        if a.element > b.element:
            temp = a
            a = b
            b = temp

        # Merge the right child of node a with node b
        a.right = self.merge(a.right, b)

        # If left child is null, make right child the left child
        if a.left == None:
            a.left = a.right
            a.right = None
        elif a.left.npl < a.right.npl:
            temp = a.left
            a.left = a.right
            a.right = temp
        a.npl = a.right == None? 0 : a.right.npl + 1
        return a

    # Inserts a new element into the Leftist Heap
    def insert(self, a):
        self.root = self.merge(Node(a), self.root)

    # Extracts and removes the minimum element from the heap
    def extractMin(self):
        if self.isEmpty(): return -1

        min = self.root.element
        self.root = self.merge(self.root.left, self.root.right)
        return min

    # Returns a list of the elements in the heap in in-order traversal
    def inOrder(self):
        lst = []
        self.inOrderAux(self.root, lst)
        return lst

    # Auxiliary function for in-order traversal
    def inOrderAux(self, n, lst):
        if n == None: return
        self.inOrderAux(n.left, lst)
        lst.append(n.element)
        self.inOrderAux(n.right, lst)

# Main method for dynamic input handling
if __name__ == "__main__":
    heap = Main()

    while True:
        try:
            command = input().strip()
            if command.isEmpty(): break

            parts = command.split(" ")
            operation = parts[0]

            if operation == "insert": # Insert an element
                value = int(parts[1])
                heap.insert(value)
                print("Inserted: " + value)
            elif operation == "extractMin": # Extract the minimum element
                min = heap.extractMin()
                print(min == -1? "Heap is empty" : "Extracted Min: " + min)
            elif operation == "inOrder": # Perform in-order traversal
                inOrderList = heap.inOrder()
                print("In-Order: " + inOrderList)
            elif operation == "clear": # Clear the heap
                heap.clear()
                print("Heap cleared")
            elif operation == "isEmpty": # Check if the heap is empty
                print("Is Empty: " + heap.isEmpty())
            else:
                print("Unknown operation: " + operation)
        except Exception as e:
            print("Error: " + e.getMessage())

