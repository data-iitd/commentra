class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

class Tree:
    def __init__(self):
        self.root = None

    def create_tree(self, parent, child_index, scanner):
        if parent is None:
            data = int(input("Enter root's data: "))
            self.root = Node(data)
            num_children = int(input(f"Enter the number of children for {data}: "))
        else:
            data = int(input(f"Enter data for child {child_index + 1} of {parent.data}: "))
            num_children = int(input(f"Enter the number of children for {data}: "))
        for i in range(num_children):
            child = self.create_tree(Node(data), i, scanner)
            parent.children.append(child)
        return parent

    def display(self):
        self._display_tree(self.root)

    def _display_tree(self, node):
        print(f"{node.data} => ", end="")
        for child in node.children:
            print(f"{child.data} ", end="")
        print(".")
        for child in node.children:
            self._display_tree(child)

    def size(self):
        return self._size_helper(self.root)

    def _size_helper(self, node):
        size = 0
        for child in node.children:
            size += self._size_helper(child)
        return size + 1

    def max(self):
        return self._max_helper(self.root)

    def _max_helper(self, node):
        max_val = node.data
        for child in node.children:
            max_val = max(max_val, self._max_helper(child))
        return max_val

    def height(self):
        return self._height_helper(self.root) - 1

    def _height_helper(self, node):
        height = 0
        for child in node.children:
            height = max(height, self._height_helper(child))
        return height + 1

    def find(self, value):
        return self._find_helper(self.root, value)

    def _find_helper(self, node, value):
        if node.data == value:
            return True
        for child in node.children:
            if self._find_helper(child, value):
                return True
        return False

    def level_order(self):
        queue = [self.root]
        while queue:
            current = queue.pop(0)
            print(current.data, end=" ")
            queue.extend(current.children)
        print()

if __name__ == "__main__":
    tree = Tree()
    scanner = input
    tree.create_tree(None, 0, scanner)
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree: " + str(tree.size()))
    print("Maximum value in the tree: " + str(tree.max()))
    print("Height of the tree: " + str(tree.height()))
    search_value = int(input("Enter a value to search: "))
    print("Is value present: " + str(tree.find(search_value)))
    print("\nLevel Order Traversal:")
    tree.level_order()
