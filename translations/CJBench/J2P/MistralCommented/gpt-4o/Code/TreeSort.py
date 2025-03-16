class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
        self.root = self._add_recursive(self.root, data)

    def _add_recursive(self, node, data):
        if node is None:
            return Node(data)

        if data < node.data:
            node.left = self._add_recursive(node.left, data)
        else:
            node.right = self._add_recursive(node.right, data)
        return node

    def in_order_traversal(self):
        result = []
        self._in_order_traversal(self.root, result)
        return result

    def _in_order_traversal(self, node, result):
        if node is not None:
            self._in_order_traversal(node.left, result)
            result.append(node.data)
            self._in_order_traversal(node.right, result)


class Main:
    @staticmethod
    def sort_array(unsorted_array):
        tree = BST()
        for element in unsorted_array:
            tree.add(element)
        return tree.in_order_traversal()

    @staticmethod
    def sort_list(unsorted_list):
        tree = BST()
        for element in unsorted_list:
            tree.add(element)
        return tree.in_order_traversal()


if __name__ == "__main__":
    import sys

    # Read the type of input (Array or List)
    type_input = int(input())
    
    # Read the size of the input
    n = int(input())

    # Based on the type of input, create an appropriate data structure
    if type_input == 1:
        array = list(map(int, input().split()))

        # Call the sorting method for the array
        sorted_array = Main.sort_array(array)

        # Print the sorted array
        print("Sorted Array:")
        print(" ".join(map(str, sorted_array)))
    elif type_input == 2:
        array = [input().strip() for _ in range(n)]

        # Call the sorting method for the array
        sorted_array = Main.sort_list(array)

        # Print the sorted array
        print("Sorted Array:")
        print(" ".join(sorted_array))
    else:
        # If an invalid type is entered, print an error message
        print("Invalid type entered.")

# <END-OF-CODE>
