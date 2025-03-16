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
    def sort(self, unsorted_array):
        tree = BST()
        for element in unsorted_array:
            tree.add(element)
        sorted_list = tree.in_order_traversal()
        return sorted_list

    def sort_list(self, unsorted_list):
        tree = BST()
        for element in unsorted_list:
            tree.add(element)
        return tree.in_order_traversal()

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().split()

        type = int(data[0])
        n = int(data[1])
        index = 2

        if type == 1:
            array = [int(data[i]) for i in range(2, n + 2)]
            sorted_array = self.sort(array)
            print("Sorted Array:")
            for num in sorted_array:
                print(num, end=" ")
        elif type == 2:
            array = [data[i] for i in range(2, n + 2)]
            sorted_array = self.sort(array)
            print("Sorted Array:")
            for string in sorted_array:
                print(string, end=" ")
        else:
            print("Invalid type entered.")

if __name__ == "__main__":
    main = Main()
    main.main()
