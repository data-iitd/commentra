
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

def is_balanced_recursive(node):
    if node is None:
        return True
    left_height = is_balanced_recursive(node.left)
    right_height = is_balanced_recursive(node.right)
    if abs(left_height - right_height) > 1:
        return False
    return max(left_height, right_height) + 1

def is_balanced_iterative(node):
    if node is None:
        return True
    stack = []
    subtree_heights = {}
    last_visited = None
    current_node = node
    while stack or current_node:
        if current_node:
            stack.append(current_node)
            current_node = current_node.left
        else:
            current_node = stack.pop()
            if current_node.right is None or current_node.right == last_visited:
                left_height = subtree_heights.get(current_node.left, 0)
                right_height = subtree_heights.get(current_node.right, 0)
                if abs(left_height - right_height) > 1:
                    return False
                subtree_heights[current_node] = max(left_height, right_height) + 1
                last_visited = current_node
                current_node = None
            else:
                current_node = current_node.right
    return True

if __name__ == "__main__":
    tree = BinaryTree()
    tree.create_tree()
    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))

