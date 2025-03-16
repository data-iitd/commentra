class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def create_tree(self):
        self.root = self._create_tree_recursive()

    def _create_tree_recursive(self):
        data = int(input())
        if data == -1:
            return None
        node = self.Node(data)
        node.left = self._create_tree_recursive()
        node.right = self._create_tree_recursive()
        return node


def is_balanced_recursive(root):
    is_balanced = [True]  # Use a list to allow modification in the helper function

    def is_balanced_recursive_helper(node):
        if node is None:
            return 0

        left_height = is_balanced_recursive_helper(node.left)
        right_height = is_balanced_recursive_helper(node.right)

        if abs(left_height - right_height) > 1:
            is_balanced[0] = False

        return max(left_height, right_height) + 1

    is_balanced_recursive_helper(root)
    return is_balanced[0]


def is_balanced_iterative(root):
    if root is None:
        return True

    is_balanced = True
    stack = []
    subtree_heights = {}
    node = root
    last_visited = None

    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            if stack:
                node = stack[-1]
                if node.right is None or node.right == last_visited:
                    left_height = subtree_heights.get(node.left, 0)
                    right_height = subtree_heights.get(node.right, 0)

                    if abs(left_height - right_height) > 1:
                        is_balanced = False

                    subtree_heights[node] = max(left_height, right_height) + 1
                    last_visited = node
                    stack.pop()
                    node = None
                else:
                    node = node.right
            else:
                break

    return is_balanced


if __name__ == "__main__":
    tree = BinaryTree()
    tree.create_tree()

    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))

# <END-OF-CODE>
