
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
        if self.root is None:
            print("")
            print("")
            return
        acc = []
        self.inorder_traversal(self.root, acc)
        print(" " + " ".join(map(str, acc)))
        acc = []
        self.preorder_traversal(self.root, acc)
        print(" " + " ".join(map(str, acc)))

    def inorder_traversal(self, node, acc):
        if node is None:
            return acc
        if node.left is not None:
            self.inorder_traversal(node.left, acc)
        acc.append(node.key)
        if node.right is not None:
            self.inorder_traversal(node.right, acc)
        return acc

    def preorder_traversal(self, node, acc):
        if node is None:
            return acc
        acc.append(node.key)
        if node.left is not None:
            self.preorder_traversal(node.left, acc)
        if node.right is not None:
            self.preorder_traversal(node.right, acc)
        return acc

if __name__ == "__main__":
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

