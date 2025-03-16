
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def create_tree(self):
        data = int(input())
        self.root = Node(data)
        self.create_tree_recursive(self.root)

    def create_tree_recursive(self, node):
        left_data = int(input())
        if left_data!= -1:
            node.left = Node(left_data)
            self.create_tree_recursive(node.left)

        right_data = int(input())
        if right_data!= -1:
            node.right = Node(right_data)
            self.create_tree_recursive(node.right)

def is_balanced_recursive(root):
    if root is None:
        return True

    left_height = is_balanced_recursive(root.left)
    right_height = is_balanced_recursive(root.right)

    if left_height == -1 or right_height == -1 or abs(left_height - right_height) > 1:
        return -1

    return max(left_height, right_height) + 1

def is_balanced_iterative(root):
    if root is None:
        return True

    stack = []
    subtree_heights = {}
    last_visited = None

    node = root
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            if node.right is None or node.right == last_visited:
                left_height = subtree_heights.get(node.left, 0)
                right_height = subtree_heights.get(node.right, 0)

                if abs(left_height - right_height) > 1:
                    return False

                subtree_heights[node] = max(left_height, right_height) + 1
                last_visited = node
                node = None
            else:
                node = node.right

    return True

if __name__ == "__main__":
    tree = BinaryTree()
    tree.create_tree()

    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))

