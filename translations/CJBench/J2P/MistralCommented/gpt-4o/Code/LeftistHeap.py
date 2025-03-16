class Node:
    def __init__(self, element):
        self.element = element
        self.npl = 0  # number of nodes in the left subtree
        self.left = None
        self.right = None


class Main:
    def __init__(self):
        self.root = None  # root of the heap

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

        if a.element > b.element:  # if a's value is greater than b's value
            a, b = b, a  # swap a and b

        a.right = self._merge(a.right, b)  # merge their right subtrees

        if a.left is None:  # if a has no left child
            a.left = a.right  # make a's left child a's right child
            a.right = None  # a no longer has a right child
        elif a.left.npl < a.right.npl:  # if the number of nodes in a's left subtree is less than the number of nodes in a's right subtree
            a.left, a.right = a.right, a.left  # swap a's left and right children

        a.npl = 0 if a.right is None else a.right.npl + 1  # update the number of nodes in a's left subtree

        return a  # return the merged node

    def insert(self, a):
        self.root = self._merge(Node(a), self.root)  # merge the new node with the root

    def extract_min(self):
        if self.is_empty():
            return -1  # if the heap is empty, return -1

        min_value = self.root.element  # save the minimum value
        self.root = self._merge(self.root.left, self.root.right)  # merge the left and right subtrees to get the new root

        return min_value  # return the minimum value

    def in_order(self):
        lst = []  # initialize an empty list
        self._in_order_aux(self.root, lst)  # traverse the heap in-order and add the values to the list
        return lst

    def _in_order_aux(self, n, lst):
        if n is None:
            return  # if n is null, return

        self._in_order_aux(n.left, lst)  # traverse the left subtree
        lst.append(n.element)  # add the value of n to the list
        self._in_order_aux(n.right, lst)  # traverse the right subtree


if __name__ == "__main__":
    import sys

    heap = Main()  # initialize an empty heap

    for line in sys.stdin:  # read commands from the user until there is no more input
        command = line.strip()  # read the command

        if not command:  # if the command is empty, break out of the loop
            break

        parts = command.split()  # split the command into parts
        operation = parts[0]  # get the operation

        try:
            if operation == "insert":  # if the operation is "insert", insert the value
                value = int(parts[1])
                heap.insert(value)
                print(f"Inserted: {value}")
            elif operation == "extractMin":  # if the operation is "extractMin", extract and print the minimum value
                min_value = heap.extract_min()
                print("Heap is empty" if min_value == -1 else f"Extracted Min: {min_value}")
            elif operation == "inOrder":  # if the operation is "inOrder", print the values in-order
                in_order_list = heap.in_order()
                print(f"In-Order: {in_order_list}")
            elif operation == "clear":  # if the operation is "clear", clear the heap
                heap.clear()
                print("Heap cleared")
            elif operation == "isEmpty":  # if the operation is "isEmpty", print whether the heap is empty or not
                print(f"Is Empty: {heap.is_empty()}")
            else:  # if the operation is not recognized, print an error message
                print(f"Unknown operation: {operation}")
        except Exception as e:  # catch any exceptions and print an error message
            print(f"Error: {e}")

# <END-OF-CODE>
