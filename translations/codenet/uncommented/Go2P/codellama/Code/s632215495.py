
import sys

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

    def print(self):
        acc = []
        if self.root is None:
            print("")
            print("")
        else:
            print(" " + " ".join(map(str, visit_inorder(self.root, acc))))
            print(" " + " ".join(map(str, visit_preorder(self.root, acc))))

def visit_preorder(node, acc):
    if node is None:
        return acc
    acc.append(node.key)
    if node.left is not None:
        acc = visit_preorder(node.left, acc)
    if node.right is not None:
        acc = visit_preorder(node.right, acc)
    return acc

def visit_inorder(node, acc):
    if node is None:
        return acc
    if node.left is not None:
        acc = visit_inorder(node.left, acc)
    acc.append(node.key)
    if node.right is not None:
        acc = visit_inorder(node.right, acc)
    return acc

def main():
    sc = sys.stdin
    n = int(sc.readline())

    tree = Tree()
    for i in range(n):
        command = sc.readline().rstrip()
        if command == "insert":
            key = int(sc.readline())
            tree.insert(key)
        elif command == "print":
            tree.print()
        else:
            raise ValueError("unknown command: " + command)

if __name__ == "__main__":
    main()

