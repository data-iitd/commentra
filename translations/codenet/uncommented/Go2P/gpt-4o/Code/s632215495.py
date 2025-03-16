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
            print(" " + " ".join(map(str, self.visit_inorder(self.root, []))))
            print(" " + " ".join(map(str, self.visit_preorder(self.root, []))))

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

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    tree = Tree()
    
    for i in range(1, n + 1):
        command = data[i].split()
        if command[0] == "insert":
            key = int(command[1])
            tree.insert(key)
        elif command[0] == "print":
            tree.print_tree()
        else:
            raise ValueError("unknown command: " + command[0])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
