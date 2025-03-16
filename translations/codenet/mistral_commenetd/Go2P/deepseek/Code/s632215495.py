class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
            return

        current_node = self.root
        while current_node is not None:
            prev_node = current_node
            if current_node.key < key:
                current_node = current_node.right
            else:
                current_node = current_node.left

        new_node = Node(key)
        new_node.parent = prev_node
        if prev_node.key < key:
            prev_node.right = new_node
        else:
            prev_node.left = new_node

    def print_tree(self):
        if self.root is None:
            print("")
            print("")
            return

        acc = []
        self._visit_inorder(self.root, acc)
        print("Inorder traversal: ", " ".join(map(str, acc)))

        acc = []
        self._visit_preorder(self.root, acc)
        print("Preorder traversal: ", " ".join(map(str, acc)))

    def _visit_preorder(self, node, acc):
        if node is None:
            return

        acc.append(node.key)
        self._visit_preorder(node.left, acc)
        self._visit_preorder(node.right, acc)

    def _visit_inorder(self, node, acc):
        if node is None:
            return

        self._visit_inorder(node.left, acc)
        acc.append(node.key)
        self._visit_inorder(node.right, acc)

def read_int(sc):
    return int(next(sc))

def read_text(sc):
    return next(sc)

def main():
    import sys
    sc = (line for line in sys.stdin)

    n = read_int(sc)
    tree = Tree()

    for _ in range(n):
        command = read_text(sc)
        if command == "insert":
            key = read_int(sc)
            tree.insert(key)
        elif command == "print":
            tree.print_tree()
        else:
            raise ValueError("unknown command: " + command)

if __name__ == "__main__":
    main()
