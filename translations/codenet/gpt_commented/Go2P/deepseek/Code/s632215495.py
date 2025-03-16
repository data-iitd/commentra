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

    def print(self):
        acc = []
        if self.root is None:
            print("")
            print("")
        else:
            print(" " + " ".join(map(str, self._visit_inorder(self.root, acc))))
            print(" " + " ".join(map(str, self._visit_preorder(self.root, acc))))

    def _visit_preorder(self, node, acc):
        if node is None:
            return acc
        acc.append(node.key)
        acc = self._visit_preorder(node.left, acc)
        acc = self._visit_preorder(node.right, acc)
        return acc

    def _visit_inorder(self, node, acc):
        if node is None:
            return acc
        acc = self._visit_inorder(node.left, acc)
        acc.append(node.key)
        acc = self._visit_inorder(node.right, acc)
        return acc

class Scanner:
    def __init__(self, input_stream):
        self.scanner = bufio.Scanner(input_stream)
        self.scanner.split(bufio.ScanWords)

    def next_text(self):
        self.scanner.scan()
        return self.scanner.text()

    def next_int(self):
        return int(self.next_text())

def is_to_as(is_list):
    return list(map(str, is_list))

