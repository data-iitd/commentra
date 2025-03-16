class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

class Tree:
    def __init__(self, root_data):
        self.root = Node(root_data)

    def create_tree(self, parent, child_index, scanner):
        if parent is None:
            print("Enter root's data:")
        else:
            print(f"Enter data for child {child_index + 1} of {parent.data}:")
        node = Node(int(scanner.readline().strip()))
        print("Enter the number of children for", node.data, ":")
        num_children = int(scanner.readline().strip())
        for i in range(num_children):
            child = self.create_tree(node, i, scanner)
            node.children.append(child)
        return node

    def display(self):
        self._display_tree(self.root)

    def _display_tree(self, node):
        print(node.data, end=" => ")
        for child in node.children:
            print(child.data, end=" ")
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
    import sys
    scanner = sys.stdin
    tree = Tree(int(scanner.readline().strip()))
    tree.create_tree(None, 0, scanner)
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree:", tree.size())
    print("Maximum value in the tree:", tree.max())
    print("Height of the tree:", tree.height())
    print("\nEnter a value to search:")
    search_value = int(scanner.readline().strip())
    print("Is value present:", tree.find(search_value))
    print("\nLevel Order Traversal:")
    tree.level_order()
