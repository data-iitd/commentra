

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
        self.root = self.add_recursive(self.root, data)

    def add_recursive(self, node, data):
        if node is None:
            return Node(data)
        if data < node.data:
            node.left = self.add_recursive(node.left, data)
        else:
            node.right = self.add_recursive(node.right, data)
        return node

    def in_order_traversal(self):
        result = []
        self.in_order_traversal_recursive(self.root, result)
        return result

    def in_order_traversal_recursive(self, node, result):
        if node is not None:
            self.in_order_traversal_recursive(node.left, result)
            result.append(node.data)
            self.in_order_traversal_recursive(node.right, result)

def sort(unsorted_array):
    tree = BST()
    for element in unsorted_array:
        tree.add(element)
    sorted_list = tree.in_order_traversal()
    return sorted_list

def sort(unsortedList):
    tree = BST()
    for element in unsortedList:
        tree.add(element)
    return tree.in_order_traversal()

if __name__ == "__main__":
    type = int(input())
    n = int(input())
    if type == 1:
        array = [int(x) for x in input().split()]
        array = sort(array)
        print("Sorted Array:")
        print(*array)
    elif type == 2:
        array = [x for x in input().split()]
        array = sort(array)
        print("Sorted Array:")
        print(*array)
    else:
        print("Invalid type entered.")

This code provides a clear structure with comments explaining each logical block, making it easier to understand and maintain.