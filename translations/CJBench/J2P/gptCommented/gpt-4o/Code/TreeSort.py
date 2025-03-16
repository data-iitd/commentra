class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.left = None  # Reference to left child node
        self.right = None  # Reference to right child node


class BST:
    def __init__(self):
        self.root = None  # Root node of the BST

    def add(self, data):
        self.root = self._add_recursive(self.root, data)  # Start the recursive addition

    def _add_recursive(self, node, data):
        if node is None:
            return Node(data)  # Create a new node if current node is null
        if data < node.data:
            node.left = self._add_recursive(node.left, data)  # Add to left subtree
        else:
            node.right = self._add_recursive(node.right, data)  # Add to right subtree
        return node  # Return the unchanged node pointer

    def in_order_traversal(self):
        result = []  # List to hold the traversal result
        self._in_order_traversal(self.root, result)  # Start the traversal from the root
        return result  # Return the collected result

    def _in_order_traversal(self, node, result):
        if node is not None:
            self._in_order_traversal(node.left, result)  # Traverse left subtree
            result.append(node.data)  # Visit the node
            self._in_order_traversal(node.right, result)  # Traverse right subtree


class Main:
    @staticmethod
    def sort_array(unsorted_array):
        tree = BST()  # Create a new BST instance
        for element in unsorted_array:
            tree.add(element)  # Add each element to the BST
        sorted_list = tree.in_order_traversal()  # Get sorted elements
        return sorted_list  # Return the sorted elements as a list

    @staticmethod
    def sort_list(unsorted_list):
        tree = BST()  # Create a new BST instance
        for element in unsorted_list:
            tree.add(element)  # Add each element to the BST
        return tree.in_order_traversal()  # Return the sorted elements as a list


if __name__ == "__main__":
    import sys

    input_type = int(sys.stdin.readline().strip())  # Read the type of input (1 for array, 2 for list)
    n = int(sys.stdin.readline().strip())  # Read the number of elements

    if input_type == 1:  # Check if the input type is for an Integer array
        array = list(map(int, sys.stdin.readline().strip().split()))  # Read integers from input
        sorted_array = Main.sort_array(array)  # Sort the array using BST
        print("Sorted Array:")  # Print sorted array
        print(" ".join(map(str, sorted_array)))  # Print each sorted integer
    elif input_type == 2:  # Check if the input type is for a String array
        array = [sys.stdin.readline().strip() for _ in range(n)]  # Read strings from input
        sorted_array = Main.sort_list(array)  # Sort the array using BST
        print("Sorted Array:")  # Print sorted array
        print(" ".join(sorted_array))  # Print each sorted string
    else:  # Handle invalid input type
        print("Invalid type entered.")  # Print error message
