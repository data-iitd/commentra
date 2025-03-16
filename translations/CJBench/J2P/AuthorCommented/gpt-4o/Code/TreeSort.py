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


class TreeSort:
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

    input = sys.stdin.read
    data = input().splitlines()

    type_of_input = int(data[0])
    n = int(data[1])

    if type_of_input == 1:
        array = list(map(int, data[2:2 + n]))
        sorted_array = TreeSort.sort_array(array)
        print("Sorted Array:")
        print(" ".join(map(str, sorted_array)))
    elif type_of_input == 2:
        array = data[2:2 + n]
        sorted_array = TreeSort.sort_list(array)
        print("Sorted Array:")
        print(" ".join(sorted_array))
    else:
        print("Invalid type entered.")
        
# <END-OF-CODE>
