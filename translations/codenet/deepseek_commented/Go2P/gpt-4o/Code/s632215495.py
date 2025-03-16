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
        prev_node = None
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
        else:
            inorder_result = self.visit_inorder(self.root, [])
            preorder_result = self.visit_preorder(self.root, [])
            print(" " + " ".join(map(str, inorder_result)))
            print(" " + " ".join(map(str, preorder_result)))

    def visit_preorder(self, node, acc):
        if node is None:
            return acc
        acc.append(node.key)
        if node.left is not None:
            self.visit_preorder(node.left, acc)
        if node.right is not None:
            self.visit_preorder(node.right, acc)
        return acc

    def visit_inorder(self, node, acc):
        if node is None:
            return acc
        if node.left is not None:
            self.visit_inorder(node.left, acc)
        acc.append(node.key)
        if node.right is not None:
            self.visit_inorder(node.right, acc)
        return acc


def next_text(iterator):
    return next(iterator)


def next_int(iterator):
    return int(next_text(iterator))


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    iterator = iter(data)

    n = next_int(iterator)
    tree = Tree()
    for _ in range(n):
        command = next_text(iterator)
        if command == "insert":
            key = next_int(iterator)
            tree.insert(key)
        elif command == "print":
            tree.print_tree()
        else:
            raise ValueError("unknown command: " + command)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
