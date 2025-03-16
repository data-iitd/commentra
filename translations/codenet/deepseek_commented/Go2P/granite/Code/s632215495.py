
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
        while current_node is not None:
            parent_node = current_node
            if current_node.key < key:
                current_node = current_node.right
            else:
                current_node = current_node.left
        new_node = Node(key)
        new_node.parent = parent_node
        if parent_node.key < key:
            parent_node.right = new_node
        else:
            parent_node.left = new_node

    def print(self):
        if self.root is None:
            print("")
            print("")
            return
        inorder_keys = self.inorder_traversal(self.root)
        preorder_keys = self.preorder_traversal(self.root)
        print(" " + " ".join(map(str, inorder_keys)))
        print(" " + " ".join(map(str, preorder_keys)))

    def inorder_traversal(self, node):
        if node is None:
            return []
        left_subtree_keys = self.inorder_traversal(node.left)
        right_subtree_keys = self.inorder_traversal(node.right)
        return left_subtree_keys + [node.key] + right_subtree_keys

    def preorder_traversal(self, node):
        if node is None:
            return []
        return [node.key] + self.preorder_traversal(node.left) + self.preorder_traversal(node.right)

def main():
    n = int(input())
    tree = Tree()
    for _ in range(n):
        command = input().split()
        if command[0] == "insert":
            key = int(command[1])
            tree.insert(key)
        elif command[0] == "print":
            tree.print()
        else:
            raise ValueError("unknown command: " + command[0])

if __name__ == "__main__":
    main()

