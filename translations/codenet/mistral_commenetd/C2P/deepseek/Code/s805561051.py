class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        self.parent = None

class BinaryTree:
    def __init__(self):
        self.nodes = [TreeNode() for _ in range(26)]
        self.n = 0

    def read_input(self):
        self.n = int(input())
        for i in range(self.n):
            self.nodes[i].value = i
            self.nodes[i].left = -1
            self.nodes[i].right = -1
            if i < self.n - 1:
                values = list(map(int, input().split()))
                if values[0] != -1:
                    self.nodes[i].left = values[0]
                    self.nodes[values[0]].parent = i
                if values[1] != -1:
                    self.nodes[i].right = values[1]
                    self.nodes[values[1]].parent = i

    def find_root(self):
        for i in range(self.n):
            if self.nodes[i].parent is None:
                return i
        return -1

    def preorder(self, node_index):
        if node_index == -1:
            return
        print(f" {node_index}", end="")
        self.preorder(self.nodes[node_index].left)
        self.preorder(self.nodes[node_index].right)

    def inorder(self, node_index):
        if node_index == -1:
            return
        self.inorder(self.nodes[node_index].left)
        print(f" {node_index}", end="")
        self.inorder(self.nodes[node_index].right)

    def postorder(self, node_index):
        if node_index == -1:
            return
        self.postorder(self.nodes[node_index].left)
        self.postorder(self.nodes[node_index].right)
        print(f" {node_index}", end="")

    def print_traversals(self):
        root_index = self.find_root()
        print("Preorder")
        self.preorder(root_index)
        print("\nInorder")
        self.inorder(root_index)
        print("\nPostorder")
        self.postorder(root_index)
        print()

# Main function to read input and print tree traversals
if __name__ == "__main__":
    tree = BinaryTree()
    tree.read_input()
    tree.print_traversals()
