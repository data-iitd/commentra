class Node:
    def __init__(self, element):
        self.element = element  # The value of the node
        self.npl = 0  # Null Path Length (NPL) for heap property
        self.left = None  # Left child node
        self.right = None  # Right child node


class Main:
    def __init__(self):
        self.root = None  # Initially, the heap is empty

    def is_empty(self):
        return self.root is None  # Returns True if root is None

    def clear(self):
        self.root = None  # Set root to None to clear the heap

    def merge(self, h1):
        self.root = self._merge(self.root, h1.root)  # Merge the current heap with h1
        h1.root = None  # Clear h1 after merging

    def _merge(self, a, b):
        # Base cases for merging
        if a is None:
            return b  # If a is None, return b
        if b is None:
            return a  # If b is None, return a

        # Ensure that 'a' is the smaller element
        if a.element > b.element:
            a, b = b, a  # Swap a and b

        # Recursively merge the right child of 'a' with 'b'
        a.right = self._merge(a.right, b)

        # Adjust the left and right children based on NPL
        if a.left is None:
            a.left = a.right  # If left is None, make left point to right
            a.right = None  # Set right to None
        elif a.left.npl < a.right.npl:
            a.left, a.right = a.right, a.left  # Swap left and right if left's NPL is less

        # Update the NPL of the current node
        a.npl = 0 if a.right is None else a.right.npl + 1
        return a  # Return the merged node

    def insert(self, a):
        self.root = self._merge(Node(a), self.root)  # Merge the new node with the current heap

    def extract_min(self):
        if self.is_empty():
            return -1  # Return -1 if the heap is empty
        min_element = self.root.element  # Store the minimum element
        self.root = self._merge(self.root.left, self.root.right)  # Merge left and right children to maintain heap
        return min_element  # Return the minimum element

    def in_order(self):
        lst = []  # List to store in-order elements
        self._in_order_aux(self.root, lst)  # Call auxiliary method for traversal
        return lst  # Return the list of elements

    def _in_order_aux(self, n, lst):
        if n is None:
            return  # Base case: if node is None, return
        self._in_order_aux(n.left, lst)  # Traverse left subtree
        lst.append(n.element)  # Add current node's element to the list
        self._in_order_aux(n.right, lst)  # Traverse right subtree


if __name__ == "__main__":
    import sys

    heap = Main()  # Create a new heap instance

    # Loop to process user commands
    for line in sys.stdin:
        command = line.strip()  # Read user command
        if not command:  # Exit loop if command is empty
            break
        parts = command.split()  # Split command into parts
        operation = parts[0]  # Get the operation type

        try:
            # Switch case to handle different operations
            if operation == "insert":
                value = int(parts[1])  # Parse the value to insert
                heap.insert(value)  # Insert the value into the heap
                print(f"Inserted: {value}")  # Confirmation message
            elif operation == "extractMin":
                min_value = heap.extract_min()  # Extract the minimum value
                print("Heap is empty" if min_value == -1 else f"Extracted Min: {min_value}")  # Output result
            elif operation == "inOrder":
                in_order_list = heap.in_order()  # Get in-order traversal
                print(f"In-Order: {in_order_list}")  # Output the in-order list
            elif operation == "clear":
                heap.clear()  # Clear the heap
                print("Heap cleared")  # Confirmation message
            elif operation == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")  # Check if heap is empty
            else:
                print(f"Unknown operation: {operation}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions

# <END-OF-CODE>
