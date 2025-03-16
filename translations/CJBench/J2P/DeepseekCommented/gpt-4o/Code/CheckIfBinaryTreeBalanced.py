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
        self._create_tree_recursive(self.root)

    def _create_tree_recursive(self, node):
        left_data = int(input())
        if left_data != -1:
            node.left = Node(left_data)
            self._create_tree_recursive(node.left)
        right_data = int(input())
        if right_data != -1:
            node.right = Node(right_data)
            self._create_tree_recursive(node.right)


def is_balanced_recursive(root):
    is_balanced = [True]

    def is_balanced_recursive_helper(node):
        if not node or not is_balanced[0]:
            return 0
        left_height = is_balanced_recursive_helper(node.left)
        right_height = is_balanced_recursive_helper(node.right)
        if abs(left_height - right_height) > 1:
            is_balanced[0] = False
        return max(left_height, right_height) + 1

    is_balanced_recursive_helper(root)
    return is_balanced[0]


def is_balanced_iterative(root):
    if not root:
        return True
    is_balanced = True
    stack = []
    subtree_heights = {}
    last_visited = None
    node = root
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack[-1]
            if not node.right or node.right == last_visited:
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
    return is_balanced


def main():
    tree = BinaryTree()
    tree.create_tree()
    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))


if __name__ == "__main__":
    main()
