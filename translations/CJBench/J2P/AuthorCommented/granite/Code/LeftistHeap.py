

class Node:
    def __init__(self, element):
        self.element = element
        self.left = None
        self.right = None
        self.npl = 0

class Main:
    def __init__(self):
        self.root = None

    def is_empty(self):
        return self.root is None

    def clear(self):
        self.root = None

    def merge(self, h1):
        self.root = self.merge_nodes(self.root, h1.root)
        h1.root = None

    def merge_nodes(self, a, b):
        if a is None:
            return b
        if b is None:
            return a

        # Ensure that the leftist property is maintained
        if a.element > b.element:
            a, b = b, a

        # Merge the right child of node a with node b
        a.right = self.merge_nodes(a.right, b)

        # If left child is null, make right child the left child
        if a.left is None:
            a.left = a.right
            a.right = None
        elif a.left.npl < a.right.npl:
            a.left, a.right = a.right, a.left

        a.npl = a.right.npl + 1 if a.right else 0
        return a

    def insert(self, a):
        self.root = self.merge_nodes(Node(a), self.root)

    def extract_min(self):
        if self.is_empty():
            return -1

        min_element = self.root.element
        self.root = self.merge_nodes(self.root.left, self.root.right)
        return min_element

    def in_order(self):
        lst = []
        self.in_order_aux(self.root, lst)
        return lst

    def in_order_aux(self, n, lst):
        if n is None:
            return

        self.in_order_aux(n.left, lst)
        lst.append(n.element)
        self.in_order_aux(n.right, lst)

# Main method for dynamic input handling
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
            if operation == "insert":  # Insert an element
                value = int(parts[1])
                heap.insert(value)
                print(f"Inserted: {value}")
            elif operation == "extractMin":  # Extract the minimum element
                min_element = heap.extract_min()
                print(min_element if min_element!= -1 else "Heap is empty")
            elif operation == "inOrder":  # Perform in-order traversal
                in_order_list = heap.in_order()
                print(f"In-Order: {in_order_list}")
            elif operation == "clear":  # Clear the heap
                heap.clear()
                print("Heap cleared")
            elif operation == "isEmpty":  # Check if the heap is empty
                print(f"Is Empty: {heap.is_empty()}")
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")

